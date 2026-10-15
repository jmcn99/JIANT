/* SPDX-License-Identifier: GPL-3.0-only
 * Copyright (C) 2026 Leo Kuroshita (@kurogedelic), Hügelton Instruments */
/* Felucca 1.2: the SEQ TOOLS layer's actions (ui_layer.c: SEQ held on STEP / the DRUM grid, PATTERN, CHANCE,
 * AUTOMATION). Included by ui_layer.c. The white keys from F3 (TL_*):
 *   F3 CLEAR  G3 REVERSE  A3 SHIFT <  B3 SHIFT >       the whole sequence
 *   C4 RANDOM D4 COOK     E4 BEAT (DRUM) F4 CLR AUTO     new / a little changed; (JIANT 0.6.8) F4: the track's automation
 *   G4 CLEAR  A4 REVERSE  B4 FILL  C5 RANDOM             the selected lane (DRUM: ui.lane, black keys 1..8 pick it)
 *   D5 COPY   E5 PASTE                                   (JIANT) one 16-step page (tl_page_copy / tl_page_paste)
 * Each works on the selected track's steps 1..LEN (the steps past LEN stay); the track's automation stays (but
 * CLR AUTO's: it clears the track's automation and locks, every step, the steps stay). No undo
 * (TONIC): the song layer's RECALL brings the section back as it was stored (but PASTE's, below).
 * A step that held something and is empty after loses its locks (as EDIT's step clear); REVERSE and SHIFT move the
 * steps' automation and locks with them. RANDOM and COOK draw from libc.c rng(): no seed is kept, each press
 * differs. A sequence of ties reversed keeps its note first: N T T -> N T T at the mirrored place */
enum { TL_CLEAR, TL_REV, TL_LEFT, TL_RIGHT, TL_RANDOM, TL_COOK, TL_BEAT, TL_CAUTO, TL_LCLR, TL_LREV, TL_LFILL, TL_LRND,
       TL_COPY, TL_PASTE, TL_N };

/* the steps as they were just before an action (tl_take): what REVERSE and SHIFT read; in the pool (RAM's .bss is
 * tight) */
static step_t tl_src[NSTEP] __attribute__((section(".pool")));

static uint32_t tl_len(const track_t *t) { return (uint32_t)clamp(t->p[P_SLEN], 1, NSTEP); }
static uint32_t tl_rnd(uint32_t n) { return n ? rng() % n : 0u; }
static int tl_gate(const step_t *s) { return s->time == ST_NOTE && s->n; }
static uint32_t tl_lane(const step_t *s, uint32_t l) { return (step_lanes(s) >> l) & 1u; }
/* place p's action is there for this track (the lane row and BEAT: DRUM only) */
static int tl_cell(const track_t *t, uint32_t p)
{
    return p < TL_N && (p < TL_BEAT || p == TL_CAUTO || p >= TL_COPY || drum_track(t));
}

/* the steps of t as they are now, before an action */
static void tl_take(const track_t *t) { memcpy(tl_src, t->step, sizeof tl_src); }

/* steps 1..len of t that are not empty (a REST); after the action the ones emptied lose their locks */
static uint64_t tl_used(const track_t *t, uint32_t len)
{
    uint64_t m = 0;
    uint32_t i;
    for (i = 0; i < len; i++)
        if (t->step[i].time != ST_REST)
            m |= (uint64_t)1 << i;
    return m;
}
static void tl_unlock(track_t *t, uint64_t was, uint32_t len)
{
    uint32_t i;
    for (i = 0; i < len; i++)
        if (((was >> i) & 1u) && t->step[i].time == ST_REST)
            (void)motion_clear_locks(t, i);
}

/* step j of t becomes the step src[j] as it was (tl_src), its automation and locks with it */
static void tl_order(track_t *t, uint32_t len, const uint8_t *src)
{
    uint8_t to[NSTEP];
    uint32_t j, k = trk_index(t), f;
    for (j = 0; j < len; j++) {
        t->step[j] = tl_src[src[j]];
        to[src[j]] = (uint8_t)j;
    }
    f = motion_guard();
    for (j = 0; j < motion.count; j++) {
        motion_event_t *e = &motion.event[j];
        if (MOTION_TRK(e) == k && MOTION_STEP(e) < len)
            e->place = (uint8_t)((e->place & 0xC0u) | to[MOTION_STEP(e)]);   /* (the track's bits kept, MOTION_TRK) */
    }
    motion_unguard(f);
}

