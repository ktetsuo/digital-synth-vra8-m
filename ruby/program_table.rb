$program_table = [

  # SUB OSC LEAD
  SAW,              # OSC1 WAVEFORM,
  SAW, 64, 74,      # OSC2 WAVEFORM, COARSE TUNE, FINE TUNE,
  SQUARE, 52, 64,   # OSC3 WAVEFORM, COARSE TUNE, FINE TUNE,
  127, ON, ON,      # VCF CUTOFF, RESONANCE, ENVELOPE,
  0, 96, 127,       # EG ATTACK, DECAY/RELEASE, SUSTAIN

  # SAW LEAD
  SAW,              # OSC1 WAVEFORM,
  SAW, 64, 74,      # OSC2 WAVEFORM, COARSE TUNE, FINE TUNE,
  SAW, 64, 64,      # OSC3 WAVEFORM, COARSE TUNE, FINE TUNE,
  127, ON, ON,      # VCF CUTOFF, RESONANCE, ENVELOPE,
  0, 96, 127,       # EG ATTACK, DECAY/RELEASE, SUSTAIN

  # SQUARE LEAD
  SQUARE,           # OSC1 WAVEFORM,
  SQUARE, 64, 74,   # OSC2 WAVEFORM, COARSE TUNE, FINE TUNE,
  SQUARE, 64, 64,   # OSC3 WAVEFORM, COARSE TUNE, FINE TUNE,
  127, OFF, ON,     # VCF CUTOFF, RESONANCE, ENVELOPE,
  0, 96, 127,       # EG ATTACK, DECAY/RELEASE, SUSTAIN

  # SYNTH PAD
  TRIANGLE,         # OSC1 WAVEFORM,
  SAW, 64, 74,      # OSC2 WAVEFORM, COARSE TUNE, FINE TUNE,
  SAW, 64, 64,      # OSC3 WAVEFORM, COARSE TUNE, FINE TUNE,
  127, OFF, ON,     # VCF CUTOFF, RESONANCE, ENVELOPE,
  127, 127, 127,    # EG ATTACK, DECAY/RELEASE, SUSTAIN

  # SYNTH BASS
  TRIANGLE,         # OSC1 WAVEFORM,
  SAW, 64, 74,      # OSC2 WAVEFORM, COARSE TUNE, FINE TUNE,
  SAW, 64, 64,      # OSC3 WAVEFORM, COARSE TUNE, FINE TUNE,
  0, ON, ON,        # VCF CUTOFF, RESONANCE, ENVELOPE,
  0, 127, 0,        # EG ATTACK, DECAY/RELEASE, SUSTAIN
]
