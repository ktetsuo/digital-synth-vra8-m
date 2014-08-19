require './common'

class WavFileOut
  SEC = 30

  def self.open(path)
    File::open(path, "wb") do |f|
      f.write("RIFF")
      f.write([0].pack("V"))
      f.write("WAVE")
      f.write("fmt ")
      f.write([16].pack("V"))
      f.write([1, 1].pack("v*"))
      f.write([AUDIO_RATE, AUDIO_RATE].pack("V*"))
      f.write([1, 8].pack("v*"))
      f.write("data")
      f.write([0].pack("V"))

      yield WavFile.new(f, AUDIO_RATE * SEC)

      file_size = f.size
      f.seek(4, IO::SEEK_SET)
      f.write([file_size - 8].pack("V"))
      f.seek(40, IO::SEEK_SET)
      f.write([file_size - 36].pack("V"))
    end
  end
end

class WavFile
  def initialize(file, max_size)
    @file = file
    @max_size = max_size
    @data_size = 0
  end

  def write(level)
    if (@data_size < @max_size)
      @file.write([level + 0x80].pack("C"))
      @data_size += 1
    end
  end
end