/* REVERSE: the mirror order; a note's ties (after it) would come before it, so the note goes first again */
static void tl_reverse(track_t *t, uint32_t len)
{
    uint8_t src[NSTEP], h;
    uint32_t j, e, x;
    for (j = 0; j < len; j++)
        src[j] = (uint8_t)(len - 1u - j);
    for (j = 0; j < len; j++) {
        for (e = j; e < len && tl_src[src[e]].time == ST_TIE; e++)
            ;
        if (e == j)
            continue;
        if (e < len && tl_src[src[e]].time == ST_NOTE) {   /* ties j .. e - 1, their note at e: the note to j */
            for (h = src[e], x = e; x > j; x--)
                src[x] = src[x - 1u];
            src[j] = h;
        }
        j = e;                                          /* (past the run and its note) */
    }
    tl_order(t, len, src);
}

/* SHIFT: rotated by one step inside LEN, d = 1 later (>), len - 1 earlier (<) */
static void tl_shift(track_t *t, uint32_t len, uint32_t d)
{
    uint8_t src[NSTEP];
    uint32_t j;
    for (j = 0; j < len; j++)
        src[j] = (uint8_t)((j + len - d) % len);
    tl_order(t, len, src);
}

/* ------------------------------------------------------------- drums --- */
/* hits per 16 steps -> per len (at least one when any) */
static uint32_t tl_per(uint32_t k16, uint32_t len) { return !k16 ? 0u : k16 * len < 16u ? 1u : (k16 * len + 8u) / 16u; }
/* k hits spread evenly over len steps (euclidean: the first on step rot; mir: mirrored around it) into lane l */
static void tl_euclid(track_t *t, uint32_t len, uint32_t l, uint32_t k, uint32_t rot, uint32_t mir)
{
    uint32_t i;
    for (i = 0; k && i < len; i++)
        if ((i * k) % len < k)
            grid_hit(t, ((mir ? len - i : i) + rot) % len, l, 1);
}
static void tl_lane_clear(track_t *t, uint32_t len, uint32_t l)
{
    uint32_t i;
    for (i = 0; i < len; i++)
        grid_hit(t, i, l, 0);
}
/* lane l at random, the drum machine way: the kick 3..5 a bar (one on step 1), the snare on beats 2 and 4, the
 * closed hat 8..12, the others sparse (any: they may stay empty, RANDOM; else at least one hit, RANDOM LANE) */
static void tl_lane_rnd(track_t *t, uint32_t len, uint32_t l, int any)
{
    tl_lane_clear(t, len, l);
    if (l == DV_KICK)
        tl_euclid(t, len, l, tl_per(3u + tl_rnd(3), len), 0, tl_rnd(2));
    else if (l == DV_SNARE)
        tl_euclid(t, len, l, tl_per(2, len), 4u % len, 0);
    else if (l == DV_HATC)
        tl_euclid(t, len, l, tl_per(8u + tl_rnd(5), len), tl_rnd(2), 0);
    else if (!any || !tl_rnd(l == DV_HATO ? 2u : 3u))
        tl_euclid(t, len, l, tl_per(1u + tl_rnd(2), len), l == DV_HATO ? (2u + 4u * tl_rnd(4)) % len : tl_rnd(len), 0);
    if (l == DV_SNARE && !tl_rnd(3))
        grid_hit(t, tl_rnd(len), l, 1);                 /* (a ghost snare now and then) */
}

