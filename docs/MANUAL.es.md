# JIANT FM — Manual de usuario

**Firmware v0.6.30 para el M-VAVE FM-1**

> *English version: [MANUAL.md](MANUAL.md).*

Este manual es para músicos que acaban de instalar JIANT FM y quieren saber cómo tocarlo, cómo armar temas con él
y, sobre todo, **cómo guardar su trabajo sin perder nada**. Sigue el firmware tal como está en la v0.6.30: cada
botón, perilla y mensaje aparece nombrado exactamente como lo muestra el equipo.

Si vas a leer un solo capítulo, leé [12. Guardar y cargar](#12-guardar-y-cargar).

## Contenido

0. [Inicio rápido](#0-inicio-rápido)
1. [El panel](#1-el-panel)
2. [La pantalla](#2-la-pantalla)
3. [Páginas y capas](#3-páginas-y-capas)
4. [Motores](#4-motores)
5. [DRUM-X](#5-drum-x)
6. [El secuenciador](#6-el-secuenciador)
7. [ARRANGE: canciones, secciones y escenas](#7-arrange-canciones-secciones-y-escenas)
8. [Dados y UNDO](#8-dados-y-undo)
9. [Efectos y master](#9-efectos-y-master)
10. [Modulación y macros](#10-modulación-y-macros)
11. [Tocar en vivo](#11-tocar-en-vivo)
12. [Guardar y cargar](#12-guardar-y-cargar)
13. [Sistema: TRACKS, LOAD y el MENU](#13-sistema-tracks-load-y-el-menu)
14. [MIDI y USB](#14-midi-y-usb)
15. [Herramientas web: emulador, instalador, editor, backup](#15-herramientas-web-emulador-instalador-editor-backup)
16. [Problemas y preguntas frecuentes](#16-problemas-y-preguntas-frecuentes)

---

## 0. Inicio rápido

### Instalación

1. Abrí el **instalador web** en Chrome o Edge: <https://juanjiant-bit.github.io/JIANT/webapp/installer/>
2. Conectá el FM-1 **directamente** a la computadora con un cable USB de datos.
3. **¿Venís de otro firmware custom (Felucca, baudgirl o cualquier otro)?** Volvé primero al firmware oficial V15
   con el botón **Return to official V15 first** del instalador (que además guarda un backup completo). Escribir
   JIANT directamente encima de otro firmware custom ya dejó algún FM-1 sin poder arrancar.
4. Apretá **Install**. Primero revisa el firmware del FM-1 y solo escribe sobre el oficial V15 o JIANT (si encuentra otro,
te manda a volver al V15 oficial primero). No desenchufes el cable mientras escribe.

JIANT no tiene samples de usuario: si venís de Felucca, sus samples de usuario (USR1–3) se pierden al instalar.
Guardá tus archivos WAV.

### Tu primer sonido (1 minuto)

1. Encendé el equipo. La firma se dibuja sola y después llegás a **HOME**: seis criaturas, una por pista.
2. Girá **ALGORITHM** para elegir una pista (T1–T6). Con el valor por defecto, **TRACKS 4**, se detiene en T4: T5 y T6 aparecen solo con TRACKS 6 (ver
   [13](#13-sistema-tracks-load-y-el-menu)).
3. Girá **PRESETS** para recorrer sonidos. Tocá las teclas.
4. Girá **KNOB 1–4**: en HOME son los cuatro controles más útiles del motor de la pista.
5. ¿No te gusta? Mantené **EDIT** y girá **SELECT**: el sonido se tira a los dados y sale una variación nueva, que escuchás al
   instante. **OCT+ OK** la deja, **OCT− CANCEL** devuelve el sonido.

### Tu primer tema (5 minutos)

1. En **HOME**, girá **SELECT**. Se abre la pantalla **GENERATOR**: elegí un **GENRE** con KNOB 1 (o dejá RANDOM) y
   apretá **OCT+**. Aparece una idea de tema completa: motores, sonidos, partes, escala, tempo y efectos. Apretá
   **PLAY**.
2. ¿No te convence? Apretá **OCT+** otra vez: semilla nueva, pieza nueva. ¿Demasiado cargada? Girá **SELECT** a la
   página 2 y bajá **DRUMS** o **ARP**, después OCT+: la misma pieza con eso cambiado. **HOME** (u OCT−) cierra la pantalla.
   Para volver a lo que había antes: mantené **GLO** y apretá **G4** (UNDO).
3. ¿Te gusta? **Pará** (PLAY) y apretá **SAVE** dos veces para llegar a **SAVE > PROJECT** (la primera pulsación de
   SAVE abre USER, la segunda PROJECT). Girá **KNOB 4** a la derecha para que muestre **[OCT+]** y apretá **OCT+**.
   Escribí un nombre con las teclas (o dejá el que te ofrece) y apretá **OCT+** otra vez. La pantalla dice **SAVED**.
4. Hacé una variación (cambiá algunos pasos, muteá una pista) y guardala en la sección **B**: en SAVE > PROJECT girá
   **KNOB 2** hasta **B** y después KNOB 4 y OCT+ como antes.
5. Apretá **SAVE** otra vez para llegar a **ARRANGE**. Girá **KNOB 2** sobre la fila **+ ADD** para agregar una fila,
   elegí su sección con KNOB 2 y su largo con **KNOB 3** (compases). Agregá una fila para A y otra para B. Apretá
   **PLAY**: el tema reproduce las filas en orden.

Ese es todo el ciclo: **hacer música → guardarla en una sección → encadenar secciones en ARRANGE**.

---

## 1. El panel

Los nombres de abajo son los que usa el firmware (la pantalla HARDWARE CALIBRATION los pide con estos nombres).

### Encoders y perillas

| Control | Qué hace |
| --- | --- |
| **SELECT** (encoder) | Solo: **recorre las páginas de la sección en la que estás** (las de EDIT en una página EDIT, las de FX en una de FX …), una por paso, sin dar la vuelta; en **HOME** abre **GEN**, el generador de temas (como HOME + SELECT). Con un botón mantenido, los **dados** de ese botón: **HOME** + SELECT **GEN**, **EDIT** + SELECT el sonido, **SEQ** + SELECT la secuencia, **LFO** + SELECT el LFO, **FX** + SELECT los efectos. **GLO** + SELECT: el tempo. Cualquier otro botón de página + SELECT: sus páginas. |
| **ALGORITHM** (encoder) | Elige la pista desde cualquier página: T1–T4, o T1–T6 con TRACKS 6. En el MENU: cambia de pestaña. |
| **PRESETS** (encoder) | En HOME, PRESETS y las páginas de sonido: recorre sonidos (los presets de fábrica de cada motor y después tus presets de usuario). En las páginas de pasos (STEP, COMP, PATTERN, AUTOMATION, TRACK): mueve el cursor de paso; en NOTE, el foco. En las páginas de lista (USER, PROJECT, ARRANGE, TOOLS, AUTO LIST): mueve la selección. **Mantené un botón de página y girá SELECT** (o PRESETS) para saltar directo por las páginas de ese botón. |
| **KNOB 1–4** | Las cuatro tarjetas (columnas) de la pantalla. Con una capa mantenida, las perillas propias de la capa. Girar rápido recorre todo el rango, despacio ajusta fino (MENU > KNOB ACCEL lo desactiva). |
| **MASTER** | El volumen de salida. |

### Botones

| Botón | Toque | Mantener |
| --- | --- | --- |
| **HOME** | Vuelve a HOME (el ecosistema). | Unos 0,7 s: abre el **MENU**. |
| **ENV** | Páginas ENV. | (sin capa) |
| **LFO** | Páginas LFO. | Capa **MACRO**: KNOB 1–4 son M1–M4. |
| **FX** | Páginas FX (dos toques rápidos: la siguiente sección de FX). | Capa de **FX punch-in**. |
| **SCL** | Páginas SCL. | Capa **SCL**: las teclas fijan la tónica. |
| **EDIT** | Páginas EDIT (en STEP: borra el paso y los TIEs de su nota que lo siguen; en USER / PROJECT: renombrar). | Capa **EDIT**: INIT, RECALL, mutes de los sonidos de DRUM-X. |
| **GLO** | MIXER → GLOBAL → SYSTEM → MIXER. | Capa **GLO**: mutes, solos, niveles, tap tempo, UNDO. |
| **SAVE** | Páginas SAVE (primera pulsación: USER). | Capa **SAVE**: tocar/guardar secciones en vivo. |
| **ARP** | Páginas ARP. | (sin capa) |
| **SEQ** | Páginas SEQ. | Capa **SEQ TOOLS** (en STEP, NOTE, PATTERN, COMP, TRACK y AUTOMATION). |
| **PLAY** | Arranca / para. | — |
| **REC** | Arma / desarma la grabación en la pista seleccionada. | Capa **REC**: CLEAR, CLICK. |
| **OCT− / OCT+** | Octava del teclado (−3 a +3; los dos juntos: vuelve a 0). En páginas de acción y en diálogos: **OCT−** = atrás / NO, **OCT+** = hacerlo / YES. | — |

### Las teclas

27 teclas de **F3 a G5** (16 blancas, 11 negras). Tocan la pista seleccionada. Con una capa mantenida se convierten en
atajos de esa capa; en la grilla DRUM son pasos y carriles; en la pantalla NAME escriben.

### Combinaciones útiles

| Combinación | Resultado |
| --- | --- |
| **GLO** mantenido + **PLAY** | Reinicia desde el principio sin parar (clock interno). |
| **GLO** mantenido + **SELECT** | Tempo, desde cualquier página. |
| **GLO** mantenido + **G4** | **UNDO** del último cambio grande (otra vez: rehacer). |
| **SEQ** mantenido + **REC** | **CLEAR ALL SEQUENCES?** — los pasos y la automatización de las seis pistas, y el carril de punch-in. |
| **REC** mantenido + **FX / EDIT / ENV / LFO / SCL / ARP / GLO** | Borra la automatización de esa parte en la pista seleccionada (GLO: la automatización de nivel y paneo de todas las pistas; FX: también el carril de punch-in). Sin diálogo. |
| **SAVE** mantenido + **OCT+** / **OCT−** | Guarda la música en la sección que está sonando / recupera esa sección tal como quedó guardada. |
| **HOME / EDIT / SEQ / LFO / FX** mantenido + **SELECT** | Los dados: todo / el sonido / la secuencia / el LFO / los efectos (ver [8](#8-dados-y-undo)). |
| **ENV / SCL / ARP / SAVE** mantenido + **SELECT**, cualquier botón de página + **PRESETS** | Salta por las páginas de ese botón. |
| Un paso mantenido (SEQ > STEP) + **KNOB 1–4** | Un parameter lock en ese paso. |
| **OCT− + OCT+** mantenidos al encender | HARDWARE CALIBRATION. |
| **OCT− + OCT+** mantenidos 5 s con el equipo funcionando | Modo de actualización (UBOOT), con una cuenta regresiva desde los 2 s; soltá para cancelar. |

---

## 2. La pantalla

- **Encabezado (arriba)**: estado de reproducción, el metrónomo, los **BPM** (se iluminan mientras cambian), la octava
  (o la fila del tema mientras suena un tema), el **medidor de carga** (cinco barritas al lado de la batería: cuánto
  del tiempo de audio está ocupando el sonido ahora) y el ícono USB. Acá también aparecen los mensajes ("SAVED",
  "T1 CLEARED"...), a veces con una segunda línea.
- **Tarjetas**: las cuatro columnas debajo del encabezado son KNOB 1–4. Un valor automatizado o con lock aparece
  marcado; una tarjeta apagada significa "acá ahora no hay nada".
- **Nombre de página**: al cambiar de página (o de pista) a mano, el nombre de la página aparece un momento sobre el pie
  de la pantalla, con la pista y su motor a la derecha; en HOME el motor de la pista, y "T1 HOME" en chico. La barra de
  arriba, las tarjetas y el gráfico quedan a la vista.
- **Gránulos**: unos puntitos flotan detrás del gráfico del panel, como en HOME (LOAD FULL con ANIM ON). Se mueven solo cuando
  el panel se redibuja igual (una perilla, el LFO, la envolvente), así que no gastan CPU.
- **Panel (al medio)**: el gráfico de la página — la criatura del motor, una envolvente, el LFO en movimiento, la
  grilla de pasos, una lista...
- **Pie**: el nombre de la página y su lugar dentro de su familia (p. ej. **DLY 2/2**), o ayudas de teclas. En las
  páginas del tema (PROJECT, ARRANGE, TOOLS, GLOBAL, SYSTEM) muestra el proyecto y su nombre en lugar del sonido de
  la pista.

Los **colores** funcionan como una cámara térmica: frío (cian, azul) es poco, caliente (naranja, amarillo, blanco) es
mucho. Violeta es lo seleccionado, naranja lo activo.

**HOME** es el ecosistema: una criatura por pista, su especie según su motor, su forma según sus cuatro perillas, que
se hincha y se calienta con su propio audio. La pista seleccionada se dibuja más grande, una muteada se oscurece, una
pista dormida (TRACKS 4) se dibuja como muteada. En el **MIXER**, las pistas dormidas aparecen en gris y dicen OFF.

Los **diálogos** preguntan antes de cualquier cosa destructiva: **OCT− NO**, **OCT+ YES**.

---

## 3. Páginas y capas

### Cómo funciona la navegación

- **Tocá** un botón de página: sus páginas. Tocalo de nuevo: la siguiente página de esa familia. Desde otra familia
  volvés a la página donde estuviste por última vez.
- **HOME** vuelve al ecosistema.
- **FX** es largo, así que está dividido en secciones: TRACK (FX, DIST, AUTO PAN), DELAY (DLY, DLY 2), REVERB
  (REVERB, REVERB 2), CHORUS, SLICER (SLICER, SL BUS, SL BUS 2, SL PITCH), MASTER. **Dos toques rápidos** en FX saltan a la
  siguiente sección.
- **Girá SELECT** para recorrer las páginas de la sección en la que estás (las de EDIT en una página EDIT, las de FX en
  una de FX), una por paso, frenando en la primera y la última; el nombre de la página aparece un momento sobre el pie.
  En HOME abre GEN, el generador de temas.
- **Mantené un botón de página y girá PRESETS** para recorrer sus páginas hacia adelante o hacia atrás (sin dar la
  vuelta); soltá y te quedás ahí. ENV, SCL, ARP y SAVE hacen lo mismo con SELECT; HOME, EDIT, SEQ, LFO y FX + SELECT son
  sus dados, GLO + SELECT el tempo.
- **Mantené** un botón de página (más allá del tiempo HOLD, MENU > HOLD, 0,4 s por defecto) para abrir su **capa**:
  las teclas y perillas cambian de función mientras lo mantenés, y un mapa muestra qué hace cada tecla. Apretar una
  tecla o girar una perilla la abre al instante. Soltá y volvés a donde estabas.
- Algunas páginas solo aparecen cuando corresponden: las páginas de operadores de FM6 en una pista FM6, las de DRUM-X
  en una pista DRUM, RETRIG en LOFI BYTE/FLOAT, y con **LOAD ECO** se ocultan las páginas SLICER y CHORUS.

### Cada página y sus cuatro perillas

"—" significa una tarjeta vacía. Las tarjetas de "acción" muestran **[OCT+]** cuando están elegidas (girá la perilla
a la derecha); apretá OCT+ para ejecutarla.

**ENV** (por pista)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| ENV | ATK | DEC | SUS | REL |
| ENV DEST | FILTER | PITCH | SHAPE | LOOP |

**LFO** (por pista)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| LFO | RATE | WAVE | PHASE | FADE |
| LFO DEST | PITCH | FILTER | SHAPE | AMP |
| MOD | SLOT (1–4) | SRC | DEST | AMT |
| MSEQ | STEP (1–16) | LEVEL | LEN | SLEW |
| MSEQ 2 | DIV | — | — | — |

**FX** (las páginas TRACK son por pista; el resto son globales)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| FX | DIST | CHORUS (envío) | DLY (envío) | REV (envío) |
| DIST | DIST | TYPE | TONE | — |
| AUTO PAN | DEPTH | RATE | SYNC | WAVE |
| SLICER | MODE | PAT | RATE | DEPTH |
| SL BUS | T1 | T2 | T3 | T4 |
| SL BUS 2 | T5 | T6 | FX | — |
| SL PITCH | STEP | PITCH | LEN | QUANT |
| DLY | TIME | FEEDBK | TONE | MIX |
| DLY 2 | WIDE | PITCH | SPRAY | MOD |
| DLY 3 | TYPE (ANALOG / DIGITAL) | PING (OFF / ON) | — | — |
| REVERB | TYPE | SIZE | DAMP (RESO: FOLLOW) | PRE (SHIMMER/CLOUD: AIR; RESO: PITCH) |
| REVERB 2 | MOD | RATE | FILT | WIDE |
| CHORUS | RATE | DEPTH | STEREO | — |
| MASTER | CLIP | PUNCH | DUCK | REL |

**SCL**

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| SCL | ROOT | SCALE | QUANT | TRANS |
| SCL 2 | ALL TR | — | — | — |

**EDIT** (por pista; qué páginas aparecen depende del motor)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 | Aparece en |
| --- | --- | --- | --- | --- | --- |
| EDIT 1 | E1 | E2 | E3 | E4 | todos los motores (ver [4](#4-motores)) |
| EDIT 2 | E5 | E6 | E7 | E8 | todos los motores |
| RETRIG | RTRG | — | — | — | LOFI con WAVE en BYTE o FLOAT |
| MORPH | MORPH | — | — | — | ANALOG (SAW..SIN), PHASE, LOFI (hasta WRAM) |
| OPERATOR | OP | RATIO / FIXED | FINE | LEVEL | FM6 |
| OP ENV | OP | STAGE | RATE | LEVEL | FM6 |
| OPERATOR 2 | OP | MODE | DTUN | VEL | FM6 |
| FILTER | TYPE | CUT | RES | DRIVE (ANALOG) / DIST (los demás) | todos los motores |
| KIT 3 | BP | FEEDBK | — | — | DRUM (todo el kit) |
| X-MOD | RATE | DEPTH | SHAPE | RAND | DRUM (todo el kit) |
| SOUND | SOUND | SIDE | PITCH | PMOD | DRUM (un sonido) |
| SOUND 2 | SOUND | DECAY | NOISE | COLOR | DRUM (un sonido) |
| SOUND 3 | SOUND | MODE | PM.TYPE | DRIVE | DRUM (un sonido) |
| SOUND 4 | SOUND | LAYER | FEEDBK | SEND | DRUM (un sonido) |
| LEVELS | KICK | SNARE | CLAP | HATCL | DRUM |
| LEVELS 2 | HATOP | TOM | RIM | BELL | DRUM |
| STEREO | IMAGE | — | — | — | DRUM (todo el kit) |
| VOICE | VOICE | GLIDE | MODE | PRIO | todos los motores |

**GLO** (MIXER es por pista; GLOBAL y SYSTEM son globales)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| MIXER | LEVEL | PAN | REV | MUTE (derecha ON, izquierda OFF) |
| GLOBAL | BPM | SWING | CLOCK | TUNE |
| SYSTEM | TRACKS | LOAD | ROUTE | CPU (%) |

**SAVE**

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| PRESETS | No. (el sonido) | ENG (el motor) | FAV (marcar como favorito) | LIST (ALL / FAV) |
| USER | SLOT (U01–U32) | LOAD (acción) | ERASE (acción) | SAVE (acción) |
| PROJECT | PROJ (1–8) | SECT (A–D) | LOAD (acción) | SAVE (acción) |
| ARRANGE | ROW | SECT (en END: STOP / x2–x8 / LOOP) | BARS | SCENE |
| TOOLS | cualquier perilla o PRESETS elige de la lista: CLEAR SEQ, INIT SOUND, DELETE ROW, CLEAR SONG, NEW PROJECT, CPU TEST | | | |

**ARP** (por pista)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| ARP | MODE | RATE | OCT | GATE |
| ARP 2 | SWING | PROB | HOLD | ORDER |

**SEQ** (por pista)

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- | --- |
| STEP (melódica: piano roll) | STEP | NOTE | TIME (NOTE / TIE / REST) | FLAG (– / ACC / SLD / A+S) |
| STEP (DRUM: grilla) | STEP | LANE | HIT | ACC |
| PATTERN | LEN | DIV | SWING | GATE |
| NOTE | FOCUS | PITCH | MOVE | MICRO (−8/16 … +7/16) |
| STRETCH | STRETCH (/8 … /2, x1, x2 … x8) | REPEAT (OFF, x2 … x8, TO 64) | NUDGE | ROTATE (−32 … +32) |
| COMP | STEP | TYPE | (su valor; ARP: ORDER × RANGE) | EVERY (ARP: RATE; RATCH / ECHO: DIV) |
| COMP 2 | STEP | TYPE (el segundo componente) | (su valor) | EVERY |
| TRACK | PITCH | CHANCE | HUMAN | REC Q |
| PLAYHEADS | HEAD | RATE | DIR | INTERVAL |
| AUTOMATION | PLAY (ON/OFF) | EVENT (cantidad) | LOCK (cantidad) | CLEAR (acción) |
| AUTO LIST | ROW | STEP | PARAM | VALUE |
| MUTATE | SOUND (cada) | PATTERN (cada) | AMOUNT | MODE |

### Las capas (mantené el botón)

**FX — efectos punch-in** (detalles en [11](#11-tocar-en-vivo))

| Teclas | Efecto |
| --- | --- |
| F3 G3 A3 | REPEAT 1/8, 1/16, 1/32 |
| B3 / C4 | LPF / HPF |
| D4 / E4 | OCT− / OCT+ |
| F4 | 1/2 TEMPO |
| G4 / A4 | DEC− / DEC+ |
| B4 / C5 | STUTTER 1/8 / 1/16 |
| D5 | ATK+ |
| E5 | ARP |
| F5 | RANDOM |
| G5 | borra el carril de punch-in |
| Teclas negras 1–6 (F#3 G#3 A#3 C#4 D#4 F#4) | mutean T1–T6 mientras las mantenés |
| A#4 | a qué pistas afectan los efectos de nota: ALL / SYN / DRM |
| **Perillas** | FILTER, CRUSH, THROW, DEPTH |

**GLO — mezcla**

| Teclas | Acción |
| --- | --- |
| Teclas negras 1–6 | MUTE T1–T6 (enganchado: apretá de nuevo para desmutear) |
| Teclas negras 7–10 (G#4 A#4 C#5 D#5) | Mutes de grupo de DRUM-X: KICK, SNARE, HAT, PERC |
| F3–D4 | SOLO T1–T6 mientras las mantenés |
| E4 | desmutea todo (pistas y grupos de batería) |
| F4 | TAP tempo (desde el tercer toque; solo con clock interno) |
| G4 | **UNDO** (otra vez: rehacer) |
| PLAY | reinicia desde el principio |
| SELECT | tempo |
| **Perillas** | LEVEL T1–T4 (con T5 o T6 seleccionada: T3–T6) |

**SCL** — cualquier tecla fija la ROOT (tónica) en el nombre de su nota. Perillas: ROOT, SCALE, ROTATE, PITCH (las dos
últimas son el ROTATE de SEQ > STRETCH y el PITCH de SEQ > TRACK).

**EDIT** — F3 **INIT** (el sonido de la pista vuelve a los valores por defecto de su motor (un INIT limpio, no un preset), seco: todos los envíos a efectos
en 0; en FM6 la voz init, solo OP1 a nivel máximo; en DRUM, también el kit
DRUM-X de fábrica), G3 **RECALL** (el sonido tal como lo guardó la sección actual; en DRUM, con su kit). Los dos
preguntan antes y no tocan los pasos. En una pista DRUM, las teclas negras 1–8 mutean cada sonido de DRUM-X (BD SD CP
CH OH TM RS CB). Perillas: las cuatro de EDIT 1.

**SEQ TOOLS** (solo en STEP, NOTE, PATTERN, COMP, TRACK y AUTOMATION) — F3 CLEAR, G3 REVERSE, A3 / B3 SHIFT a la izquierda /
derecha, C4 RANDOM, D4 COOK, E4 BEAT (DRUM), F4 CLR AUTO (la automatización y los locks de la pista; los pasos quedan).
En una pista DRUM, las herramientas de carril: G4 CLR, A4 REV, B4 FILL, C5 RND sobre el carril elegido con las teclas
negras 1–8. **REC** (con SEQ mantenido): CLEAR ALL. Perillas: LEN, DIV, SWING, GATE. Estas herramientas no tienen
UNDO.

**REC** — F3 **CLEAR** borra los pasos y la automatización de la pista seleccionada (sin diálogo; UNDO lo puede
recuperar), G3 **CLICK** (OFF / REC / ON). KNOB 1: CLICK.

**SAVE — capa de tema** (detalles en [7](#7-arrange-canciones-secciones-y-escenas))

| Teclas | Acción |
| --- | --- |
| F3 G3 A3 B3 | tocar la sección A / B / C / D (en el compás siguiente si está sonando; al instante si está parado). Varias en una misma mantenida: una cadena rápida. |
| C4 D4 E4 F4 | STORE: guarda la música en A / B / C / D |
| D5 | LOOP / SONG: qué reproduce PLAY |
| E5 | SONG REC |
| G5 | ir a la página ARRANGE |
| OCT+ / OCT− | guardar en / recuperar la sección que está sonando |
| **KNOB 1** | el proyecto (1–8); se aplica al soltar SAVE, solo con el transporte parado |

**LFO — macros**: KNOB 1–4 son M1–M4. Soltá y quedan **enganchadas** (el encabezado dice [LFO] LATCH, y KNOB 1–4
siguen controlando las macros en todas las páginas) hasta que apretás LFO de nuevo. F3 tira rutas nuevas, G3 las
borra. (LFO + SELECT tira el LFO de la pista, con KEEP / CANCEL: ver los dados.)

---

## 4. Motores

Ocho motores, todos de síntesis, sin samples. Cualquier motor puede ir en cualquier pista. Elegilos con **PRESETS**
(una sola lista con todos los motores) o con KNOB 2 (ENG) en SAVE > PRESETS. También figuran las cuatro perillas de
HOME de cada pista.

**Cambios suaves**: pasar una pista a otro motor apaga el anterior de a poco (unos 12 ms) y lo que estés sosteniendo
(teclas, o las notas que sostiene el secuenciador) sigue en el motor nuevo, entrando de a poco; no se corta nada.
Cambiar un valor de lista (WAVE, CHIP, un tipo) mientras suenan notas hace una pequeña bajada (unos 3 ms) en vez de un
click; las notas siguen.

| Motor | EDIT 1 | EDIT 2 | Perillas de HOME |
| --- | --- | --- | --- |
| **ANALOG** | WAVE, DETUNE, MIX, NOISE | CUT, RES, DRIVE, INT | CUT, RES, ATK, REL |
| **FM6** | ALG, FB, MOD, RATIO | MEG, VMOD, DETUNE, SLOT | MOD, RATIO, MEG, SLOT |
| **PHASE** | WAVE, WAVE2, DCW, ENV | DETUNE, LINE, SUB, FB | DCW, ENV, DETUNE, REL |
| **LOFI** | CHIP, WAVE, DUTY, CRUSH | —, VIB, BEND, MASK | WAVE, DUTY, CRUSH, REL |
| **VOICE** | VOWEL, VOWEL2, TALK, SHIFT | BUZZ, BREATH, Q, RAND | VOWEL, BUZZ, BREATH, TALK |
| **WHEEL** | REG, SUB, BODY, TOP | PERC, CLICK, DRIVE, ROTOR | REG, PERC, DRIVE, ROTOR |
| **NOISE** | MODE, COLOR, FREQ, PEAK | TRK, DENSE, DRIFT, CRUSH | FREQ, PEAK, COLOR, REL |
| **DRUM** (DRUM-X) | MORPH, TUNE, TONE, DECAY | NOISE, FM ENV, FOLD, DRIVE | MORPH, TUNE, TONE, DECAY |

- **ANALOG**: dos osciladores. WAVE: SAW, SQR, TRI, SIN, PWM, SYNC, RING, SAW3. **INT** fija el intervalo del
  oscilador 2 (±24 semitonos). Su filtro es por voz.
- **FM6**: un motor FM de seis operadores (msfa, de Dexed), 32 algoritmos dibujados en pantalla, cuatro voces por
  pista. Las perillas de EDIT 1/2 son macros sobre el patch. **SLOT**: los patches de fábrica F1–F8, OWN (un patch
  editado o importado) y B1–B32 (un banco DX7 de 32 voces enviado desde el editor web; los slots vacíos se saltean).
  **OPERATOR / OP ENV / OPERATOR 2** editan cada uno de los seis operadores en el equipo (KNOB 1 elige el operador);
  editar convierte el patch en propio de la pista (SLOT OWN), y se guarda con el proyecto. Una voz del banco que
  elegís se copia a la pista, así que los proyectos la conservan aunque después mandes otro banco.
- **PHASE**: distorsión de fase. WAVE / WAVE2: SAW, SQR, PLS, DSIN, SPLS, RSAW, RTRI, RTRP. LINE: MIX o RING.
  **FB** realimenta la salida hacia la fase.
- **LOFI**: sonidos de chip. CHIP: 4BIT, 4B/2, 8BIT, 1BIT, STEP. WAVE: PLS, TRI, SAW, NOIS, WRAM, **BYTE**, **FLOAT**.
  - **BYTE** (bytebeat): KNOB 3 pasa a ser **ALGO** (32 fórmulas), KNOB 4 **VAR** (muta la fórmula); EDIT 2 pasa a
    ser **MOTION, GRIT, BEND, LOOP**. MOTION acelera o frena el ritmo de la fórmula (64 = tal como está escrita),
    GRIT es un reductor de frecuencia de muestreo, BEND pliega el tiempo, LOOP repite un tramo mínimo (con LOOP alto
    el ruido se vuelve una nota afinada).
  - **FLOAT** (floatbeat): CHIP pasa a ser la resolución (4BIT, 4B/2, FULL, 1BIT), KNOB 3 **ALGO** (32 fórmulas
    hechas de senos), KNOB 4 **VAR**; EDIT 2: **MOTION, FEEDBK, BEND, LOOP**. Mantené una tecla: la fórmula suena en
    esa tonalidad.
  - Página **RETRIG** (BYTE / FLOAT): **RTRG ON** reinicia la fórmula desde el principio en cada nota.
- **MORPH** (EDIT > MORPH, en ANALOG, PHASE y LOFI): la onda se desliza de forma continua hacia las siguientes (en
  ANALOG SAW > SQR > TRI > SIN, en PHASE hacia su forma siguiente, en LOFI hacia la onda siguiente hasta WRAM). 0 = la
  onda tal como la elegiste. En ANALOG y LOFI la modulación **SHAPE** también mueve el morph, así un LFO o una
  envolvente barren la onda. La página dibuja un ciclo de la onda resultante y dice qué dos ondas mezcla.
- **VOICE**: una voz por formantes (basada en klattsch): vocales, habla, aliento.
- **WHEEL**: un órgano de drawbars: registraciones (REG), percusión (PERC: OFF, 2ND, 3RD, 2SOFT, 3SOFT, 2SLOW,
  3SLOW), click de tecla, drive, ROTOR (OFF, SLOW, FAST).
- **NOISE**: ruido coloreado y metálico. MODE: ANLG, DUST, LFSR, META (DUST es solo el crepitar: con DENS en 0 igual crepita suave). PEAK es su propia resonancia.
- **DRUM**: DRUM-X, ver [5](#5-drum-x).

### FILTER (todos los motores)

EDIT > **FILTER**: **TYPE** LP, HP, BP o **COMB** (un filtro peine afinado a la nota que tocás; CUT lo mueve, RES es
cuánto resuena), **CUT**, **RES**, y KNOB 4: en ANALOG su propio DRIVE, en todos los demás motores el DIST de la
pista. En ANALOG el filtro es por voz; en LOFI la página de filtro maneja su filtro por voz; en los demás es un filtro
sobre la pista que sigue a LFO DEST / ENV DEST FILTER.

### VOICE (todos los motores)

EDIT > **VOICE**: **VOICE** POLY, MONO, LEG (legato), UNI (unísono); **GLIDE**; **MODE** RATE o TIME (cómo se mide el
glide); **PRIO** LAST, LOW, HIGH. Las seis pistas comparten un presupuesto de 8 voces; FM6 toca como máximo cuatro por
pista.

---

## 5. DRUM-X

DRUM-X es un kit sintetizado de ocho sonidos, **BD SD CP CH OH TM RS CB**, generados en tiempo real.

- (0.7.2) **Nueve kits como presets del motor DRUM**: DRUM-X (el kit de fábrica), 909 CLUB, 808 BOOM, LOFI DUST,
  INDUSTRIAL, ACOUSTIC, DUB ROOTS, TECHNO RAW, BREAKS. Recorrer uno (PRESETS en HOME, el editor, un PROGRAM CHANGE)
  carga el kit completo en la sección: los lados A y B de los ocho sonidos, sus LAYER y SEND, y las perillas KIT de la
  pista. Cambiar de motor, INIT SOUND, cargar un proyecto y GEN dejan el kit de la sección como está; DRUM-X devuelve el
  de fábrica. Editá cualquiera en EDIT > SOUND; la sección guarda el resultado.

- Cada sonido tiene dos lados, **A** y **B**. **MORPH** (KIT, KNOB 1, también en HOME) mueve todo el kit entre ellos:
  la perilla para tocar en vivo.
- Las páginas van **primero todo el kit, después un sonido, al final los volúmenes y el estéreo** (0.6.58):
  - **KIT** (EDIT 1): MORPH, TUNE, TONE, DECAY. **KIT 2** (EDIT 2): NOISE, **FM ENV** (FM golpeada con cada golpe que se
    va en pocos milisegundos: un parche, un click, un filo metálico en el ataque, la cola limpia), **FOLD** (un
    wavefolder después de la envolvente: ataque brillante, cola limpia), DRIVE.
  - **KIT 3**: **BP**, un pasa-banda sobre los sonidos de metal (hi-hats, rim, cowbell), OFF o 15 centros de 1,5 a 9 kHz
    aprox.; **FEEDBK**, el oscilador de cada sonido realimentado sobre sí mismo (OFF, 1–15: cálido, gruñido, arena,
    ruido).
  - **X-MOD**: **RATE** (OFF, 4BAR … 1/32, a tempo), **DEPTH** (cuánto oscila MORPH), **SHAPE** (SINE, TRI, SAW, RAMP,
    S&H), **RAND** (cada golpe con su propio MORPH y un poco de afinación).
  - **FILTER**: el del kit.
  - **SOUND 1–4**, un sonido cada una: la KNOB 1 es siempre **SOUND** (cuál; tocar una tecla también lo elige).
    - **SOUND**: SIDE (A / B), PITCH, PMOD (cuánto cae la afinación).
    - **SOUND 2**: DECAY, NOISE, COLOR, del lado elegido en SOUND (la KNOB 1 lo muestra: "SD B").
    - **SOUND 3**: **MODE** (onda SIN / FM / MTL / BEL, filtro de ruido LP / BP / HP, "+" para snap), **PM.TYPE** (cómo
      se mueve la afinación: DECAY, LONG, NOISE, SINE), **DRIVE** (ON / OFF).
    - **SOUND 4**: **LAYER** (OFF, 1–15): un segundo oscilador en un intervalo desafinado, modulado en frecuencia por el
      sonido, más cuanto más alto: de un filo metálico a un golpe sin nota, así el sonido se funde en el ritmo y no
      molesta a la armonía (el kit de fábrica lo tiene en redoblante, hi-hats y cowbell); **FEEDBK** (OFF, 1–15): el de
      ese sonido (se suma al de KIT 3); **SEND**: ese golpe solo hacia un efecto, OFF y después CHO, DLY, REV con 16
      cantidades cada uno, en una sola perilla ("REV 75%"), además de los envíos de la pista. Los dados (EDIT + SELECT en
      una pista DRUM, DICE ALL) mueven fuerte LAYER y FEEDBK. Cada sonido con LAYER usa un poco de CPU (como FEEDBK).
  - **LEVELS / LEVELS 2**: el nivel de cada sonido (KICK, SNARE, CLAP, HATCL, HATOP, TOM, RIM, BELL).
  - **STEREO**: **IMAGE** (automatizable) barre el kit por sus ubicaciones en el estéreo. 0 (MONO): todos al medio; los
    primeros pasos lo abren; desde ahí cada paso es otra ubicación (cada sonido por su propia curva), así que girala
    hasta que la imagen quede bien. El bombo queda cerca del medio. DRV, DIST y el FILTER trabajan sobre la suma del
    kit, así que con ellos la imagen se angosta (la página dibuja los sonidos en gris).
  - KIT 3, X-MOD, LAYER, FEEDBK y SEND se guardan con el kit de la sección.
- **Mutes**: GLO mantenido + teclas negras 7–10 mutean los grupos KICK, SNARE, HAT, PERC; EDIT mantenido + teclas
  negras 1–8 mutean cada sonido.
- **EDIT mantenido + SELECT** tira un kit nuevo alrededor del de fábrica. **EDIT mantenido + F3 (INIT)** trae de
  vuelta el kit de fábrica.

El kit se guarda con cada sección de un proyecto (no con los presets de usuario — ver [12](#12-guardar-y-cargar)).

---

## 6. El secuenciador

Cada pista tiene su propio patrón de **64 pasos** con su propio largo (LEN), división (DIV), swing y gate, así que
patrones de distinto largo giran unos contra otros.

### Escribir pasos

- **SEQ > STEP** en una pista melódica es un **piano roll**. KNOB 1 mueve el cursor de paso, KNOB 2 transpone el paso,
  KNOB 3 fija NOTE / TIE / REST, KNOB 4 fija acento / slide. Un paso guarda hasta cuatro notas.
  - **Duración de notas con KNOB 3**: un **TIE** se estira hacia atrás hasta la nota más cercana: los pasos vacíos del
    medio también pasan a ser TIEs (TIED 1-5), dentro de LEN y dando la vuelta al final. Una nota con el componente
    PULSE no se rellena.
  - Un **REST** sobre una nota (su NOTE o uno de sus TIEs) la corta ahí: los TIEs que siguen pasan a ser silencios
    (CUT AT 3) y pierden sus parameter locks. Si seguís girando de TIE a NOTE, es una nota nueva y los TIEs rellenados
    quedan; girar una NOTE pasando por TIE hasta REST borra esa nota y no rellena nada.
- **Grabación por pasos**: en STEP, con el transporte **parado**, apretá **REC** (la pantalla dice KEYS WRITE STEPS).
  Tocá una nota o un acorde: entra en el paso del cursor y, cuando soltás, el cursor avanza. Sin armar, las teclas
  solo suenan.
  - **Duración**: con las teclas apretadas, girá **KNOB 1**: la nota o el acorde dura esa cantidad de pasos (1–16,
    con ties). Se escribe cuando soltás y el cursor salta al final.
  - **Arpegio**: con las teclas apretadas, apretá **ARP**: el acorde se escribe arpegiado en el piano roll. KNOB 1 pasa
    a ser la resolución (1/16, 1/8, 1/8., 1/4: una nota cada 1–4 pasos), KNOB 2 el orden (UP, DOWN, UP-DN, RND) y
    KNOB 3 las octavas (1–3). La pantalla muestra lo elegido; al soltar se escribe y el cursor queda después. KNOB 4
    (y 2–3 sin ARP) sigue haciendo parameter locks en el paso.
- **EDIT** (toque) en STEP borra el paso del cursor; sobre una nota, también los TIEs que la siguen (como un REST en KNOB 3).
- En una pista **DRUM**, STEP es una **grilla**: las teclas blancas son los 16 pasos de la página, las teclas negras
  1–8 eligen el carril (y lo tocan), la tecla negra 9 mantenida es ACC (las teclas blancas entonces activan o
  desactivan acentos), las teclas negras 10 / 11 bajan / suben de página cuando LEN pasa de 16. Perillas: STEP,
  LANE, HIT, ACC.

### Grabación en vivo

Apretá **REC** en cualquier lado (no en STEP con el transporte parado): la pista queda armada y arranca el transporte.
Lo que tocás se graba en el patrón, cuantizado a sus pasos, en overdub. Los movimientos de perilla en la pista
seleccionada se graban como **automatización**. MENU > AUDIO tiene el **CLICK** (OFF / REC / ON), **CLICK LEVEL** y
**COUNT-IN** (OFF, 1 BAR, 2 BARS).

### Páginas de patrón

- **COMP** (step components, al estilo OP-Z): hasta dos por paso (**COMP** el primero, **COMP 2** el segundo, igual;
  0.6.82). KNOB 1 elige el paso, KNOB 2 su **TYPE**, KNOB 3 su valor, KNOB 4 **EVERY** (0.6.92; en COMP, el RATE de un
  ARP o el DIV de RATCH / ECHO van ahí en su lugar). La fila de arriba marca cada paso que tiene uno (naranja ARP,
  violeta TRIG, gris CHANCE, color del tema RATCH); abajo se dibuja el componente del paso (la escalera del arpegio con
  la nota que suena encendida; las vueltas del TRIG).
  - **CHANCE** (0–100 %) y **RATCH** (x1–x4): la probabilidad y el ratchet propios del paso (solo en COMP). El KNOB 4
    de RATCH es su **DIV**: STEP reparte los golpes en el paso (como antes); 1/2, 1/3, 1/4, 1/6, 1/8 los separa esa
    fracción de paso desde el inicio, los que entren (RATCH x3 a 1/8: tres golpes rápidos y después silencio).
  - **ARP NOTES / SEQ / SCALE**: el paso toca un arpegio y sigue sobre los ties que vienen después (su duración, el
    paso y sus ties). NOTES: las notas del paso, de grave a agudo; SEQ: la melodía del patrón, en el orden en que la
    toca el patrón (0.6.82; antes se ordenaba como NOTES); los dos sobre 1–4 octavas. SCALE: la escala hacia arriba
    desde la nota más grave del paso, 3, 5, 8 o 15 grados. KNOB 3 **ORDER** y rango en una sola lista (UP, DOWN, UP-DN,
    RND sobre 1 OCT, después sobre 2 OCT …; en SCALE 3, 5, 8, 15 DEG). KNOB 4 **RATE** (0.6.92), la velocidad del
    arpegio en tiempo musical: **x1** una nota por paso (el DIV de la pista, 1/16), **1/32** dos por paso, **1/32T**
    tres, **1/64** cuatro, **1/64T** seis, **1/128** ocho (la tarjeta dice la figura según el DIV de la pista; un DIV
    raro: xn). Los x2 … x8 de antes son los mismos valores.
  - **TRIG**: el paso suena solo en algunas vueltas del patrón: 1:2, 2:2, 1:3, 2:3, 3:3, 1:4 … 4:4, 1:8, FIRST, !1ST
    (todas menos la primera).
  - **RAND**: la nota sube o baja por la escala al azar, hasta RANGE grados (1–7).
  - **OCT**: una octava: +1, −1, +1 cada dos vueltas, −1 cada dos vueltas, ALT (arriba y abajo alternando), RND.
  - **TONAL**: desde este paso hasta el final de la vuelta todas las notas se mueven SHIFT grados (−7 a +7) por la escala.
  - **BEND**: la nota se desliza BEND semitonos (−12 a +12) durante el paso.
  - **ECHO**: el paso se repite x2–x8 en su duración, cada repetición más suave. KNOB 4 su **DIV**, como el de RATCH:
    STEP reparte las repeticiones en el paso, 1/2 … 1/8 fija cuán separadas van.
  - **PULSE**: la nota vuelve a sonar en los pasos vacíos que siguen, cada 1–4 pasos (EVERY), hasta la próxima nota.
  - **JUMP**: después de este paso el patrón sigue desde TO STEP.
  - **REV**: desde este paso el patrón vuelve hacia atrás hasta el paso 1 y después sigue hacia adelante (ping-pong).
    JUMP y REV giran el patrón en las vueltas que dice **EVERY** (abajo): EVERY 1:2 salta una vuelta sí y otra no,
    FIRST solo la primera vez (una intro), !FIRST todas menos la primera (0.6.92; antes era TIMES).
  - **FILL**: el paso suena solo mientras mantenés **FX**.
  - **KILL**: el paso primero corta todo lo que suena en la pista (releases largos, notas sostenidas) y después toca.
  - **WALK** y **CLIMB** (0.6.98, a la manera de los componentes evolutivos del OP-Z y el OP-XY): las notas del paso se
    mueven un grado de la escala (WALK) o una octava (CLIMB) **cada tantas vueltas** del patrón (KNOB 4: 1 … 10, 12,
    16 vueltas por movimiento), dentro de un **rango** (WALK 3, 5, 7 o 12 grados; CLIMB 1 … 4 octavas), y vuelven a
    empezar. KNOB 3 el **MODE** y el rango juntos: **UP** (0, 1, 2 … rango, 0 …), **DOWN**, **UP-DN** (ida y vuelta),
    **RND** (un lugar del rango por movimiento, el mismo en cada vuelta completa). Se apilan entre sí y con el resto:
    un WALK en COMP y un CLIMB en COMP 2 se suman, un TONAL o un OCT encima siguen valiendo, un ARP camina con su
    acorde. Cuatro notas con un WALK UP-DN 5 cada 2 vueltas y un CLIMB UP 1 cada 3 vuelven a sí mismas a las 36
    vueltas, distintas en cada pasada. Un kit de batería los ignora. La página dibuja los movimientos del rango, con el
    de esta vuelta encendido.
  - **Dos en un paso**: suenan los dos (un ECHO con un OCT: las repeticiones una octava arriba; un RAND con un OCT:
    los dos movimientos). Gana el que deja la nota en silencio: un **TRIG** o un **FILL** en cualquiera de los dos
    lugares decide primero si el paso suena. De dos que hacen lo mismo gana el primero (un ARP sobre un ECHO, dos ARP:
    el de COMP).
  - **EVERY** (0.6.92, KNOB 4 en COMP 2, y en COMP para todos los tipos menos ARP, RATCH y ECHO): en qué vueltas del
    patrón suenan los componentes del paso — **ALWAYS**; **1:2** (1ª, 3ª, … vuelta), **2:2** (2ª, 4ª, …); **1:3**,
    **2:3**, **3:3**; **1:4** … **4:4**; **1:8**; **FIRST** (solo la primera vuelta); **!FIRST** (todas menos la
    primera); **SKIP** al final de la perilla (se guarda pero no suena: un interruptor). Un solo valor por paso, para
    sus dos componentes, que se fija desde el KNOB 4 de COMP 2 sea cual sea su TYPE (o desde COMP, en los tipos que no
    usan esa perilla): un arpegio que entra cada cuatro compases es ARP en COMP (ORDER, RATE) y EVERY 4:4 en COMP 2.
    La nota propia del paso suena en todas las vueltas (eso lo decide un componente **TRIG**). Reemplaza a WHEN (esa
    página ya no existe), con su A / B leídos como uno solo.
  Los proyectos los guardan. **En un kit de batería** (0.6.83) también funcionan: OCT, RAND y TONAL afinan los golpes
  (RAND y TONAL en la escala de la pista), BEND dobla cada golpe durante el paso; ARP NOTES toca los sonidos del paso
  uno tras otro, SEQ los sonidos del patrón en el orden en que suenan, SCALE re-dispara los golpes del paso, cada parte
  un grado más arriba.
- **Un slide de acordes largo** (0.6.83): el glide hacia un acorde dura lo que dura ese acorde, con sus TIEs; GLIDE
  fija cuánto de ese tramo (127: todo). Un acorde sostenido con TIEs en pasos lentos (p. ej. DIV 1/4 a 120 BPM: diez
  pasos, 5 s) se desliza así de lento y suave; las notas nuevas aparecen a medida que se deslizan.
- **PATTERN** (la segunda página SEQ): LEN (1–64), DIV, SWING, GATE — el largo del patrón, la figura de su paso, su
  swing y la duración de todas las notas (la de un paso solo: el TIE de STEP, o MICRO para su entrada).
- **Mover una nota o un acorde** que entró antes o después: **NOTE**, KNOB 1 FOCUS en el paso, KNOB 3 **MOVE** lo
  corre de a un paso a los costados (FOCUS ALL: el acorde entero con sus TIE; una nota enfocada: esa sola).
- **STRETCH** (0.6.85, después de NOTE): cambia la forma de toda la secuencia de la pista elegida **mientras girás la
  perilla** (0.6.92; antes esperaba OCT+). Cada giro parte de la secuencia como estaba antes del primero (su base), así
  que x2 y después x4 es x4, no x8, y volver al medio es volver a donde empezaste; el cartel dice el LEN antes y
  después (LEN 4 > 16); **UNDO** (GLO + G4) lo deshace; si editás el resultado, pasa a ser la nueva base. La otra
  perilla toma el resultado como su base (0.6.96): REPEAT x2 y después STRETCH x2 estira las repeticiones.
  - **KNOB 1 STRETCH**: **x2 … x8** separa los pasos esa cantidad de veces (LEN 4 x4: 16); una nota sostenida sigue
    sostenida y las cortas quedan cortas; pasados los 64 pasos se corta el final. **/2 … /8** la comprime: de cada
    grupo de pasos queda el primero que suena (LEN 32 /2: 16). **x1** en el medio: como estaba. La automatización y los
    locks se mueven con sus pasos.
  - **KNOB 2 REPEAT**: copia los pasos 1..LEN detrás de sí mismos, **x2 … x8** veces o **TO 64** (todas las copias
    enteras que entren), con automatización y locks; **OFF** a la izquierda: como estaba. Cuatro notas pasan a ser una
    base de 64 pasos sobre la que grabar más notas (REC en vivo suma encima).
  - **KNOB 3 NUDGE**: toda la secuencia un paso a la derecha / izquierda, dando la vuelta dentro de LEN (como TOOLS
    A3 / B3).
  - **KNOB 4 ROTATE** (−32 … +32; era el OFFSET de SHIFT): la secuencia leída desde otro paso, sin mover los pasos —
    una rotación en vivo, automatizable (también en el KNOB 3 de la capa SCL).
- **MICRO** (0.6.92, KNOB 4 de NOTE; era el OFFSET de la página TIMING): el lugar propio del paso enfocado fuera de la
  grilla, en dieciseisavos de paso, de −8/16 (medio paso antes) a +7/16 (después); **EDIT** lo devuelve a la grilla.
  Los pasos adelantados suenan realmente antes: el paso anterior termina antes y la grilla se mantiene. El piano roll
  dibuja las notas donde suenan. Un acorde comparte el offset de su paso; mover, estirar o repetir pasos lo conserva;
  se guarda con el proyecto. **REC Q** (KNOB 4 de TRACK) es la cuantización de grabación que lo escribe: en 100 % (por
  defecto) la grabación en vivo se ajusta a la grilla; más abajo, el paso guarda esa parte de dónde lo tocaste (0 %:
  todo), antes o después.
- **TRACK** (0.6.92; era SHIFT + HUMAN): los ajustes de toda la pista. **PITCH** (±24 semitonos; no en baterías).
  **CHANCE**: la probabilidad de toda la pista; 100 % toca cada paso como está escrito, menos lo va raleando (escala la
  probabilidad propia de cada paso, la de los dados o el editor). **HUMAN** (una sola cantidad, 0–100 %): la pista
  toca como una persona, cada nota un poco distinta en cada vuelta, con los pasos como están escritos — su velocity
  sube o baja al azar (hasta ±50 al 100 %), entra un poco tarde (hasta 40 ms, nunca más de un tercio del paso, nunca
  antes; las notas de un acorde siguen juntas y un STRUM mantiene su separación), dura más o menos (hasta ±40 %) y el
  DECAY y el RELEASE de su envolvente se alargan o acortan un poco (hasta ±20). En 0 % toca exactamente lo escrito
  (por defecto). Se mantiene al cambiar el sonido; se puede automatizar. Un proyecto guardado con los viejos VEL / TIME
  / GATE carga con el menor de los tres como HUMAN. **REC Q**: ver MICRO. El viejo **C.LEN** (los componentes como un
  carril con su propio largo) ya no existe: los componentes viven en sus pasos y EVERY dice cada cuánto suenan.
- **AUTOMATION**: PLAY activa o desactiva la automatización de la pista, EVENT y LOCK cuentan los registros, CLEAR
  los borra (OCT+, con diálogo). La automatización es lo que grabás girando una perilla con REC encendido mientras la
  pista suena (un valor que se mueve a lo largo del patrón), más los parameter locks (un valor por paso, ver abajo):
  esta página muestra cuántos de cada uno tiene la pista y si suenan; la pista de ayuda de la página lo dice. En AUTO
  LIST se ven y se editan uno por uno.
- **AUTO LIST**: cada evento de automatización y cada lock en forma de lista. KNOB 1 la fila, 2 el paso, 3 el
  parámetro, 4 el valor. En **+ ADD LOCK**, OCT+ agrega un lock; sobre un registro, OCT+ lo alterna entre LOCK y AUTO;
  **EDIT** lo borra.
- **MUTATE**: la pista cambia sola, sincronizada con el clock, para que una textura evolucione durante minutos.
  **SOUND** y **PATTERN**: cada OFF, 1, 2, 4, 8, 16 o 32 compases (el cambio cae en el 1 del compás). **AMOUNT**:
  cuánto (al activar uno queda en 50 %). La página (0.6.92) muestra los próximos 32 compases de la pista elegida como
  una sola tira, una marca en cada compás donde cae un cambio (naranja: SOUND, violeta: PATTERN), el cabezal encima y
  una línea que dice qué hace cada perilla. **MODE**: **ORBIT** varía alrededor del ancla (la música como estaba al
  activar MUTATE, al dar PLAY, cuando apretás **OCT+** acá: KEEP, o cuando escribiste o borraste pasos por última
  vez), así nunca pierde su identidad y una secuencia que borrás queda borrada; MUTATE nunca llena un patrón vacío; **DRIFT** sigue desde
  como está ahora. SOUND cambia los valores del motor, el filtro, su envolvente, DEC, REL y los envíos (nunca LEVEL, PAN
  ni MUTE); PATTERN mueve notas por la escala, cambia acentos, agrega o saca una nota fuera del tiempo (nunca en el
  tiempo); en DRUM cambia golpes, nunca el bombo. **OCT−** acá (o **GLO + A4**, FREEZE) frena todas las mutaciones
  hasta volver a apretarlo. En HOME cada bichito tiene un anillo de puntos que se llena hasta su próximo cambio y se
  enciende entero cuando cambia.
- **PLAYHEADS** (SEQ, página 8; antes FUGUE), a la Fugue Machine: tres **cabezales** más (2, 3 y 4) leen los mismos pasos que el
  secuenciador de la pista. KNOB 1 **HEAD** elige uno, KNOB 2 **RATE** (OFF, 1/4, 1/3, 1/2, 2/3, x1, 3/2, x2, x3, x4 del
  de la pista), KNOB 3 **DIR** (FWD, REV, PING, RND), KNOB 4 **INTVL**, su intervalo en grados de la escala (−14 a +14; una
  pista de batería mantiene sus carriles). Un cabezal toca las notas de cada paso con su velocidad, acento y probabilidad
  y el GATE de la pista (sin components, locks ni ratchets: esos son del secuenciador): cánones, contrapunto, patrones
  que se desfasan consigo mismos. La página dibuja los pasos, el cabezal del secuenciador y dónde va cada cabezal. Se
  guarda con la sección; los cabezales arrancan y paran con el transporte.

### Parameter locks

En **SEQ > STEP**, **mantené un paso** (una tecla de la grilla, o la nota que estás entrando en el roll) y girá una
perilla: ese paso recibe su propio valor del parámetro que esa perilla edita en la última página de sonido que
visitaste. Tocá EDIT mientras mantenés el paso para borrar sus locks. Los eventos de automatización y los locks
comparten **64 registros por sección** (todas las pistas juntas); cuando se acaban, la pantalla dice
**AUTOMATION FULL**.

### Escala

**ROOT, SCALE y QUANT son globales**: una sola escala para todo el tema. En la pista que sea que los fijes (perilla,
capa SCL, MIDI, la carga de un proyecto), todas las pistas melódicas la siguen al instante; las pistas de batería no
tienen. Cada pista conserva su propio TRANS.

- SCALE: CHR, MAJ, MIN, DOR, MIX, PEN, MPEN, HARM, PHRY, LYD, LOC, MEL, BLUES, WHOLE, DIMHW, DIMWH.
- QUANT: OFF; SNAP (las teclas se ajustan a la escala); WHITE (las teclas blancas recorren la escala, las negras no
  suenan); SEQ (como SNAP, y además las notas del secuenciador se ajustan mientras suenan).
- **SCL 2 > ALL TR** (antes se llamaba STRN) mueve todas las secuencias hacia arriba o hacia abajo por la escala (±14
  grados), en todas las pistas a la vez. Es global y se guarda con el proyecto: si tus notas suenan más graves o más
  agudas de lo que muestra el piano roll, fijate acá. Cuando no está en 0 el piano roll muestra **ALL TR** y su valor, y
  al dar PLAY también lo avisa. 0 = apagado.
- La reverb RESO y los pasos de afinación del SLICER también siguen la escala.

### CHORD (0.6.81)

**SCL > CHORD** hace que una tecla toque un acorde en la pista (inspirado en el Omnichord y el Orchid):

- **CHORD**: OFF; en la escala (todos los acordes afinados, sin pensar): **TRIAD**, **7TH**, **ADD9**, **SUS2**,
  **SUS4**, armados sobre el grado de la tecla (una tecla fuera de la escala toma la nota de la escala de abajo; CHR: la
  escala mayor de ROOT); formas en cualquier tecla: **MAJ**, **MIN**, **7**, **MAJ7**, **MIN7**, **POWER**.
- **VOICING**: CLOSE (posición fundamental); **LEAD** (cada acorde toma la inversión más cercana al anterior: el voice
  leading, la suavidad del Orchid); OPEN (la segunda nota una octava arriba); +BASS (suma la fundamental una octava
  abajo).
- **STRUM**: 0 todas a la vez; desde ahí, las notas entran una tras otra de grave a agudo (hasta ~63 ms entre ellas),
  como un arpa.

Al soltar la tecla terminan todas las notas del acorde (las que faltaban del strum ya no entran). El acorde se graba en
el paso, en vivo y en la grabación por pasos (0.6.83: la grabación por pasos tomaba solo la nota de la tecla), y el ARP
lo arpegia. Se encienden las teclas de todas las notas que suenan, la forma completa del acorde también: sirve para ver
y aprender los acordes. Con **STRUM** (0.6.84) un acorde grabado entra entero en el paso donde bajaste la tecla (sus
notas siguientes ya no se van al paso de al lado), y el secuenciador rasguea cada paso con acorde de la misma manera,
de grave a agudo (dentro de la mitad del gate del paso). STRUM en 0: los acordes de los pasos como antes, todos juntos. Una pista de batería, MONO, LEGATO y UNISON tocan solo la fundamental. Las notas MIDI
suenan tal cual llegan.

### ARP

ARP: MODE, RATE, OCT (1–4), GATE. ARP 2: SWING, PROB, HOLD, ORDER (NOTE / PLAY). Modos: OFF, UP, DN, UPDN, RND, ORD,
REPEAT, DNUP, UP+8, CONV, DIVG, PINKY, THUMB, WALK, CHORD, **TRNS** (las teclas y el MIDI entrante transponen la
secuencia de la pista según su distancia a C4, sin tocar notas). **Latch de teclas**: con MODE OFF, **HOLD ON** deja
las notas sonando después de soltarlas; el acorde siguiente las reemplaza.

### Borrar

| Para borrar | Hacé |
| --- | --- |
| Los pasos y la automatización de la pista seleccionada | **REC mantenido + F3**, o SAVE > TOOLS > CLEAR SEQ, o SEQ TOOLS F3 |
| Los pasos y la automatización de las seis pistas, y el carril de punch-in | **SEQ mantenido + REC**, después OCT+ |
| **Todo** (NEW PROJECT): cada pista con el sonido por defecto de su motor (seco, FM6 con la voz init), sin pasos ni automatización; mezcla, efectos, tempo y SLICER por defecto; el arreglo vacío, las macros en 0, el kit DRUM-X de fábrica. Quedan los proyectos guardados, los presets de usuario, el MENU, CLOCK, TUNE y MIDI | **MENU > SYSTEM > INIT SYSTEM** o **SAVE > TOOLS > 5 NEW PROJECT**, después OCT+ (UNDO devuelve la música) |
| *(no borra)* Una canción de prueba pesada, para medir la CPU en el equipo y escuchar si hay clics (cada pista viva con acordes de cuatro notas, dos componentes por paso y glides largos, el kit con todos los carriles, todos los FX, 160 BPM) | **SAVE > TOOLS > 6 CPU TEST**, OCT+, después PLAY (UNDO devuelve tu música) |
| Solo la automatización de una parte en la pista seleccionada | **REC mantenido + FX / EDIT / ENV / LFO / SCL / ARP / GLO** |
| La automatización de la pista, conservando los pasos | SEQ TOOLS **F4 CLR AUTO**, o SEQ > AUTOMATION > CLEAR |

Al borrar una pista aparece **T3 CLEARED** con **SEQ+REC: ALL TRACKS** debajo, como recordatorio de la combinación
para todas las pistas.

---

## 7. ARRANGE: canciones, secciones y escenas

### Las piezas

- Un **proyecto** es un tema. Hay **8 proyectos**.
- Cada proyecto tiene **4 secciones, A–D**. Una sección es una foto completa de la música: el sonido, los pasos y la
  automatización de cada pista, el kit DRUM-X y sus mutes, el carril de punch-in, el SLICER, las macros, más el tempo
  y los efectos globales.
- Cada proyecto tiene un **arreglo**: hasta **16 filas**, cada una una sección que suena durante **1–64 compases**,
  opcionalmente con una **escena**, y una regla de **END** (final).

Son 32 secciones en total (8 × 4).

### La página ARRANGE (SAVE > ARRANGE)

El tema como una columna de filas. Cada fila muestra el chip de su sección (A–D, cada una con su color), sus compases
como bloques que se llenan a medida que suenan, su cantidad de compases y un punto si tiene escena. Una fila que apunta
a una sección sin nada guardado dice **EMPTY**. Debajo de las filas: **+ ADD** (con cuántas de las 16 filas están en
uso) y **END**. A la derecha, todo el tema como una sola tira con el cabezal de reproducción, y el total de compases.

| Perilla | Sobre una fila | Sobre + ADD | Sobre END |
| --- | --- | --- | --- |
| KNOB 1 (o PRESETS) | elige la fila | | |
| KNOB 2 | su sección A–D; girada a la izquierda más allá de A: **DELETE SONG ROW?** | agrega una fila (misma sección que la fila de arriba, 1 compás) | **STOP**, **x2 … x8**, **LOOP** |
| KNOB 3 | sus compases (1–64) | agrega una fila | |
| KNOB 4 | derecha: guarda una **escena** (SCENE STORED); izquierda: la borra | | |

- **PLAY** (u OCT+) en ARRANGE reproduce el tema desde el principio; otra vez: para.
- Cuando el tema termina (o lo parás), vuelve la música que tenías antes de apretar PLAY (SONG END).
- END: **STOP** reproduce el tema una vez, **x2–x8** esa cantidad de veces, **LOOP** para siempre.
- Si una fila apunta a una sección vacía, el tema no arranca: la pantalla dice **PATTERN A EMPTY** (o B, C, D).
- Mientras suena un tema, la edición de pasos está bloqueada (**STOP TO EDIT**).
- Para borrar una fila también podés usar SAVE > TOOLS > DELETE ROW (la fila que tiene seleccionada ARRANGE). Para
  borrar todo el arreglo: TOOLS > CLEAR SONG (**CLEAR SONG ORDER?**). Ninguna de las dos cosas se puede deshacer.
- El arreglo se guarda automáticamente (unos 2 segundos después de un cambio, con el transporte parado). Ver
  [12](#12-guardar-y-cargar).

### Escenas

Una escena se guarda por fila y, cuando esa fila arranca, recupera: los mutes de pista (T1–T6), los mutes de grupo de
DRUM-X, las macros M1–M4 y los efectos de nota punch-in que estén mantenidos. Sigue vigente durante las filas
siguientes que no tengan escena. Las escenas se aplican cuando suena un tema, no en una cadena rápida. SONG REC también
guarda una por fila a medida que empieza cada una.

### Tocar secciones en vivo (capa SAVE)

Mantené **SAVE**:

- **F3–B3**: tocar la sección A–D. Si está sonando, entra en el **compás siguiente**; si está parado, se carga al
  instante.
- Tocá **dos o más** de F3–B3 en una misma mantenida: una **cadena rápida** — suenan por turno, cada una durante el
  largo de su patrón más largo, una y otra vez, empezando en el compás siguiente (parado: al instante).
- **C4–F4**: **guardar** la música actual en A–D (funciona mientras suena; ver [12](#12-guardar-y-cargar) para saber
  cuándo llega a la flash).
- **OCT+**: guardar en la sección que está sonando (PLAY A SECTION FIRST si no hay ninguna). **OCT−**: recuperarla tal
  como quedó guardada.
- **D5**: **LOOP / SONG** — en modo SONG, PLAY desde cualquier página reproduce el arreglo.
- **E5**: **SONG REC** — las secciones que tocás en vivo (y sus compases) se escriben en las filas del arreglo, con
  una escena cada una. Reemplaza las filas actuales.
- **G5**: saltar a ARRANGE.
- **KNOB 1**: elegir otro proyecto; cambia al soltar SAVE (solo parado) y **carga su sección A**.

---

## 8. Dados y UNDO

### GEN — el generador de temas (HOME + SELECT)

En **HOME**, girá **SELECT** (o mantené HOME y girá SELECT, desde cualquier página). Se abre la pantalla
**GENERATOR**: tres páginas de ajustes, **SELECT** cambia de página, **KNOB 1–4** fijan los cuatro valores que se
ven, **OCT+** arma la pieza y **HOME** (u OCT−) cierra la pantalla (la pieza queda; **UNDO**, GLO + G4, devuelve lo que había
antes). **PLAY** arranca y para el transporte sin salir de la pantalla (0.6.97).

| Página | KNOB 1 | KNOB 2 | KNOB 3 | KNOB 4 |
|---|---|---|---|---|
| 1/3 | **GENRE**: RANDOM (la pantalla abre ahí; la mitad de sus tiradas son mutantes de dos géneros, con nombre A+B) o uno de 43 | **SEED** 0000–9999 | **ENERGY** 0–100 % | **FORM**: LOOP, PARTS, SONG |
| 2/3 | **DRUMS** | **BASS** | **CHORDS** | **ARP** — cada uno OFF, 10–100 %, o **AUTO** (lo que pide el género) |
| 3/3 | **LEAD** (igual) | **COMPLEX** 0–100 % | **SWING** AUTO o 0–100 % | **HUMAN** 0–100 % |

La pieza es **determinista**: los mismos ajustes dan siempre la misma pieza, así que una semilla que te gustó se
puede volver a marcar. **OCT+ con los ajustes sin tocar tira una semilla nueva** (otra pieza); girá una perilla y
apretá OCT+ y tenés **la misma pieza con esa sola cosa cambiada**: cada parte saca sus números al azar de su propio
flujo, así que mover BASS deja la batería y el lead como estaban. La pantalla muestra **LAST: HOUSE 0421** (el género
y la semilla).

Los géneros: HOUSE, DEEP HOUSE, MICRO HOUSE, TECH HOUSE, ACID HOUSE, TECHNO, DETROIT, DUB TECHNO, HARD TECHNO,
HYPNOTIC, TRANCE, ELECTRO, EBM, ITALO, SYNTH POP, DARKWAVE, POST PUNK, TRIBAL PUNK, MINIMAL SYNTH, MAN MACHINE,
MOTORIK, INDIE, SHOEGAZE, POST ROCK, FUNK, DISCO, BOOM BAP, TRAP, UK GARAGE, DUBSTEP, BREAKS, DRUM & BASS, DUB,
STEPPERS, JAZZ, BOSSA, AFROBEAT, AMBIENT, NEO CLASSIC, IMPRESSION, SOUNDTRACK, IDM, BROKEN. Cada uno sabe su rango de
tempo, sus escalas y progresiones, su mapa de batería y su kit, sus arquetipos de bajo y su registro, cómo hablan sus
acordes, su arpegio y su lead, qué receta de sonido toma cada rol, qué tan humano toca y su espacio (tipo de reverb,
tipo y tiempo del delay, cuánta humedad).

De qué está hecha una pieza:

- **Batería** a partir de un **mapa de prioridades** (como el Grids de Mutable Instruments): cada paso de cada carril
  tiene un nivel, y suena donde el nivel supera la densidad que fija DRUMS; al bajarla se van primero los ghosts y al
  final las anclas del bombo. Después los ghost notes del redoblante en las mejores posiciones (primero la
  semicorchea antes del 2 y del 4), la célula de acentos de los hats (house, funk, garage, máquina), una pequeña
  variación en los compases pares (COMPLEX), el **fill** del género en el último compás de la frase (redoble, corrida
  de toms, el bombo que se va, redoble de hats, fill lineal de funk, los bombos en semicorcheas de Blue Monday, un rim
  de dub, un corte antes del uno) y el redoblante atrasado donde el género toca atrás (TIMING). ENERGY y las
  cantidades deciden cuánto suena; el bombo nunca se cae del uno.
- **Bajo** a partir de unos cincuenta **arquetipos escritos contra el bombo**: offbeat y bounce de house, walking de
  semicorcheas deep, semicorcheas rodantes y rebote de octava de techno, Detroit, EBM, italo, psy, UK garage,
  Jamerson, alrededor del bombo, on the one, slap, Good Times, walking y two-feel de jazz, boogie, country, ska,
  tumbao, bossa, corcheas de rock, semicorcheas punk, McCartney, Peter Hook, motorik, post punk angular, indie, one
  drop, steppers, rockers, dub, boom bap, 808 de trap, DnB, jungle, wobble, pedal, quintas, Suicide, Kraftwerk; y
  **acid** con las reglas de la 303 (acentos en 3–5 pasos, slides en 2–3, un salto de octava después de un slide, los
  acentos variando por compás). La raíz en cada cambio de acorde, aproximaciones por semitono a la raíz siguiente, un
  pickup al final del cuarto compás; el bombo **doblado**, **respondido** (el bajo no pisa los pasos del bombo),
  **entrelazado** (y una nota justo después) o sostenido debajo, según el género.
- **Acordes** a partir de progresiones con una **calidad** por acorde — séptimas, novenas, add9, sus2, sus4, sextas,
  cuartas, power chords, la tercera subida de la dominante en menor —, recoloreadas por el género (tríadas simples,
  ricas, suspendidas, cuartales, power, paralelas), **voiceadas en C3..G5 y enlazadas a la voz más cercana** (o
  movidas en paralelo: techno, impresionismo), tocadas sostenidas, creciendo, en stabs a contratiempo, pulsadas,
  dubeadas por el delay, en skank, comping, con empuje, como drone, escasas, broken (UK garage) o con gate de trance.
- **Arpegio**: un orden sobre el acorde voiceado — arriba, arriba y abajo, abajo, Alberti, los grupos de Glass, un
  pulso de Reich, un secuenciador, una caminata, ciclos de 3 o 5 contra el compás (polimetría), un gate de trance,
  octavas — en semicorcheas o corcheas, con huecos (ARP), en C3..C5.
- **Lead**: un **motivo** de un compás (sus ataques sorteados por la métrica, su contorno por los pesos de la
  tonalidad — la tónica, la quinta y la tercera más probables —, un salto compensado por un paso, notas del acorde en
  los tiempos fuertes) en una **frase** de cuatro compases (A A A A', A A' A A'', A silencio A A', A A silencio A'),
  variada por un operador por compás (el final movido, la última nota omitida, una tercera arriba o un paso abajo,
  una nota de paso); o un ostinato hipnótico sobre un euclidiano, notas largas, una línea tintinnabuli, una figura de
  máquina, un hook de dos compases (llamada y respuesta). Nunca una segunda menor ni un tritono contra el bajo; nunca
  por encima de G5; los agudos más suaves.
- **Sonidos** por **receta** según el rol: sub, acid, Reese, bajo FM, bajo de rock, el bajo con chorus de Hook, wow
  bass; pad, cuerdas, coro, órgano (WHEEL), piano eléctrico, stab, acorde de dub, pluck, campana, lead, lead vocal,
  chip, teclas, drone, ruido, textura, hoover, un muro shoegaze, una guitarra con trémolo. Una receta elige un motor,
  un sonido de fábrica cuyo nombre encaja, mueve un poco sus parámetros, da forma a la envolvente, al filtro (tipo,
  corte, resonancia, la envolvente sobre él), un LFO lento, saturación, chorus, glide, el modo de voz. El **kit** es
  uno de siete (909, 808, click, industrial, suave, dub, breaks) escrito sobre el kit DRUM-X de fábrica, con el TONE,
  DECAY, NOISE y DRIVE de la pista de batería.
- **Mezcla**: nivel, paneo y envíos por rol y según la humedad del género; **HUMAN** fija el HUMAN de SEQ > TRACK en cada pista
  según el rol (hats y leads más, el bombo nada) escalado por qué tan humano es el género (una banda más que una
  máquina); SWING el del género salvo que lo fijes; DUCK, CLIP y PUNCH en el master; el TYPE, PING-PONG y TIME del
  delay y el tipo de reverb, los del género.
- Con **TRACKS 6** la sexta pista es una **textura** (un drone, ruido, un coro, un órgano, cuerdas) en notas largas.
- **FORM**: **LOOP** escribe un loop (2 o 4 compases). **PARTS** además guarda las secciones **A** (la pieza), **B**
  (un break: sin batería ni bajo) y **C** (un drop: la batería más densa) y llena ARRANGE con A B A C (PLAY toca el
  tema, como hacía el DICE ALL de 0.6.81). **SONG** escribe una forma de club: **A** el drop, **B** la intro (batería y
  bajo), **C** el build (entran los acordes, su filtro se abre a lo largo del loop, un redoble al final, el delay
  lanzado en el último paso) y **D** el break (sin batería ni bajo, los acordes más húmedos), en ARRANGE como
  B C A D C A con filas de 16 compases (el drop 32). Los géneros ambient y post-rock reciben un arco (fino, entra,
  ápice). Las secciones tuyas (guardadas por vos, no por GEN) nunca se pisan: entonces la pieza queda en un loop.

Cada pieza reemplaza los pasos, sonidos, kit, mezcla y automatización de todas las pistas. Los mutes quedan como
estaban. Los roles que suenan van en las primeras pistas (la batería en la pista DRUM), así que con TRACKS 4 escuchás
los más importantes.

### Dados de sonido (EDIT + SELECT)

Mantené **EDIT** y girá SELECT (desde cualquier página): la pista seleccionada carga un preset de fábrica al azar de su motor y cada
parámetro del motor se mueve hasta un cuarto de su rango. En DRUM, los dos lados de cada sonido del kit se tiran
alrededor del kit de fábrica. Lo escuchás al instante bajo **KEEP DICED SOUND?** (DRUM: **KEEP DICED KIT?**): girá
SELECT otra vez para otra tirada, **OCT+ OK** la deja, **OCT− CANCEL** devuelve el sonido que tenías antes de la
primera tirada (solo el sonido de esa pista: la música sigue). Después de OK, **GLO mantenido + G4** también lo deshace.

### Dados de secuencia, LFO y FX (SEQ / LFO / FX + SELECT)

La misma idea para las otras partes de la pista seleccionada, cada una se escucha al instante bajo su diálogo **KEEP
DICED …?** (SELECT otra vez: otra tirada, **OCT+ OK** la deja, **OCT− CANCEL** devuelve lo que había, el resto sigue
sonando):

- **SEQ + SELECT**: una secuencia nueva como escribe una parte DICE ALL, en la escala de la pista: un beat en una pista
  DRUM; si no, el rol al que suenan sus pasos (notas graves: un bajo, acordes: un pad, si no una lead o un arpegio). Su
  sonido, su mezcla y su automatización quedan.
- **LFO + SELECT**: el LFO de la pista: un rate en el medio del rango, cualquier onda y fase, a veces un fade, apuntado
  sobre todo al filtro, un poco a la forma, rara vez al pitch o al volumen.
- **FX + SELECT**: el drive de la pista (la mitad de las veces nada), sus envíos de chorus, delay y reverb, un AUTO PAN
  una vez de cada tres, y el tipo, tamaño y damping del reverb compartido y el tiempo y feedback del delay (con pitch una
  vez de cada cinco).

### Dados de macros

Con las macros abiertas (LFO mantenido) o enganchadas: **F3** tira rutas de macro nuevas en las pistas que están
sonando; G3 las borra. Ver [10](#10-modulación-y-macros).

### UNDO (GLO mantenido + G4)

Un paso atrás sobre el **último cambio grande**. Apretarlo otra vez va hacia adelante (rehacer). El transporte sigue
sonando. G4 "respira" en el mapa de GLO cuando hay algo para deshacer; si no hay nada, dice **NOTHING TO UNDO**.

**UNDO cubre**: DICE ALL, un sonido tirado a los dados, una pista borrada (REC F3, TOOLS CLEAR SEQ), CLEAR ALL
SEQUENCES (SEQ + REC), NEW PROJECT, INIT y RECALL (capa EDIT o TOOLS), borrar la automatización
(SEQ > AUTOMATION) y una sección cargada con **SAVE > PROJECT > LOAD**. Restaura la música tal como estaba: sonidos,
pasos, automatización, el kit, el carril de punch-in, las macros, el tempo y los efectos globales.

**UNDO no cubre**: saltos de sección, cadenas rápidas y RECALL desde la capa SAVE, cambiar de proyecto con KNOB 1 de
la capa SAVE, CLEAR SONG, borrar una fila, SONG REC, nada de lo guardado (secciones, presets de usuario), cargas de
presets de usuario, sonidos elegidos con PRESETS, acciones de SEQ TOOLS, ni giros comunes de perilla. No está
disponible mientras suena un tema (**STOP TO EDIT**). Guarda un solo paso, en RAM: se pierde al apagar.

---

## 9. Efectos y master

### Por pista

- **FX**: cantidad de DIST y los tres envíos (CHORUS, DLY, REV).
- **DIST**: cantidad, **TYPE** (SOFT, HARD, FOLD, CRUSH, RECT), **TONE** (más oscuro / más brillante).
- **AUTO PAN**: el paneo de la pista oscilando a izquierda y derecha alrededor de su PAN. **DEPTH** (0 = apagado),
  **RATE**, **SYNC** (BEAT: RATE en divisiones 4BAR … 1/32, sincronizado al compás; FREE: RATE en Hz), **WAVE** (SIN,
  TRI, SAW, SQR, S&H).
- **FILTER**: ver [4](#4-motores).

### SLICER (uno solo, en un bus)

- **SLICER**: **MODE** OFF, GATE, STUT; **PAT** 1–16; **RATE** 1/8 … 32T; **DEPTH**.
- **SL BUS / SL BUS 2**: ON / OFF para lo que entra: **T1–T6** y **FX** (los retornos de delay, reverb y chorus).
  Con todo en ON corta toda la mezcla después de los efectos; con FX en OFF las colas suenan libres.
- **SL PITCH**: las repeticiones siguen una secuencia de afinación de 16 pasos (±24 semitonos). KNOB 1 el paso,
  KNOB 2 su afinación, LEN, QUANT (CHR o SCL: la escala del tema).
- Cada sección conserva su propia configuración del SLICER. Con **LOAD ECO** no hay SLICER (sus pistas van directo a
  la mezcla).

### Delay

- **DLY**: **TIME** (divisiones sincronizadas 4BAR … 1/32, o tiempos libres de 5 ms a 1,48 s), **FEEDBK**, **TONE**
  (por debajo del centro más oscuro, por encima más fino), **MIX**. FEEDBK se comporta como el de un delay analógico
  (una cinta, un PT2399; 0.6.86, 0.6.89): con **TONE al centro (50 %)** cada repetición es una copia de lo que entró;
  en **100 %** los ecos mantienen su volumen mucho tiempo (bajan muy de a poco y nunca se cortan), y **pasado 100 %**
  se realimentan y se sostienen, saturando suave en vez de recortar (bajalo para que se apaguen). Hasta 80 % es igual
  que antes. **TONE** es resonante: del centro hacia abajo un pasabajos que barre de ~8 kHz a ~250 Hz, del centro
  hacia arriba un corte de graves que barre de ~70 Hz a ~3 kHz, los dos con un pico en el corte: las repeticiones se
  oscurecen o afinan y se angostan a una banda en cada pasada (estilo dub), y en los extremos con FEEDBK alto el lazo
  autooscila en esa banda.
- **DLY 2**: **WIDE** (el eco derecho más tarde), y el delay **GRAIN**: **PITCH** (±12 semitonos por repetición) y
  **SPRAY**. Con LOAD LITE o ECO el delay GRAIN suena como un delay común (la tarjeta dice LITE / ECO). **MOD**
  (0.6.86): la deriva de la cinta, WOW lento y FLUTTER rápido sobre las repeticiones (0, por defecto: nada, copias
  exactas; ~20 como una cinta; hasta un chorus mareado); las repeticiones siguen brillantes mientras derivan (0.6.89);
  se guarda con el proyecto.
- **DLY 3** (0.6.90): **TYPE**: **ANALOG** (por defecto: la saturación suave, el TONE resonante, FEEDBK pasado 100 %
  autooscila) o **DIGITAL** (repeticiones limpias, TONE un filtro común, FEEDBK 100 % como máximo: pasado eso las
  repeticiones se mantienen, nunca crecen). **PING**: **ON** manda las repeticiones izquierda, derecha, izquierda … por
  el estéreo, cada una FEEDBK más suave (TIME hasta 0,74 s; sin WIDE ni el delay GRAIN). Se guarda con el proyecto.

### Reverb (cinco modelos)

**REVERB > TYPE** elige el modelo; **SIZE** es el decaimiento en todos los modelos. KNOB 3 y 4 cambian de significado
según el tipo:

| TYPE | Qué es | KNOB 3 | KNOB 4 |
| --- | --- | --- | --- |
| **ROOM** | Sala clásica | DAMP | PRE (pre-delay, ms) |
| **SPRING** | Tanque de resortes de amplificador | DAMP | PRE |
| **SHIMR** (shimmer) | Sube una octava en cada pasada | DAMP | **AIR** (±24 st: más oscuro y grave / más aireado y agudo) |
| **RESO** | Cuatro cuerdas afinadas a la escala del tema | **FOLLOW** (OFF / T1–T6: el acorde sigue la nota más grave que toca esa pista) | **PITCH** (el acorde 0–14 grados hacia arriba en la escala) |
| **CLOUD** | Nube granular; SIZE al máximo la congela | DAMP | **AIR** |

**REVERB 2**: **MOD** (profundidad de modulación), **RATE**, **FILT** (tono de entrada: más oscuro / más brillante;
0.6.86 resonante, una banda en el corte para tallar el lugar del espacio), **WIDE**.

Con **LOAD LITE**, SHIMMER y CLOUD suenan como ROOM y RESO como SPRING; con **LOAD ECO** todas las reverbs suenan como
SPRING. La configuración se conserva; la tarjeta TYPE muestra LITE o ECO debajo de su valor.

### Chorus

**CHORUS**: RATE, DEPTH, **STEREO** (0 como siempre, hacia abajo hasta mono, hacia arriba hasta casi el doble de
ancho). Se oculta con LOAD ECO (la tarjeta de envío de chorus de una pista dice entonces ECO).

### MASTER

- **CLIP**: saturación que agrega carácter, no volumen.
- **PUNCH**: engorda las pistas DRUM.
- **DUCK**: el bombo baja todo lo demás; **REL** es su release.

---

## 10. Modulación y macros

- **ENV DEST**: la envolvente hacia FILTER, PITCH, SHAPE; **LOOP ON**: con la nota mantenida, la envolvente vuelve al
  ataque cuando llega al sustain (un LFO con forma de ADSR).
- **LFO**: RATE, WAVE (SIN, TRI, SAW, SQR, S&H), PHASE, FADE. **LFO DEST**: PITCH, FILTER, SHAPE, AMP.
  - **RATE** es libre en Hz; girándolo a la izquierda pasado el más lento queda **a tempo** (4BAR, 2BAR, 1BAR, 1/2,
    1/4, 1/8D, 1/4T, 1/8, 1/8T, 1/16, 1/16T, 1/32), enganchado al compás mientras el transporte toca (PHASE es su
    desfase).
  - **PHASE** es dónde reinicia el LFO una frase nueva; girándolo a la izquierda pasado 0 queda en **FREE**: nunca se
    reinicia, corre libre.
- **Matriz MOD**: 4 slots por pista (KNOB 1 elige el slot).
  - Fuentes: OFF, LFO, ENV, VEL, KEY, RAND, MODW (MIDI CC1), AT (aftertouch), EXPR (CC11), **M1–M4**, **STEP** (MSEQ).
  - Destinos: PITCH, CUT, SHP, AMP, PAN, DIST, CHO, DLY, REV, RATE (velocidad del LFO), VIB, **E1–E8** (las perillas
    EDIT propias del motor, mostradas por nombre), **CLIP** y **PNCH** (el master), y (0.7.0) los buses de FX: **D.TIM D.FB
    D.TON D.MIX** (DELAY TIME, FDBK, TONE, MIX), **R.SIZ R.DMP** (REVERB SIZE, DAMP), **C.RAT C.DEP** (CHORUS RATE,
    DEPTH). AMT 64 con la fuente a tope = todo el rango del parámetro; los slots de todas las pistas sobre el mismo bus se
    suman. Una fuente STEP (la secuencia de modulación) sobre D.TIM secuencia el tiempo del delay.
- **MSEQ**: un secuenciador de modulación de 16 pasos por pista, como un secuenciador de CV. KNOB 1 elige el paso,
  KNOB 2 fija su nivel, LEN y SLEW; DIV en MSEQ 2. Usalo desde MOD con SRC **STEP**.

### Macros M1–M4

- **Mantené LFO**: KNOB 1–4 pasan a ser M1–M4, y el mapa muestra a dónde va cada una ("NO ROUTE: MOD SRC" si no van a
  ningún lado).
- Soltá: quedan **enganchadas** — KNOB 1–4 siguen moviendo las macros en cualquier página — hasta que apretás LFO de
  nuevo.
- Cada encendido arranca con rutas al azar (dos por pista) en las pistas que no tienen ninguna. **F3**
  tira rutas nuevas en las pistas que están sonando; **G3** las borra.
- Las rutas son slots MOD comunes (SRC M1–M4): editalas a mano en LFO > MOD. Los valores de las macros se guardan con
  cada sección.

---

## 11. Tocar en vivo

### FX punch-in (mantené FX)

Efectos que actúan mientras mantenés su tecla y vuelven exactamente atrás cuando la soltás. **FX > PUNCH** (0.6.99)
es su secuenciador: el carril que los graba. **LEN** su largo, 1 … 64 pasos; **RES** el paso, 1/8, 1/16 o 1/32 de
tiempo (64 pasos de 1/16 son cuatro compases, de 1/32 dos, de 1/8 ocho); el KNOB 3 dice qué está haciendo (REC
mientras graba, PLAY mientras suena, si no cuántos pasos tienen un efecto); **CLEAR** (KNOB 4 y OCT+) lo vacía. La
página dibuja las celdas del carril con el color de cada efecto y el cabezal encima, el nombre del último efecto y
las pistas sobre las que actúa (ALL, SYN, DRM). Para grabar: REC armado y tocando (no en una canción), mantené FX y
la tecla del efecto; los pasos que pasa lo reciben; **G5** sostenido borra por donde pasa el cabezal. Se guarda con
la sección.

- **Sobre el audio**: REPEAT 1/8, 1/16, 1/32 (F3 G3 A3), LPF (B3), HPF (C4). REPEAT arranca en la siguiente 1/16
  mientras suena. Por debajo de unos 81 BPM, REPEAT 1/8 es demasiado largo para su buffer y aparece atenuado.
- **Sobre las notas**: OCT− / OCT+ (D4 E4), 1/2 TEMPO (F4), DEC− (corto, punteado) / DEC+ (largo) (G4 A4), STUTTER
  1/8 / 1/16 (B4 C5), ATK+ (ataques lentos, baterías incluidas) (D5), ARP (E5; en una pista DRUM, un fill nuevo en cada
  pulsación), RANDOM (F5). Entran en la siguiente 1/16. **A#4** elige a qué pistas afectan: ALL, SYN (sintes) o DRM
  (baterías); el encabezado lo muestra.
- **Perillas** con FX mantenido: **FILTER** (izquierda pasa-bajos, derecha pasa-altos), **CRUSH**, **THROW** (manda la
  mezcla seca al delay y la reverb), **DEPTH** (el nivel del REPEAT).
- **Teclas negras 1–6**: mutean T1–T6 mientras las mantenés (no se guarda).

**El carril de punch-in**: cada sección tiene un carril de 64 pasos de 1/16 (4 compases). Con **REC armado y sonando**
(no durante un tema), los **efectos de nota (D4–F5)** que mantenés se graban en él, uno por paso (REPEAT, LPF, HPF y
los mutes no se graban). Mantené **FX + G5** mientras suena para borrar por donde pasa el cabezal; parado, FX + G5
borra todo el carril. **REC mantenido + FX** también lo borra (junto con la automatización de FX de la pista).

**Traba**: mantené FX hasta que se abra su mapa y soltalo sin tocar nada: la capa FX queda abierta (**[FX] LOCKED**),
como las macros con LFO; las teclas tocan los efectos (momentáneos: apretada suena, soltada se apaga), las perillas son
las macros del FX y OCT− es ALL OFF, con las dos manos libres. Apretá **FX** otra vez para destrabar (los efectos
trabados que dejaste prendidos siguen). Si lo mantenés tocando teclas o perillas, FX funciona como siempre y se cierra al soltar.

**FX LATCH** (MENU > CONTROL > FX LATCH, **OFF por defecto**; ON por defecto de 0.6.44 a 0.6.63): en ON, una tecla
apretada con FX activa y desactiva su efecto, las macros de las perillas conservan sus valores, **FX + OCT−** apaga
todo (FX ALL OFF). Los efectos trabados no se graban en el carril.

### Mutes y solos

- **GLO mantenido**: las teclas negras 1–6 mutean T1–T6 (enganchado, se guarda con el proyecto y en las escenas);
  F3–D4 hacen solo mientras las mantenés; las teclas negras 7–10 mutean los grupos de DRUM-X; E4 desmutea todo.
- **MIXER** KNOB 4: MUTE de la pista seleccionada.
- **EDIT mantenido** en una pista DRUM: las teclas negras 1–8 mutean cada sonido de DRUM-X.
- **FX mantenido**: las teclas negras 1–6 mutean mientras las mantenés.

### Capas en vivo y el tema

La capa SAVE (saltos de sección en el compás, cadenas rápidas, guardar, recuperar, SONG REC) está descripta en
[7](#7-arrange-canciones-secciones-y-escenas). GLO + PLAY reinicia desde el principio sin parar.

---

## 12. Guardar y cargar

Este es el capítulo para leer con atención. JIANT guarda varios tipos de datos en lugares distintos y de maneras
distintas.

### El panorama general

- **La música** es lo que está sonando ahora, en RAM: los sonidos y pasos de las seis pistas, la automatización, los
  efectos, el tempo.
- Las **secciones** (A–D de cada uno de los 8 proyectos) son donde **guardás** la música de forma permanente, en
  flash.
- El **arreglo** (filas, END, escenas) pertenece al proyecto y se guarda solo.
- Los **presets de usuario** (32 slots) guardan sonidos sueltos.
- La **configuración** (el MENU, TRACKS, LOAD) se guarda sola.
- El **autoguardado** (autosave) es una copia de seguridad de la música, para que la vuelvas a encontrar después de
  apagar. **No es un guardado en una sección**, y no ocurre al apagar.

### Qué se guarda dónde

| Qué | Dónde vive | Cómo se guarda | ¿Sobrevive al apagado? |
| --- | --- | --- | --- |
| La música actual (sonidos, pasos, automatización, tempo, efectos, kit, macros, carril de punch-in, SLICER) | RAM | No se guarda sola — guardala en una sección. El **autoguardado** conserva una copia. | Solo a través del autoguardado |
| Una **sección** (A–D de un proyecto) | Flash | **SAVE > PROJECT > SAVE** (parado), o **capa SAVE C4–F4 / OCT+** | Sí (guardados desde la capa: una vez que parás) |
| El **arreglo** (filas, compases, END, escenas) de cada proyecto | Flash (índice de temas) | Automáticamente, ~2 s después de un cambio con el transporte parado | Sí |
| **Presets de usuario** U01–U32 (un sonido + un patrón de 16 pasos) | Flash | **SAVE > USER > SAVE** (parado) | Sí |
| **Configuración** (MENU, TRACKS, LOAD, favoritos) | Flash | Automáticamente (MENU: al cerrarlo; mientras suena: después de parar) | Sí |
| El **autoguardado** | Flash, en su propio lugar | 10 s después del último cambio, parado y sin actividad, como máximo una vez por minuto | Sí (se restaura al encender si RESTORE LAST está en ON) |
| El **banco de voces FM6** B1–B32 | Flash, en su propio lugar | Se envía desde el editor web | Sí (no está en el backup: guardá el .syx) |
| **UNDO** | RAM | — | No |

### Cómo funciona realmente el autoguardado

- Escribe una copia de la música **después de 10 segundos sin cambios**, solo cuando el transporte está **parado**,
  no hay ninguna tecla ni botón mantenido y no está sonando nada, y **como máximo una vez por minuto**.
- **No** guarda cuando apagás. Si cambiás algo y apagás dentro de esos segundos, ese último cambio se pierde. Para ir
  a lo seguro: **pará, esperá ~10 s**, o mejor, guardá en una sección.
- Al encender, el equipo arranca en cero, como lo deja **NEW PROJECT** (cada pista con el sonido por defecto de su motor,
  sin pasos). Con **MENU > SYSTEM > RESTORE LAST ON** el autoguardado pasa a ser la música (la pantalla dice
  **RESTORED**). Desde 0.6.40 RESTORE LAST viene en **OFF**: sin autoguardado.
- Después de un crash, un cuelgue o un arranque fallido, el autoguardado no se restaura (la música que estaba sonando
  podría ser lo que causó el crash).

### Para guardar una sección de un proyecto

1. **Pará** el transporte (guardar necesita el transporte parado: si no, **STOP TO SAVE**).
2. Apretá **SAVE** hasta llegar a **PROJECT** (SAVE abre primero USER y después PROJECT).
3. **KNOB 1**: el proyecto (1–8). Girarla **no** cambia la música que estás tocando — solo elige dónde guardar.
   (Cambia de proyecto, así que hacelo con el transporte parado.)
4. **KNOB 2** (o PRESETS): la sección A–D. La lista muestra el nombre de cada sección (o USED / --), **NOW** en la
   sección de la que vino la música, y los compases que suena en el arreglo.
5. **KNOB 4** a la derecha: SAVE queda elegido ([OCT+]). Apretá **OCT+**.
6. Si la sección ya tiene algo: **OVERWRITE PROJECT A?** (con su nombre). OCT+ YES.
7. Se abre la pantalla **NAME** con un nombre listo. Editalo o no, y después **OCT+** escribe. **OCT−** cancela y no
   escribe nada.
8. La pantalla dice **SAVED**.

Una sección guarda la música **incluyendo el tempo y los efectos globales**. El **nombre del proyecto** es el nombre
de su sección A.

### Para cargar una sección

1. SAVE > PROJECT, **KNOB 1** el proyecto, **KNOB 2** la sección.
2. **KNOB 3** a la derecha (LOAD), apretá **OCT+**. La pantalla dice **LOADED**.

LOAD **detiene la reproducción** y reemplaza la música: sonidos, pasos, automatización, el kit, el carril de punch-in,
las macros, y el **tempo, los efectos, el ruteo MIDI y la configuración de clock** guardados con ella. El arreglo se
queda. Si no era lo que querías, **GLO + G4** (UNDO) trae de vuelta lo que tenías.

### Guardado rápido mientras suena (capa SAVE)

Mantené SAVE y apretá **C4–F4** para guardar la música en la sección A–D del proyecto actual, u **OCT+** para guardar
en la sección que está sonando. Esto funciona **mientras suena**, sin poner nombre. El guardado queda en **RAM al
instante y pasa a la flash cuando parás**. Si apagás antes de parar, se pierde — así que pará antes de apagar.

### Copiar

- **Una sección a otra letra**: cargala (LOAD) y después guardala (SAVE) en la otra letra.
- **Una sección a otro proyecto**: cargala, girá KNOB 1 hasta el otro proyecto (la música se queda) y guardá en una
  letra.
- **"Guardar como" un proyecto nuevo**: con tu música sonando, pará, andá a SAVE > PROJECT, girá KNOB 1 hasta un
  proyecto vacío y guardá en A.

### Cambiar de proyecto

- En **SAVE > PROJECT, KNOB 1** cambia de proyecto pero **conserva la música** (para guardarla ahí o cargar una de
  sus secciones).
- Con **KNOB 1 de la capa SAVE** (mantené SAVE, girá, soltá) cambia el proyecto **y su sección A pasa a ser la
  música** (si tiene una). La música anterior se reemplaza y **UNDO no la puede traer de vuelta** — guardala antes.
- Las dos cosas necesitan el transporte parado (**STOP TO CHANGE PROJECT** / **STOP TO CHANGE SONG**). Las secciones
  guardadas con la capa SAVE se escriben en la flash antes del cambio.

### Poner nombres (la pantalla NAME)

Se abre cuando guardás una sección o un preset de usuario, y cuando apretás **EDIT** en SAVE > USER o SAVE > PROJECT
(renombra el slot seleccionado; solo se escribe el nombre). Hasta 12 caracteres, en mayúsculas.

| Control | Hace |
| --- | --- |
| Teclas blancas | Letras al estilo teléfono: AB, CD, EF, GH, IJK, LM, NO, PQ, RS, TU, VW, XYZ, después 123, 456, 789, 0-. — tocá de nuevo dentro de 0,8 s para el siguiente carácter |
| Teclas negras (por nombre) | **F#** cursor a la izquierda, **G#** espacio, **A#** cursor a la derecha, **C#** borrar, **D#** alternar ABC / 123 (dígitos y símbolos, uno por tecla) |
| KNOB 1 | mover el cursor |
| KNOB 2 | cambiar el carácter en el cursor |
| OCT+ / OCT− | escribir / cancelar |

Un nombre vacío: una sección de proyecto queda sin nombre, un preset de usuario recibe uno automático.

### Presets de usuario (SAVE > USER)

32 slots para sonidos sueltos. **SAVE** abre directamente en esta página con SAVE ya elegido, así que **SAVE, OCT+,
OCT+** guarda el sonido de la pista seleccionada con el nombre que te ofrece.

- **KNOB 1**: el slot (U01–U32). **KNOB 2** LOAD, **KNOB 3** ERASE (pregunta antes), **KNOB 4** SAVE (pregunta antes
  de sobrescribir, después NAME). Girá la perilla a la derecha para elegir, **OCT+** para ejecutar. Guardar y borrar
  necesitan el transporte parado.
- Un preset de usuario guarda el **motor, sus parámetros de sonido y un patrón de 16 pasos**; un sonido FM6 conserva
  su patch.
- **No** guarda el **kit DRUM-X** (ese vive en las secciones del proyecto).
- Cargar uno carga solo el sonido.
- Tus presets de usuario también aparecen al recorrer con PRESETS, después de los sonidos de fábrica.

### Preguntas frecuentes sobre guardar

**Apagué y se perdieron mis últimos cambios.** El autoguardado solo escribe después de 10 s sin cambios con el
transporte parado, como máximo una vez por minuto, nunca al apagar. Pará y esperá un momento, o guardá en una sección.

**Dice STOP TO SAVE.** Guardar en una sección o en un preset de usuario escribe la flash, lo que pausa el audio un
instante, así que solo se hace con el transporte parado. Apretá PLAY para parar y probá de nuevo (la pantalla NAME
queda abierta; PLAY ahí solo para).

**Dice SAVED (NO FLASH).** No se detectó el chip de flash, así que el guardado quedó solo en RAM. Sobrevive a un
reset, no a un apagado. Reiniciá el equipo; si lo sigue diciendo, ver [16](#16-problemas-y-preguntas-frecuentes).

**Dice SECTION 90% FULL / TOO FULL TO SAVE / SECTION FULL.** Una sección tiene un tamaño fijo. Una música muy cargada
(seis pistas de acordes en los 64 pasos más mucha automatización) puede no entrar. Guardar una sección que no entra
dice SECTION FULL y deja intacta la que estaba guardada. Acortá patrones, borrá pasos o automatización que no uses.

**Guardé con la capa SAVE mientras sonaba y lo perdí.** Lo guardado desde la capa llega a la flash cuando parás. Pará
antes de apagar.

**¿Mi arreglo se guarda?** Sí, automáticamente, un par de segundos después de cada cambio con el transporte parado.

**¿Dónde está mi kit de batería en un preset de usuario?** Los presets de usuario no guardan el kit DRUM-X; guardá la
sección del proyecto.

**¿Puedo hacer un backup de todo?** Sí: el backup completo del editor web incluye los 8 proyectos con sus secciones,
arreglos y escenas, los presets de usuario y la configuración. Ver
[15](#15-herramientas-web-emulador-instalador-editor-backup).

---

## 13. Sistema: TRACKS, LOAD y el MENU

### TRACKS (GLO > SYSTEM, KNOB 1 — también MENU > AUDIO > TRACKS)

- **4** (por defecto): suenan T1–T4; **T5 y T6 están dormidas**. Conservan su sonido, sus pasos y su mezcla, y no
  consumen nada. Si se le manda una nota a una pista dormida (una tecla, MIDI, sus pasos) o PLAY arranca con pasos en
  ellas, la pantalla dice **T5-T6 ASLEEP** y **GLO>SYSTEM>TRACKS 6**. Las pistas dormidas aparecen tenues en el mapa
  de GLO y en gris en HOME y en el MIXER.
- **6**: suenan las seis pistas. Vigilá el medidor de carga.

### LOAD (GLO > SYSTEM, KNOB 2 — también MENU > SYSTEM > LOAD)

Cuán pesado puede ponerse el sonido.

| LOAD | Qué cambia mientras suena |
| --- | --- |
| **FULL** (por defecto) | Todo tal como está configurado. |
| **LITE** | Las reverbs SHIMMER y CLOUD suenan como ROOM, RESO como SPRING; el delay GRAIN suena común; FM6 toca dos voces. La pantalla se dibuja más liviana: los seres y gráficos se animan a unos 20 cuadros por segundo con contornos más simples, y los valores cambian al instante (sin dígitos que ruedan). |
| **ECO** | LITE, más: todas las reverbs suenan como un SPRING liviano, **sin SLICER** (sus pistas van directo a la mezcla), **sin chorus** (sus páginas se ocultan), como máximo **4 voces** por pista de sinte y **6 voces** entre todas las pistas (8 si no; la batería también cuenta). Cuando la carga sube, las colas casi en silencio se sueltan antes. La pantalla a unos 14 cuadros por segundo, los seres aún más simples. |

LOAD solo cambia cómo se renderizan las cosas: **los proyectos conservan su configuración** y suenan como se guardaron
en FULL (o en otro FM-1). Las tarjetas de los efectos sustituidos dicen LITE o ECO. LOAD libera **CPU**, no RAM: el
firmware reserva toda su memoria al arrancar. La tarjeta **CPU** (KNOB 4 en SYSTEM) y el medidor de carga del
encabezado muestran la carga de audio. TRACKS y LOAD son configuraciones del equipo, no forman parte de un proyecto.

### ROUTE (GLO > SYSTEM, KNOB 3)

**CH1-6**: los canales MIDI 1–6 tocan las pistas 1–6, los canales 7–16 se ignoran. **SEL**: todos los canales tocan
la pista seleccionada.

### GLOBAL (GLO > GLOBAL)

**BPM** (40–240), **SWING**, **CLOCK** (INT, USB, TRS: sigue el clock MIDI y el start/stop de esa entrada), **TUNE**
(±50).

### El MENU (mantené HOME)

**ALGORITHM** cambia de pestaña, **PRESETS** se mueve entre filas, **cualquier perilla** u **OCT+ / OCT−** cambia el
valor. HOME lo cierra (en ese momento se guarda la configuración).

| Pestaña | Fila | Valores |
| --- | --- | --- |
| DISPLAY | COLOR | GREY, GREEN, AMBER, ICE, VIOLET, ROSE, PAPER, HI-CON, NIGHT, MONO, **JIANT** (por defecto) |
| DISPLAY | STYLE | FLAT, LINE |
| DISPLAY | LARGE | OFF, ON (etiquetas y valores grandes) |
| DISPLAY | ANIM | ON, OFF (los valores saltan directo; la firma de encendido aparece entera) |
| DISPLAY | LEDS | OFF, DIM LO, **DIM HI** (por defecto), INV |
| DISPLAY | SCREEN OFF | **NEVER** (por defecto), 5 MIN, 15 MIN, 30 MIN, 60 MIN |
| CONTROL | HOLD | 0.3 s, **0.4 s** (por defecto), 0.5 s, 0.6 s — cuánto tarda un botón mantenido en abrir su capa |
| CONTROL | KNOB ACCEL | **ON** (por defecto), OFF |
| CONTROL | FX LATCH | **OFF** (por defecto desde 0.6.64), ON |
| CONTROL | BPM LOCK | OFF, ON — DICE ALL conserva el tempo (el tempo es GLO + SELECT, F4 TAP de GLO o el BPM de GLOBAL) |
| CONTROL | SCALE LEDS | OFF, ON — las teclas de la escala se iluminan, la tónica más brillante |
| CONTROL | MIDI OUT | **KEYS**, CLOCK, ALL, OFF — qué sale por MIDI USB (ver [14](#14-midi-y-usb)) |
| AUDIO | SPEAKER EQ | FLAT, LOWCUT, BASS+ (un EQ en el master para el parlante chico; también llega a las salidas y al USB) |
| AUDIO | USB LEVEL | MASTER (el USB sigue a la perilla MASTER), FIXED (USB a nivel completo), −6 / −12 / −18 / −24 dB (USB fijo y atenuado: para un celular o una computadora cuya entrada satura a nivel completo) |
| AUDIO | CLICK | OFF, REC (mientras una pista está armada y sonando), ON |
| AUDIO | CLICK LEVEL | LOW, MID, HIGH |
| AUDIO | COUNT-IN | OFF, 1 BAR, 2 BARS |
| AUDIO | TRACKS | **4** (por defecto), 6 |
| SYSTEM | USB | CONSOLE (la consola serie con audio USB estéreo, por defecto; era USB SERIAL ON), STEREO (solo audio + MIDI, clase 0; era OFF: ayuda a que macOS 13–15 vea la entrada de audio USB), STEMS (0.7.1: entrada de audio de 8 canales, ver "Stems" más abajo) |
| SYSTEM | RESTORE LAST | **OFF** (por defecto: sin autoguardado, el encendido arranca en cero), ON (la última sesión vuelve al encender) |
| SYSTEM | LOAD | ECO, LITE, **FULL** (por defecto) |
| SYSTEM | CALIBRATION | OCT+ abre HARDWARE CALIBRATION (enseñarle cada botón y perilla) |
| SYSTEM | INIT SYSTEM | OCT+ pregunta, y después todo vuelve a cero para una canción nueva (como SAVE > TOOLS > NEW PROJECT; UNDO devuelve la música) |
| SYSTEM | ABOUT | OCT+ abre: versión, código QR, AUDIO LOAD (NOW, PEAK, LATE, SHED desde el encendido) y créditos (se desplaza con PRESETS, OCT− vuelve) |

Si escuchás clicks, abrí ABOUT y mirá **LATE** (bloques de audio que llegaron tarde) y **SHED** (voces que la
protección desvaneció): una foto de esa pantalla ayuda cuando reportás un problema.

---

## 14. MIDI y USB

- **USB** es MIDI y audio class-compliant: la salida master le llega a la computadora como una entrada de audio USB.
- **MIDI IN** por USB y por el jack **TRS**. **ROUTE** decide qué pista toca cada canal (ver
  [13](#13-sistema-tracks-load-y-el-menu)). Las notas entrantes en una pista armada se graban igual que las teclas.
- **MIDI OUT** (por USB; MENU > CONTROL > **MIDI OUT**, 0.6.72), cada pista por su canal (T1 = canal 1 … T6 =
  canal 6):
  - **KEYS** (por defecto): las teclas mandan sus notas, como siempre.
  - **CLOCK**: y además el clock (24 por negra) con **START / STOP**, mientras el tempo es el del FM-1 (CLOCK INT): una
    caja de ritmos o un DAW lo siguen. El clock corre también parado, así el que sigue conoce el tempo antes del PLAY.
  - **ALL**: y además todas las notas que toca el FM-1: el secuenciador, el arpegiador, PLAYHEADS y las repeticiones de
    los punch-in, con el OCT− / OCT+ y el RANDOM de los punch-in aplicados; cada nota tiene su note-off, y STOP, un
    pánico o un cambio del ajuste apagan lo que quede sonando. Grabá la música del FM-1 en un DAW como MIDI, o tocá
    otros sintes con él.
  - **OFF**: nada.
- **PROGRAM CHANGE** (0.6.72): el programa *n* en el canal que toca una pista carga en esa pista el sonido número
  *n* + 1 de la lista de PRESETS (los presets de cada motor en su orden, después los presets de usuario); la pista
  seleccionada no cambia.
- **Secciones y proyectos** (0.6.80): el **canal 16** es el de la canción: su PROGRAM CHANGE nunca carga un sonido
  (con cualquier ROUTE). Los programas **0–3** saltan a la sección **A–D** del proyecto (sonando: en el compás
  siguiente, como las teclas de la capa de la canción; parado: en el momento; si está vacía, lo avisa); los programas
  **16–23** cargan el proyecto **1–8** con su sección A (solo parado, como SAVE > PROJECT). Un pedal MIDI o un DAW
  pueden llevar un set entero.
- **No es posible**: MIDI OUT por el jack **TRS** (el jack del FM-1 es solo de entrada: no le llega ninguna línea de
  salida) ni **MIDI por Bluetooth** (el chip tiene radio, pero su software de Bluetooth es el SDK cerrado de JieLi,
  que JIANT no usa).
- **Clock**: GLO > GLOBAL > CLOCK **USB** o **TRS** sigue el clock y los Start / Continue / Stop de esa entrada. Con un
  clock externo, TAP y el reinicio con GLO + PLAY quedan desactivados.
- **Controladores** (en la pista que toca el canal): CC5 glide, CC7 nivel, CC10 paneo, CC71 resonancia y CC74 cutoff
  (los propios del motor, donde los tiene), CC72 release, CC73 attack, CC75 decay, CC91 envío de reverb, CC93 envío
  de chorus, CC94 envío de delay; **CC16–23** los ocho valores propios del motor (las perillas de EDIT 1 / EDIT 2,
  E1–E8, sea cual sea el motor: CC16 es el KNOB 1 de EDIT 1), **CC102 / CC103** cutoff / resonancia del filtro post,
  **CC104** drive, **CC105** sustain (0.6.96). CC1 (rueda de modulación), CC11 (expresión) y el aftertouch de canal son fuentes de
  la matriz MOD (MODW, EXPR, AT). Funcionan el pitch bend, el sustain (CC64), All Sound Off (CC120) y All Notes Off
  (CC123). Un CC se graba como automatización igual que un movimiento de perilla.
- Nombre USB MIDI y audio: "JIANT FM" (0.7.0; "JIANT Update" mientras se instala un paquete). El editor web y el instalador aceptan también un equipo que todavía se llame "Felucca".

### Stems (0.7.1)

Dos maneras de sacar cada pista por separado, para procesarlas de a una en un DAW:

- **Por USB, en vivo: MENU > SYSTEM > USB > STEMS.** El equipo se vuelve a enumerar como una entrada de audio USB de 8
  canales a 44.1 kHz, 16 bits (en el DAW, la entrada del equipo con 8 canales): los canales 1–6 son las seis pistas, cada
  una en mono con su LEVEL, DIST, ruteo al SLICER y mutes incluidos y sin su PAN (lo que suma a la mezcla, L + R a la
  mitad); los canales 7–8 son el retorno de FX en estéreo (los buses DELAY, REVERB y CHORUS, y el del SLICER cuando está
  encendido). Todo antes del master: sin leveler, limiter, CLIP ni perilla MASTER, así la suma de los ocho es la mezcla
  tal como la oyen los buses. USB LEVEL a −6 dB o menos deja margen. La consola serie queda apagada en este modo; el
  USB-MIDI, el editor y el instalador siguen funcionando. El parlante y los auriculares tocan el master como siempre.
- **Desde un backup, fuera de línea: "Stems" en la página del emulador.** Hacé un backup del FM-1 ("Back up" en el
  editor o el instalador), abrí la página del emulador, desplegá "Stems", cargá el archivo, elegí una canción (sus filas
  se tocan una vez; una canción en LOOP, una vuelta) o la sección en vivo con una cantidad de compases, y apretá Render.
  Cada pista se renderiza sola con su propia parte de DELAY, REVERB y CHORUS (sin los envíos de las otras), más la mezcla
  completa MIX (el master tal como lo toca el FM-1), todas del mismo largo, estéreo 16 bits 44.1 kHz, en un ZIP: T1.wav ..
  T6.wav y MIX.wav (una pista en silencio no se incluye). Más rápido que el tiempo real, sin límites del USB y sin tocar
  el equipo.

---

## 15. Herramientas web: emulador, instalador, editor, backup

Las tres funcionan en el navegador y se actualizan solas con cada cambio del firmware.

### Emulador — <https://juanjiant-bit.github.io/JIANT/>

El mismo código que el FM-1, con sonido, en el navegador. Tocalo con el mouse o con el teclado de la computadora: las
filas **Z–'** y **Q–O** son las teclas, **1** a **=** los botones de FX a REC, **[ ]** OCT− / OCT+, **↑ ↓** SELECT,
**← →** ALGORITHM; **Shift-clic** mantiene un botón. Ideal para aprender las capas sin el equipo.

### Instalador — <https://juanjiant-bit.github.io/JIANT/webapp/installer/>

Chrome o Edge, con el FM-1 conectado directo a la computadora.

- **Install**: instala JIANT (primero revisa el FM-1: solo sobre el oficial V15 o JIANT).
- **Return to official V15**: dale el **FM-1.fwsc** original sin modificar de M-VAVE (se verifica localmente en el
  navegador). Primero guarda un backup completo (música actual, música guardada, bancos de sonido y configuración; no
  los samples de usuario). Usalo antes de instalar JIANT si tu FM-1 tiene **otro firmware custom** (Felucca,
  baudgirl…), y siempre que quieras volver al firmware de fábrica. El V15 oficial no puede abrir música de JIANT; para
  restaurar el backup más adelante, reinstalá JIANT y usá el editor.

### Editor — <https://juanjiant-bit.github.io/JIANT/webapp/editor/>

Todos los parámetros desde la computadora, por USB. Pestañas: Sound, 6-OP FM, Sequencer, Tracks, Library, Projects,
Settings.

- **6-OP FM**: editá patches FM6, importá .syx y **Send to the device's voice bank (B1–B32)** (enviá al banco de voces
  del equipo).
- **Projects**: los slots de proyecto y el **Complete backup**: **Save backup** y **Restore backup**.

### El backup completo

**Save backup** descarga un único archivo con: la música actual, **los 8 proyectos con sus 4 secciones cada uno**, los
arreglos y las escenas, los 32 presets de usuario (con sus patches FM6) y la configuración. **Restore backup**
reemplaza todo eso en el equipo (mantené el USB conectado). El **banco de voces FM6 (B1–B32) no está incluido**:
guardá tus archivos .syx.

Hacé un backup antes de actualizar, antes de volver al firmware de fábrica, y cada vez que terminás algo que te
encanta.

---

## 16. Problemas y preguntas frecuentes

**T5 o T6 no suenan.** TRACKS está en 4 (el valor por defecto): T5 y T6 están dormidas. GLO > SYSTEM > TRACKS **6** (o
MENU > AUDIO > TRACKS). La pantalla te avisa cuando tocás en una pista dormida.

**Después de borrar una secuencia, seguían sonando notas en todas las pistas.** Esto se corrigió en la v0.6.28: ahora
un borrado termina las repeticiones del carril de punch-in (STUTTER, ARP), una pista DRUM sin pasos no recibe fill de
ARP, y se cancela un salto de sección o una cadena rápida que estaba esperando el compás. Si algo sigue sonando
después de un borrado, puede ser el **carril de punch-in**: mantené **REC y apretá FX** para borrarlo (o
**SEQ + REC** para borrar todo).

**Dos núcleos (0.6.71, prueba).** El segundo núcleo calcula algunas pistas de sinte; MENU > ABOUT dice **CORES 2**,
o **CORES 1** y por qué (REC al prender, una lectura mala, sin respuesta, una falla: entonces sigue con un núcleo
hasta que lo apagues). Mantené **REC** al prender para tocar con un núcleo.

**Clicks, cortes, el medidor de carga lleno.** Dejá TRACKS en 4, probá **LOAD LITE** o **ECO**, usá menos voces (MONO,
menos pistas FM6), reverbs más livianas (CLOUD y SHIMMER son las más pesadas). Revisá MENU > SYSTEM > ABOUT >
AUDIO LOAD.

**SELECT no cambia el tempo.** Desde 0.6.67 SELECT solo recorre las páginas; el tempo es **GLO mantenido + SELECT**
(o F4 TAP de GLO, o la perilla BPM de GLO > GLOBAL).

**Las perillas controlan M1–M4 en lugar de la página.** Las macros están enganchadas (el encabezado dice [LFO] LATCH).
Apretá LFO.

**Un tema no arranca: "PATTERN A EMPTY" / "ADD A SONG ROW".** Una fila apunta a una sección vacía, o no hay filas.
Guardá música en esa sección, o cambiá la fila.

**Dice STOP TO EDIT.** Está sonando un tema (arreglo) o una cadena rápida; paralo para editar pasos, usar herramientas
o UNDO.

**Las teclas parecen invertidas / un botón hace otra cosa.** Corré HARDWARE CALIBRATION: mantené OCT− y OCT+ mientras
encendés (o MENU > SYSTEM > CALIBRATION) y enseñale cada botón y perilla. Una tecla del piano cancela.

**La entrada de audio USB no aparece en macOS.** MENU > SYSTEM > USB **STEREO** (o STEMS).

**SAVED (NO FLASH).** No se detectó el chip de flash; lo guardado queda solo en RAM. Apagá y prendé el equipo. Si
persiste, hacé un backup de lo que puedas con el editor y reinstalá.

**El FM-1 queda en negro después de una actualización interrumpida.** Fijate si la computadora lo ve como
**WL80UBOOT** (un dispositivo USB 4C4A:8057): ese es el modo de arranque del chip y el instalador lo puede volver a
escribir (probá con otro cable). Para entrar a propósito al modo de actualización desde un equipo funcionando, mantené
**OCT− + OCT+** durante 5 segundos. Si eso no alcanza,
[FM-1 Transporter](https://github.com/kurogedelic/FM-1-transporter) lee y escribe la flash con una Seeed XIAO RP2040.

**Quiero volver al firmware de fábrica.** Usá la sección **Return to official V15** del instalador (hace un backup
antes), o el actualizador propio de M-VAVE.

**Vengo de baudgirl / Felucca. ¿Puedo instalar directamente?** No: primero volvé al V15 oficial con el instalador y
después instalá JIANT. Pasar directamente desde otro firmware custom ya brickeó algún FM-1.

**¿Adónde fueron mis samples de Felucca?** JIANT no tiene samples de usuario; esa flash ahora guarda los temas.

---

Si mi trabajo resuena con vos, considerá apoyarme en Ko-fi (https://ko-fi.com/juanjiant) — en Argentina: Cafecito (https://cafecito.app/juanjiant).
