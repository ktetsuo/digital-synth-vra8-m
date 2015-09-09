require_relative 'common'

class LFO
  def initialize
    @phase = 0x4000
    set_level_eg_coef(0)
    set_rate(0)
    set_rate_eg_amt(0)
  end

  def set_level_eg_coef(controller_value)
    @level_eg_coef = controller_value << 1
  end

  def set_rate(controller_value)
    @rate = controller_value
  end

  def set_rate_eg_amt(controller_value)
    @rate_eg_amt = controller_value << 1
  end

  def clock(rate_eg_control)
    rate = @rate + high_byte(@rate_eg_amt * rate_eg_control)
    if (rate > 127)
      rate = 127
    end
    rate = (rate >> 1) + 2
    @phase += rate
    @phase &= 0xFFFF

    level = @phase
    if ((level & 0x8000) != 0)
      level = ~level + 0x10000
    end
    level -= 0x4000
    level = high_sbyte(high_sbyte(level << 1) *
                       (high_byte(@level_eg_coef * rate_eg_control) +
                        (254 - @level_eg_coef)))
    return level
  end
end