/* the lane hits of steps 1..len (n-th: its step and lane), the kick on step 1 not counted (it stays) */
static uint32_t tl_hit_nth(const track_t *t, uint32_t len, uint32_t n, uint32_t *ip, uint32_t *lp)
{
    uint32_t i, l, c = 0;
    for (i = 0; i < len; i++)
        for (l = 0; l < NLANE; l++)
            if (tl_lane(&t->step[i], l) && (i || l != DV_KICK) && c++ == n) {
                *ip = i;
                *lp = l;
                return 1;
            }
    return c;
}
static uint32_t tl_lane_hits(const track_t *t, uint32_t len, uint32_t l)
{
    uint32_t i, c = 0;
    for (i = 0; i < len; i++)
        c += tl_lane(&t->step[i], l);
    return c;
}
/* COOK on drums: 10..20 % of the hits (at least one) moved a step, or one added on a lane in use, or one taken
 * away (never a lane's last, never the kick on step 1). A try that cannot (the step taken, a lane's last hit) does
 * not count: another one is made (at most a few times as many) */
static uint32_t tl_cook_hit(track_t *t, uint32_t len)
{
    uint32_t i = 0, l = 0, j, r = tl_rnd(4), n = tl_hit_nth(t, len, ~0u, &i, &l);   /* (n: the count) */
    if (r == 2u || !n) {                                /* add: on a lane in use (none: the closed hat) */
        uint32_t used = 0;
        for (j = 0; j < len; j++)
            used |= step_lanes(&t->step[j]);
        for (l = DV_HATC, j = tl_rnd(NLANE); used && j < 2u * NLANE; j++)
            if ((used >> (j % NLANE)) & 1u) {
                l = j % NLANE;
                break;
            }
        j = tl_rnd(len);
        if (tl_lane(&t->step[j], l))
            return 0;
        grid_hit(t, j, l, 1);
        return 1;
    }
    tl_hit_nth(t, len, tl_rnd(n), &i, &l);
    if (r == 3u) {                                      /* take one away */
        if (tl_lane_hits(t, len, l) < 2u)
            return 0;
        grid_hit(t, i, l, 0);
        return 1;
    }
    j = (i + (tl_rnd(2) ? 1u : len - 1u)) % len;        /* move one a step on (or back) */
    if (tl_lane(&t->step[j], l))
        return 0;
    r = (step_accents(&t->step[i]) >> l) & 1u;
    grid_hit(t, i, l, 0);
    grid_hit(t, j, l, 1);
    if (r)
        grid_acc(t, j, l, 1);
    return 1;
}
static void tl_cook_drum(track_t *t, uint32_t len, uint32_t hits)
{
    uint32_t m = hits * (10u + tl_rnd(11)) / 100u, n, sig = steps_sig(t);
    for (m = m ? m : 1u, n = 4u * m + 64u; n; n--) {
        if (tl_cook_hit(t, len) && m)
            m--;
        if (!m && steps_sig(t) != sig)                  /* (a hit moved there and back: one more) */
            break;
    }
}

/* FILL LANE: each press the next of every step, every 2nd, every 4th, none (anything else: every step).
 * Returns the division now (0: cleared) */
static uint32_t tl_fill(track_t *t, uint32_t len, uint32_t l)
{
    static const uint8_t E[3] = {1, 2, 4};
    uint32_t e, i, now = 0;
    for (e = 0; e < 3u && !now; e++) {
        for (i = 0; i < len && tl_lane(&t->step[i], l) == (i % E[e] == 0u); i++)
            ;
        if (i == len)
            now = e + 1u;
    }
    e = now == 3u ? 0u : E[now % 3u];
    for (i = 0; i < len; i++)
        grid_hit(t, i, l, e && i % e == 0u);
    return e;
}

/* ----------------------------------------------------------- melodic --- */
static int32_t tl_in_scale(const track_t *t, int32_t n) { return (int32_t)((scale_mask(t) >> (uint32_t)((n - t->p[P_ROOT] + 120) % 12)) & 1u); }
/* the next note of the scale above (d 1) or below (d -1) n */
static int32_t tl_neigh(const track_t *t, int32_t n, int32_t d)
{
    uint32_t g = 12;
    do
        n += d;
    while (g-- && !tl_in_scale(t, n));
    return clamp(n, 0, 127);
}
/* RANDOM on a melodic track: the rhythm stays (the NOTE steps, their ties, accents and chance), the notes are new: a
 * walk through the track's scale (ROOT, SCL) 9 semitones either side of the pattern's middle (an empty pattern:
 * around the root near C4, on an 8th-note rhythm with some rests). A chord keeps its shape, each note snapped
 * down into the scale */
