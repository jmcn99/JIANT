# JIANT FM

**Bio-synthetic operating system for the M-VAVE FM-1** — synthesis, sequencing, mutation, performance.

[![License: GPL-3.0-only](https://img.shields.io/badge/license-GPL--3.0--only-blue.svg)](LICENSE)
[![Emulator](https://img.shields.io/badge/try%20it-in%20the%20browser-ff7a00.svg)](https://juanjiant-bit.github.io/JIANT/)

![JIANT FM: the signature, the screens and what's new: song ideas, ARRANGE, undo, TRACKS and LOAD](docs/jiant-hero.png)

JIANT FM is an alternative firmware for the **M-VAVE FM-1**, made for playing live and building whole songs without
a computer. It is a fork of [Felucca](https://github.com/hugelton/Felucca) 1.1.5.1 by Hügelton Instruments (GPL-3.0)
and takes its song system from [SLOOP](https://github.com/isod89/sloop-fm1).

**▶ [Try it in the browser](https://juanjiant-bit.github.io/JIANT/)** · **[Web installer](https://juanjiant-bit.github.io/JIANT/webapp/installer/)** · **[Web editor](https://juanjiant-bit.github.io/JIANT/webapp/editor/)**: the emulator runs the same code as
the FM-1, with sound, and is played with your computer keyboard or the mouse. The emulator, the installer and the
editor update themselves with every change merged into `main`.

> **Status: in development (v0.7.2).** It builds and passes every test (Felucca's and its own), Back up the flash before installing it.

> ⚡ **New in 0.6.85 – 0.6.92: a song generator you steer, a compact sequencer that breathes, a delay that feeds back.**
> - **GEN (HOME + SELECT)**: a screen of three pages — GENRE (43 genres or RANDOM), SEED, ENERGY, FORM (loop, parts,
>   a club song); how much DRUMS, BASS, CHORDS, ARP, LEAD; COMPLEX, SWING, HUMAN. OCT+ makes the piece (again: a new
>   seed), the knobs re-make it with one part changed. Drums from priority maps, ~50 bass archetypes written against
>   the kick, chords with a quality each, motifs in phrases, sounds by recipe.
> - **A compact sequencer** (0.6.92): 11 SEQ pages instead of 15, the same powers. **EVERY** on each step says on
>   which loops its components play (1:2 … 4:4, 1:8, FIRST, !FIRST, SKIP): an arpeggio every fourth bar, a jump only
>   the first time. **ARP RATE** in note values (1/32, 1/32T, 1/64 …). **TRACK**: PITCH, CHANCE, one **HUMAN** amount
>   (velocity, timing, gate, decay and release vary a little every loop) and REC Q.
> - **Off the grid**: **REC Q** keeps where you played each note (up to half a step early or late) and **NOTE > MICRO**
>   moves any step by sixteenths; early notes really play early.
> - **STRETCH · REPEAT** act as the knob turns: stretch a sequence x2 … x8 or squeeze it, clone a pattern of any
>   length up to 64 steps, NUDGE it a step, **ROTATE** where it is read from.
> - **A delay to play**: ANALOG (FEEDBK past 100 % self-oscillates, saturating softly; resonant TONE) or DIGITAL
>   (clean); **PING-PONG** across the stereo; with TONE in the middle the repeats are copies of what went in; tape
>   **MOD**.
> - Still on both cores (0.6.71, experimental): **MENU > ABOUT** says **CORES 2** or **CORES 1**.
> [Details](#both-cores-dual-core).

> 🫶 If you resonate with my work, consider supporting me on **[Ko-fi](https://ko-fi.com/juanjiant)** (in Argentina:
> **[Cafecito](https://cafecito.app/juanjiant)**). Thanks for all the good energy, hope you enjoy this little beast ✨🎹

## Manual

What changed in each version: the **[Changelog](#changelog)**, at the end of this page.

The full user manual, every page, layer and setting, with a careful chapter on saving: **[English](docs/MANUAL.md)** ·
**[Español](docs/MANUAL.es.md)**.

## Cheat sheets

Two printable sheets with everything on the device. Click an image to open it full size, or download the PDF.

| Controls | Sound · FX · Mod |
| --- | --- |
| [![JIANT FM cheat sheet: controls](docs/cheatsheet-controls.png)](docs/cheatsheet-controls.png) | [![JIANT FM cheat sheet: sound, effects and modulation](docs/cheatsheet-sound.png)](docs/cheatsheet-sound.png) |
| Every knob and button, the layers with their key maps (FX, GLO, SAVE, EDIT, LFO, SCL, SEQ, REC), the combos and every page's four knobs. **[PDF](docs/cheatsheet-controls.pdf)** | The eight engines' EDIT pages, FILTER, VOICE, ENV, LFO, the MOD matrix, MSEQ, macros, the sequencer, scales and ARP, songs, and every effect: DIST, the SLICER bus, delay, the five reverbs and the master. **[PDF](docs/cheatsheet-sound.pdf)** |

## The idea

A pocket synthesizer shouldn't feel like a menu. JIANT starts from a simple question: what if the device behaved
less like a tool and more like an organism?

That's why everything in JIANT is alive and visible. The screen works like a **thermal camera**: colour isn't
decoration, it's intensity. Cold is cyan and violet, hot is red, orange, yellow and white. A high parameter burns; a
sounding voice glows; silence cools down. Each engine is a **being**, a protozoan drawn in lines whose shape comes
from what you're playing: open the filter and it grows spines, raise the resonance and its membrane vibrates, detune
the oscillators and its nuclei drift apart. HOME is an **ecosystem**: six creatures, one per track, breathing with
their own audio. You don't need to read numbers to know what's going on; you can see it.

At the same time, what is technical is shown as technical. The LFO runs at its rate, the envelope shows where the
voice is, the distortion draws its transfer curve, the delay its echoes, the reverb its response. The organic invites
you to play; the technical lets you understand what you did.

The second idea is that **randomness is an invitation, not an accident**. Every session starts with macros rolled
towards what your sounds have; SELECT on HOME dices the whole piece, on EDIT the sound; macro dice only land on what is playing.
The system pushes you to move things and always leaves you near something that works: the dice start from factory
presets and vary around them, never from nothing.

The third is that **everything is playable and everything is recordable**. Effects are played on the keys and land
in an automation lane; knobs record their movement; songs are built from bars and scenes, and recorded while you
play them. No computer, no samples: everything is synthesized in real time on a chip designed for something else.

And the last one is a discipline: **lightweight**. Every graphic is a handful of lines, every effect fits in the
audio CPU budget, the signature shown at power-on is 428 bytes. An instrument that feels big inside a small device.

## The system

### Both cores (dual core)

*Since 0.6.71, experimental.* The FM-1's chip (JieLi AC791N) has **two processor cores**; Felucca and JIANT up to
0.6.70 used one, which ran everything: the sound, the screen, the keys. Now the second one helps with the sound:

- **How the work is shared.** Every 0.7 ms block, the tracks are split between the two cores by how long each took to
  render over the last blocks (timed as they play, since 0.6.73). While the first core renders its tracks, the second
  renders the others into buffers of its own; then they are added together and go through the master on the first
  core. The drum tracks go together, on one core or the other. Since 0.6.75 the second core also runs the effect
  buses (chorus, delay, reverb), on the sends of the block before (0.7 ms later, inaudible), so they no longer wait.
- **The same sound.** The sum is exactly the one-core sum: a test plays a whole six-track song both ways and checks
  that the output is identical, bit for bit.
- **More room.** With the second core doing part of the synth work, the load meter stays lower: more tracks, voices,
  FM6 and heavy reverbs before the clicks and the cut notes start. LOAD LITE / ECO are still there for the heaviest
  songs.
- **Units that cannot run it.** On some FM-1s the second core now and then reads a word of memory wrong, more often
  under load (found by the Melodee and fm1-x0x developers). JIANT guards against it: every job carries a check word,
  and if the second core reads a wrong one, faults or does not answer in time, it is **stopped at once and the first
  core plays every track again**, with no crash (at most one 0.7 ms block of those tracks is lost). Since 0.6.76 the
  effects' output is checked too: far out of range, the block is muted, their lines cleared and the second core stopped
  the same way. Such a unit
  then stays on one core **until it is switched off**, and so does any unit after a crash while both cores ran.
- **What it says.** MENU > ABOUT, under AUDIO LOAD: **CORES 2**, or **CORES 1** with the reason: REC AT POWER-ON,
  BAD READ, NO ANSWER, FAULT, SINCE A FAULT (an earlier one this power-on), NO START.
- **One core on purpose.** Hold **REC** while switching the FM-1 on: that session plays on one core, as before.
- **Credits.** How to start the second core safely on the FM-1 and the guard against misreads come from
  [Melodee](https://github.com/keremimo/melodee) (keremimo) and [fm1-x0x](https://github.com/charlesvestal/fm1-x0x)
  (Charles Vestal), both GPL-3.0; JIANT's version is in `firmware/hal/fm1_multicore.h`.

### A living screen

![HOME, DICE ALL, ARRANGE, DRUM-X, PUNCH-IN FX and TRACKS · LOAD](docs/jiant-screens.png)

*HOME with its six beings, the song in ARRANGE, the piano roll with the lead off the grid, STRETCH, the delay feeding
back and the DRUM-X colony, exactly as the firmware draws them while a song plays (frames of the presentation song).*

- **Thermal palette**: values, curves, steps, hits and notes are coloured by intensity (cyan → blue → violet → red →
  orange → yellow → white). Selection is violet and active is orange. Fonts, the landing page's: values in
  [IBM Plex Mono](https://github.com/IBM/plex), page names in [Michroma](https://github.com/googlefonts/Michroma-font),
  labels in [Chakra Petch](https://github.com/m4rc1e/Chakra-Petch). No boxes: the cards and panels are their text and
  graphs on black.
- **HOME, the ecosystem**: one being per track (its species from its engine, its shape from its four knobs). Each one
  heats up, swells and moves with its own audio; the selected track is drawn bigger; muted ones go dark; in silence
  they all stay still.
- **Engine pages**: the sound's being drawn in isotherms (four contours of the same body, cold edge, hot core). The
  knobs read as what they are: **CUT** grows spines (more harmonics, spikier), **RES** makes the membrane vibrate,
  **DTN/SPRD** splits two nuclei, **NOIS/RAND/CRSH** frays the edge, **WAVE** changes the lobes.
- **DRUM-X, the colony**: one being per kit sound, each with its own shape (round kick, spiky snare, fringed hats,
  clustered clap, star-shaped cowbell) that swells and heats up when it hits.
- **Live technical graphs**: LFO (the wave runs at its rate, with playhead and current value), ENV (a dot travels the
  curve with the sounding voice), DIST (transfer curve by TYPE and TONE response), DLY and DLY 2 (the echoes, L and
  R), REVERB and REVERB 2 (the impulse response, stereo, drawn per model), CHORUS (the three modulated lines), AUTOPAN (the swing across the stereo field), MASTER
  (clipper curve, PUNCH shape, how much DUCK pulls down), ENV/LFO DEST (bipolar columns under each knob, lit by what
  they send), VOICE (one cell per voice and the glide curve), GLOBAL (the bar in thermal columns with swing, clock and
  tuning).
- **Load meter**: five small bars next to the battery showing the current audio load.
- **Power-on**: the "Jiant FM1" signature is written stroke by stroke in thermal colours (MENU > ANIM OFF: it shows
  up whole).

### Engines
Eight engines, all synthesis, no samples: **ANALOG, FM6, PHASE, LOFI, VOICE, WHEEL, NOISE and DRUM (DRUM-X)**.
- **ANALOG**: two oscillators with **INT** (an interval of ±24 semitones: fifths, octaves) and DTN; besides SAW, SQR,
  TRI, SIN and PWM it has **SYNC**, **RING** and **SAW3** (three saws). Its filter is per voice.
- **FM6**: Dexed's engine (imports .syx), with its algorithms drawn. Fully editable on the device (from Felucca 1.5):
  **EDIT > OPERATOR** (KNOB 1 the operator 1–6, then RATIO or FIXED frequency, FINE, LEVEL), **OP ENV** (the stage
  ATK DEC SUS REL, its RATE and LEVEL, drawn as the envelope) and **OPERATOR 2** (MODE ratio/fixed, DETUNE, VEL), the
  operator lit on the algorithm chart with its frequency. Editing makes the patch the track's own (SLOT OWN) and it is
  saved with the project; the macros (EDIT 1 / 2) still act on top. The web editor edits every byte of it too.
  **Voice bank** (from Felucca 1.4.1): import a 32-voice DX7 cartridge (.syx) in the web editor's 6-OP FM tab and press
  **Send to the device's voice bank**; on an FM6 track **SLOT** (EDIT 2, KNOB 4) then goes F1–F8, OWN, **B1–B32**
  (empty slots skipped), the voice's name on the chart. A voice loaded is copied into the track: projects and user
  presets keep it even after you send another bank. The bank lives in its own flash sector, written power-cut safe;
  the full backup does not include it (keep the .syx).
- **PHASE**: phase distortion with **FB** (the output feeds back into the phase: from hard edge to growl).
- **LOFI**: 1, 4 and 8-bit chip with **BYTE** (bytebeat: 32 formulas picked with ALGO and mutated with VAR). In
  BYTE, **MOTN** sets the speed of the formula's rhythm, **GRIT** crushes its rate, **BEND** folds time and **LOOP**
  repeats a short stretch of the formula: the noise becomes a tone tuned to the note. **FLOAT** is a floatbeat
  generator: 32 formulas of `t` made of sines (rhythm, melody and timbre at once), in the key played.
- **VOICE** (formants, after klattsch), **WHEEL** (drawbar organ) and **NOISE** (coloured and metallic noise).
- **FILTER on every engine** (EDIT > FILTER): **TYPE** LP, HP, BP or **COMB** (a comb tuned to the note you're
  playing; CUT moves it ±32 semitones and RES is how much it rings), **CUT** and **RES**. On ANALOG it's its per-voice
  filter, with DRV; on LOFI it's per voice too (its CUT and RES are the ones on this page); on the others it's a filter
  on the track that follows the LFO and the envelope (LFO/ENV DEST FLT), and its DRV is the track's DIST.

### DRUM-X: synthesized drums with morph
An 8-sound kit (BD SD CP CH OH TM RS CB) generated in real time, Microtonic style.
- Each sound has two sides, **A** and **B**; **MORPH** (KNOB 1) moves between them.
- **FOLD** runs each sound's oscillator through a wavefolder after its envelope: the hit starts bright and the tail
  returns to the clean wave. **FM** changes the timbre with harmonic FM in 8 bands; plus TUNE, TONE, DECAY, NOISE and
  DRV.
- **EDIT > SOUND 3** (per sound): **PMOD** picks how the pitch moves (DECAY, LONG like the 808, random NOISE, SINE),
  **DRV** saturates the oscillator for dense kicks, and **WAVE** changes the waveform.
- **Group mutes** (KICK, SNARE, HAT, PERC) with GLO held and **per-sound mutes** with EDIT held.
- **EDIT > X-MOD** (0.5.1): a tempo-synced LFO on MORPH and RAND, which gives every hit its own MORPH and tune.

### Dice: the system invites you to move everything
- **SELECT** changes the tempo on GLO's pages (GLOBAL, SYSTEM, MIXER) and with GLO held. On **EDIT** it **rolls the
  track's sound dice**: a synth loads one of its factory presets at random and moves each engine parameter up to a
  quarter of its range; DRUM-X rolls the A and B sides of each sound around the factory kit. On **HOME** it opens
  **GEN**, the song generator (since 0.6.91): three pages of settings — a genre among 43 (house, techno, dub, UK garage,
  funk, post punk, jazz, ambient …) or RANDOM, a seed, an energy, a form (a loop, parts, a club song); how much drums,
  bass, chords, arp and lead; complexity, swing, how human. **OCT+** writes the piece from them (OCT+ again: a new
  seed; a knob turned and OCT+: the same piece with that one thing changed), **OCT−** is done. Every piece has one
  scale, drums from the genre's priority map, a bass archetype written against the kick, chords with a quality each
  voiced and led, a motif in phrases, a sound recipe a role, the genre's kit and space (see v0.6.91).
- **UNDO: GLO held + G4** takes back the last big change (DICE ALL, a sound diced, a clear, INIT, RECALL, a pattern or
  project loaded); pressing it again goes forward (redo). G4 breathes when there is something to undo.
- **Macros M1–M4** (LFO held; they stay latched when released until you press LFO again): every session starts with
  two random routes per track towards what its sound has. With the macros open, **SELECT** rolls new routes, only on
  the tracks that are playing; F3 too, G3 clears them. They can be assigned by hand in MOD (SRC M1…M4) and are saved
  with the project.

### Punch-in FX: effects you play and record
With FX held the keys become effects that act while held; on release everything goes back exactly.
- **Audio**: REPEAT 1/8 · 1/16 · 1/32, LPF and HPF.
- **On the notes, OP-Z style**: OCT− and OCT+, 1/2 TEMPO, short DECAY (also lowers sustain: plucks) and long, STUTTER
  1/8 · 1/16, ATK+ (drums too), momentary ARP (on drums, a different fill every time) and RANDOM.
- **Quantized**: they kick in on the transport's next sixteenth; REPEAT and SLICER follow the grid from the first
  moment.
- **Automatable**: with REC armed they land in a 4-bar lane per section. A#4 chooses whether they affect everything,
  the synths or the drums.

### Sequencing
- 64 steps per track, piano roll, drum grid, parameter locks, chance, ratchets, slide and knob automation; live
  recording with overdub, metronome and count-in.
- **SHIFT**: shifts the sequence in steps (OFFSET) and in pitch (PITCH), automatable.
- **One scale for everything**: ROOT, SCALE and QUANT are the song's, the same on every melodic track (no track keeps
  a scale of its own, whatever loads it); **STRN** moves all sequences through the
  scale degrees. **ARP TRNS**: the keys transpose the sequence.
- **SEQ + REC** clears every sequence; **REC + FX / EDIT / ENV / LFO…** clears only that part's automation.

### Songs inside the device
**8 projects**, each with **4 sections (A–D)** and a song of up to 16 rows by bars (SAVE > **ARRANGE**), SLOOP style:
live sections that come in on the next bar, quick chain, SONG REC and STORE / RECALL. Each row can hold a **scene**
(mutes, DRUM-X group mutes, macros and MIDI punch-ins), saved with KNOB 4 on ARRANGE or on its own when recording with
SONG REC. The song's END plays it once (STOP), x2..x8 or forever (LOOP).

### Modulation
- **MOD matrix**: 4 slots per track. Sources: LFO, ENV, VEL, KEY, RAND, MIDI controllers, the 4 macros and STEP.
- **MSEQ**: a modulation sequencer per track (16 levels, LEN, DIV, SLEW), like a CV sequencer.
- **ENV LOOP**: with the note held, the envelope goes back to the attack when it reaches sustain: an ADSR-shaped LFO.

### Effects and master
- **DIST** per track with TYPE (SOFT, HARD, FOLD, CRUSH, RECT) and TONE; the **SLICER** on a bus: T1–T6 and the FX returns switched in (SL BUS), a pitch sequence for its repeats (SL PITCH).
- **Delay**: synced or free TIME (5 ms to 1.48 s), a single TONE, **grain delay** with PITCH and SPRAY (at long times
  too), stereo WIDTH.
- **Reverb** with five models: ROOM, SPRING, **SHIMR** (shimmer, goes up an octave on every pass), **RESO** (four
  strings tuned to the song's scale) and **CLOUD** (a granular wash that blooms into a tail and can freeze); with pre-delay, modulation,
  filter and width; **chorus**, a three-voice stereo ensemble.
- **Master**: **CLIP** (saturation with level compensation: adds character, not volume), **PUNCH** (drives the drums into saturation: denser, fatter body),
  **DUCK** (the kick pulls the rest down) and an **always-on leveler** (a slow 2:1 rider with automatic make-up, from
  −9 to +6 dB: it follows the song, not each hit) before the limiter and the soft clip: quiet patches and heavy CLIP play at a consistent volume.

### Knob acceleration
Turning fast sweeps the whole range; turning slowly is fine adjustment. Turn it off in MENU > KNOB ACCEL.

### Connections and storage
- USB: class-compliant MIDI and audio (the master reaches the computer); TRS MIDI; internal, USB or TRS clock.
- 32 named user presets; the project autosaves 10 s after the last change while stopped (not at power-off).
- **Web editor** for every parameter: FM6 patches, grid, mix and full backup (all 8 songs with their sections, rows
  and scenes).

<details>
<summary><b>What changed from Felucca 1.1.5.1</b></summary>

- **New interface**: thermal palette, Chakra Petch font, beings, HOME ecosystem, live technical graphs and a
  power-on signature.
- **DRUM** is DRUM-X; Felucca's kits were retired. **CHORD** was retired (its parameters are SHIFT). **PHYS** and
  **TRIO** were retired (TRIO lives inside ANALOG; a PHYS sound plays as ANALOG's first preset).
- **No samples**: user samples and the SAMPLE, SLICE and GRAIN engines are gone, to make room for DRUM-X, the effects,
  the punch-ins and the songs. A sound from those engines loads as ANALOG.
- **8 songs**: song 1 is the usual 4 projects, so whatever you saved with Felucca shows up there.
- **FX layer**: REVERSE, TAPE STOP, FREEZE and the harmonizer are gone; the MIDI punch-ins came in.
- **SELECT**: tempo on GLO's pages and the MIXER, the sound's dice on EDIT, everything diced on HOME (after YES).
- **EDIT held**: INIT / RECALL instead of the voice selector. One-step **UNDO** with GLO held + G4 (SAVE held: OCT+ stores the
  section, OCT− recalls it). **No layer lock.**
- **USB names**: "JIANT FM" (MIDI and audio), "JIANT Update" while updating; the web editor and the installer take the older "Felucca" too.

</details>

## Controls

- Pressing a page button opens its page; pressing it again, the next one. HOME goes back to the main screen.
- **Holding** a button opens its quick layer: keys and knobs change function while it is held.

| Hold | Keys | Knobs |
| --- | --- | --- |
| **FX** | F3 G3 A3 REPEAT 1/8, 1/16, 1/32; B3 LPF; C4 HPF. MIDI punch-ins: D4 OCT−, E4 OCT+, F4 1/2 TEMPO, G4 DEC−, A4 DEC+, B4 C5 STUTTER 1/8 · 1/16, D5 ATK+ (everything's attack up, drums included), E5 ARP (drums: a new fill on every press), F5 RANDOM (notes and steps). Everything comes in on the transport's next 1/16. Black keys 1–6: mute T1–T6; A#4 chooses which tracks the MIDI ones affect (all, synths, drums). **Automate**: with REC armed and playing (not in a song), the note effects D4–F5 you hold are recorded in the section's lane (64 steps of 1/16, one a step: the lowest held); repeats, filters, mutes and latched effects are not; G5 erases it where the playhead passes, or entirely with the transport stopped | FILTER, CRUSH, THROW, DEPTH |
| **ARP TRNS** | With the ARP mode on TRNS, the keys (and incoming MIDI) transpose the track's sequence by their interval from C4, without playing notes; the transposition stays on release | — |
| **SEQ > STRETCH · TRACK** | ROTATE (STRETCH, KNOB 4) reads the track's sequence from another step, −32 to +32 (within LEN; live recording writes where you hear it) and PITCH (TRACK, KNOB 1) transposes it ±24 semitones (not on kits). Both can be automated and are also on the SCL layer (KNOB 3 / 4) | ROTATE, PIT |
| **REC + another button** | Hold REC and press FX, EDIT, ENV, LFO, SCL, ARP or GLO: clears that part's automation on the selected track (knob movements and per-step locks; stored values stay). FX: the punch-in lane too. GLO: levels and pan of the 6 tracks. The other way round (FX held then REC) arms recording, as always | — |
| **SEQ + REC** | Hold SEQ and press REC: CLEAR ALL SEQUENCES? (OCT+ confirms): clears the steps and automation of the 6 tracks and the punch-in lane | — |
| **LFO** | — (**MACRO** layer: below, where each macro goes) | M1, M2, M3, M4 |
| **GLO** | Black keys 1–6 mute T1–T6 (latched); 7–10 DRUM group mutes: KICK, SNARE, HAT, PERC; F3–D4 solo T1–T6 while held; E4 unmutes everything; F4 tap tempo; G4 **UNDO** the last big change (again: redo) | T1–T4 level (with T5 or T6 selected: T3–T6) |
| **SCL** | Any key picks the root | ROOT, SCALE, OFFSET, PITCH |
| **EDIT** | F3 **INIT**: the track's sound goes back to factory (on DRUM, the DRUM-X kit too). G3 **RECALL**: back to the sound saved in the section (on DRUM, with its kit). Both ask for confirmation and leave the steps alone. On a DRUM track, black keys 1–8 mute each DRUM-X sound. The engine and sounds are picked in PRESETS | The engine's first 4 EDIT knobs |
| **SEQ** | On the SEQ pages: SEQ TOOLS | LEN, DIV, SWING, GATE |
| **REC** | F3 CLEAR the track, G3 CLICK | CLICK |
| **HOME** | Tap: HOME; held ~0.7 s: MENU | — |
| **SAVE** | Song layer (on SAVE > ARRANGE, KNOB 4 = SCENE): F3–B3 play A–D on the next bar (stopped: at once; several in one hold: quick chain), C4–F4 store into A–D, D5 LOOP / SONG, E5 SONG REC, G5 ARRANGE; OCT+ stores the playing section, OCT− recalls it | KNOB 1: project 1–8 (on release, stopped: loads its section A, replacing the music, no UNDO) |

Others: **PLAY** starts and stops; **REC** arms the selected track; **SELECT** changes the tempo on GLO's pages, rolls
the sound's dice on EDIT and dices everything on HOME (after YES); **ALGORITHM** picks the track on every page; **PRESETS** changes the
sound; **OCT− / OCT+** the octave (on action pages and dialogs: back / confirm); GLO + PLAY restarts from the
beginning.

## User manual

A practical guide to what's new, in the order you'll run into it. The [Controls](#controls) table has the details of
each layer; the complete manual is in **[docs/MANUAL.md](docs/MANUAL.md)** (en español:
**[docs/MANUAL.es.md](docs/MANUAL.es.md)**).

### 1. Getting around
- Each page button (EDIT, ENV, LFO, FX, SEQ, SCL, ARP, GLO, SAVE) opens its first page; pressing it again moves to the
  next one. The title at the top tells you where you are. **HOME** takes you back to the ecosystem.
- **FX in sections**: TRACK (FX, DIST, AUTOPAN), SLICER (4 pages), DELAY (2), REVERB (2), CHORUS, MASTER. A tap goes to
  the next page; **two quick taps** jump to the next section. The footer counts the page within its section (DLY 2/2).
- **Jump to a page**: hold a page button (ENV, LFO, FX, SCL, EDIT, GLO, SAVE, ARP, SEQ) and turn **PRESETS**: its pages go by one by one, forwards or back, with the title on screen; let go and you stay there (no tap, no layer). A plain tap still steps to the next page.
- **ALGORITHM** picks the track (T1–T6) from any page; track pages show the selected track.
- The four knobs drive the four columns on screen. Turning fast sweeps the whole range, slowly fine-tunes.
- **Holding** a button opens its layer (FX, GLO, SCL, LFO, EDIT, SAVE…): release it and you're back where you were.

### 2. Reading the screen
- **HOME**: each being is a track. Its species tells the engine, its shape comes from its four knobs, and it swells
  and heats up with its own audio. The biggest one is the selected track; a dark one is muted.
- **Colours**: cold (cyan, blue) is little, hot (orange, yellow, white) is a lot. Violet is what's selected, orange
  what's active.
- **Load meter** (top right, next to the battery): five small bars showing how much of the audio time the sound is
  using right now. The firmware's RAM is reserved entirely at boot and doesn't change, so this is what's worth
  watching: with all five lit (red, yellow) you're close to the limit and should cut voices, the CLOUD reverb or heavy
  effects. If it's often full: GLO > SYSTEM > **TRACKS 4** (the default; also MENU > AUDIO > TRACKS) leaves T5 and T6
  asleep for headroom, and **LOAD** (next to it; also MENU > SYSTEM > LOAD) lightens the sound: **FULL** everything as
  set, **LITE** the heavy reverbs, the GRAIN delay and FM6 lightened (SHIMMER and CLOUD as ROOM, RESO as SPRING, the
  GRAIN delay plain, FM6 two voices), **ECO** that plus every reverb a SPRING, no SLICER, no chorus (their pages
  hidden) and at most 4 voices a synth track. The project keeps its settings: back on FULL it sounds as saved.
- **Power-on**: the signature draws itself in about a second, with beings swimming round it. To boot straight in: MENU > **ANIM OFF**.

### 3. Making a sound
1. Pick the track with ALGORITHM and the engine/preset with **PRESETS**.
2. **EDIT** opens the engine's pages. Every engine has a **FILTER** page: KNOB 1 TYPE (LP, HP, BP, COMB), KNOB 2 CUT,
   KNOB 3 RES and KNOB 4 DRV (on ANALOG the filter's saturation; on the others the track's DIST). COMB with lots of
   RES and CUT near the centre turns any sound metallic, tuned to the note.
3. **ENV** and **LFO** have their DEST pages: each column sends to a destination (FLT also moves the FILTER page's
   filter). **ENV LOOP** turns the envelope into an LFO while the note is held.
4. **Out of ideas?** **SELECT** on EDIT rolls the sound's dice: it loads a random factory preset of the engine and
   moves its parameters. On HOME it dices the whole piece. Roll until something clicks; GLO + G4 undoes the last one.
5. **EDIT held**: F3 INIT puts the sound back to factory, G3 RECALL to the one you saved in the section.

**LOFI BYTE** (LOFI with WAVE on BYTE): ALGO picks one of 32 bytebeat formulas and **VAR** mutates it (0–15 as
written, then 7 more ways, each with 16 amounts: try sweeping it slowly). On the second page **MOTN** speeds the
formula's rhythm up or down without changing the pitch (64 as written), **GRIT** holds each sample longer (a rate
crusher), BEND folds time (glitches) and LOOP repeats a tiny stretch: with LOOP high the noise turns into a tuned
note. Use the FILTER page for the cutoff and resonance.

**LOFI FLOAT** (WAVE on FLOAT): a floatbeat generator. ALGO picks one of 32 formulas of `t` made of sines (F01
`sin(t·(t>>11^t>>13&7))`, F02 FM with a walking index, F03 a nibble-table melody, F05 a kick and a bass, F06
Sierpinski partials, F07 rhythmic drive, F10 a snare and a tone, F13 a fold, F15 a staircase sine, F19 odd partials
building up, F22 a drum loop, F23 bytebeat inside the phase, F26 a dropped bit, F30 a glide up the partials, F32
euclid hats over a walking chord…). Hold a key: the formula plays in that key. **VAR** mutates `t` like in BYTE,
**MOTN** speeds its slow bits up or down, **FBK** feeds the output back into the formula's time (from a shimmer to chaos), **BEND** folds `t`, **LOOP**
locks it into a short window. CHIP sets the resolution: FULL is smooth, 4BIT and 1BIT crush it.

### 4. DRUM-X drums
- Set a track to DRUM. **KNOB 1 MORPH** goes from side A to side B of the whole kit: it's the knob to play live.
- **FOLD** folds each hit's wave: the attack shines and the tail comes back clean. **FM ENV** strikes FM on each hit's attack (a beater, a click, a metal edge) and leaves the tail clean; EDIT > **TONE** has a band-pass for the hats, rim and cowbell (**BP**) and the oscillators' **FEEDBK**.
- **EDIT > SOUND, SOUND 2, SOUND 3** edit each sound (BD, SD, CP, CH, OH, TM, RS, CB; KNOB 1 on SOUND and SOUND 3
  picks which). SOUND 3 has **PMOD**
  (how the pitch falls: DECAY, 808-style LONG, NOISE, SINE), DRV and WAVE.
- Mutes: **GLO held** + black keys 7–10 (KICK, SNARE, HAT, PERC); **EDIT held** + black keys 1–8 (each sound).
- SELECT on a DRUM track rolls a new kit around the factory one.
- **EDIT > X-MOD** moves the kit by itself: **RATE** (OFF, 4 bars … 1/32, in time with the tempo), **DEPTH** (how far
  it swings MORPH), **SHAPE** (SINE, TRI, SAW, RAMP, S&H) and **RAND** (each hit gets its own MORPH and up to a
  semitone of tune: no two hits alike, great on hats and percussion). INIT turns it off.

### 5. Macros (M1–M4)
- **Hold LFO**: the knobs become M1–M4. Release LFO and they stay **latched** until you press LFO again.
- Every session starts with random routes. With the macros open, **SELECT** rolls new routes only on the tracks that
  are playing; **F3** too, **G3** clears them.
- To pick them by hand: LFO > **MOD**, SRC M1…M4 to any destination. They're saved with the project.

### 6. Effects
- **FX held** turns the keyboard into effects that act while you hold the key and come in on tempo: REPEAT, LPF/HPF,
  octaves, stutter, short/long decay, ARP, RANDOM… (details in [Controls](#controls)). With REC armed and playing,
  they're recorded into the section's lane; G5 erases it.
- **FX** pages: DIST and AUTOPAN per track; SLICER, SL BUS, SL BUS 2 and SL PITCH (the slicer bus, per section); the global DLY / DLY 2, REVERB / REVERB 2, CHORUS and MASTER.
- **AUTOPAN** (FX, after DIST): the track's pan swings left and right around its PAN. **DEPTH** how far (0: off),
  **RATE** how fast, **SYNC** BEAT (RATE in divisions, 4 BARS to 1/32, in time with the bar while playing) or FREE
  (RATE in Hz), **WAVE** SIN, TRI, SAW, SQR or S&H. Square and S&H jump side to side without clicking. The screen
  draws the stereo field with the swing running down it and a dot where the sound is now.
- **CHORUS > STEREO**: the chorus's stereo spread. 0 sounds as it always did; down to mono, up to about twice as wide.

**REVERB > TYPE** (KNOB 1) picks the model. **SIZE is the decay** on every model: the top of the knob gives very long
tails. The other knobs change meaning with the type:

| TYPE | What it is | SIZE | DAMP | MOD | RATE | WIDE |
| --- | --- | --- | --- | --- | --- | --- |
| **ROOM** | Classic room | Decay | Darkens the highs | Modulates the tail (chorus) | Modulation speed | Stereo |
| **SPRING** | Amp spring tank | Spring length and decay | Darkens | How much it wobbles | Wobble speed | Stereo |
| **SHIMR** (shimmer) | A room that rises an octave on every pass: angelic tail | Decay | Darkens | **How much shimmer** (0 = ROOM) | — | — |
| **RESO** | Four strings ringing **tuned to the scale** (I, III, V and VII of ROOT/SCALE). On RESO, PRE becomes **PITCH** (the chord 0–14 steps up the scale) and DAMP becomes **FOLLOW** (OFF / T1–T6: the chord follows the lowest note that track plays, gliding) | Decay (how long they ring) | FOLLOW | Past halfway: opens the chord an octave | — | — |
| **CLOUD** | Granular wash: grains of the last ~0.7 s, scattered and bloomed into a reverb tail that feeds back into itself | Decay; **at max it freezes** the cloud | Darkens | How many grains change pitch (×2, ×½, fifth), plus a chorus on the tail | Grain density | Stereo spread of the grains and the tail |

PRE (pre-delay) and FILT (input tone) work on ROOM and SPRING; on SHIMMER and CLOUD the PRE knob is **AIR** (±24
semitones), on RESO it is PITCH (and DAMP is FOLLOW). LOAD LITE / ECO swaps the heavy ones while they sound (see
GLO > SYSTEM). Ideas: RESO on the drums so the kit sings in the song's
key; CLOUD with SIZE at max to freeze a chord and keep playing over it; SHIMR on a slow pad.

**MASTER**: CLIP saturates without raising the volume (the leveler compensates), PUNCH fattens the drums (more body and density, the tails stay whole), DUCK
makes the kick pull the rest down. The leveler is always on: no need to babysit the volume between patches.

### 7. Sequencing and modulation
- **SEQ**: steps, piano roll, per-step locks, chance, ratchets. **REC** arms live recording; moving a knob while it
  plays records automation.
- **SEQ > TRACK**: PITCH transposes the sequence, CHANCE thins it, HUMAN loosens it; STRETCH's ROTATE reads it from
  another step. **SCL**: ROOT and SCALE apply to every track
  (and to the RESO reverb).
- **LFO > MSEQ**: a 16-step modulation sequencer. KNOB 1 picks the step, KNOB 2 its level, LEN and SLEW its length and
  smoothness; send it to a destination from MOD (SRC STEP).
- Clearing: **REC + button** clears that part's automation; **SEQ + REC** clears every sequence.

### 8. Songs and scenes
- **SAVE held**: F3–B3 launch sections A–D on the next bar while playing (stopped: at once; several in a row build a
  chain), C4–F4 store the current
  section into A–D, D5 toggles LOOP / SONG, E5 records the song live (SONG REC).
- SAVE > **ARRANGE** builds the song: a column of rows (up to 16), each a section and its bars; + ADD adds one; the END
  row plays the song once, x2..x8 or in a LOOP. KNOB 4 stores a **scene** (mutes, macros, punch-ins) in the row.
- 8 projects: KNOB 1 with SAVE held picks which (on release, with the transport stopped: it loads that project's
  section A, replacing the music; no UNDO).

### 9. Saving
- **Sound presets**: SAVE > **USER**: KNOB 1 picks the slot (32), KNOB 4 SAVE stores the track's sound, KNOB 2 LOAD
  loads it, KNOB 3 ERASE deletes it. EDIT names it.
- **Project**: SAVE > PROJECT: KNOB 1 the project (1–8), KNOB 2 the section A–D, LOAD, SAVE; SAVE > ARRANGE chains the sections into the song. The project autosaves 10 s after your last change while stopped
  (at most once a minute; never at power-off: stop and wait a moment before switching off). MENU > RESTORE LAST OFF
  turns it off. The full story, with what is saved where: **[the manual, chapter 12](docs/MANUAL.md)**.
- **Backup**: the web editor (USB) downloads and restores everything: songs, sections, scenes and presets.

### Share your presets
Made something you love? Build it on the device, save it to USER, download the backup with the web editor and share
it (or just describe the idea: name, engine, what you use it for). The best ones can become factory presets in the
next release.

## Building and testing

See [BUILDING.md](BUILDING.md). In short:

```
./build.sh                 # firmware: build/felucca.fwsc
web/emu/build.sh           # browser emulator: build/emu
tests/run_tests.sh         # host, web editor and emulator tests
```

Every change is tested in the emulator first. The published version
([juanjiant-bit.github.io/JIANT](https://juanjiant-bit.github.io/JIANT/)) is built by
[.github/workflows/emulator.yml](.github/workflows/emulator.yml) on every push to `main` (in the repository:
Settings → Pages → Source: **GitHub Actions**, once).

## Installing (at your own risk)

1. **Back up the flash** before the first install. **JIANT has no user samples:** if you're coming from Felucca,
   samples USR1–3 are lost on install (that flash now stores the songs). Keep your WAVs.
2. **Coming from another custom firmware (Felucca, baudgirl or any other)? Return to official V15 first** (the
   installer's **Return to official V15 first** button, which also saves a complete backup), then install JIANT: writing
   it straight over another custom firmware has bricked an FM-1. From official V15 or an earlier JIANT, install
   directly from the **[web installer](https://juanjiant-bit.github.io/JIANT/webapp/installer/)** (Chrome or Edge, the
   FM-1 connected by USB straight to the computer). It checks the FM-1 first and writes only over official V15 or JIANT. It offers the **approved** version only: every change merged into `main` goes first to the
   [emulator](https://juanjiant-bit.github.io/JIANT/) (and a preview installer for testing), is checked there, and only
   then reaches this installer ([web/STABLE](web/STABLE.md)). Offline: `python3 tools/fm1_install.py build/felucca.fwsc`.
3. **Since 0.6.71 JIANT uses both cores** ([details](#both-cores-dual-core)). If your FM-1 crashes, freezes or
   clicks more than before, hold **REC** while switching it on (one core) and tell us what MENU > ABOUT says.
4. To go back to the official firmware, use M-VAVE's updater or the installer's **Return to official V15**.

If the FM-1 stays black after an interrupted update, check whether the computer sees it as **WL80UBOOT** (or a USB
device 4C4A:8057): that's the chip's boot mode and it can be recovered by running the installer again with another
cable. If that's not enough, [FM-1 Transporter](https://github.com/kurogedelic/FM-1-transporter) reads and writes the
flash with a Seeed XIAO RP2040.

## Documents

These design notes are in Spanish.

| Document | What's in it |
| --- | --- |
| [FELUCCA-TONIC-VISION.md](FELUCCA-TONIC-VISION.md) | The vision and the full wish list |
| [FELUCCA-TONIC-SPEC.md](FELUCCA-TONIC-SPEC.md) | The phases and the working rules |
| [docs/TONIC-AUDIT.md](docs/TONIC-AUDIT.md) | Audit: memory, engines, effects, SLOOP's song mode |
| [docs/TONIC-SONG-PLAN.md](docs/TONIC-SONG-PLAN.md) | Song mode plan |
| [docs/TONIC-DRUMX.md](docs/TONIC-DRUMX.md) | DRUM-X: the voice, the per-section kit and the phases |
| [docs/TONIC-UI.md](docs/TONIC-UI.md) | The JIANT FM interface: screen map, format, flash measurements |
| [Cheat sheets](#cheat-sheets) | Controls and sound reference (PNG and PDF; made by `tools/gen_cheatsheets.py` + `tools/render_cheatsheets.mjs`) |
| [BUILDING.md](BUILDING.md) | Toolchain, build, emulator and tests |
| [web/EDITOR_PROTOCOL.md](web/EDITOR_PROTOCOL.md) | The editor's SysEx protocol |
| [LICENSING.md](LICENSING.md) | Licenses of each part |

## Credits

- **[Felucca](https://github.com/hugelton/Felucca)** by [Hügelton Instruments](https://hugelton.com)
  (Leo Kuroshita, [@kurogedelic](https://github.com/kurogedelic)): the whole base of this firmware; PHASE's waveforms
  (a port of [CrispyZebra](https://github.com/hugelton/CrispyZebra), GPL-3.0); the DRUM voices and kits; the
  [Fukiai](https://github.com/hugelton/Fukiai) icon font ([MIT](LICENSES/MIT-Fukiai.txt)). And Felucca's
  contributors: keremimo, ChanceTheMaker, andreahaku, spinkham, zednaked, jasonpersinger.
- **[SLOOP](https://github.com/isod89/sloop-fm1)** by isod89 (GPL-3.0): the sections, quick chain and SONG REC system
  the song mode is based on.
- Fonts: [Chakra Petch](https://github.com/m4rc1e/Chakra-Petch) ([SIL OFL 1.1](LICENSES/OFL-ChakraPetch.txt)), the
  labels; since 0.6.56 [IBM Plex Mono](https://github.com/IBM/plex) ([SIL OFL 1.1](LICENSES/OFL-IBMPlexMono.txt)), the values,
  and [Michroma](https://github.com/googlefonts/Michroma-font) ([SIL OFL 1.1](LICENSES/OFL-Michroma.txt)), the big titles; up to 0.4, [Inter Tight](https://github.com/rsms/inter-tight) ([SIL OFL 1.1](LICENSES/OFL-InterTight.txt));
  in the emulator, [DotGothic16](https://github.com/fontworks-fonts/DotGothic16) ([SIL OFL 1.1](LICENSES/OFL-DotGothic16.txt)).
- VOICE: after [klattsch](https://github.com/tgies/klattsch) by Tony Gies (MIT); formant data from Klatt (1980) and
  Hillenbrand et al. (1995).
- FM6: msfa from [Dexed](https://github.com/asb2m10/dexed), Google Inc. and Pascal Gauthier
  ([Apache-2.0](LICENSES/Apache-2.0-msfa.txt)).
- Both cores (0.6.71): the way to start the AC79's second core and the guard against its misreads after
  [Melodee](https://github.com/keremimo/melodee) by keremimo and [fm1-x0x](https://github.com/charlesvestal/fm1-x0x)
  by Charles Vestal (both GPL-3.0).
- Emulator: after [X0X](https://github.com/charlesvestal/fm1-x0x) by charlesvestal (GPL-3.0).
- Testing and CPU work on a real FM-1: **praztalfractal** ([GitHub: gospodindilly-ops](https://github.com/gospodindilly-ops)):
  the load measurements behind the dual core work, the guard on the effects (0.6.76) and the hot code in RAM (0.6.78).
- Package format: [JieLi AC79 SDK](https://gitee.com/Jieli-Tech/fw-AC79_AIoT_SDK)
  ([Apache-2.0](LICENSES/Apache-2.0.txt); three of its files go into every package, none in this tree).

## AI-assisted development

JIANT is developed with the help of AI agents for the code, the tests and the documentation. The instrument's design
and the decisions are made by its author.

## License

Free software: [GPL-3.0-only](LICENSE), like Felucca. The fonts and the ported DSP keep their own licenses
([LICENSES/](LICENSES/)); details in [LICENSING.md](LICENSING.md).

"Felucca" and "Hügelton Instruments" are names of Hügelton Instruments; JIANT is not affiliated with them. M-VAVE and
FM-1 are trademarks of their owners; JIANT is not affiliated with or endorsed by them.

Copyright (C) 2026 Leo Kuroshita (@kurogedelic), Hügelton Instruments — Felucca.
JIANT's modifications are distributed under the same license.

## Changelog

Every update is listed here, newest first. (Since 0.6.80 at the end of the page: what the synth does comes first.)

### Unreleased (draft, after v0.7.2)
- **Note lengths on SEQ > STEP with KNOB 3 (TIME)**, melodic tracks: a TIE stretches back to the nearest note before
  it, the empty steps in between filled with TIEs (TIED 1-5; within LEN, round its end; not on a PULSE note); a REST
  on a note cuts it there, the TIEs after it rests without their locks (CUT AT 3). On past TIE to NOTE keeps the fill;
  NOTE through TIE to REST clears the note and fills nothing. EDIT on STEP clears a note's TIEs after the step too.
  DRUM tracks, live and step recording as before.

### v0.7.2
- **Nine DRUM-X kits as DRUM presets**: DRUM-X (the factory kit), 909 CLUB (driven kick, bright snare and hats, the
  snare and clap into the reverb), 808 BOOM (the long-decay kick and tom, the sine snare, soft hats, a metal cowbell),
  LOFI DUST (dark, short, noisy, with layers and feedback on the snare and rim), INDUSTRIAL (FM kick driven, metal
  snare, glitch rim and bell, delay on the tom and rim), ACOUSTIC (bell-toned snare and tom, soft hats, a little reverb
  on everything), DUB ROOTS (deep kick, the snare and clap wet, the rim and bell into the delay), TECHNO RAW (FM kick,
  hard snare, loud hats), BREAKS (snappy snare, band-passed hats). Browsing them on a DRUM track (PRESETS, the editor,
  PROGRAM CHANGE) loads the whole kit into the section: the eight sounds' A and B, their LAYERs and SENDs, plus the
  track's MORPH, TUNE, TONE, DECAY, NOISE, FM ENV and DRIVE. An engine switch, INIT SOUND, a project load and the
  generator leave the section's kit as it is; browsing back to DRUM-X brings the factory kit.

### v0.7.1
- **Stems over USB: MENU > SYSTEM > USB > STEMS.** The device re-enumerates as an 8-channel USB audio input (44.1 kHz,
  16 bit): channels 1–6 the six tracks, each mono with its LEVEL, DIST, SLICER routing and mutes in (its PAN not: what it
  adds to the mix, L + R halved), channels 7–8 the FX return in stereo (the DELAY, REVERB and CHORUS buses, the
  SLICER's when it is on). All before the master (no leveler, limiter, clip or MASTER knob: the mix's own scale; USB
  LEVEL −6 dB or more gives headroom). Record the eight in Ableton, Logic or Reaper and post-process each track. The
  row replaces USB SERIAL: **CONSOLE** (the serial console with stereo audio, as ON was), **STEREO** (audio + MIDI only,
  as OFF was), **STEMS**.
- **Stems from the browser: the emulator page renders a backup's song as separate WAV tracks in a ZIP.** Back up the
  FM-1 (the editor's or the installer's "Back up"), load the file on the emulator page (Stems), pick a song or the live
  section with a bar count, and get T1..T6 and MIX, all the same length, 16-bit 44.1 kHz, each track alone with its own
  share of the DELAY, REVERB and CHORUS (the others' sends left out), the song's rows once (a LOOP song once round).
  Faster than real time, no USB limits, nothing on the device.
- The USB audio ring moved into the pool (8 KiB: the stems need four times the stereo stream's); the RAM-code reach
  margin 12 KiB (was 16: RAMTEXT has moved up twice already, each move off the user stack).

### v0.7.0
- **46 new factory presets**, a palette the song generator and the player share: ANALOG JUNO PAD, REESE, HOOVER, DUB
  STAB, CELLO, ARP PLUCK, MOOG LEAD, DARK PAD, GLASS KEYS, ORGAN SQR; PHASE CZ PIANO, GLASS PAD, DIGI STAB, SYN BASS,
  VOX PAD, HARP, PD LEAD, RING KEYS; LOFI CHIP PAD, GB ARP, TRI BASS, SOFT CHIP, SAW CHIP; VOICE OOH PAD, CHANT, TALK
  BOX; WHEEL DUB ORGAN, SOFT KEYS, CHURCH, WAVE ORGAN, REED BASS; NOISE SEA, HISS PAD, CRACKLE, TAPE AIR; FM6 ICE
  BELL, DX KEYS, FM PLUCK, SOFT BELL, FM STRINGS, HARD BASS, WOOD. Appended: every stored preset number stays.
- **GEN: the sounds from that palette** (every recipe's words point at the new presets first: a pad is a JUNO PAD or a
  GLASS PAD, a stab a DUB STAB or a DIGI STAB, a lead a MOOG LEAD or a PD LEAD, a texture the SEA or TAPE AIR ..), and
  **melodies that hold together**: the line stays in its octave (a leap past a sixth takes the octave nearer the last
  note), the motif follows the chord the nearer way (a fourth up is a fifth down, never an octave's worth of leap, and
  less often), every phrase ends on a chord tone.
- **GEN: HOME closes the screen** (OCT− still does).
- **The modulation matrix reaches the FX buses**: eight destinations after CLIP and PNCH, D.TIM D.FB D.TON D.MIX
  (DELAY), R.SIZ R.DMP (REVERB), C.RAT C.DEP (CHORUS); AMT 64 at a full source = the whole range, every track's
  slots add. A STEP source (the mod sequence) on D.TIM sequences the delay time; an LFO on R.SIZ breathes the room.
- **MENU > AUDIO > USB LEVEL: −6 / −12 / −18 / −24 dB** after MASTER and FIXED: USB audio fixed and attenuated, for a
  phone or a computer whose input clips at the full level (the recordings came out distorted). The speaker and the
  headphones keep the MASTER knob.
- **The device is JIANT everywhere it speaks**: USB MIDI and audio "JIANT FM" (the updater "JIANT Update"), the
  editor's version string "JIANT v0.7.0", the splash, ABOUT, CREDITS, the console and the crash screen. The web
  editor and the installer accept both names, so an older firmware still connects.
- **Fix (a community report): browsing presets switched SCL > CHORD off.** A sound load now keeps CHORD, VOICING and
  STRUM, and with them C.LEN, CHANCE and MUTATE: the sequencer's settings, not the sound's.

### v0.6.99
- **FX > PUNCH: the punch-in effects' sequencer.** The lane that records them gets a page: **LEN** 1 … 64 steps, **RES**
  1/8, 1/16 or 1/32 of a beat, KNOB 3 its state (REC, PLAY, or how many steps hold an effect), **CLEAR** (KNOB 4,
  OCT+). The page draws the lane's cells in the effects' colours with the playhead, the last effect's name and the
  tracks it acts on. Recording as before: REC armed and playing, FX held with the effect's key; G5 erases. LEN and
  RES are saved with the section (a new block: older firmware ignores it, older projects load as 64 steps of 1/16).

### v0.6.98
- **WALK and CLIMB, evolving step components** (after the OP-Z's and OP-XY's): the step's notes move a degree of the
  scale (WALK) or an octave (CLIMB) every so many loops (1 … 10, 12, 16), over a range (3, 5, 7, 12 degrees; 1 … 4
  octaves), UP, DOWN, UP-DN or RND, then round again. They stack: a WALK on COMP with a CLIMB on COMP 2, a TONAL or an
  OCT on top, an ARP walking with its chord. Four notes, two of these, and the pattern evolves for dozens of loops
  before it comes back to itself. The COMP page draws the moves round the range, this loop's lit; GEN uses them on
  leads and arps. Older projects are untouched (new component ids).

### v0.6.97
- **GEN: the drums less alike.** A throw takes its closed hats, open hats, rim, cowbell and toms from pools of
  patterns (eighths, driven sixteenths, offbeats, shuffles, tresillos ..) now and then instead of the genre's map, swaps
  the snare and the clap now and then, adds a kick on a weak step more often; FORM PARTS / SONG give **each section
  its own fill** (roll, toms, hat roll, drop, linear, kick sixteenths).
- **The kit's space**: the snare and the clap into the reverb (the kit's own SENDs, by how wet the genre is), the rim
  into the delay and a touch of reverb on the open hat where the genre is wet; **MORPH automated** over the loop on the
  drum track now and then (the kit's character drifting and back).
- **Effects by genre**: the wet genres (dub, dub techno, shoegaze, ambient ..) get long delay tails with the tape's
  wobble (FEEDBK 58–80, MOD 20–50); a **punch-in lane** in the SONG form: a stutter into the drop (1/8, then 1/16 on
  the build's last beat), the synths an octave up on the break's last bar.
- **Sounds**: leads no longer at full sustain (SUS 30–90, their decay in play), a late vibrato on half the leads, a
  slow tremolo or pan on pads, arps panning on the beat; **more step components** (from COMPLEX 30 up: echoes,
  octaves, bends, pulses, ratchets, some every other loop).
- **Lead melodies** from a library of rhythmic cells that hold together (a long note and two short ones, a tresillo, a
  pickup into the three, a dotted push ..) thinned by COMPLEX, instead of onsets drawn one by one.
- **POST PUNK after Joy Division and New Order**: Hook's bass high on the neck (Transmission's eighths over root,
  fifth, octave and seventh; Blue Monday's sequenced sixteenth octaves; Ceremony's run), Morris's drums (the kick
  syncopated against flat sixteenth hats, or four on the floor with a clap, open hats and toms into the one),
  Sumner's pulsed chords, an octave arp, strings and a choir behind, 118–148 BPM.
- **PLAY on the GEN screen** runs and stops the transport: the piece heard without leaving the screen.
- The memory map: the RAM code 4 KiB higher (the image grew past a call's reach from it), the user stack 4 KiB
  shorter (19.75 KiB).

### v0.6.96
- **MUTATE** (reported on r/MVaveFM1): a new piece from GEN or the dice turns MUTATE off on every track and makes the
  piece its anchor (a reroll kept the lanes, the drum track's above all, and ORBIT mutated around the previous piece's
  sounds); a sound loaded onto a mutating track re-anchors too. The MUTATE page shows the selected track alone since
  0.6.92 (it showed six with TRACKS 4).
- **LEDS DIM HI brighter** (reported): the idle glow was the pulse alone (~1/30 of lit), too dim to find the keys;
  now the glow plus a lit frame in eight (~15 %), the grid's beats and the scale's root a level above (~40 %). DIM LO
  stays the darker one, OFF and INV as they were.
- **STRETCH over REPEAT**: the other knob's result is the base now, so REPEAT x2 then STRETCH x2 stretches the
  repeats (it went back to the sequence before the repeat); the same knob still works from its own base.
- **ABOUT / CREDITS** opens on the project's own information (JIANT FM for the MVAVE FM-1, by Juan Jiant, Argentina:
  the site, the videos, Ko-fi and Cafecito), Felucca's credits and licences below as before.
- **GEN screen**: the body is cleared once on entering, not on every knob or page (it flickered).
- **MIDI CC for the engine's knobs** (asked on YouTube): CC16–23 set the engine's eight values (EDIT 1 / EDIT 2's
  knobs, E1–E8, whatever the engine), CC102 / CC103 the post filter's cutoff / resonance, CC104 DRIVE, CC105 SUSTAIN;
  recorded as automation like a knob, as the rest of the map.

### v0.6.95
- **GEN: every throw its own.** A genre's throw may take a neighbour's drum map (the map's family: HOUSE takes DEEP's
  or TECH HOUSE's, TECHNO DETROIT's or HYPNOTIC's ..), another chord play (stabs become pulses or dub chords ..) and a
  role's neighbouring recipe (a pluck a bell, a pad strings ..), each about a third of the time, so two throws of a
  genre are no longer the same piece in another key. The hats and the percussion thin with the DRUMS amount a hit at a
  time.
- **RANDOM throws mutants** half the time or so: the drums of one genre, the bass of another, the chords, arp, lead and
  space from either, a tempo between the two, more components, and an arp or lead in another metre (12, 20, 24 or 28
  steps against the 16). Named after both: **EBM+JAZZ 0421**.
- **EBM after Nitzer Ebb**: three new bass archetypes (relentless sixteenths on the root, the octave and the minor
  third, a rest where the body hits, accents on the beat), a square bass recipe, short and driven, 118–132 BPM.
- **POST ROCK after Radiohead**: add9 / sus progressions (i add9, VI7, VII sus2, iv add9; i, III, VI, V sus4), long roots
  walking up at the phrase's end, a clean arpeggio, an electric piano, a voice lead, strings behind.
- A power chord voiced over the top of its range came down an octave (HARD TECHNO's pads).

### v0.6.94
- **GEN: the snare a snare.** The generated kits' snare came out tonal (the FM oscillator's sweep over the noise):
  now mostly noise (NOISE +26..40 on both ends of the lane), shorter (DECAY −10..18), less pitch sweep, the noise's
  band a little brighter, and its own FEEDBK (3..6) on top of the factory LAYER. Every genre's kit, over the genre's
  offsets. **The hats** a band-pass high up (COLOR +10..18, the factory kit's high-pass replaced) with more noise in
  them (NOISE +18..28).

### v0.6.93
- **GEN opens on RANDOM** every time (a genre is that visit's choice), and the generator tuned against its own labels
  (every genre dumped as text and read: tempo, sounds, drums, bass, chords, arp, lead):
  - **ARP**: the amount is its density (20–95 % of the steps; under 35 % in eighths): no more sixteenths everywhere.
  - **Chords**: stabs and comping present at the genre's amounts (the comp figure varied a bar, an anticipation of 3
    or of the bar), POWER pushes every bar.
  - **Sounds**: a recipe's words tried in order (a reese is FAT BASS before SAW LEAD), its cutoff and resonance set as
    written (plucks were dull, square basses squelchy), no LOFI for leads, keys, strings or sine keys (chip sounds
    only where the genre asks: electro, micro house, IDM), the texture track quieter (the noise drone half).
  - **Drums**: ENERGY in the density and the velocities, the hats driven to sixteenths above 66 %, the open hats and
    percussion thinned under 34 %; hat rolls in TRAP, DUBSTEP and UK GARAGE; the disco cowbell softer.
  - **Lead**: SPARSE varied (a long note, or two short ones stepping into it, from the one or the third beat); the
    HOOK and McCARTNEY basses back in the bass's octave.
  - Harmonic minor out of TECHNO, ELECTRO, EBM, TRIBAL PUNK and DRUM & BASS.

### v0.6.92
- **A compact sequencer: 11 SEQ pages instead of 15, the same powers** (an audit of every parameter: what each does,
  what was twice, what did nothing). The order: STEP, PATTERN, NOTE, STRETCH, COMP, COMP 2, TRACK, PLAYHEADS,
  AUTOMATION, AUTO LIST, MUTATE.
- **EVERY** (COMP and COMP 2, KNOB 4): one setting a step saying on which loops of the pattern its components play:
  ALWAYS, 1:2, 2:2, 1:3, 2:3, 3:3, 1:4 … 4:4, 1:8, FIRST, !FIRST, SKIP. An arpeggio that comes in every fourth bar,
  an echo on the odd loops, a JUMP only the first time (it is JUMP / REV's TIMES too). It replaces the WHEN page (its
  A read as is; a step saved with a B other than ALWAYS reads as another EVERY: set it again) and the components' lane
  C.LEN.
- **ARP RATE in musical time** (COMP, KNOB 4): x1 (a note a step), 1/32, 1/32T, 1/64, 1/64T, 1/128 — the card says the
  note value for the track's DIV. KNOB 3 ORDER and range as one list (UP … RND over 1 … 4 OCT; SCALE 3 … 15 DEG).
- **TRACK** (it was SHIFT + HUMAN): PITCH, CHANCE, **HUMAN** and REC Q. HUMAN is one amount: each note's velocity
  (±50 at 100 %), start (up to 40 ms late), length (±40 %) and its envelope's DECAY and RELEASE (±20) vary a little
  every loop. Projects saved with VEL / TIME / GATE load with the smallest of the three. SHIFT's OFFSET is **ROTATE** on
  the STRETCH page (and the SCL layer's KNOB 3).
- **STRETCH and REPEAT act as the knob turns** (no OCT+), always from the sequence as it was before the first turn
  (x2 then x4 is x4; back to the middle: back to it); the message says LEN before > after; UNDO as ever. KNOB 3 NUDGE,
  KNOB 4 ROTATE.
- **NOTE** gained **MICRO** (KNOB 4; the TIMING page's OFFSET): the focused step's place off the grid by sixteenths.
  The TIMING page is gone; REC Q is on TRACK. The step's LEN is the TIE on STEP (the WHEN page's LEN is gone).
- **AUTOMATION** and **MUTATE** say what they are: a hint line on entering, MUTATE's page the selected track's next
  32 bars as one strip (SOUND / PATTERN marks, the playhead) and a line a knob.
- GEN writes HUMAN as the one amount. The tests (`tests/ratchet_test.c`, `tests/ui_test.c`) cover EVERY, RATE, the
  TRACK page, HUMAN's spread and STRETCH / REPEAT on the turn.

### v0.6.91
- **GEN: the song generator, rewritten, with a screen (HOME + SELECT).** Three pages: **GENRE** (43: HOUSE, DEEP
  HOUSE, MICRO HOUSE, TECH HOUSE, ACID HOUSE, TECHNO, DETROIT, DUB TECHNO, HARD TECHNO, HYPNOTIC, TRANCE, ELECTRO, EBM,
  ITALO, SYNTH POP, DARKWAVE, POST PUNK, TRIBAL PUNK, MINIMAL SYNTH, MAN MACHINE, MOTORIK, INDIE, SHOEGAZE, POST ROCK,
  FUNK, DISCO, BOOM BAP, TRAP, UK GARAGE, DUBSTEP, BREAKS, DRUM & BASS, DUB, STEPPERS, JAZZ, BOSSA, AFROBEAT, AMBIENT,
  NEO CLASSIC, IMPRESSION, SOUNDTRACK, IDM, BROKEN; or RANDOM), **SEED** (0000..9999), **ENERGY**, **FORM** (LOOP,
  PARTS: sections A B A C in ARRANGE, SONG: intro, build, drop, break); **DRUMS BASS CHORDS ARP** and **LEAD**
  amounts (OFF .. 100 %, AUTO the genre's); **COMPLEX**, **SWING** (AUTO the genre's), **HUMAN**. **OCT+** makes the
  piece; the same settings and OCT+ again throw a new seed; a knob turned and OCT+ re-make the same piece with that one
  part changed (each part draws from its own stream). **OCT−** closes; **UNDO** (GLO + G4) as before.
- How it writes: the **drums** from a map of priorities a genre (after Mutable Instruments' Grids: a hit where the
  level clears the density, ghosts first to go, the kick's anchors last; the snare's ghosts on the best positions, the
  hats' accent cell, a variation on the even bars, the genre's fill on the phrase's last bar — a roll, toms, the kick
  dropped, a hat roll, a linear fill — and the snare laid back where the genre plays late); the **bass** from ~50
  archetypes written against the kick (offbeat, bounce, deep walk, rolling sixteenths, Detroit, EBM, italo, psy, UKG,
  Jamerson, around the kick, on the one, slap, Good Times, walking, two-feel, boogie, country, ska, tumbao, bossa,
  rock eighths, punk sixteenths, McCartney, Hook, motorik, angular, indie, one drop, steppers, rockers, dub, boom bap,
  trap, DnB, jungle, wobble, pedal, fifths, Suicide, Kraftwerk, acid by the 303's rules), the root at every chord
  change, approaches by a semitone, the kick doubled, answered or interlocked; the **chords** from progressions with a
  quality a chord (sevenths, ninths, add9, sus2, sus4, sixths, fourths, power; a dominant's raised third in minor),
  voiced in C3..G5 and led to the nearest voicing (or moved in parallel), played held, stabbed, pulsed, dubbed,
  skanked, comped, broken or trance-gated; the **arp** an order over the voiced chord (up, up-down, Alberti, Glass,
  pulse, sequencer, walk, cycles of 3 and 5, a trance gate, octaves); the **lead** a one-bar motif (its onsets by the
  metre, its contour by the key's weights, leaps filled, chord tones on the strong steps) in a four-bar phrase
  (A A A A', A A' A A'', A R A R' ..) varied by one operator a bar, or an ostinato, long notes, a tintinnabuli line, a
  machine's figure, a two-bar call and answer; the **sounds** by recipe a role (sub, acid, Reese, FM bass, rock bass,
  Hook's chorused bass, pad, strings, choir, organ — WHEEL at last —, EP, stab, dub chord, pluck, bell, lead, vox,
  chip, keys, drone, noise, texture, hoover, wall, tremolo guitar), the **kit** a kit (909, 808, click, industrial,
  soft, dub, breaks), the **mix** by role, **HUMAN** and the snare's TIMING by how human the genre is, the reverb
  and the delay (type, ping-pong, time) the genre's. The lead keeps off minor seconds and tritones against the bass.
  With TRACKS 6 the sixth track is a texture (drone, noise, choir, organ). The old DICE ALL's genres are inside
  (DARKWAVE, POST PUNK, EBM, MAN MACHINE, HYPNOTIC, SOUNDTRACK, IDM, BROKEN ..).
- The tests: `tests/gen_test.c` measures every genre (one scale, the kick anchored, the bass's roots at the changes,
  the lead's chord tones, every piece storable, the forms); `web/emu/gen_bench.mjs` renders every genre to WAV from
  the browser build.

### v0.6.90
- **DLY 3 > TYPE: ANALOG or DIGITAL.** ANALOG is the delay as it was (soft saturation, resonant TONE, past 100 % it
  self-oscillates); DIGITAL repeats clean, TONE a plain filter, FEEDBK 100 % at most (past it the repeats hold, never
  grow).
- **DLY 3 > PING: ping-pong.** The repeats go left, right, left … across the stereo field, each FEEDBK softer (one delay
  line read twice: no extra memory; TIME up to 0.74 s).
- **SEQ pages in a sensible order**: the piano roll (STEP) and the pages that edit it come one after another, NOTE,
  TIMING, STRETCH, COMP, COMP 2, WHEN; then the track's, PATTERN, SHIFT, HUMAN, PLAYHEADS, AUTOMATION ...
- DICE ALL: an accent left on a drum lane without its hit (it was never heard, but undo / redo lost it) no more.

### v0.6.89
- **The delay, fixed and cleaner.** Long FEEDBK tails were cut off abruptly after a few seconds: the effects' noise
  gate, meant for the reverbs' residue, took them for silence; now a delay tail is never gated while it is heard. With
  **TONE in the middle** each repeat is a copy of what went in (no fixed darkening any more; a DC block at 1 Hz only),
  and at **FEEDBK 100 %** the echoes hold for a long time (about −0.2 dB a second). **TONE at either end** with high
  FEEDBK self-oscillates at its band. The loop's saturation is exact up to half scale (it colored every repeat a
  little). **MOD** reads the line with 4-point Hermite interpolation (as DaisySP's delay line), so drifting repeats
  stay bright; its default is now 0.
- README: new images (TIMING, HUMAN, STRETCH, CHORD, the delay) and what's new on top.

### v0.6.88
- **Record off the grid.** SEQ > TIMING's **REC Q** (per track): at 100 % (the default) live recording snaps to the
  grid as always; lower, each step keeps where you played it, up to half a step early or late (in sixteenths of a
  step), and plays it back there. 50 % keeps half of it, 0 % all of it.
- **SEQ > TIMING** (after NOTE): KNOB 1 the step, KNOB 2 its **OFFSET** (−8/16 … +7/16: early / late; EDIT puts it
  back on the grid), KNOB 3 REC Q. The piano roll draws each note where it plays. Early notes really play early (the
  step before ends that much sooner, the grid kept); a moved, stretched or repeated step keeps its offset; stored with
  the project, no extra memory.

### v0.6.87
- **SEQ > HUMAN**: the sequencer plays like a person, each note a little different every time round (the steps
  stay as written). **VEL** varies each note's velocity (up to ±38 at 100 %), **TIME** starts it a little late (up to
  30 ms, never early; a chord stays together), **GATE** varies its length (up to ±40 %). 0 % (the default, and every
  project before) plays exactly as written. Per track, kept when you change the sound, automatable.

### v0.6.86
- **The delay feeds back like an analog one** (a tape, a PT2399). Its FEEDBK reached only 84 % and the loop clipped
  hard, so the echoes always died within a couple of seconds. Now each repeat gets a little darker and thinner and
  wobbles slightly (wow and flutter); around **100 %** the echoes hang on for many seconds, and **past 100 %** they
  grow into themselves and hold, saturating softly (turn it down to let them go). Up to 80 % it sounds as before; the
  screen shows FEEDBK as 0–120 % (100 % = the loop's gain 1).
- **DLY 2 > MOD**: the delay's tape drift (slow wow, fast flutter) on the repeats, as the reverb has its MOD: 0 none,
  20 the default, up to a seasick chorus. Saved with the project.
- **Resonant TONE (delay) and FILT (reverb)**: one way a low-pass sweeping down, the other a low cut sweeping up, both
  with a peak at the cutoff, like a band-pass: carve where the repeats and the room sit. The delay's repeats narrow
  to that band pass after pass. All this costs about 2 % more audio CPU.

### v0.6.85
- **SEQ > STRETCH**, a new page after NOTE, to reshape a whole sequence (pick with a knob, OCT+ does it, UNDO
  brings it back):
  - **STRETCH x2 … x8 or /2 … /8**: the steps spread that many times apart (held notes held, short ones short) or
    squeezed together; automation and locks move with their steps.
  - **REPEAT x2 … x8 or TO 64**: clone a pattern of any length after itself, e.g. four notes into a 64-step bed for an
    arpeggio to record more notes over.
  - **NUDGE**: the whole sequence a step left or right at once (one note or chord: NOTE > MOVE, as before).

### v0.6.84
- **CHORD records whole in step recording too.** Armed and stopped on STEP, a key now writes the chord it plays (it
  wrote its note alone); live recording already did.
- **STRUM records cleanly.** A strummed chord went into the grid note by note, its later notes falling into the next
  step, irregular and ugly. Now the chord goes whole into the step where the key went down, and the sequencer strums
  every chord step back as you played it, low to high (STRUM 0: all at once, as before).
- **The keys show every note sounding**, a chord's whole shape included (CHORD, LATCH, a chord gliding, MIDI): see
  the chords as you play them, and learn them.
- **SAVE > TOOLS > 6 CPU TEST**: builds a heavy test song (chords of four, two step components a step, long glides,
  the kit on every lane, every FX, 160 BPM) to measure the CPU on the device and listen for clicks; UNDO brings your
  music back.
- **CPU watched on Linux too**: the tests count the audio path's instructions under valgrind (every engine, every
  reverb, a full mix, the sequencer at its heaviest, the CPU TEST song) and fail on +8 %; the Mac-only reverb check
  follows what the FM-1's own code measures.

### v0.6.83
- **Long, smooth chord slides.** The glide into a chord now lasts as long as that chord, its TIEs included (GLIDE: how
  much of it). Hold a chord over TIEs on slow steps and it slides for seconds (DIV 1/4 at 120 BPM, ten steps: 5 s),
  smoothly: the pitch moves in fractions of a step, and a new note fades in as it glides (it rises from the nearest
  other note, never from its own pitch).
- **Step components on drums.** OCT, RAND and TONAL tune the hits, BEND bends each one over the step; ARP NOTES plays
  the step's sounds one after another, ARP SEQ the pattern's in the order they play, ARP SCALE retriggers the step's
  hits a degree further up each part.

### v0.6.82
- **Two step components on one step, and WHEN for every one (SEQ > COMP, COMP 2, WHEN).** COMP 2 gives a step a
  second component; both play (an ECHO with an OCT: the repeats an octave up). One that keeps the note silent wins: a
  TRIG or FILL in either place decides first whether the step plays. WHEN sets the loops each plays on: ALWAYS, 1:2,
  2:2 or SKIP (kept but off).
- **Division and duration**: RATCH and ECHO get a **DIV** (the step shared out, or the hits 1/2 … 1/8 of a step
  apart), ECHO goes up to x8, and a step's **LEN** sets each note's (or each RATCH / ECHO / ARP part's) gate on its
  own. ARP SEQ now plays the pattern's melody in its order (it was sorted like NOTES).
- **Chord glide**: a POLY chord with SLD glides into the next one, each note to its partner; with **GLIDE** up on a
  POLY track every chord glides by itself. Three into four: the new note fades in from the nearest; four into three:
  the extra one glides on and fades out. It follows the voices actually sounding.
- **Piano roll: SEQ > NOTE** focuses one note of a chord: PITCH moves it, MOVE moves it (or the whole step) along
  the steps, LEN stretches it, EDIT deletes it; holding a step shows how far its length reaches.
- **SEQ pages in a new order**: STEP, PATTERN, SHIFT, **PLAYHEADS** (was FUGUE), then NOTE, COMP, COMP 2, WHEN,
  AUTOMATION, AUTO LIST, MUTATE.
- **Fixes**: ANALOG MORPH sounds on every wave (SIN round to saw, PWM's width, SYNC / RING's ratio, SAW3's spread);
  every LFO and ENV destination is heard on every engine; SCL TRANS moves the sequence too; FM6's ENV page (SUS did
  nothing) moves the carriers' envelopes; AUTO PAN named on its page and the SLICER before MASTER in FX.

### v0.6.81
- **CHORD is back, light (SCL > CHORD; after the Omnichord and the Orchid).** A key plays a chord: in the scale
  (TRIAD 7TH ADD9 SUS2 SUS4, always in key) or a shape on any key (MAJ MIN 7 MAJ7 MIN7 POWER); VOICING CLOSE, **LEAD**
  (each chord the inversion nearest the last: voice leading), OPEN, +BASS; **STRUM** the notes in one by one, low to
  high, as a harp. It records into the step and feeds the ARP. Old projects: OFF.
- **DICE ALL learned from records.** Post punk measured on Joy Division and Bauhaus: the kick on every beat, the hat on
  the offbeat eighths, the bass repeating each note two to four eighths, one or two chords over four bars, major too,
  open filters. **GOTHIC** slower and on one chord; a new genre, **DARKWAVE** (Boy Harsher: four on the floor, a low
  bass hammering its root). And **EBM, GOTHIC, BREAKBEAT, IMPRESSION**; songs of two to four parts sequenced in
  ARRANGE (PLAY plays the song); sevenths, ninths and suspended chords, ambient arps; leads always moving (filter
  envelope, LFO, auto pan or chorus); a short cowbell, a low or middle kick; the master glued (DUCK, CLIP, PUNCH).
- **No more clicks turning things** (found sweeping every parameter over a held chord): the delay's TIME, WIDE and
  PITCH crossfade instead of jumping; the chorus DEPTH, its width and the delay MIX glide; the filter TYPE fades
  (into and out of the COMB too); the COMB no longer crackles on a loud part (an overflow); FM6's ALG and PHASE's FB
  smooth.
- **DRUM-X IMAGE**: no clicks turning it, no bitcrusher-like grit through the kit's filter.
- **ARRANGE survives power-off** (the power-on reset it, then saved the empty rows over it).
- **The palette**: settings from Felucca (often GREY or MONO, a black and white screen) are set to JIANT once at the
  first power-on; a palette picked after that stays.

### v0.6.80
- **DICE ALL (HOME + SELECT): less cheesy, closer to the wave.** The generator wrote textbook pieces: a lead phrased
  like a nursery tune (a motif, its sequence, a cadence held on the tonic), every chord four lush notes, the arps up
  and down. Now:
  - **Four new genres** after Joy Division, Suicide, New Order and Kraftwerk, two throws in five: **POST PUNK** (the
    bass singing the tune high, power chords, a tight kit with sixteenths on the hat), **SYNTH POP** (a melodic bass,
    a sequencer, four on the floor and a handclap, Blue Monday's sixteenth kicks at the loop's end), **MINIMAL SYNTH**
    (a rockabilly bass ostinato over one organ chord held through, a cheap rhythm box) and **MAN MACHINE** (a
    sequencer bass, root, octave, fifth; a machine's tune repeated exactly, the same strength every note; a dry
    machine kit with its metal). They take the places of COLD WAVE, INDIE POP and ELECTRO PUNK. Their chords are one
    or two, never the scale's diminished one.
  - **Every genre:** the lead repeats its motif (A A A A', the last note moved or left out) instead of ending on the
    tonic; its strong notes a chord tone three times in five, a ninth or an eleventh the others; repeated notes in its
    contour. Chords may be power chords (root, fifth, octave) or triads.
  - **A fix:** the arps built their chords a scale step above the harmony (against the bass); now on it.
  - `tools/dice_render.c` writes thrown pieces as WAV files, to judge the generator by ear.
- **MIDI: sections and projects by PROGRAM CHANGE on channel 16** (the song's channel: it never loads a sound there).
  Programs 0–3 jump to section A–D (playing: on the next bar, as the song layer's keys; stopped: at once), 16–23 load
  project 1–8 (stopped only). A foot controller or a DAW can run a set. A test sends them.
- **MIXER: the six columns with every COLOR and STYLE** (they showed only with COLOR JIANT FM and STYLE FLAT; any other
  showed Felucca's four). MENU > LARGE still shows four, bigger.

### v0.6.79
- **Credits:** praztalfractal ([GitHub: gospodindilly-ops](https://github.com/gospodindilly-ops)), who tests JIANT
  on a real FM-1 and brings the CPU ideas (the effects' guard, the code in RAM), joins the credits: MENU > ABOUT and
  [Credits](#credits). Welcome!

### v0.6.78
- **Experimental: the hottest sound code runs from RAM** (another idea from a tester, after Melodee). The firmware runs
  from the flash through a cache; between two audio blocks the screen and the keys fill that cache with their own
  code, and the next block has to fetch its code from the slow flash again: likely one source of the load peaks
  (LATE, SHED in ABOUT). Now 18 KB of it is copied to RAM at power-on and runs from there: the mix and the master, the
  FX layer, the SLICER, and the first core's copies of a track's mix and the effect buses. The second core keeps the
  flash copies (it now and then misreads RAM on some units). The code itself is the same as before (only its place
  changed), so the sound is identical; whether the peaks go down can only be measured on a real FM-1: compare PEAK,
  LATE and SHED in MENU > ABOUT with 0.6.77 on the same song. If it does not help, it goes.

### v0.6.77
- **FM6: the operator graphs follow the knobs again.** On EDIT > OP ENV the envelope's curve did not move while you
  turned RATE or LEVEL (nor when you changed the stage or the operator), and OPERATOR's chart missed its edits too:
  the screen redraws a graph only when something it shows changed, and on these pages the patch was not on that list.
  It is now, with a test that turns each knob and checks the graph redraws.

### v0.6.76
- **The effects guarded on the second core** (a tester's idea, thanks!). On some FM-1s the second core now and then
  reads a word of memory wrong; the check word guards the hand-over of each job, not the numbers the job reads. With
  the effects there since 0.6.75, a test now feeds every value of their state a wrong word (on all five reverbs):
  their lines are 16-bit and clamped, so nothing can grow through the feedback, at worst a short burst the master's
  limiter holds. Two guards came out of it: ROOM's modulation, given a wrong offset, now puts it back instead of
  reading far outside its buffers; and if the effects' output ever goes far out of range (as the known wrong read
  would make it), that block is muted, every delay and reverb line is cleared, and the second core is stopped as a
  BAD READ (one core until switched off). USB console `status`: `fx_trips`.

### v0.6.75
- **The effects on the second core.** The chorus, delay and reverb buses ran on the first core after both cores had
  rendered their tracks: a fixed piece of every block the second core could not help with (up to a quarter of the
  work, more with a heavy reverb). Now they run on the second core while the first renders its tracks, on the sends
  of the block before, so the wet signal comes 0.7 ms later than the dry one, too little to hear. With one core they
  run at the same point, so the sound is the same either way (the test still checks it bit for bit). In the
  simulation of a heavy six-track song the mean load falls from 77 % to 63 % of one core, and the peaks (the ones that
  make the LATE and SHED counts in ABOUT) are now about 18 % lower than on one core (before, they barely moved).

### v0.6.74
- **Fewer clicks.** When the FM-1 has to let a voice go (all 8 voices busy and a new note comes, or the load guard
  freeing time), it cut it in 0.7 ms: on a loud note, a bass note most, that is a click, and it happened a few times a
  second in a busy song. Now the voice fades out over ~4.4 ms along a half cosine (gentle in and out): measured on a
  55 Hz bass, the click is about 7 times smaller. A new test keeps it so. The voices fading do not count in the
  budget, so the new note never waits.

### v0.6.73
- **Both cores, better shared** (after the first tests on a real unit: mean load 54 %, but a few blocks near the limit,
  a click now and then): each track's render is now **timed** as it plays, and the tracks are split between the cores
  by what they really take (it was an estimate from their voices and engines). The **drums can go to the second core
  too** (all the DRUM tracks together, on one core or the other): they were always on the first, often the heaviest
  part of a song, which left the cores uneven.
- USB console `status`: `cpu2`, `cpu2_jobs`, `cpu2_tracks`, `cpu2_wait_max_us` (0.6.72), to see the second core at work.

### v0.6.72
- **MIDI OUT** (MENU > CONTROL > MIDI OUT, over USB): **KEYS** (as before), **CLOCK** (and the clock with START / STOP
  while the tempo is the FM-1's own: drum machines and DAWs follow it), **ALL** (and every note the FM-1 plays: the
  sequencer, the arp, FUGUE, the punch-in repeats with OCT and RANDOM, each track on its channel, every note ended),
  **OFF**.
- **PROGRAM CHANGE**: program *n* on a track's channel loads the PRESETS list's sound *n* + 1 into that track.
  (0.6.80) On **channel 16**, the song's: 0–3 jump to section A–D (on the next bar), 16–23 load project 1–8.
- MIDI check: USB / TRS MIDI IN, clock, Start / Continue / Stop and the punch-ins verified by the tests. MIDI OUT on the
  TRS jack is not possible (the jack is an input only) and neither is Bluetooth MIDI (it needs JieLi's closed SDK).

### v0.6.71
- **Both cores** (experimental, [details](#both-cores-dual-core)): the FM-1's chip has two cores and JIANT used one. Now, while the first renders its
  tracks, the second renders some synth tracks of its own (the drums stay on the first), whichever has less to do;
  the sound is bit for bit the one core's (a test checks it). The way to start it safely and the guard for units that
  cannot run it come from Melodee (keremimo) and fm1-x0x (Charles Vestal), GPL-3.0: if the second core reads a wrong
  job, faults or does not answer, it is stopped and the first plays every track again, no crash; such a unit stays on
  one core until switched off. **MENU > ABOUT** says CORES 2 or CORES 1 and why. Hold **REC** while powering on for
  one core that session.

### v0.6.70
- **LOAD ECO really lighter** (4 tracks with reverb and delay still crackled on ECO): the SPRING every reverb becomes
  on ECO was heavier than a plain ROOM; on ECO it now runs a shorter chain (4 stages instead of 10, a third of the
  reverb's cost gone). The voices all tracks share drop from **8 to 6** on ECO, and the load budget steps in sooner
  (at half the time instead of 65 %), taking only tails that are nearly silent: the peaks when every track hits at
  once no longer reach the point where the sound breaks.

### v0.6.69
- **SELECT scrolls inside the section**: alone it goes through the pages of the section you are in (EDIT's on an EDIT
  page, FX's on an FX page …), stopping at its first and last page; on HOME it opens DICE EVERYTHING? as before. The button combos stay:
  HOME / EDIT / SEQ / LFO / FX + SELECT their dice, GLO + SELECT the tempo.
- **The presentation film**: a new one for this version (tools/video/capture_promo.c, promo.html): dark hypnotic
  techno by the real engines, the screen floating in a living membrane, annotated like a specimen, and the list of all
  that is new.

### v0.6.68
- **Fix: a cleared sequence came back by itself.** With MUTATE PATTERN on, clearing a track while it played let the
  old melody return a few bars later (ORBIT mutated around the anchor taken before the clear), and DRIFT could add drum
  hits to an empty kit. Now the anchor follows the steps you write or clear, and MUTATE never fills an empty pattern.

### v0.6.67
- **SELECT scrolls the pages**: turn it alone and it goes through every page, one a detent, in the panel's order (HOME,
  EDIT, ENV, LFO, FX, SCL, ARP, SEQ, GLO, SAVE), the page's name shown below for a moment.
- **A button held + SELECT is its dice**, heard at once under **KEEP?** (OK keeps, CANCEL puts back what was there):
  **HOME** everything (DICE EVERYTHING?), **EDIT** the sound, **SEQ** a new sequence for the track (as DICE ALL writes
  a part, in its scale), **LFO** the track's LFO, **FX** its effects and the shared reverb and delay. **GLO + SELECT**
  is the tempo; ENV, SCL, ARP, SAVE + SELECT (and any button + PRESETS) jump through their pages. The macros' dice is F3.

### v0.6.66
- **Pages with SELECT**: hold a page button and turn **SELECT** to go through its pages (PRESETS still works too).
  While it pages, SELECT dices nothing, nor in the moment after you let go. GLO + SELECT stays the tempo; with LFO
  held, F3 rolls the macros.

### v0.6.65
- **Sound dice with OK / CANCEL**: EDIT + SELECT rolls the sound and you hear it at once under **KEEP DICED SOUND?**
  (DRUM: KEEP DICED KIT?). Turn SELECT again for another roll; **OCT+ OK** keeps it, **OCT− CANCEL** brings back
  the sound you had, only that track's, with the music playing on. No more sounds lost by accident.

### v0.6.64
- **FX held opens the punch-in FX and stays**: hold FX until its map opens and let go: the FX screen stays open, both
  hands free, until you press FX again. The effects are **momentary** again by default (a key plays its effect while
  held); MENU > CONTROL > FX LATCH ON makes them toggle, as in 0.6.44–0.6.63.
- **Page name at the bottom**: the page's name now shows for a moment over the footer (which says the same), so the
  header, the cards and the graph stay in sight.
- **Granules for free**: the drifting dots behind the panels move only when the panel redraws anyway (a knob, the LFO,
  the envelope); they no longer redraw the panel on their own.

### v0.6.63
- **A safer installer**: before writing, it checks the FM-1's firmware by itself (no tick box any more): official V15
  or JIANT, it installs; Felucca, baudgirl or anything else, it writes nothing and sends you to **Return to official
  V15 first** (going straight from another custom firmware has bricked an FM-1). JIANT now tags itself in the editor's
  INFO for it; older JIANT versions are recognised by their six tracks.

### v0.6.62
- **Step components with TIMES**: JUMP and REV get KNOB 4, **TIMES**: ALWAYS (as before), **x1** (once a pass, then
  the pattern plays on past it: a section twice, then the rest), **x2**, **1:2** (once, every other pass). A jump back
  no longer has to shorten the sequence. Old projects play as before (ALWAYS).

### v0.6.61
- **The page name in the header**, not over the parameters or the graph: for 0.9 s the header shows the page (and the
  track and engine at the right); on HOME a track change shows its engine, with "HOME" small.
- **Granules in the panels**: a few dots drift behind the graphs, as on HOME (LOAD FULL with ANIM ON; not on the lists
  and the step grids).

### v0.6.60
- **All black**: cards, panels, menu rows and dialogs are their text, graphs and beings on black, with no box drawn
  (the chosen row and the buttons keep their fill).

### v0.6.58
- **Page name over the cards, shorter**: the big name now covers the four cards for 0.45 s (was the graph for 0.7 s), on
  one line with the track and engine at the right; the graph stays in sight.
- **INIT SYSTEM in the MENU** (SYSTEM tab): everything back to zero for a new song, after OCT+ asks (as SAVE > TOOLS >
  NEW PROJECT; UNDO brings the music back).
- **FX LATCH on in the browser emulator too** (the punch-in FX latch was ON on the device only).
- **DRUM-X pages: the kit, a sound, then the volumes and the stereo**: KIT, KIT 2, KIT 3 (BP, FEEDBK), X-MOD, FILTER;
  SOUND 1–4; LEVELS, LEVELS 2 and **STEREO** (IMAGE, moved from KIT 3).

### v0.6.57
- **LOAD LITE / ECO also lighten the screen**: the beings, the scope and the animated graphs redraw at most every 50 ms
  (LITE, ~20 frames a second) or 70 ms (ECO, ~14), the beings' outlines with fewer points (LITE about half the lines,
  ECO a third), and values snap instead of rolling. The main loop keeps that time for the keys, the knobs and the LCD.
  A new page or track still draws at once; FULL is unchanged.

### v0.6.56
- **The landing's typography and windows** (the JIANT palette; the beings, DRUM-X and the colours stay as they are):
  values in **IBM Plex Mono**, page names and big numbers in **Michroma**, labels still in Chakra Petch. Cards, panels,
  rows, tabs and buttons are square with four **HUD corners**; the page banner is the landing's tag (a dark window,
  orange corners, the name in Michroma, the track under it). The fonts take 4 KB less flash than before; no CPU cost.

### v0.6.55
- **ALGORITHM only offers the tracks that play**: with TRACKS 4 it stops at T4, T5 and T6 no longer show up (they were
  asleep and confusing). TRACKS 6 brings them back; going back to 4 while on T5 / T6 selects T4.

### v0.6.54
- **DRUM-X pages in order**: first the whole kit, then one sound. **KIT** (EDIT 1), **KIT 2** (EDIT 2), **KIT 3** (TONE's
  BP and the kit's FEEDBK, with IMAGE), X-MOD, FILTER, **LEVELS**; then **SOUND 1–4**, KNOB 1 always the sound: SOUND
  (SIDE PITCH PMOD), SOUND 2 (DECAY NOISE COLOR), SOUND 3 (MODE PM.TYPE DRIVE), SOUND 4 (LAYER FEEDBK SEND, the bus and
  amount on one knob). 14 pages became 12; the TONE, LAYER, SEND and IMAGE pages are folded in, SOUND 3's WAVE (MODE
  has it) is gone.

### v0.6.53
- **Memory check.** Flash 392 KB of 568 KB; RAM 80 KB of 96 KB; the big-buffer pool 325 KB of 336 KB. The pool was the
  tight one (3.9 KB usable over its 8 KB reserve): the DRUM-X hits' state and the FM6 user-voice buffer moved to the
  ordinary RAM, so the pool has 11 KB to spare and the RAM 16 KB. No sound or behaviour changed.

### v0.6.52
- **FUGUE** (SEQ > FUGUE), after the Fugue Machine: three more playheads on every track, each with its RATE (1/4 .. x4),
  DIRECTION (FWD, REV, PING, RND) and INTERVAL in the scale (-14 .. +14 degrees), reading the same steps: canons,
  counterpoint, a pattern phasing against itself. Saved with the section. Cost: a few operations a block a head; RAM
  +0.4 KB.

### v0.6.51
- **LFO in time and free-running** (asked on YouTube): RATE turned left past the slowest goes in time with the tempo
  (4BAR … 1/32, triplets and a dotted eighth), locked to the bar while playing; PHASE turned left past 0 is **FREE**:
  the LFO never restarts with a note. The mod matrix moves RATE within its kind (free or in time).
- **The page's name, big**: changing page or track by hand shows the page's name in the middle for 0.7 s, with the track
  and its engine, so the pages need no memorising.
- **The power-on signature** stays a little longer (written in 0.8 s, held 0.9 s).

### v0.6.50
- **Fix: MORPH clicked when turned** (ANALOG, PHASE, LOFI). It moved in steps once a block; now it is slewed and ramped
  sample by sample across each block, including in and out of 0.

### v0.6.49
- **DRUM-X LAYER** (EDIT > LAYER, each sound): a second, out-of-tune oscillator frequency-modulated by the sound, from a
  metal edge to a clang with no note, so drums melt into the rhythm and stop fighting the harmony. **FEEDBK** per sound
  on the same page (on top of TONE's, the kit's). Saved with the kit; the dice (SELECT, DICE ALL) set both boldly.
- **Cowbell tamed**: the factory one shorter, noisier, with a LAYER, and the cowbell 4 dB under the other sounds in
  every kit (it stuck out). The factory snare and hats get a LAYER too.
- **Power-on is a clean INIT**: every track its engine's own defaults (not its first preset), every effect send at 0,
  FM6 the init voice; INIT SOUND and NEW PROJECT the same. (The power-on still loaded the presets with their sends.)
- Cost: a sound with a LAYER costs about what FEEDBK does; the factory kit with all 8 sounds ringing at once +13 % on the
  drum voices (host), nothing on sounds without one. RAM: +200 B of pool, +16 B. Older projects keep their kit as it was (no LAYER).

### v0.6.48
- **DRUM-X IMAGE** (EDIT > IMAGE on a DRUM track, one knob, automatable): sweeps the kit through its stereo placings
  (each sound on its own curve), so you turn it until the image sits right. 0 = all in the middle, as before. The kick
  stays near the middle; with DRV, DIST or the FILTER the image narrows (they work on the kit's sum).
- **DRUM-X SEND** (EDIT > SEND): each sound its own send to CHORUS, DELAY or REVERB and an AMOUNT, so one hit goes to an
  effect without the whole kit. Saved with the section's kit.
- Cost, measured: about +3 % of the mix with IMAGE on and every sound sending (host); nothing when IMAGE is 0 and no
  SEND is set. RAM +1.3 KB, no pool.

### v0.6.47
- **C.LEN** (SEQ > SHIFT, KNOB 4): the step components get a length of their own. OFF: each step its own component, as
  before. 1–64: the components of steps 1..C.LEN are read in turn as the track plays, so over a pattern of another
  length they drift across the notes (polymeter, as the OP-Z's). The COMP page marks the lane and where it is.
  Automatable. Costs nothing on the audio: a copy of the step once per step.

### v0.6.46
Feedback from users (YouTube, Reddit):
- **INIT SOUND is dry**: every effect send (DIST, CHORUS, DELAY, REVERB) at 0, so the effects are yours to add. On
  **FM6** INIT is the init voice (OP1 alone at full level, the rates at 99: a plain sine) instead of a factory patch.
- **NEW PROJECT** (it was INIT SYSTEM: SAVE > TOOLS, 5th row): a clean start, every track its engine's sound, dry, FM6
  the init voice, no steps or automation.
- **NOISE DUST** never silent: at DENS 0 it still crackles softly (DUST is only the crackle).
- **FM6 EDIT 1**: the chart says the algorithm's number also when ALG follows the patch ("ALG 05 PAT").
- **Web installer**: pick an earlier version to go back to (the last few stay there), and links to the manual
  (English, Español).

### v0.6.45
- **MORPH** (EDIT > MORPH) on ANALOG, PHASE and LOFI: the wave slides continuously into the next ones; on ANALOG and
  LOFI the SHAPE modulation sweeps it too. The page draws the morphed cycle.
- **Fix (reported on Reddit): "the sequence pitch drops by itself"**. It was SCL 2's STRN, a global transpose of
  every sequence that is easy to turn by mistake next to ROOT. Renamed **ALL TR**; when it is not 0 the piano roll
  shows an **ALL TR** badge and PLAY warns. 0 = off.

### v0.6.44
- **Punch-in FX latched by default** (asked by many): **FX LATCH** is now ON (turned on once for everyone; turn it OFF
  in MENU > CONTROL if you prefer holding). **Lock**: hold FX until its map opens and let go without touching
  anything: the FX layer stays open (**[FX] LOCKED**), as the macros latch with LFO; keys toggle effects, knobs are
  FX's macros, OCT− all off. Press FX again to unlock.

### v0.6.43
- **MUTATE** (SEQ > MUTATE, a suggestion from the community): each track's **SOUND** and **PATTERN** change by
  themselves every 1 to 32 bars, on the bar, in time with the clock; **AMOUNT** how much; **ORBIT** varies around an
  anchor (KEEP: OCT+ on the page) so the music stays itself for minutes, **DRIFT** wanders on. Never LEVEL, PAN or
  MUTE, never the kick. **FREEZE** (OCT− on the page, or GLO + A4) stops it all. The page draws the next 32 bars of
  every track; on HOME each being gets a ring filling up to its next change.

### v0.6.42
- **Step components, the second set** (SEQ > COMP): **RAND** (the note at random in the scale), **OCT** (an octave,
  every loop or every other one, by turns, at random), **TONAL** (the rest of the loop moved along the scale),
  **BEND** (the note glides over the step), **ECHO** (repeats, each softer), **PULSE** (again on the empty steps
  after it), **JUMP** (then another step), **REV** (back to step 1: ping-pong), **FILL** (only while FX is held) and
  **KILL** (cuts what the track sounds). Each with its picture on the page.

### v0.6.41
- **Smooth engine and waveform changes**: another engine fades the old one out (~12 ms) and what is held (keys, the
  sequencer's notes) goes on in the new engine, fading in, instead of being cut. A list value changed while notes
  sound (WAVE, CHIP, a type) dips for ~3 ms instead of clicking; the notes go on.

### v0.6.40
- **INIT SYSTEM** (SAVE > TOOLS, 5th row, with a dialog; UNDO brings the music back): everything to zero at once:
  every track its engine's default sound, no steps, automation or locks, the mix, effects, tempo and SLICER at their
  defaults, the song empty, macros at 0, the factory DRUM-X kit. Saved projects, user presets, MENU, CLOCK, TUNE and
  MIDI stay.
- **Power-on at zero**: the device starts as INIT SYSTEM leaves it. **RESTORE LAST** (MENU > SYSTEM) is now **OFF** by
  default; turn it ON to get the last session back at power-on (if you had set it OFF before, it reads ON once: set
  it again).

### v0.6.39
- **Step components** (OP-Z style), on a new page **SEQ > COMP** right after STEP: one per step, picked with KNOB 2.
  **ARP NOTES / SEQ / SCALE** turn a step into an arpeggio (its own notes, every note of the pattern, or the scale up
  from it; UP, DOWN, UP-DN, RND; x2 to x8 in the step; 1 to 4 octaves or 3 to 15 degrees) that goes on over the ties
  after it. **TRIG** plays a step only on some loops (1:2 .. 4:4, 1:8, FIRST, NOT FIRST). The step's own **CHANCE**
  and **RATCH** are back here too. The page draws the arpeggio's ladder (the note playing lit) and TRIG's loops.

### v0.6.38
- **Step recording, chords with a length and arpeggios**: on STEP with REC (stopped), hold a note or a chord and turn
  **KNOB 1**: it lasts that many steps, written when you let go. Press **ARP** while holding it: the chord goes into
  the roll as an arpeggio, KNOB 1 its resolution (1/16 .. 1/4), KNOB 2 the order (UP, DOWN, UP-DN, RND), KNOB 3 the
  octaves.
- **DICE ALL**: the lead never goes past G5 on any of its paths (a FRANTIC cell could reach C#6).

### v0.6.37
- **SEQ pages, lighter**: PHRASES and the step CHANCE page are out of the cycle; **SHIFT** is now the last SEQ page
  and has a third knob, **CHANCE**: the whole track's probability (100 % plays every step as written, lower thins it
  out), automatable like OFFSET and PITCH. Old projects and presets keep playing as they were.
- **Films**: the presentation video in the landing page's look, with a dark minimal techno track (low FM chords, acid,
  a cyber line).

### v0.6.36
- **DRUM-X: FM becomes FM ENV.** The old FM knob put a fixed FM over every hit and muddied the kit (the macros' dice
  liked it a lot). **FM ENV** strikes the FM with each hit and lets it go with the pitch envelope (a few ms): a beater,
  a click, a metal edge on the attack, the tail as the kit has it. Projects keep the value; its effect is the new one.
- **DRUM-X: EDIT > TONE**, a new page after X-MOD: **BP**, a band-pass on the hats, the rim and the cowbell (OFF or 15
  centres, about 1.5 to 9 kHz), and **FEEDBK**, every sound's oscillator fed back into itself (warm to growl to noise).
  Saved with the section's kit in a byte it already reserved: older projects open with both OFF, sections no bigger.
- **Films**: the features film's music is new and darker (E harmonic minor, Em(add9) Cmaj7 Am7 B7, a rolling sub, a
  low arp, the robot low and spaced) and the camera cuts to HOME's beings every two bars of a long scene; the DICE ALL
  film shows HOME's beings instead of the mixer.

### v0.6.35
- **DICE ALL: the drums as before, darker.** The chords, the variety and the guard rails of 0.6.34 stay; the drums go
  back to 0.6.33's, which sounded better: the DRUM-X kit rolled around the factory one through a soft low-pass, the
  patterns written whole (the energy no longer thins or fills them), and in the night's genres they almost always play.
  The night's genres come up four throws in five (IDM and DARK IDM still the most).
- **Two new films**: the DICE ALL film (one minute: a throw every few seconds, an animated die rolling between them,
  no names) and the features film updated; thumbnails for both (`tools/video/thumbnails.py`).

### v0.6.34
- **DICE ALL: a generator of pieces, not of conditions.** Each throw makes three choices and guard rails keep it
  musical inside the chaos (see the manual, chapter 8):
  - **A genre**: the dark ones, plus five new worlds: **SOUNDTRACK** (enveloping pads, no drums or a heartbeat),
    **HARD TECHNO**, **INDIE POP**, **ELECTRO PUNK** and **NEO CLASSICAL** (Reich's pulses and phases, Glass's additive
    arps, Pärt's tintinnabuli).
  - **An energy**: **SPACE** (two or three things, long tails: minimalism with cared-for timbres), MID, **FRANTIC**.
  - **An orchestration**: which roles play; **the drums may not play at all** (about a third of the throws).
  - Guard rails: **chords always of four notes**, **deep basses** (from E1), **arps in the middle octaves** (C3–C5:
    Alberti, Glass groups, a Reich pulse, a walk), **coherent melodies** (a motif in steps developed over four bars,
    ending on a cadence), **space between notes**, **high notes softer** and high parts quieter, the lead under G5.
  - **Seven drum kits** built on DRUM-X: 808, HARD, CLICK, INDUS, SOFT, GLITCH, ELECTRO.
  - Sounds always fit their role (never a bass sound off the bass); envelopes shaped for the role and the energy.
  - **A twist** in one throw in five: two loops phasing, a comb, the grain delay down, a polymetric lead, a drone.

### v0.6.33
- **DICE ALL: more IDM, darker, never flat.** IDM and a new **DARK IDM** (slow, phrygian, a drone, in-scale fourths,
  a few long notes) come up about 4 throws in 10; IDM's scales and progressions darker (PHRY, HARM; the flat second).
  - **A filter envelope on every sound** (strongest on the bass and the arps, their envelope made a pluck), so each
    note opens and closes instead of sitting still.
  - **The filter TYPE changes**: LP mostly, BP on chords, arps and textures, the COMB tuned to the note on arps and
    textures; a slow LFO of its own shape (SIN, TRI, S&H for the IDM arps) on the cutoff; a little drive (SOFT, FOLD)
    on some basses and leads; the drums through a soft low-pass (the hats not glassy).
  - **Delay and reverb vary**: the delay time (1/4, 1/8, 8T, 16T, 1/16), the GRAIN delay pitched an octave or a fourth
    down or a fifth up (often on IDM), the reverb type among ROOM, SPRING, RESO and CLOUD, its size, modulation and
    width; each track its own space, now and then one soaked and one dry, chorus on some chords.
  - Measured over 90 throws: brightness 1714 Hz (0.6.31) → **722 Hz**, the same loudness.

### v0.6.32
- **DICE ALL goes dark.** "Out of 30 sequences one is OK": the song ideas were shrill, cheesy, too bright and happy.
  Now they are night music: **DARK MINIMAL**, **DUB TECHNO**, **IDM**, **DARK ELECTRO**, **ACID NIGHT**, **COLD WAVE**,
  **BROKEN**, **HYPNOTIC**, **DEEP BREAKS**, in minor modes only (MIN, DOR, PHRY, HARM, MEL, MPEN; no major,
  mixolydian, lydian or blues), no pop progressions.
  - **A harmony bug fixed**: the chords were built from the scale's fifth and the lead from its third, so a v chord
    sounded over a i bass. Every part now starts from the same tonic.
  - **Chords with colour**: voiced as 7ths, 9ths without the 5th, in-scale fourths or suspended, and led to the
    nearest voicing in a middle register (no leaps); dub stabs keep one voicing, offbeat after offbeat, into the delay.
  - **Filtered**: every synth's cutoff goes down by role (chords and arps darkest), with some resonance; a slow LFO
    makes the chords breathe, the envelope plucks the arps. Bright factory sounds (bells, brass, marimbas, organs,
    chiptune) are never picked.
  - **Melodies lower and stranger**: the lead around C3–C4 in small steps, or a hypnotic euclidean ostinato that turns
    on itself (Marc Houle, The Hacker), or a few long notes; arps an octave lower without octave jumps.
  - **Grooves**: a rolling offbeat sub and a dub bass, minimal and deep-techno beats with ghosts, rims and chance,
    velocities a little human; darker delay and reverb (lower tone, more damping, no SHIMMER, CLOUD pitched down).
  - Measured over 90 throws: the mix's brightness (its spectral centroid) **1714 Hz → 1376 Hz**, the average note
    **an octave lower** (65 → 55).

### v0.6.31
- **The full manual, in English and Spanish**: [docs/MANUAL.md](docs/MANUAL.md) · [docs/MANUAL.es.md](docs/MANUAL.es.md).
  Every page and its four knobs, every layer's keys, the engines, DRUM-X, the sequencer, ARRANGE, the dice and UNDO,
  effects, modulation, performance, the MENU, MIDI, the web tools and troubleshooting, and a careful chapter on
  **saving**: what is saved where, how the autosave really works (10 s after the last change while stopped, never at
  power-off), quick stores, copying, switching projects, names and user presets.
- **SELECT on the MIXER sets the tempo**, as on GLO's other pages (GLO's button opens it); it said DICE: HOME / EDIT.
- **New README images** and **presentation video v3**: the screens as they look now, taken from the video's footage
  (song ideas, ARRANGE, UNDO, TRACKS and LOAD, one scale), with the support links at the end.
- README and cheat sheets corrected against the firmware: the autosave, ARRANGE instead of the SONG page, what the
  punch-in lane records, UNDO on GLO's G4, HOME held for MENU, the reverbs' AIR knob, DRUM-X's labels.

### v0.6.30
- **LOAD, next to TRACKS** (GLO > SYSTEM: KNOB 1 **TRACKS 4 / 6**, KNOB 2 **LOAD ECO / LITE / FULL**; also MENU > SYSTEM >
  LOAD). TRACKS says how many tracks play, LOAD how heavy the sound may get, so you choose: a lean, ultra-optimised
  system to push to the limit, or a slow one full of heavy effects. Everything is swapped only while it sounds; the
  project keeps its settings and sounds as saved back on FULL (or on another unit).
  - **FULL** (the default): everything as set.
  - **LITE**: the heavy parts swapped for their nearest light kin: SHIMMER and CLOUD reverbs as ROOM, RESO as SPRING,
    the GRAIN delay as a plain delay, FM6 two voices.
  - **ECO**: LITE, and every reverb a light SPRING (0.6.70: a shorter chain), **no SLICER** (its tracks go straight
    to the mix) and **no chorus**: their pages disappear until you leave ECO. Every synth track plays at most
    **4 voices** (the drums as ever), **6** between all tracks (8 otherwise), and the load budget steps in sooner.
  - Since 0.6.71 the second core takes part of the synth work ([both cores](#both-cores-dual-core)): FULL goes much
    further before LOAD is needed.
  - The cards of what's swapped say **LITE** or **ECO** under their value.
  - Why CPU and not RAM: the firmware reserves all its memory at boot, so nothing can be freed while it runs. What runs
    out is the audio time (the load meter, the CPU % card next to LOAD), and that's what LOAD gives back.
- 0.6.29's **6 LITE** comes up as TRACKS 6 + LOAD LITE. GLO > SYSTEM's USB card is gone (the header shows USB).
- **Ko-fi / Cafecito**: support links in the README, the web installer, the web editor and the emulator.

### v0.6.29
- **TRACKS has a middle option: 6 LITE.** GLO > SYSTEM > TRACKS (and MENU > AUDIO > TRACKS) now reads **4 FULL** (the
  default), **6 LITE** or **6 FULL** (the old 6 HIGH). With 6 LITE all six tracks play and the heaviest parts are
  swapped for their nearest light kin while they sound: the **SHIMMER** and **CLOUD** reverbs play as **ROOM**,
  **RESO** as **SPRING**, the **GRAIN** delay (DLY 2 PITCH / SPRAY) as a plain delay, and **FM6** plays two voices
  instead of four. Nothing in the project changes: back on 6 FULL (or on another unit) it sounds as saved. The cards
  that are swapped say **LITE** under their value.
- **Fixed**: when a message covered the header while the BPM was rolling, the old BPM could stay half-rolled.

### v0.6.28
- **"After clearing a sequence it still triggers notes on all tracks" — fixed.** The punch-in FX lane (effects
  recorded by holding FX keys while REC is armed) kept repeating the last notes of the cleared steps with STUTTER and
  ARP, and ARP played random fills on a DRUM track with no steps. Now a clear ends those repeats and forgets the notes,
  a DRUM track with no steps gets no fill, and an effect **latched** with FX LATCH no longer records itself into the lane
  (only one held by hand does). A section jump or quick chain waiting for the next bar is called off by a clear (it
  brought the steps back). To erase the lane itself: hold REC and press FX.
- **Clears say which track**: "T3 CLEARED", and below it "SEQ+REC: ALL TRACKS" (the others play on; SEQ held + REC
  clears all six).
- **T5 and T6 asleep (TRACKS 4) can't go unnoticed**: when a note is sent to them (a key, MIDI, their steps) or PLAY
  starts with steps on them, the screen says T5-T6 ASLEEP · GLO>SYSTEM>TRACKS 6.

### v0.6.27
- **DICE ALL never repeats itself**: the moment you press (the timer's ticks) stirs the random numbers on every throw,
  and the last 32 pieces are remembered by a fingerprint (every track's steps, engines and the tempo): a piece that
  matched one would be thrown again. **The tempo moves on every throw** (at least 3 BPM, inside the style's range),
  unless MENU > BPM LOCK is on.

### v0.6.26
- **HOME + SELECT is a song-idea generator.** Each throw picks a **style** with its own tempo, swing, scales, chord
  progressions, drums, bass, how much silence it leaves, the engines it likes and its delay and reverb: **ROBOT POP**,
  **ELECTRO**, **BIG BEAT**, **ORGANIC**, **ART ROCK**, **DUB PUNK**, **MINIMAL**, **SYNTH POP**, **IDM** (the screen
  says which). Every track gets a **role** (DRUMS, BASS, CHORDS, LEAD, ARP, TEXTURE; with TRACKS 4 the first four), a
  **new engine** the style likes for it (FM6 on two tracks at most: its CPU), a factory sound whose name fits the role,
  moved a little, its voice mode, gate, level, pan and sends, and a part written from **one harmony**: the bass on the
  chords' roots (octaves, pumping, acid with slides, walking, drones, blips), chords voiced in the scale (7ths in some
  styles; held, stabbed, pulsed or sparse), the arp over the chord's notes with holes, the lead a motif repeated with a
  variation or answered, and whole bars left silent. ORGANIC, MINIMAL and IDM put loops of odd lengths against each
  other. Drums from each style's bars with fills, ghosts and accents; IDM's euclidean, ratcheted and by chance.
  No automation and no modulation beyond the macros' routes (nothing that takes RAM). UNDO (GLO + G4) as before.

### v0.6.25
- **Interface audit, second round.**
  - **SAVE > TOOLS is a list**: KNOB 1 (or PRESETS, or any knob) moves the pick down and up, OCT+ does it (its dialog
    first). It was one knob per action.
  - **The footer on the song's and the instrument's pages** (PROJECT, ARRANGE, TOOLS, GLOBAL, SYSTEM) shows the
    project and its name, not the track's engine and sound.
  - **Clearer messages**: SAVED (NO FLASH) instead of SAVED (RAM); an empty favourites list says NONE (was --/0).
  - **Layers**: on GLO, a track asleep (TRACKS 4) has its SOLO and MUTE dim and its key quiet.

### v0.6.24
- **Interface audit, first round.**
  - **The song in one place**: SAVE > ARRANGE (SEQ > SONG was the same page twice and is gone from SEQ).
  - **Readable names**: LEVEL, SWING, CLOCK, DEPTH, STEREO, FEEDBK, SPRAY, FOLLOW, PUNCH, TRACKS, ROUTE, SCALE, QUANT,
    TRANS, OFFSET, PITCH, FILTER, SHAPE, PHASE, ORDER, VOICE, GLIDE, DEST, DETUNE, NOISE, CRUSH, DRIFT, DECAY, COLOR,
    VOWEL, BREATH, MORPH, MOTION, DRIVE, ROTOR, RATIO... instead of LVL, SWG, CLK, CDP, STER, FDBK, SPRY, FOLW...
    Library files saved by the web editor with the old names load as before.
  - **Mixer (6 columns)**: each sound's name cut to fit (no "..."); a muted track keeps its name, in the accent colour.
  - **FX in sections** (TRACK, SLICER, DELAY, REVERB, CHORUS, MASTER): a tap the next page, two quick taps the next
    section; the footer counts within the section.

### v0.6.23
- **ARRANGE: delete a row right there**: KNOB 2 (SECT) turned left of A asks **DELETE ROW?** (OCT+ yes).

### v0.6.22
- **ARRANGE (SEQ > SONG) redrawn, after SLOOP's arranger**: the song as a column of rows, each a coloured section chip
  (A, B, C, D each its own heat), its bars as blocks that fill as they play, the count on the right and a dot for its
  scene; a section with nothing stored says EMPTY. Under them **+ ADD** (how many rows of the 16 are used) and **END**.
  On the right the whole song as one strip (each row as long as its share of the bars, the play head on it) and the bars
  in all. KNOB 1 the row, 2 its section (left of A: DELETE ROW?), 3 its bars, 4 its scene.
- **END: STOP, x2 .. x8 or LOOP**: the song plays once, that many times, or round and round (KNOB 2 on END).
- **Tracks asleep (TRACKS 4) in grey**: on HOME as a muted being, on the mixer greyed with OFF.

### v0.6.21
- **HOME + SELECT dices everything** (after **DICE EVERYTHING?**, OCT+ yes / OCT− no): one musical scale for every
  engine and the effects, each track a new engine, sound and sequence in that scale (T1 a bass; the others a lead, pad
  or arpeggio; DRUM a beat), the macros' routes and the delay, reverb and chorus. Tempo, levels and mutes stay.
- **SELECT by page**: the tempo on GLO's pages (GLOBAL, SYSTEM, MIXER), the sound's dice on EDIT only, nothing on the
  others (it says where).
- **UNDO: GLO held + G4**: the last big change taken back (DICE ALL, a sound diced, a clear, INIT, RECALL, a pattern or
  project loaded); again: forward. The transport keeps playing.
- **Installer**: a warning to return to official V15 first when coming from another custom firmware (a brick was
  reported going straight from one), with the button right there; Install is enabled once you confirm the FM-1 runs
  official V15 or JIANT.

### v0.6.20
- **SCALE is global, strictly**: ROOT, SCALE and QNT are one for the whole song. Before, a project, MIDI or
  automation could leave a track in its own scale; now every melodic track follows the selected one's at once.

### v0.6.19
- **TRACKS on GLO > SYSTEM** (KNOB 2: TRKS 4 LOW / 6 HIGH), next to the tracks: the same setting as MENU > AUDIO >
  TRACKS, saved. Going to 4, T5 and T6 now fade out (they were cut: a click).
- **Less stutter under load** (a full check of the last updates):
  - the overload guard sheds a voice again only after two overloaded blocks in a row (since 0.6.17 one spike, e.g. a
    key scan, was enough: a voice cut every 3 ms, clicks and cut tails);
  - the load budget is measured on the sound alone, and it only takes tails under -50 dB (was -30: audible);
  - a track let go from a black-key mute or a solo no longer keeps the FX layer working every block.
- **GRAIN delay without clicks**: with a long TIME, a grain's new spray moved the other grain in the middle of its
  window (a click every grain); and the FX buses' quiet gate now opens and reopens with a short fade (it jumped).
- **DRUM-X DRV**: several loud hits at once with DRV high could wrap into a full-scale click; held now.
- **LATCH**: turning HOLD off or ARP on with a key down, SEQ TOOLS CLEAR and REC CLEAR ALL now let the latched notes
  go (they kept droning and stacked up); a panic also ends them on MIDI OUT.
- MENU > ABOUT's AUDIO LOAD updates live.

### v0.6.18
- **MENU > AUDIO > TRACKS: 4 LOW (the default) or 6 HIGH.** With 4, tracks 5 and 6 sleep: they keep their sound,
  steps and mix but don't play or cost anything, and the whole CPU goes to T1-T4 (selecting T5 or T6 says so). With
  6, all six play and you know you're near the limit: watch the load meter. The setting is kept with the others.
- **Release tails ring out again with a sequence running.** Since 0.6.16 the load budget took the oldest released
  voice for every new note once the audio passed 65 %, so with the sequencer playing the tails were cut. Now it only
  takes a tail that is nearly gone (under -30 dB); otherwise the note is added and the tails ring. The guard at 80 %
  stays the last line.

### v0.6.17
- **DRUM-X at half the work**: each hit computed at 22 kHz (it is low-passed at ~8 kHz anyway) and brought back to
  full rate, its noise kept at the same level: the kit costs about 45 % less, the heaviest part of a busy song.
- **The guard acts sooner**: the load budget from 65 % (was 70), and over 80 % a voice fades after a single
  overloaded block (was two in a row).
- **MENU > ABOUT shows the audio's load** (scroll with PRESETS): NOW and PEAK (% of the time the audio took), LATE
  (blocks that came too late: each one a click) and SHED (voices the guard faded), since power-on. Send a photo of
  it after a click to tell what happened.

### v0.6.16
- **Stable under load: the load budget.** The device measures how much of its time the audio takes. Past 70 %, the
  sound may not grow: a new note takes a voice (the oldest released first) instead of adding one, and CLOUD spawns
  half its grains; under 60 % for a while, back to normal. The overload guard (80 %) stays as the last line. The
  load stops climbing before the screen lags or the sound clicks, whatever you turn on.
- **Mutes and solos cost nothing**: GLO's solo and the FX layer's black-key mutes were the sound silenced after
  being made; now they are MIDI mutes: the track gets no new notes and, once faded, its voices end.
- **FM6 plays 4 voices a track** (was 6): six operators a voice, the heaviest engine.
- **DRUM-X's DRV and knee on the kit's sum** (were each hit's): the same glue on the bus, half the work.

### v0.6.15
- **No hiss at rest with CLIP up**: the clipper rounded a tail's tiny negative residue down (-1) and drove it x4: a
  constant offset with a faint hiss on one side, even with every track off. Now rounded; and the FX buses (delay,
  chorus, reverbs) fade their own last residue to silence once nothing has been sent to them for a while (1.5 s at
  -55 dB, 4 s at -36 dB, 8 s at -30 dB), so the tails' rounding never leaves a hum. CLOUD's FREEZE is never gated.
- **CLOUD always dies out**: past SIZE ~80 its loop rang on for ever (its tail fed back into its own line); now only
  the grains feed it: a long tail that ends (SIZE 126 stays a faint wash for long, close to FREEZE).
- **More headroom**: DRUM-X stops computing a hit at -66 dB (was -84), FM6 ends a released note once its carriers
  are under ~-66 dB (its six operators no longer run for seconds on an inaudible tail), and the overload guard steps
  in at 80 % of the audio's time (was 85 %): it fades a voice before the sound clicks and the screen starves.

### v0.6.14
- **No more sharp highs when changing presets**: the notes still sounding used to take the new sound's values at once
  (its filter, its envelope amounts), jumping bright and loud. Now they fade out in ~3 ms with the sound they had
  (all of it, kept the moment before the change), and the new notes start clean. Also on user presets and sections.
- **SEQ TOOLS** (SEQ held): each cell shows its key with the octave (F3 CLEAR, F4 CLR AUTO: both read "F" before),
  and the footer shows **REC: CLEAR ALL** (all six tracks' steps and automation, OCT+ confirms), which was nowhere
  on screen.
- **Key LATCH**: with ARP OFF, **ARP 2 > HOLD ON** latches the keys: the notes keep sounding when you let go, the
  next chord replaces them, HOLD OFF lets them go.
- **CLOUD costs about a third less CPU**: its grains computed every other sample (the line they read is written at
  half rate anyway), the same sound. First step against the lag and clicks with six tracks busy.

### v0.6.13
- **AIR on SHIMMER and CLOUD** (REVERB's fourth knob, PRE on ROOM / SPRING): ±24 semitones. Down, the reverb goes lower
  and darker; up, higher and airier, in pitch and in filter at once. SHIMMER's loop climbs octave + AIR on each pass
  (an octave down to two up); CLOUD's grains move with it. 0 sounds as before.
- **CLOUD's graph** is a swarm of moving dots: AIR lifts or sinks the cloud, MOD splits it into octave layers, the
  grains playing now drawn bigger.
- **AUTOPAN's graph** fixed (SIN came out wrong) and drawn like LFO's: two cycles across, the playhead and a dot on
  where the pan is now, L up, R down.
- **CHORUS STER** moves its graph: the three taps fan apart with it, and fold into one line at mono.
- **SAVE > TOOLS** says what each knob does (CLEAR SEQ, INIT SOUND, DELETE ROW n, CLEAR SONG) instead of "TURN TO PICK";
  the page name in the footer is lit, so you always see where you are.
- **LOFI BYTE / FLOAT: RETRIG** (EDIT > RETRIG, after EDIT 2): **RTRG ON** starts the formula from the top on every
  note, instead of carrying on where it was.

### v0.6.12
- **Projects in SAVE**: SAVE > PROJECT now shows the project (1–8, each a whole song) and its four **sections A–D**,
  each with its own sequences and sounds for the six tracks. KNOB 1 opens another project (stopped; the music you are
  playing stays, ready to be stored into one of its sections), KNOB 2 or PRESETS picks the section, LOAD makes it the
  music, SAVE stores the music into it. Each section shows whether it's saved, **NOW** on the one playing and the bars
  it plays in the song; the arrangement sits below in a line (A4>B8>D4>B8).
- **ARRANGE**, right after PROJECT: the project's song, sections chained by bars as in SLOOP (the same rows as
  SEQ > SONG; OCT+ plays it). To copy a section, LOAD it and SAVE it into another letter.

### v0.6.11
- **FM6 voice bank**, from Felucca 1.5.1: a whole 32-voice DX7 cartridge (.syx) sent from the web editor (6-OP FM tab,
  **Send to the device's voice bank**), picked on the device with **SLOT B1–B32** after F1–F8 and OWN (empty slots
  skipped; the voice's name above the algorithm). Loading a voice copies it into the track, so projects and presets
  keep it whatever the bank holds later. Its own flash sector (0xE7000), written so a power cut leaves the old bank or
  the new one, never half; editor commands 74–77 as Felucca's. The full backup doesn't include it: keep the .syx.

### v0.6.10
- **FM6 fully editable on the device**, brought from Felucca 1.5.1: EDIT > **OPERATOR** (operator 1–6, RATIO / FIXED,
  FINE, LEVEL), **OP ENV** (each stage's RATE and LEVEL, drawn) and **OPERATOR 2** (MODE, DTUN, VEL), on an FM6 track
  only. The patch becomes the track's own (SLOT OWN), saved as always; no new format, a few bytes of RAM. An edit keeps
  the patch's volume trim (0.6.8), so the level doesn't jump while you turn.
- **Fix**: a card could keep a stale gauge colour or width (or lose its tail with a long label) until the page was
  redrawn; its cache now holds the whole card.

### v0.6.9
- **AUTOPAN** per track (FX > AUTOPAN, after DIST): DPTH, RATE, SYNC (BEAT: 4 BARS .. 1/32 in time with the bar;
  FREE: Hz) and WAVE (SIN TRI SAW SQR S&H), through the pan's glide so even SQR doesn't click; its own graph. It
  lives in the slots of the old per-track slicer (a bus since 0.6.3): no more memory, the project format unchanged,
  every old project and preset loads with it off.
- **CHORUS > STER**: the chorus's stereo amount, 0 as it always sounded, down to mono, up to about twice as wide
  (in a stored slot that was unused).
- Cheat sheets and manual updated.

### v0.6.8
Fixes from the first users' reports:
- **No more crackles turning knobs.** Measured on every engine, a knob turned fast against the same move made smooth:
  - **FILTER** (every engine but ANALOG): going in and out of the chain (CUT at the top with RES 0, the LP open) and
    changing TYPE now crossfade, the filter starting from the sound instead of a stale state. It clicked each time CUT
    or RES crossed the open point (FM6's CUT 17x the high-frequency energy, now as smooth as a slow turn).
  - **LEVEL and PAN** glide (~3 ms) instead of stepping at each knob move.
  - **DIST** comes in smoothly from 0: DST 1..8 blend the dry sound into the drive (at 1 it was the full drive, with
    its low cut, at once).
- **FM6: SysEx voices no longer distort.** DX7 voices with several carriers at full came out up to 5x louder than the
  factory patches, and their chords kept the master's limiter about 10 dB down (that was the glitchy, noisy sound). A
  voice above the level every voice is made for is now trimmed to it, per patch and automatically: its chords
  sit where the factory patches' do (the limiter about 2 dB, as theirs). Quieter voices and the 8 factory patches are
  untouched; nothing is ever boosted. Tested with 71 classic DX7 voices.
- **SEQ TOOLS: F4 CLR AUTO** clears the selected track's automation and parameter locks (every step), the steps stay.
  It breathes when there is automation to clear. Next to F3 CLEAR (the sequence).
- **Video v2** (`tools/video/`): every effect, DRUM-X's pages, the modulators, sequencers and automation, a beat from
  soft to industrial at 132 BPM, fast montage cuts; the captions come from the capture's own script.

### v0.6.7
- **Cheat sheets** in the README: controls, and sound · effects · modulation, as images and printable PDFs.
- **Page jump fix**: once you turn PRESETS with a page button held, that button's layer (its map) stays off until you
  let the button go, even if you keep holding past the HOLD time or the first turn came at the very moment you pressed
  it. Hold it again afterwards and the layer works as always.
- **Presentation video tools** (`tools/video/`): `capture.c` plays a 60 s demo song on the real engines in the host
  build and records the FM-1's screen and audio; `compose.py` makes a 1080p video from them in the project's look.

### v0.6.6
- **Jump straight to a page**: hold a page button (ENV, LFO, FX, SCL, EDIT, GLO, SAVE, ARP, SEQ) and turn **PRESETS**
  to go through that button's pages forwards or back (FX has 13, EDIT up to 16), the title on screen; let go and you
  stay on that page. It doesn't take anything away: with a button held, PRESETS did nothing before; a tap still goes to
  the next page, and once you used a layer's knobs or keys while holding, PRESETS stays out of it.

### v0.6.5
- **RESO (reverb) changes chords now.** On RESO, the REVERB page's PRE knob becomes **PITCH** (the strings' chord
  0–14 steps up the scale) and DAMP becomes **FOLW**: OFF, or T1–T6, the chord built on the lowest note that track
  plays, so the strings follow your bass line or your chords, gliding from one to the next (the chord stays when the
  track goes quiet). The pre-delay and the damping were barely used on RESO; ROOM, SPRING, SHIMMER and CLOUD keep them.

### v0.6.4
- **LOFI FLOAT: DRV is gone, FBK takes its place.** DRV had a scaling bug that silenced the engine as soon as it was
  turned up, and it duplicated the DIST on the FILTER page anyway. **FBK** (feedback) sends the output back into the
  formula's time: the floatbeat modulates itself like FM, from a slight shimmer to chaos, a different deformation on
  every ALGO. Projects saved before keep their values (FBK starts where DRV was).

### v0.6.3
- **The SLICER is now one slicer on a bus, like a sampler's chop.** Its settings (mode, pattern, rate, depth) are the
  section's, and on **SL BUS** / **SL BUS 2** you choose with seven ON/OFF switches what goes in: **T1–T6** and
  **FX** (the delay, reverb and chorus returns). Everything ON turns it into a **stutter sequencer for the whole mix,
  after the effects**: the reverb and delay tails get cut too. With FX OFF the tails ring free over the cut.
  The routed tracks enter after their DIST, filter, level and pan; their sends still go to the effects.
- **SL PITCH**: the repeats (STUT) follow a **16-step pitch sequence** (±24 semitones, with the mod sequencer's page
  layout: KNOB 1 the step, KNOB 2 its pitch, LEN, QNT). Played like a tape (higher = faster), the loop keeps the
  step's rhythm; **QNT SCL** snaps the steps to the song's scale. One sample turns into an arpeggio.
- No limit of tracks any more (STUT on four was the 0.6.2 compromise), the same memory as before (32 KB, now a
  stereo recording of 371 ms), and less CPU: one slicer instead of one per track.
- Each section of a song keeps its own SLICER settings. Projects from before load with their slicer settings turned
  into the bus's: the first track that had it on gives the mode, pattern, rate and depth, the tracks that had it on
  go in, FX stays out.

### v0.6.2
- **SLICER memory shared**: GATE works on all six tracks as before; **STUT** (the one that records and repeats) can
  run on **up to 4 tracks at once**. A fifth STUT track plays live without repeats and the screen says
  **STUT: 4 TRACKS MAX**; when one of the four leaves STUT, the waiting one takes its place on the next step. Each
  track keeps its own pattern, rate and depth, and its sends still follow the chopped sound. This frees 16 KB of
  the big-buffer memory (pool now at 92 %, 25 KB free) for future effects.

### v0.6.1
- **MIXER: the six tracks at once** in the JIANT style, as six thermal columns (number, sound, LEVEL as the heat
  column with the meter over it, its dB, PAN and REV as two bars underneath). The other styles keep four cards that
  follow the selected track.

### v0.6.0
- **Six tracks instead of four.** T5 starts on PHASE and T6 on WHEEL (any engine can go on any track, as always),
  each with its own sequence, sound, effects sends and automation. **ALGORITHM** scrolls T1..T6.
- **Same storage, everything kept**: still 8 songs × 4 sections plus the 4 project slots, and the song sequencer
  (rows of sections with repeats and scenes) works as before, so you can build whole songs with intro, verse,
  chorus and bridge. To fit six tracks in the same space, sections are now saved **compressed**: only the steps
  that have something, and only the parameters you changed, are stored. The music at power-on takes about a
  quarter of a section; even six tracks with 4-note chords on all 64 steps fit.
- **A fill warning**: a moment after you stop editing, if the music is near the size of a section the screen says
  **SECTION 90% FULL**; if it no longer fits, **TOO FULL TO SAVE**. Saving a section in that state says
  **SECTION FULL** and changes nothing: the section already saved stays as it was. All memory is fixed at build
  time (nothing is allocated while you play), so a full section can never crash the system.
- **Projects and sections from 0.5 load as they were**: their four tracks keep their sound and steps, T5 and T6
  start empty on their default sounds.
- **GLO** (held): black keys 1–6 mute T1–T6, 7–10 the DRUM groups (KICK, SNARE, HAT, PERC); white keys F3–D4 solo
  T1–T6 while held, E4 unmutes everything, F4 tap tempo. The four knobs are T1–T4's levels, or T3–T6's when T5 or
  T6 is selected. **FX** (held): black keys 1–6 mute T1–T6.
- **MIXER** shows four tracks at a time and follows the selected one (T5 or T6 selected: T3–T6). (0.6.1: all six in the JIANT style.)
- **HOME**: six beings in the ecosystem, a bit smaller.
- **Song scenes** remember the mutes of T5 and T6 too. **Automation** (knobs and per-step locks) works on all six.
- **MIDI IN**: ROUT **CH1-6** (was CH1-4): channels 1–6 play tracks 1–6, 7–16 stay free for other instruments.
- Web editor: six tracks in the track selector, the mixer and automation.

### v0.5.5
- **FLOAT is a floatbeat generator now**: bytebeat's sibling in floats. Each of the 32 ALGOs is a formula of `t`
  made of sines, as in the floatbeat scene: `sin(t·(t>>11 ^ t>>13 & 7))`, FM whose index walks with `t`'s bits,
  melodies read from nibble tables, kicks, snares and hats inside the formula, Sierpinski partials, drive and folds,
  staircase sines, xor'd and dropped bits, risers, polyrhythms, chords whose root walks… rhythm, melody and timbre at
  once. `t` runs 32 steps per cycle of the note, so every formula plays in the key you hold (and, as in bytebeat, its
  rhythm runs faster up the keyboard). It shares BYTE's controls: **VAR** mutates `t` (8 ways), **MOTN** runs its
  slow bits faster or slower, **BEND** folds it, **LOOP** locks it into a short window; the new **DRV** folds the
  output from clean to wild.

### v0.5.4
- **FLOAT makes patterns now, not just waveforms.** Every ALGO is a step sequencer: 8 patterns (an arpeggio, a
  melody, a Sierpinski rhythm, a 5-in-8 euclid, a random walk, a `t>>9 % 13` line, a drone with 3-against-4 accents,
  octave leaps) × 4 smooth timbres (sine, FM that darkens as each note falls, wavefold, hard sync sweeping down).
  The notes are harmonics of the key you play (just intonation), the steps are the song's 1/16 notes.
- **New knob, MOTN (motion)**, on BYTE and FLOAT, in the slot that was empty: the speed of the formula's time. In
  FLOAT it goes from one step per bar to steps so fast the pattern turns into a timbre; in BYTE it speeds up or slows
  down the formula's slow bits (its rhythm and melody) without changing the pitch. 64 is as written.
- **VAR is drastic now**, on every BYTE and FLOAT formula: it mutates the formula's time in 8 different ways (stairs
  that transpose as they go, xor and or with itself, holes in the rhythm, the phrase backwards, multiplied,
  scrambled), so each formula gives many timbres and sequences.
- **The second LOFI page cleaned up**: BYTE shows MOTN · GRIT · BEND · LOOP (GRIT holds samples longer, a rate
  crusher), FLOAT MOTN · DCY · BEND · LOOP (DCY: from short plucks to legato). The second RES (already on the FILTER
  page) and the empty slot are gone. Projects saved before keep their sound (MOTN set to 64, GRIT/DCY to 0).

### v0.5.3
- **A new power-on screen**, after feedback from the community: the signature used to be drawn as straight segments
  (it looked like MS Paint next to the rest of the interface). Now each stroke is smoothed and drawn as a curve with a
  round pen that tapers at the ends, like ink; the pen's tip is a glowing nucleus; and three small beings (a
  radiolarian, an amoeba, a hydra) swim in from outside the screen and circle the signature while it is written,
  warming up as it grows and pulsing once it is done. It costs 16 bytes of RAM, and the splash now runs on the clock
  (drawing the beings does not make it longer). MENU > ANIM OFF still shows it whole at once.

### v0.5.2
- **BYTE: new formulas, no silent starts.** The 17 most familiar one-liners (`t*(42&t>>10)`, `t&t>>8` and friends)
  were replaced by less obvious ones: rhythms and arpeggios after Tejeez, xpansive's "lost in space", a melody of
  `t>>9` modulo 13, textures built from `t%24` and `t%19`, and more. Each formula now starts where it is already
  moving: 14 of the 32 used to sit silent for up to half a second after the note; now all 32 sound within 30 ms.
- **FLOAT: 32 formulas** (16 new): drifting unison, sub-and-fifth organ, self-FM, glides through partials, gated
  rhythms, CZ-style phase distortion, formants, breath, harmonic chords, breathing bells, stepped sines, PWM, random
  held partials, hard sync, three-against-four. **CHIP now sets FLOAT's resolution**: FULL (smooth, the default),
  4BIT, 4B/2, 1BIT, STEP.
- **LOFI presets in order**: browsing shows the BYTE presets, then FLOAT, then the classic chip sounds.
- **Parameter check**: NOISE's resonance is now **PEAK** (it sat next to the FILTER page's RES with the same name).
- **Lighter audio interrupt**: 0.5.1's X-MOD LFO had been compiled into the audio interrupt's inner path with its
  divisions (its cost estimate almost tripled); it now runs once per block, outside it, and the interrupt is back to
  its 0.5 budget.

### v0.5.1
- **Master no longer smears the mix.** The always-on leveler was riding every hit: measured on the demo song, its
  gain swung about 5 dB inside each beat and the limiter was working 95 % of the time. Now it follows the song's
  loudness over about a second and a half (0.3 dB of movement per beat) and leaves the limiter more headroom (active
  less than half as often, and lighter). Same loudness, transients and space come back.
- **CLOUD is bigger**: 12 overlapping grains instead of 8, each one a few cents off (a chorused shimmer), the grains
  fed back into the cloud so it keeps building, and a louder bloom.
- **RESO rings much longer**: the top of SIZE now sustains for many seconds.
- **Chorus rebuilt as an ensemble**: three voices swept a third of a cycle apart, left, right and centre: stereo
  even with WIDTH at 0, wider with it.
- **New LOFI wave: FLOAT** (floatbeat, bytebeat's smooth sibling): 16 formulas made of sines (FM, harmonic
  arpeggios, folded sines, beating pairs, plucks, pads), tuned to the note; VAR, BEND, RES and LOOP as in BYTE.
  Three new presets: FLOAT FM, FLOAT ARP, FLOAT PAD.
- **New DRUM-X page: X-MOD**, a modulator for the whole kit: a tempo-synced LFO on MORPH (RATE from 4 bars to
  1/32, DPTH, SHPE: sine, triangle, saw, ramp, sample & hold) and RAND (every hit its own MORPH and tune). Saved
  with the kit; the A–B bar shows the morph moving.

### v0.5
First public release.
