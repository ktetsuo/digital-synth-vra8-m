#pragma once

#include "Common.h"
#include "FreqTable.h"
#include "WaveTable.h"

template <uint8_t T>
class VCO
{
  static const uint8_t** m_waveTables;
  static uint8_t         m_courseTune;
  static uint8_t         m_fineTune;
  static uint8_t         m_noteNumber;
  static uint16_t        m_phase;
  static uint16_t        m_freq;

public:
  inline static void resetPhase()
  {
    m_phase = 0;
  }

  inline static void setWaveform(uint8_t waveform)
  {
    switch (waveform) {
    case SAWTOOTH:
      m_waveTables = g_waveTablesSawtooth;
      break;
    case SQUARE:
      m_waveTables = g_waveTablesSquare;
      break;
    case TRIANGLE:
      m_waveTables = g_waveTablesTriangle;
      break;
    case SINE:
      m_waveTables = g_waveTablesSine;
      break;
    }
  }

  inline static void setCoarseTune(uint8_t coarseTune)
  {
    m_courseTune = coarseTune;
    updateFreq();
  }

  inline static void coarseTune()
  {
    m_courseTune;
  }

  inline static void setFineTune(uint8_t fineTune)
  {
    m_fineTune = fineTune;
    updateFreq();
  }

  inline static void noteOn(uint8_t noteNumber)
  {
    m_noteNumber = noteNumber;
    updateFreq();
  }

  inline static uint8_t clock()
  {
    m_phase += m_freq;

    PROGMEM const uint8_t* waveTable = m_waveTables[highByte(m_freq)];
    uint8_t currIndex = highByte(m_phase);
    uint8_t nextIndex = currIndex + 0x01;
    int8_t currData = pgm_read_byte(waveTable + currIndex);
    int8_t nextData = pgm_read_byte(waveTable + nextIndex);

    int8_t level;
    uint8_t nextWeight = lowByte(m_phase);
    if (nextWeight == 0) {
      level = currData;
    } else {
      uint8_t currWeight = 0 - nextWeight;
      level = highByte((currData * currWeight) + (nextData * nextWeight));
    }

    return level;
  }

private:
  inline static void updateFreq()
  {
    uint8_t pitch = m_noteNumber + m_courseTune;
    if (pitch < (NOTE_NUMBER_MIN + 64) || pitch > (NOTE_NUMBER_MAX + 64)) {
      m_freq = 0;
    } else {
      uint8_t noteNumber = pitch - 64;
      if (m_fineTune <= 63) {
        m_freq = pgm_read_word(g_freqTableMinus10Cent + noteNumber);
      } else if (m_fineTune == 64) {
        m_freq = pgm_read_word(g_freqTable0Cent       + noteNumber);
      } else {
        m_freq = pgm_read_word(g_freqTablePlus10Cent  + noteNumber);
      }
    }
  }
};

template <uint8_t T> const uint8_t** VCO<T>::m_waveTables = g_waveTablesSawtooth;
template <uint8_t T> uint8_t         VCO<T>::m_courseTune = 64;
template <uint8_t T> uint8_t         VCO<T>::m_fineTune   = 64;
template <uint8_t T> uint8_t         VCO<T>::m_noteNumber = 60;
template <uint8_t T> uint16_t        VCO<T>::m_phase      = 0;
template <uint8_t T> uint16_t        VCO<T>::m_freq       = 0;