static void tl_random_notes(track_t *t, uint32_t len)
{
    uint8_t deg[20];
    int32_t c = 0, lo, d, x;
    uint32_t i, k, g = 0, nd = 0, at;
    for (i = 0; i < len; i++)
        if (tl_gate(&t->step[i])) {
            c += t->step[i].note[0];
            g++;
        }
    if (g) {
        c /= (int32_t)g;
    } else {                                            /* no rhythm: 8ths, a few rests, always step 1 */
        c = 60 + t->p[P_ROOT] % 12;
        c -= c > 66 ? 12 : 0;
        for (i = 0; i < len; i++) {
            step_clear(&t->step[i]);
            if (i % 2u == 0u && (!i || tl_rnd(4))) {
                t->step[i].time = ST_NOTE;
                t->step[i].n = 1;
                t->step[i].vel = 96;
            }
        }
    }
    for (lo = clamp(c - 9, 12, 100), x = lo; x <= lo + 18 && nd < sizeof deg; x++)
        if (tl_in_scale(t, x))
            deg[nd++] = (uint8_t)x;
    if (!nd)
        return;
    at = nd / 2u + tl_rnd(5);
    at = at >= 2u ? at - 2u : 0u;
    for (i = 0; i < len; i++) {
        step_t *s = &t->step[i];
        if (!tl_gate(s))
            continue;
        at = at >= nd ? nd - 1u : at;
        d = (int32_t)deg[at] - s->note[0];
        s->note[0] = deg[at];
        for (k = 1; k < s->n && k < 4u; k++) {
            x = clamp(s->note[k] + d, 1, 127);
            while (!tl_in_scale(t, x) && x > 1)
                x--;
            s->note[k] = (uint8_t)x;
        }
        if (!tl_rnd(6)) {                               /* a leap now and then, else a step or two */
            at = tl_rnd(nd);
        } else {
            x = (int32_t)at + (int32_t)tl_rnd(5) - 2;
            at = (uint32_t)(x < 0 ? -x : x >= (int32_t)nd ? 2 * ((int32_t)nd - 1) - x : x);
        }
    }
}

/* COOK on a melodic track: 15..25 % of the NOTE steps (at least one; more when they undid each other): a note to the
 * next scale note up or down (mostly) or an octave, an accent on / off, a chance of 50 / 75 % or back to 100 */
static void tl_cook_notes(track_t *t, uint32_t len, uint32_t g)
{
    uint32_t m = g * (15u + tl_rnd(11)) / 100u, i, k, r, n, sig = steps_sig(t), tries = 64;
    for (m = m ? m : 1u; tries-- && (m || steps_sig(t) == sig); m -= m != 0u) {   /* (undone again: one more) */
        step_t *s;
        n = tl_rnd(g);
        for (i = 0; i < len && (!tl_gate(&t->step[i]) || n--); i++)
            ;
        s = &t->step[i % NSTEP];
        r = tl_rnd(8);
        if (r == 6u) {
            s->flags ^= SF_ACCENT;
        } else if (r == 7u) {
            step_set_chance(s, step_chance(s) < 100u ? 100u : tl_rnd(2) ? 75u : 50u);
        } else {
            int32_t d = tl_rnd(2) ? 1 : -1, o = r == 5u ? d * 12 : 0;
            for (k = 0; k < s->n && k < 4u; k++)       /* (an octave out of 24 .. 108: a scale step instead) */
                if (s->note[k] + o < 24 || s->note[k] + o > 108)
                    o = 0;
            for (k = 0; k < s->n && k < 4u; k++)
                s->note[k] = (uint8_t)(o ? s->note[k] + o : tl_neigh(t, s->note[k], d));
        }
    }
}

