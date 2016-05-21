# refs http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt

require_relative 'common'
require_relative 'mul-q'
require_relative 'vcf-table'

class VCF
  AUDIO_FRACTION_BITS = 14

  def initialize
    @x_1 = 0
    @x_2 = 0
    @y_1 = 0
    @y_2 = 0
    set_cutoff(127)
    set_resonance(0)
    set_cutoff_eg_amt(0)
  end

  def set_cutoff(controller_value)
    @cutoff = controller_value
  end

  def set_resonance(controller_value)
    if (controller_value >= 96)
      @lpf_table = $vcf_lpf_table_q_4_sqrt_2
    elsif (controller_value >= 32)
      @lpf_table = $vcf_lpf_table_q_2
    else
      @lpf_table = $vcf_lpf_table_q_1_over_sqrt_2
    end
  end

  def set_cutoff_eg_amt(controller_value)
    @cutoff_eg_amt = controller_value
  end

  def clock(audio_input, cutoff_eg_control)
    cutoff = @cutoff + high_byte(@cutoff_eg_amt * cutoff_eg_control)
    if (cutoff > 127)
      cutoff = 127
    end

    i = cutoff * 3
    b_2_over_a_0_low  = @lpf_table[i + 0]
    b_2_over_a_0_high = @lpf_table[i + 1]
    a_1_over_a_0_high = @lpf_table[i + 2]
    b_2_over_a_0 = b_2_over_a_0_low | (b_2_over_a_0_high << 8)
    a_2_over_a_0 = (b_2_over_a_0 << 2) - (a_1_over_a_0_high << 8) -
                                         (1 << VCF_TABLE_FRACTION_BITS)

    x_0  = audio_input >> (16 - AUDIO_FRACTION_BITS)
    tmp  = mul_q15_q15(x_0 + (@x_1 << 1) + @x_2, b_2_over_a_0)
    tmp -= mul_q15_q7( @y_1,                     a_1_over_a_0_high)
    tmp -= mul_q15_q15(@y_2,                     a_2_over_a_0)
    y_0  = tmp << (16 - VCF_TABLE_FRACTION_BITS)

    if (y_0 > ((1 << (AUDIO_FRACTION_BITS - 1)) - 1))
      # printf("y_0 overflow: %d\n", y_0)  # for tests
      y_0 = ((1 << (AUDIO_FRACTION_BITS - 1)) - 1)
    end
    if (y_0 < -(1 << (AUDIO_FRACTION_BITS - 1)))
      # printf("y_0 overflow: %d\n", y_0)  # for tests
      y_0 = -(1 << (AUDIO_FRACTION_BITS - 1))
    end

    @x_2 = @x_1
    @y_2 = @y_1
    @x_1 = x_0
    @y_1 = y_0

    return y_0 << 2
  end
end
