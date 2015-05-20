# VRA8-M Ruby Edition

require_relative 'common'
require_relative 'synth'
require_relative 'audio-out'
require_relative 'wav-file-out'

OPTION_RECORDING = false

$synth = Synth.new

if ARGV.length == 1
  File::open(ARGV[0], "rb") do |bin_file|
    wav_file_out = WAVFileOut.new("./a.wav")
    while(c = bin_file.read(1)) do
      b = c.ord
      $synth.receive_midi_byte(b)
      4.times do
        a = $synth.clock
        wav_file_out.write(a)
      end
    end
    wav_file_out.close
  end
else
  require 'unimidi'
  # workaround: midi-jruby (0.0.12) cannot receive a data byte 2 with a value of 0
  module MIDIJRuby
    class Input
      class InputReceiver
        def send(msg, timestamp = -1)
          if msg.respond_to?(:get_packed_msg)
            m = msg.get_packed_msg
            @buf << [m & 0xFF, (m & 0xFF00) >> 8, (m & 0xFF0000) >> 16].take(msg.get_length)
          else
            str = String.from_java_bytes(msg.get_data)
            arr = str.unpack("C" * str.length)
            arr.insert(0, msg.get_status)
            @buf << arr
          end
        end
      end
    end
  end
  require 'thread'
  q = Queue.new
  t = Thread.new do
    wav_file_out = WAVFileOut.new("./a.wav") if OPTION_RECORDING
    AudioOut::open
    loop do
      if (!q.empty?)
        n = q.pop
        n.each do |e|
          e[:data].each do |b|
            $synth.receive_midi_byte(b)
          end
        end
      end
      a = $synth.clock
      wav_file_out.write(a) if OPTION_RECORDING
      AudioOut::write(a)
    end
  end
  UniMIDI::Input.gets do |input|
    loop do
      m = input.gets
      q.push(m)
    end
  end
end