/* ------------------------------------------------------------ actions --- */
/* the action of place p on track t (lane l): its message; 0 = nothing done (said why) */
static const char *tl_do(track_t *t, uint32_t p, uint32_t l)
{
    static char b[24];
    uint32_t len = tl_len(t), i, n = 0;
    uint64_t was = tl_used(t, len);
    int drum = drum_track(t);
    const char *msg = 0;
    l %= NLANE;
    if (p == TL_CAUTO) {                                /* (JIANT 0.6.8) the automation and locks, every step */
        if (!motion_count(t)) {
            ui_message("NOTHING TO CLEAR");
            return 0;
        }
        motion_clear(t);
        return "AUTOMATION CLEARED";
    }
    if (p == TL_COOK) {                                 /* (nothing there: nothing to cook) */
        for (i = 0; i < len; i++)
            n += drum ? (uint32_t)__builtin_popcount(step_lanes(&t->step[i])) : (uint32_t)tl_gate(&t->step[i]);
        if (!n) {
            ui_message("NOTHING TO COOK");
            return 0;
        }
    }
    tl_take(t);
    switch (p) {
    case TL_CLEAR: {                                     /* (0.6.28: names the track, ends its held / repeated notes) */
        static char cb[20];
        for (i = 0; i < len; i++)
            step_clear(&t->step[i]);
        latch_drop_req |= (uint8_t)(1u << trk_index(t));
        str_cpy(cb, "T1 CLEARED", sizeof cb);
        cb[1] = (char)('1' + trk_index(t));
        msg = cb;
        break;
    }
    case TL_REV: tl_reverse(t, len); msg = "REVERSED"; break;
    case TL_LEFT: tl_shift(t, len, len - 1u); msg = "SHIFTED LEFT"; break;
    case TL_RIGHT: tl_shift(t, len, 1u); msg = "SHIFTED RIGHT"; break;
    case TL_RANDOM:
        if (drum) {
            for (i = 0; i < len; i++)
                step_clear(&t->step[i]);
            for (i = 0; i < NLANE; i++)
                tl_lane_rnd(t, len, i, 1);
            msg = "RANDOM BEAT";
        } else {
            tl_random_notes(t, len);
            msg = "RANDOM NOTES";
        }
        break;
    case TL_COOK:
        if (drum)
            tl_cook_drum(t, len, n);
        else
            tl_cook_notes(t, len, n);
        msg = "COOKED";
        break;
    case TL_BEAT:                                       /* four on the floor, the backbeat, 8th hats */
        for (i = 0; i < len; i++) {
            step_clear(&t->step[i]);
            if (i % 4u == 0u) grid_hit(t, i, DV_KICK, 1);
            if (i % 8u == 4u) grid_hit(t, i, DV_SNARE, 1);
            if (i % 2u == 0u) grid_hit(t, i, DV_HATC, 1);
        }
        msg = "BASIC BEAT";
        break;
    default:                                            /* the lane's */
        str_cpy(b, drum_lane_name(t, l), sizeof b);
        if (p == TL_LCLR) {
            tl_lane_clear(t, len, l);
            msg = " CLEARED";
        } else if (p == TL_LREV) {
            for (i = 0; i < len; i++) {
                const step_t *s = &tl_src[len - 1u - i];
                grid_hit(t, i, l, tl_lane(s, l));
                if (tl_lane(s, l))
                    grid_acc(t, i, l, (step_accents(s) >> l) & 1u);
            }
            msg = " REVERSED";
        } else if (p == TL_LFILL) {
            n = tl_fill(t, len, l);
            msg = n == 1u ? " EVERY STEP" : n == 2u ? " EVERY 2ND" : n ? " EVERY 4TH" : " CLEARED";
        } else {
            tl_lane_rnd(t, len, l, 0);
            msg = " RANDOM";
        }
        str_cpy(b + str_len(b), msg, sizeof b - str_len(b));
        msg = b;
        break;
    }
    tl_unlock(t, was, len);
    return msg;
}

/* ------------------------------------------------- (0.6.85) SEQ > STRETCH --- */
/* the selected track's steps 1..LEN as a whole, its automation and locks with them (tl_src: the steps before):
 *   STRETCH xk: step i to step i*k (LEN x k, up to 64: what falls past 64 is cut); a note held into the next step (a TIE
 *     after it) keeps holding over the new steps, a short note stays short (its gate), a hit stays a hit
 *   STRETCH /k: step j takes the first step that plays among i = j*k .. j*k+k-1 (a TIE if the note before holds on);
 *     LEN / k (rounded up)
 *   REPEAT xk: steps 1..LEN again after them, k times in all (LEN x k, up to 64; TO 64: as many whole times as fit),
 *     the automation and locks copied while there is room
 * Returns the new LEN (0: nothing to do) */
