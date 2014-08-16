# ISGK VRA8 Digital Synthesizer V0.xx

2014-08-16 risgk

## Concept

- 8-bit Virtual Analog Monophonic Synthesizer

## VRA8.ino Features

- Arduino Uno, Serial MIDI, PWM Audio, Buzzer
- Audio Rate: 31250 Hz
- Bit Depth: 8 bits

## VRA8.rb Features

- Prototype of VRA8.ino
- Software Synthesizer for Windows
- Using Ruby, win32-sound, UniMIDI

## Synthesizer Modules

- OSC1:
    - WAVEFORM: [SAW, SQUARE, TRIANGLE]
- OSC2:
    - WAVEFORM: [SAW, SQUARE, TRIANGLE]
    - COARSE TUNE: [-64, ..., -12, ..., 0, ..., +7, ..., +12, ..., +24, ..., +63 (semitone)]
    - FINE TUNE: [-10, 0, +10 (cent)]
- OSC3:
    - WAVEFORM: [SAW, SQUARE, TRIANGLE]
    - COARSE TUNE: [-64, ..., -12, ..., 0, ..., +7, ..., +12, ..., +24, ..., +63 (semitone)]
    - FINE TUNE: [-10, 0, +10 (cent)]
- MIXER
- FILTER:
    - CUTOFF: [AR/16, ..., AR/8, ..., AR/4]
    - RESONANCE: [OFF (Q = 0.7071), ON (Q = 1.414)]
    - ENVELOPE: [OFF, ON]
- AMP
- EG:
    - ATTACK: [8, 16, 33, 65, 131, 261, 522, 1044, 2089 (ms)]
    - DECAY: [8, 16, 33, 65, 131, 261, 522, 1044, 2089 (ms)]
    - SUSTAIN: [0, ..., 1/4, ..., 1/2, ..., 3/4, ..., 127/128]
    - RELEASE: [8, 16, 33, 65, 131, 261, 522, 1044, 2089 (ms)]

## Preset Programs

- 0: VRA Lead
- 1: Saw Lead
- 2: Saw Lead Bass
- 3: Saw Lead Fifth
- 4: Saw Lead Eighth
- 5: Square Lead
- 6: Synth Bass
- 7: Synth Brass
- 8: Synth Strings
- 9: Synth Pad
- 10: xxxx
- 11: xxxx
- 12: xxxx
- 13: xxxx
- 14: xxxx
- 15: xxxx

## MIDI Implementation Chart

      Digital Synthesizer                                             Date: 2014-xx-xx
      Model: VRA8                     MIDI Implementation Chart       Version: 0.xx
    +-------------------------------+---------------+---------------+-------------------+
    | Function...                   | Transmitted   | Recognized    | Remarks           |
    +-------------------------------+---------------+---------------+-------------------+
    | Basic        Default          | x             | 1             |                   |
    | Channel      Changed          | x             | 1             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Mode         Default          | x             | Mode 4        |                   |
    |              Messages         | x             | x             |                   |
    |              Altered          | ************* |               |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Note                          | x             | 24-108        |                   |
    | Number       : True Voice     | ************* | 24-108        |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Velocity     Note On          | x             | x  *1         |                   |
    |              Note Off         | x             | x  *2         |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | After        Key's            | x             | x             |                   |
    | Touch        Channel's        | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Pitch Bend                    | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Control                    40 | x             | o             | OSC1 WAVEFORM     |
    | Change                     41 | x             | o             | OSC2 WAVEFORM     |
    |                            42 | x             | o             | OSC2 COARSE TUNE  |
    |                            43 | x             | o             | OSC2 FINE TUNE    |
    |                            44 | x             | o             | OSC3 WAVEFORM     |
    |                            45 | x             | o             | OSC3 COARSE TUNE  |
    |                            46 | x             | o             | OSC3 FINE TUNE    |
    |                            70 | x             | o             | EG SUSTAIN        |
    |                            71 | x             | o             | FILTER RESONANCE  |
    |                            72 | x             | o             | EG RELEASE        |
    |                            73 | x             | o             | EG ATTACK         |
    |                            74 | x             | o             | FILTER CUTOFF     |
    |                            75 | x             | o             | EG DECAY          |
    |                            81 | x             | o             | FILTER ENVELOPE   |
    +-------------------------------+---------------+---------------+-------------------+
    | Program                       | x             | o             |                   |
    | Change       : True #         | ************* | 0-15          |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | System Exclusive              | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | System       : Song Position  | x             | x             |                   |
    | Common       : Song Select    | x             | x             |                   |
    |              : Tune Request   | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | System       : Clock          | x             | x             |                   |
    | Real Time    : Commands       | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Aux          : Local On/Off   | x             | x             |                   |
    | Messages     : All Notes Off  | x             | o             |                   |
    |              : Active Sensing | x             | x             |                   |
    |              : System Reset   | x             | x             |                   |
    +-------------------------------+---------------+---------------+-------------------+
    | Notes                         | *1  9nH v=1-127                                   |
    |                               | *2  9nH v=0 or 8nH v=0-127                        |
    +-------------------------------+---------------------------------------------------+
      Mode 1: Omni On,  Poly          Mode 2: Omni On,  Mono          o: Yes
      Mode 3: Omni Off, Poly          Mode 4: Omni Off, Mono          x: No
