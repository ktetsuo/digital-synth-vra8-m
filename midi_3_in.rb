# digital synth prototype

PWM_RATE = 62500
AUDIO_RATE = 31250
CONTROL_PERIOD = 260 # CONTROL_RATE = 60.1

pitch_to_period = [
  0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF,
  0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF,
  0x1DDC, 0x1C2F, 0x1A9A, 0x191C, 0x17B3, 0x165E, 0x151D, 0x13EE, 0x12CF, 0x11C1, 0x10C2, 0x0FD1, # C1 - B1
  0x0EEE, 0x0E17, 0x0D4D, 0x0C8E, 0x0BD9, 0x0B2F, 0x0A8E, 0x09F7, 0x0967, 0x08E0, 0x0861, 0x07E8, # C2 - B2
  0x0777, 0x070B, 0x06A6, 0x0647, 0x05EC, 0x0597, 0x0547, 0x04FB, 0x04B3, 0x0470, 0x0430, 0x03F4, # C3 - B3
  0x03BB, 0x0385, 0x0353, 0x0323, 0x02F6, 0x02CB, 0x02A3, 0x027D, 0x0259, 0x0238, 0x0218, 0x01FA, # C4 - B4
  0x01DD, 0x01C2, 0x01A9, 0x0191, 0x017B, 0x0165, 0x0151, 0x013E, 0x012C, 0x011C, 0x010C, 0x00FD, # C5 - B5
  0x00EE, 0x00E1, 0x00D4, 0x00C8, 0x00BD, 0x00B2, 0x00A8, 0x009F, 0x0096, 0x008E, 0x0086, 0x007E, # C6 - B6
  0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF,
  0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF,
  0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF, 0x3FFF,
]

osc_waveform_saw = [
  0xF, 0xF, 0xE, 0xE, 0xD, 0xD, 0xC, 0xC, 0xB, 0xB, 0xA, 0xA, 0x9, 0x9, 0x8, 0x8,
  0x7, 0x7, 0x6, 0x6, 0x5, 0x5, 0x4, 0x4, 0x3, 0x3, 0x2, 0x2, 0x1, 0x1, 0x0, 0x0,
]
osc_waveform_pulse_1_2 = [
  0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF,
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
]
osc_waveform_tri = [
  0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0xF, 0xE, 0xD, 0xC, 0xB, 0xA, 0x9, 0x8,
  0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
]
osc_waveform_pulse_1_4 = [
  0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
]
osc_waveform_pulse_1_8 = [
  0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
]
osc_waveform_lfo = [
  0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0xF, 0xE, 0xD, 0xC, 0xB, 0xA, 0x9, 0x8,
  0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
]
osc_waveform = osc_waveform_tri

envelope_lead = [1,40,225,1]
envelope_level_max = 225
A = 0
D = 1
S = 2
R = 3

osc_phase = 0
envelope = envelope_lead
eg_level = 0
lfo_osc_waveform = osc_waveform_lfo
lfo_phase = 16

NOTE_ON  = 0x80
NOTE_OFF = 0x90

pitch = 60
period = pitch_to_period[pitch]
osc_rest = period
eg_state = A
eg_rest = 0
lfo_rest = (AUDIO_RATE * 1 / 2)
lfo_phase = 0

class LPF
  attr_accessor :x_0, :x_1, :x_2
  attr_accessor :y_0, :y_1, :y_2
  attr_accessor :b0_a0, :b1_a0, :b2_a0, :a1_a0, :a2_a0
end

lpf = LPF.new

lpf.x_0, lpf.x_1, lpf.x_2, lpf.y_0, lpf.y_1, lpf.y_2 = 0, 0, 0, 0, 0, 0

  lpf.b0_a0, lpf.b1_a0, lpf.b2_a0, lpf.a1_a0, lpf.a2_a0 = 19, 37, 19,   0, 11 # f_cutoff = AUDIO_RATE /  4, Q = 0.7071