static void tl_motion_map(track_t *t, uint32_t olen, uint32_t num, uint32_t den, uint32_t nlen)   /* event step s < olen
                                                                                                * -> s*num/den */
{
    uint32_t i, n = 0, k = trk_index(t), f = motion_guard();
    for (i = 0; i < motion.count; i++) {
        motion_event_t e = motion.event[i];
        if (MOTION_TRK(&e) == k && MOTION_STEP(&e) >= olen && MOTION_STEP(&e) < nlen) continue;   /* (its step cleared) */
        if (MOTION_TRK(&e) == k && MOTION_STEP(&e) < olen) {
            uint32_t s = MOTION_STEP(&e) * num / den;
            if (s >= nlen) continue;                    /* (cut with its step) */
            e.place = (uint8_t)((e.place & 0xC0u) | s);
        }
        motion.event[n++] = e;
    }
    memset(motion.event + n, 0, (MOTION_MAX - n) * sizeof motion.event[0]);
    motion.count = (uint8_t)n;
    RING_PUBLISH();
    motion_unguard(f);
}
static uint32_t tl_stretch(track_t *t, int32_t k)
{
    uint32_t len = tl_len(t), nlen, i, j;
    if (k >= 2) {
        uint32_t m = (uint32_t)k;
        nlen = len * m > NSTEP ? NSTEP : len * m;
        tl_take(t);
        for (j = 0; j < nlen; j++) step_clear(&t->step[j]);   /* (the steps past the new LEN stay, as every tool's) */
        for (i = 0; i < len && i * m < NSTEP; i++) {
            const step_t *s = &tl_src[i];
            int hold = s->time == ST_TIE || (s->time == ST_NOTE && s->n && i + 1u < len && tl_src[i + 1u].time == ST_TIE);
            t->step[i * m] = *s;
            for (j = 1; j < m && i * m + j < NSTEP; j++)
                if (hold) { t->step[i * m + j].time = ST_TIE; t->step[i * m + j].vel = s->vel; }
        }
        tl_motion_map(t, len, m, 1, nlen);
    } else if (k <= -2) {
        uint32_t d = (uint32_t)-k;
        nlen = (len + d - 1u) / d;
        tl_take(t);
        for (j = 0; j < len; j++) step_clear(&t->step[j]);
        for (j = 0; j < nlen; j++) {
            uint32_t pick = NSTEP, tie = 0;
            for (i = j * d; i < j * d + d && i < len; i++) {
                if (tl_src[i].time == ST_NOTE && (tl_src[i].n || tl_src[i].hit)) { pick = i; break; }
                tie |= tl_src[i].time == ST_TIE;
            }
            if (pick < NSTEP) t->step[j] = tl_src[pick];
            else if (tie && j) { t->step[j].time = ST_TIE; t->step[j].vel = tl_src[j * d].vel; }
        }
        tl_motion_map(t, len, 1, d, nlen);
    } else
        return 0;
    t->p[P_SLEN] = (int16_t)(nlen ? nlen : 1u);
    return nlen;
}
static uint32_t tl_repeat(track_t *t, uint32_t k)       /* k: 2..8 times, 0: to 64 */
{
    uint32_t len = tl_len(t), nlen, j, i, n, tk = trk_index(t), f;
    nlen = k ? len * k : (NSTEP / len) * len;
    if (nlen > NSTEP) nlen = NSTEP;
    if (nlen <= len) return 0;
    for (j = len; j < nlen; j++)
        t->step[j] = t->step[j % len];
    tl_motion_map(t, len, 1, 1, nlen);                  /* (what the copies cover loses its own automation) */
    f = motion_guard();                                 /* the automation and locks of steps 1..LEN on each copy */
    n = motion.count;
    for (i = 0; i < n; i++) {
        motion_event_t e = motion.event[i];
        uint32_t s = MOTION_STEP(&e);
        if (MOTION_TRK(&e) != tk || s >= len) continue;
        for (j = s + len; j < nlen && motion.count < MOTION_MAX; j += len) {
            motion_event_t c = e;
            c.place = (uint8_t)((c.place & 0xC0u) | j);
            motion.event[motion.count++] = c;
        }
    }
    RING_PUBLISH();
    motion_unguard(f);
    t->p[P_SLEN] = (int16_t)nlen;
    return nlen;
}

