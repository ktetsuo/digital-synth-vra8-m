# Digital Synth VRA8 1.x.x

2014-xx-xx ISGK Instruments  
[https://github.com/risgk/DigitalSynthVRA8](https://github.com/risgk/DigitalSynthVRA8)

## Concept

- 8-bit Virtual Analog (Monophonic) Synthesizer
- No Keyboard, MIDI Sound Module
- For Arduino Uno

## VRA8 Features

- Sketch for Arduino Uno
- Serial MIDI In (38400 bps), PWM Audio Out (Pin 6), PWM Rate: 62500 Hz
- Sampling Rate: 15625 Hz, Bit Depth: 8 bits
- Recommending [Hairless MIDI<->Serial Bridge](http://projectgus.github.io/hairless-midiserial/) to connect PC
- Files
    - "DigitalSynthVRA8.ino" for Arduino Uno
    - "MakeSampleWavFile.cc" for Debugging on PC, makes a sample WAV file

## VRA8.rb Features

- Simulator of VRA8, Software Synthesizer for Windows
- Sampling Rate: 15625 Hz, Bit Depth: 8 bits
- Using Ruby (JRuby), UniMIDI, and win32-sound
    - `jgem install unimidi`
    - `jgem install win32-sound`
- Usage
    - `jruby vra8.rb` starts VRA8.rb
    - `jruby vra8.rb sample_midi_stream.bin` makes a sample WAV file
- Known Issues
    - VRA8.rb uses the full power of 2 CPU cores...

## VRA8 CTRL Features

- Parameter Editor (MIDI Controller) for VRA8, HTML5 App
- Please enable Web MIDI API of Google Chrome
    - `chrome://flags/#enable-web-midi`
- Recommending [loopMIDI](http://www.tobias-erichsen.de/software/loopmidi.html) (virtual loopback MIDI cable) to connect VRA8

## Synth Modules

- VCO 1
    - Waveform: Sawtooth(0), Square(1), Triangle(2)
    - Coarse Tune: -64(0), ..., 0(64), ..., +63(127) [semitone]
- VCO 2
    - Waveform: Sawtooth(0), Square(1), Triangle(2)
    - Coarse Tune: -64(0), ..., 0(64), ..., +63(127) [semitone]
    - Fine Tune: -10(58), 0(64), +10(70) [cent]
- VCO 3
    - Waveform: Sawtooth(0), Square(1), Triangle(2)
    - Coarse Tune: -64(0), ..., 0(64), ..., +63(127) [semitone]
    - Fine Tune: -10(58), 0(64), +10(70) [cent]
- VCF
    - Filter Type: LPF, Attenuation Slope: -12 [dB/oct]
    - Cutoff Frequency: 977(0), ..., 1953(64), ..., 3906(127) [Hz]
    - Resonance: Off(0), On(127)
    - Envelope Amount: 0(0), ..., 50(64), ..., 100(127) [%]
- VCA
- EG
    - Attack Time: 16(0), ..., 262(64), ..., 4178(127) [ms]
    - Decay Time: 12(0), ..., 197(64), ..., 3134(127) [ms]
    - Sustain Level: 0(0), ..., 50(64), ..., 100(127) [%]

## Preset Programs

    +------+------------------+
    | PC # | Program Name     |
    +------+------------------+
    |    0 | Sub Osc Lead     |
    |    1 | Saw Lead         |
    |    2 | Square Lead      |
    |    3 | Synth Pad        |
    |    4 | Synth Bass       |
    +------+------------------+

## MIDI Implementation Chart

      ISGK Instruments                                                Date: 2014-xx-xx       
      Model: Digital Synth VRA8       MIDI Implementation Chart       Version: 1.x.x         
    +-------------------------------+---------------+---------------+-----------------------+
    | Function                      | Transmitted   | Recognized    | Remarks               |
    +-------------------------------+---------------+---------------+-----------------------+
    | Basic        Default          | x             | 1             |                       |
    | Channel      Changed          | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Mode         Default          | x             | Mode 4 (M=1)  |                       |
    |              Messages         | x             | x             |                       |
    |              Altered          | ************* |               |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Note                          | x             | 0-127         |                       |
    | Number       : True Voice     | ************* | 24-96         |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Velocity     Note On          | x             | x  *1         |                       |
    |              Note Off         | x             | x  *2         |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | After        Key's            | x             | x             |                       |
    | Touch        Channel's        | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Pitch Bend                    | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Control                    14 | x             | o             | VCO 1 Waveform        |
    | Change                     15 | x             | o             | VCO 1 Coarse Tune     |
    |                            16 | x             | o             | VCO 2 Waveform        |
    |                            17 | x             | o             | VCO 2 Coarse Tune     |
    |                            18 | x             | o             | VCO 2 Fine Tune       |
    |                            19 | x             | o             | VCO 3 Waveform        |
    |                            20 | x             | o             | VCO 3 Coarse Tune     |
    |                            21 | x             | o             | VCO 3 Fine Tune       |
    |                            22 | x             | o             | VCF Cutoff Frequency  |
    |                            23 | x             | o             | VCF Resonance         |
    |                            24 | x             | o             | VCF Envelope Amount   |
    |                            25 | x             | o             | EG Attack Time        |
    |                            26 | x             | o             | EG Decay Time         |
    |                            27 | x             | o             | EG Sustain Level      |
    +-------------------------------+---------------+---------------+-----------------------+
    | Program                       | x             | o             |                       |
    | Change       : True Number    | ************* | 0-4           |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | System Exclusive              | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | System       : Song Position  | x             | x             |                       |
    | Common       : Song Select    | x             | x             |                       |
    |              : Tune Request   | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | System       : Clock          | x             | x             |                       |
    | Real Time    : Commands       | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Aux          : Local On/Off   | x             | x             |                       |
    | Messages     : All Notes Off  | x             | o             |                       |
    |              : Active Sensing | x             | x             |                       |
    |              : System Reset   | x             | x             |                       |
    +-------------------------------+---------------+---------------+-----------------------+
    | Notes                         | *1  9nH v=1-127                                       |
    |                               | *2  9nH v=0 or 8nH v=0-127                            |
    +-------------------------------+-------------------------------------------------------+
      Mode 1: Omni On,  Poly          Mode 2: Omni On,  Mono          o: Yes                 
      Mode 3: Omni Off, Poly          Mode 4: Omni Off, Mono          x: No                  
