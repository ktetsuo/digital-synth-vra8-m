require_relative 'common'

class Voice
  def initialize
    @vco = IVCO.new
    @vcf = IVCF.new
    @vca = IVCA.new
    @eg  = IEG.new
    @lfo = ILFO.new
    @srl = ISlewRateLimiter.new
    @note_number = NOTE_NUMBER_MIN
  end

  def note_on(note_number)
    if ((note_number >= NOTE_NUMBER_MIN) && (note_number <= NOTE_NUMBER_MAX))
      @note_number = note_number
      @eg.note_on
    end
  end

  def note_off
    @eg.note_off
  end

  def control_change(controller_number, controller_value)
    case (controller_number)
    when LFO_RATE
      @lfo.set_rate(controller_value)
    when LFO_RATE_EG_AMT
      @lfo.set_rate_eg_amt(controller_value)
    when LFO_LEVEL_EG_COEF
      @lfo.set_level_eg_coef(controller_value)
    when VCO_COLOR_LFO_AMT
      @vco.set_color_lfo_amt(controller_value)
    when VCO_MIX
      @vco.set_mix(controller_value)
    when VCO_MIX_EG_AMT
      @vco.set_mix_eg_amt(controller_value)
    when VCO_PULSE_WIDTH
      @vco.set_pulse_width(controller_value)
    when VCO_SAW_SHIFT
      @vco.set_saw_shift(controller_value)
    when VCO_PORTAMENTO
      @srl.set_slew_time(controller_value)
    when VCF_CUTOFF
      @vcf.set_cutoff(controller_value)
    when VCF_RESONANCE
      @vcf.set_resonance(controller_value)
    when VCF_CUTOFF_EG_AMT
      @vcf.set_cutoff_eg_amt(controller_value)
    when VCA_GAIN
      @vca.set_gain(controller_value)
    when EG_ATTACK
      @eg.set_attack(controller_value)
    when EG_DECAY_RELEASE
      @eg.set_decay_release(controller_value)
    when EG_SUSTAIN
      @eg.set_sustain(controller_value)
    when ALL_NOTES_OFF
      @eg.note_off
    end
  end

  def clock
    eg_output = @eg.clock
    lfo_output = @lfo.clock(eg_output)
    srl_output = @srl.clock(@note_number << 8)
    vco_output = @vco.clock(srl_output, eg_output, lfo_output)
    vcf_output = @vcf.clock(vco_output, eg_output)
    vca_output = @vca.clock(vcf_output, eg_output)
    return high_sbyte(vca_output)
  end
end