/* ------------------------------------------- (JIANT) COPY / PASTE PAGE --- */
/* D5 COPY: the 16 steps of a page of the selected track (the page the cursor is on: STEP / NOTE ui.cursor / 16, the
 * DRUM grid's page ui.bank, black keys 10 / 11) into tl_pg, with their automation events and locks. The steps past
 * LEN on a page LEN ends inside are copied as empty steps (what does not play is not copied).
 * E5 PASTE: tl_pg onto the cursor's page of the selected track: its 16 steps and the automation / locks on them
 * replaced; a lock on an empty step is not copied, so none lands on one (as tl_unlock clears them). A page past LEN:
 * LEN grows to cover it. The cursor cannot go past LEN (cursor_set wraps), so a paste onto a page that already holds
 * the copy goes to the page after it instead: COPY on page 1 then PASTE PASTE PASTE fills pages 2, 3, 4 (LEN 16 > 64). When
 * the 64 motion records run out the events that fit are pasted ("AUTO FULL: n LEFT OUT").
 * Between tracks: a DRUM page onto a DRUM track, a melodic page onto a melodic track only (a step's lane hits mean
 * nothing to a melodic track, its notes nothing to the grid); another engine: the engine's own ids are left out (as
 * motion_sound_loaded). The copy lasts until another COPY (not saved).
 * PASTE is undoable (GLO + G4): the one SEQ TOOLS action with undo_mark(), an exception to "no undo" above (a paste
 * can overwrite a page that took a while to make; STRETCH / REPEAT mark it the same way) */
static struct {
    step_t step[16];
    motion_event_t ev[MOTION_MAX];                      /* (their step: the page's own 0..15, place's track bits 0) */
    uint8_t valid, n, nev, drum, eng;                   /* (n: its steps inside LEN; eng: eng_idx) */
} tl_pg __attribute__((section(".pool")));              /* (zeroed at boot: nothing copied) */

/* the page the cursor is on, inside LEN */
static uint32_t tl_page_now(const track_t *t)
{
    uint32_t pg = drum_track(t) ? ui.bank : ui.cursor / 16u, last = (tl_len(t) - 1u) / 16u;
    return pg > last ? last : pg;
}
static const char *tl_page_copy(const track_t *t, uint32_t pg)
{
    static char b[20];
    uint32_t len = tl_len(t), at = pg * 16u, k = trk_index(t), i;
    tl_pg.n = (uint8_t)(len - at < 16u ? len - at : 16u);
    for (i = 0; i < 16u; i++) {
        if (i < tl_pg.n)
            tl_pg.step[i] = t->step[at + i];
        else
            step_clear(&tl_pg.step[i]);
    }
    tl_pg.nev = 0;
    for (i = 0; i < motion.count; i++) {
        const motion_event_t *e = &motion.event[i];
        if (MOTION_TRK(e) != k || MOTION_STEP(e) < at || MOTION_STEP(e) >= at + tl_pg.n ||
            ((e->param & MOTION_LOCK) && t->step[MOTION_STEP(e)].time == ST_REST))
            continue;                                   /* (a lock on an empty step: not copied, as tl_unlock) */
        motion_at(&tl_pg.ev[tl_pg.nev], MOTION_STEP(e) - at, MOTION_VAL(e));
        tl_pg.ev[tl_pg.nev++].param = e->param;
    }
    tl_pg.valid = 1;
    tl_pg.drum = (uint8_t)drum_track(t);
    tl_pg.eng = (uint8_t)eng_idx(t->eng_req);
    str_cpy(b, "PAGE 1 COPIED", sizeof b);
    b[5] = (char)('1' + pg);
    return b;
}
/* page pg of t holds the copy already: its steps and its records the same (a lock on an empty step aside) */
static int tl_page_same(const track_t *t, uint32_t pg)
{
    uint32_t at = pg * 16u, k = trk_index(t), i, n = 0;
    if (memcmp(&t->step[at], tl_pg.step, sizeof tl_pg.step))
        return 0;
    for (i = 0; i < motion.count; i++) {                /* (as a COPY of it would hold them) */
        const motion_event_t *e = &motion.event[i];
        n += MOTION_TRK(e) == k && MOTION_STEP(e) >= at && MOTION_STEP(e) < at + 16u &&
             !((e->param & MOTION_LOCK) && t->step[MOTION_STEP(e)].time == ST_REST);
    }
    if (n != tl_pg.nev)
        return 0;
    for (i = 0; i < tl_pg.nev; i++) {
        const motion_event_t *e = &tl_pg.ev[i];
        int32_t j = motion_find(t, at + MOTION_STEP(e), MOTION_ID(e));
        if (j < 0 || motion.event[j].param != e->param || MOTION_VAL(&motion.event[j]) != MOTION_VAL(e))
            return 0;
    }
    return 1;
}
/* the paste onto t at the cursor's page pg: its message (*lost: the records left out for room), 0 = nothing done
 * (said why) */