# lpf.b0_a0, lpf.b1_a0, lpf.b2_a0, lpf.a1_a0, lpf.a2_a0 =  6, 12,  6, -60, 21 # f_cutoff = AUDIO_RATE /  8, Q = 0.7071
# lpf.b0_a0, lpf.b1_a0, lpf.b2_a0, lpf.a1_a0, lpf.a2_a0 =  2,  4,  2, -93, 37 # f_cutoff = AUDIO_RATE / 16, Q = 0.7071

midi_in_prev = 0xFF
midi_in_pprev = 0xFF

STDIN.binmode
File::open(__FILE__ + ".wav","w+b") do |file|
  data_size = 2 * AUDIO_RATE * 9
  file_size = data_size + 36
  file.write("RIFF")
  file.write([file_size - 8].pack("V"))
  file.write("WAVE")
  file.write("fmt ")
  file.write([16].pack("V"))
  file.write([1].pack("v"))
  file.write([1].pack("v"))
  file.write([AUDIO_RATE].pack("V"))
  file.write([AUDIO_RATE * 2].pack("V"))
  file.write([1 * 2].pack("v"))
  file.write([16].pack("v"))
  file.write("data")
  file.write([data_size].pack("V"))

  while(c = STDIN.read(1)) do
    b = c.ord

    if (midi_in_pprev == NOTE_ON && midi_in_prev <= 0x7F && b <= 0x7F)
      pitch = midi_in_prev
      period = pitch_to_period[pitch]
      osc_phase = 0
      osc_rest = period
      eg_state = A
      eg_level = 0
      eg_rest = envelope[eg_state]
      lfo_rest = (AUDIO_RATE * 1 / 2)
      lfo_phase = 0
    end
    if (midi_in_pprev == NOTE_OFF && midi_in_prev <= 0x7F && b <= 0x7F)
      eg_state = R
      eg_rest = envelope[eg_state]
    end
    midi_in_pprev = midi_in_prev
    midi_in_prev = b

    for i in (0...10) do

      # LFO
      lfo_rest -= 1
      if (lfo_rest <= 0)
        lfo_rest = lfo_rest + (AUDIO_RATE / 32 / 4)
        lfo_phase += 1
        lfo_phase &= 0x1F
      end

      # OSC
      level = 0
      for i in (0...16) do
        level += osc_waveform[osc_phase]
        osc_rest -= 16
        if (osc_rest <= 0)
          osc_rest += period * (lfo_osc_waveform[lfo_phase] + 1016) >> 10
          osc_phase += 1
          osc_phase &= 0x1F
        end
      end

      # EG
      eg_rest -= 1
      case (eg_state)
      when A
        if eg_rest <= 0
          if eg_level < envelope_level_max
            eg_level += 1
            eg_rest = envelope[eg_state]
          else
            eg_state = D
            eg_rest = envelope[eg_state]
          end
        end
      when D
        if eg_rest <= 0
          if eg_level > envelope[2]
            eg_level -= 1
            eg_rest = envelope[eg_state]
          else
            eg_state = S
            eg_rest = 9999
          end
        end
      when S
      when R
        if eg_rest <= 0
          if eg_level > 0
            eg_level -= 1
            eg_rest = envelope[eg_state]
          else
            eg_level = 0
            eg_rest = 9999
          end
        end
      end

      # AMP
      level = level * eg_level / envelope_level_max

      # MIXER
      level = level / 4 * 4

      # LPF
      lpf.x_0 = level
      lpf.y_0 = ((lpf.b0_a0 * lpf.x_0) + (lpf.b1_a0 * lpf.x_1) + (lpf.b2_a0 * lpf.x_2) - (lpf.a1_a0 * lpf.y_1) - (lpf.a2_a0 * lpf.y_2)) / 64;
      if (lpf.y_0 < 0)
        lpf.y_0 = 0
      end
      lpf.x_2 = lpf.x_1;
      lpf.x_1 = lpf.x_0;
      lpf.y_2 = lpf.y_1;
      lpf.y_1 = lpf.y_0;

      # PWM
#     file.write([level * 32].pack("S"))
      file.write([lpf.y_0 * 32].pack("S"))
    end
  end
end