static const char *tl_page_paste(track_t *t, uint32_t pg, uint32_t *lost)
{
    static char b[20];
    uint32_t at, i, k = trk_index(t), n, f, on, had, other = tl_pg.eng != eng_idx(t->eng_req);
    *lost = 0;
    if (!tl_pg.valid) {
        ui_message("NOTHING COPIED");
        return 0;
    }
    if (tl_pg.drum != (uint8_t)drum_track(t)) {
        ui_message(tl_pg.drum ? "DRUM PAGE: DRUM ONLY" : "NOTE PAGE: NOT DRUM");
        return 0;
    }
    if (pg + 1u < NSTEP / 16u && tl_page_same(t, pg))
        pg++;                                           /* (already there: the page after it) */
    at = pg * 16u;
    undo_mark();                                        /* (0.6.21) UNDO: GLO + G4 (the exception: see above) */
    for (i = 0; i < 16u; i++)
        t->step[at + i] = tl_pg.step[i];
    on = (motion.on >> k) & 1u;
    had = motion_count(t);
    f = motion_guard();                                 /* the page's records go */
    motion_restore(t);
    for (i = 0, n = 0; i < motion.count; i++) {
        const motion_event_t *e = &motion.event[i];
        if (MOTION_TRK(e) == k && MOTION_STEP(e) >= at && MOTION_STEP(e) < at + 16u)
            continue;
        motion.event[n++] = *e;
    }
    memset(motion.event + n, 0, (MOTION_MAX - n) * sizeof motion.event[0]);
    motion.count = (uint8_t)n;
    RING_PUBLISH();
    motion_unguard(f);
    for (i = 0; i < tl_pg.nev; i++) {                   /* the copy's, while there is room */
        const motion_event_t *e = &tl_pg.ev[i];
        uint32_t s = at + MOTION_STEP(e);
        if (other && motion_engine_id(MOTION_ID(e)))
            continue;
        if (motion_put(t, s, MOTION_ID(e), MOTION_VAL(e), e->param & MOTION_LOCK) == 2u)
            (*lost)++;
    }
    motion_full = 0;                                    /* (said here: AUTO FULL, not ui_notices' AUTOMATION FULL) */
    if (had) {                                          /* (PLAY as it was; a track with none: on, as recording does) */
        f = motion_guard();
        motion.on = (uint8_t)(on ? motion.on | 1u << k : motion.on & ~(1u << k));
        motion_unguard(f);
    }
    if (at + tl_pg.n > tl_len(t))
        t->p[P_SLEN] = (int16_t)(at + tl_pg.n);
    n = at + ui.cursor % 16u;                           /* (the cursor onto the page: it shows) */
    cursor_set((int32_t)(n < tl_len(t) ? n : tl_len(t) - 1u));
    str_cpy(b, "PASTED TO PAGE 1", sizeof b);
    b[15] = (char)('1' + pg);
    return b;
}
