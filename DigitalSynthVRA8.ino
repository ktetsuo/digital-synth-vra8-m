#include "Arduino.h"
#include "Common.h"
#include "Synth.h"
#include "SerialIn.h"
#include "AudioOut.h"

#define SW 2
inline boolean isSwOn() {
  return !digitalRead(SW);
}
#define LED_R 10
#define LED_G 9
#define LED_B 11
inline void ledWrite(uint8_t r, uint8_t g, uint8_t b)
{
  AudioOut::analogWrite(LED_R, 255 - r);
  AudioOut::analogWrite(LED_G, 255 - g);
  analogWrite(LED_B, 255 - b);
}

#define JP1 12
#define JP2 13
#define JP3 14  // A0
#define JP4 15  // A1
#define JP5 16  // A2

boolean l_bDemoMode = false;
boolean l_bSinth = false;
uint16_t l_timerSec;

#define MSEC(t) (uint16_t)((float)t * (float)AudioOut::COUNT_FREQ / 1000.f)

namespace Melody {
#define TEMPO (245) // ms
#define LEN(t) (MSEC(t * TEMPO))
typedef struct {
  uint8_t pitch;
  uint16_t len;
} NOTE;
static const NOTE l_note[] = {
  {62, LEN(1)}, // re
  {69, LEN(1)}, // la
  {66, LEN(1)}, // fa#
  {69, LEN(1)}, // la
  {66, LEN(1)}, // fa#
  {74, LEN(1)}, // re+
  {69, LEN(1)}, // ra
  {74, LEN(1)}, // re+
  {67, LEN(1)}, // so
  {74, LEN(1)}, // re+
  {71, LEN(1)}, // si
  {74, LEN(1)}, // re+
  {79, LEN(4)}, // so+
};
uint8_t m_next;
uint8_t m_index;
boolean m_bRinging;
uint16_t m_count = 0;
void start() {
  m_bRinging = true;
  m_index = 0;
  m_next = 1;
  Synth::noteOn(l_note[m_index].pitch);
  m_count = 0;
}
void stop() {
  m_bRinging = false;
  Synth::noteOff(l_note[m_index].pitch);
}
void run() {
  if (!m_bRinging) {
    return;
  }
  if (l_note[m_index].len <= ++m_count) {
    Synth::noteOff(l_note[m_index].pitch);
    Synth::noteOn(l_note[m_next].pitch);
    m_index = m_next;
    m_next = (m_next + 1) % (sizeof(l_note) / sizeof(*l_note));
    m_count = 0;
  }
}
};

namespace SwWithoutChat {
boolean m_bOnWithoutChat = true;
boolean m_bOnOld = true;
uint8_t m_count = 0;
void run() {
  boolean bOn = isSwOn();
  if (bOn == m_bOnOld) {
    if (MSEC(10) < m_count) {
      m_bOnWithoutChat = bOn;
    } else {
      m_count++;
    }
  } else {
    m_bOnOld = bOn;
    m_count = 0;
  }
}
boolean isOn() {
  return m_bOnWithoutChat;
}
};
namespace SwWatcher {
boolean m_bOn = true;
boolean m_bOnOld = true;
void run() {
  m_bOnOld = m_bOn;
  SwWithoutChat::run();
  m_bOn = SwWithoutChat::isOn();
}
boolean isDown() {
  // off -> on
  return (!m_bOnOld && m_bOn);
}
boolean isUp() {
  // on -> off
  return (m_bOnOld && !m_bOn);
}
};

namespace Timer {
uint16_t m_count;
uint16_t m_msec;
uint16_t m_sec;
boolean m_bCounting;
void run() {
  if (!m_bCounting) {
    return;
  }
  if (MSEC(1) <= ++m_count) {
    m_count = 0;
    if (1000 <= ++m_msec) {
      m_sec++;
      m_msec = 0;
    }
  }
}
void start() {
  m_bCounting = true;
  m_count = 0;
  m_msec = 0;
  m_sec = 0;
}
void stop() {
  m_bCounting = false;
}
uint16_t getSec() {
  return m_sec;
}
uint16_t getMsec() {
  return m_msec;
}
boolean isCounting() {
  return m_bCounting;
}
};

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  Color(uint8_t R, uint8_t G, uint8_t B) : r(R), g(G), b(B) {}
  Color(const Color& color) : r(color.r), g(color.g), b(color.b) {}
  Color() {}
};

namespace Light {
void turnOn(const Color & color) {
  ledWrite(color.r, color.g, color.b);
}
void turnOff() {
  ledWrite(0, 0, 0);
}
};

namespace Blink {
Color m_color;
uint16_t m_interval;
uint16_t m_count;
boolean m_bOn;
void run() {
  if (++m_count == m_interval) {
    if (m_bOn) {
      ledWrite(0, 0, 0);
      m_bOn = false;
    } else {
      ledWrite(m_color.r, m_color.g, m_color.b);
      m_bOn = true;
    }
    m_count = 0;
  }
}
void start(const Color & color, uint16_t interval) {
  m_color = color;
  m_interval = interval;
  m_count = 0;
}
};

namespace Rainbow {
uint16_t m_interval;
uint16_t m_count;
uint8_t m_index;
const Color l_rainbow[] = {
  {0xff,    0,    0},
  {0xdf, 0x1f,    0},
  {0xbf, 0x3f,    0},
  {0x9f, 0x5f,    0},
  {0x7f, 0x7f,    0},
  {0x5f, 0x9f,    0},
  {0x3f, 0xbf,    0},
  {0x1f, 0xdf,    0},
  {   0, 0xff,    0},
  {   0, 0xdf, 0x1f},
  {   0, 0xbf, 0x3f},
  {   0, 0x9f, 0x5f},
  {   0, 0x7f, 0x7f},
  {   0, 0x5f, 0x9f},
  {   0, 0x3f, 0xbf},
  {   0, 0x1f, 0xdf},
  {   0,    0, 0xff},
  {0x1f,    0, 0xdf},
  {0x3f,    0, 0xbf},
  {0x5f,    0, 0x9f},
  {0x7f,    0, 0x7f},
  {0x9f,    0, 0x5f},
  {0xbf,    0, 0x3f},
  {0xdf,    0, 0x1f},
};
void run() {
  if (++m_count == m_interval) {
    ledWrite(l_rainbow[m_index].r, l_rainbow[m_index].g, l_rainbow[m_index].b);
    m_count = 0;
    if (++m_index == sizeof(l_rainbow) / sizeof(l_rainbow[0])) {
      m_index = 0;
    }
  }
}
void start(uint16_t interval) {
  m_interval = interval;
  m_count = 0;
  m_index = 0;
}
};

void setup() {
  Synth::initialize();
  SerialIn::open();
  AudioOut::open();
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(JP1, INPUT_PULLUP);
  //pinMode(JP2, INPUT_PULLUP); // can't use for input
  pinMode(JP3, INPUT_PULLUP);
  pinMode(JP4, INPUT_PULLUP);
  pinMode(JP5, INPUT_PULLUP);
  l_bSinth = !digitalRead(JP1);
  l_bDemoMode = isSwOn();
  uint16_t minute = ((!digitalRead(JP3)  ? 1 : 0) << 2) + ((!digitalRead(JP4)  ? 1 : 0) << 1) + ((!digitalRead(JP5)  ? 1 : 0));
  if (minute == 0) {
    l_timerSec = 30;
  } else {
    l_timerSec = minute * 60;
  }
  Light::turnOff();
}

void loop() {
  if (l_bSinth) {
    while (true) {
      if (SerialIn::available()) {
        uint8_t b = SerialIn::read();
        Synth::receiveMIDIByte(b);
      }
      int8_t level = Synth::clock();
      AudioOut::write(level);
    }
  }
  enum {READY, SLEEP, COUNT, COUNT_LAST, ALARM};
  if (l_bDemoMode) {
    uint8_t state = SLEEP;
    while (true) {
      SwWatcher::run();
      switch (state) {
        case SLEEP:
          if ( SwWatcher::isDown()) {
            Melody::start();
            Rainbow::start(MSEC(100));
            state = ALARM;
          }
          break;
        case ALARM:
          Melody::run();
          Rainbow::run();
          if ( SwWatcher::isDown()) {
            Melody::stop();
            Light::turnOff();
            state = SLEEP;
          }
          break;
        default:
          break;
      }
      int8_t level = Synth::clock();
      AudioOut::write(level);
    }
  } else {
    uint8_t state = READY;
    Light::turnOn(Color(0, 0, 255));
    Timer::start();
    while (true) {
      SwWatcher::run();
      switch (state) {
        case READY:
          Timer::run();
          if (10 <= Timer::getSec()) {
            Timer::stop();
            Light::turnOff();
            state = SLEEP;
          } else if (SwWatcher::isDown()) {
            Timer::stop();
            Light::turnOff();
            Blink::start(Color(255, 255, 255), MSEC(500));
            Timer::start();
            state = COUNT;
          }
          break;
        case SLEEP:
          if (SwWatcher::isDown()) {
            Blink::start(Color(255, 255, 255), MSEC(500));
            Timer::start();
            state = COUNT;
          }
          break;
        case COUNT:
          Timer::run();
          Blink::run();
          if (l_timerSec - 10 <= Timer::getSec()) {
            Timer::stop();
            Blink::start(Color(255, 255, 255), MSEC(125));
            Timer::start();
            state = COUNT_LAST;
          }
          if (SwWatcher::isDown()) {
            Melody::stop();
            Timer::stop();
            Light::turnOn(Color(0, 0, 255));
            Timer::start();
            state = READY;
          }
          break;
        case COUNT_LAST:
          Timer::run();
          Blink::run();
          if (10 <= Timer::getSec()) {
            Melody::start();
            Rainbow::start(MSEC(100));
            Timer::stop();
            state = ALARM;
          }
          if (SwWatcher::isDown()) {
            Melody::stop();
            Timer::stop();
            Light::turnOn(Color(0, 0, 255));
            Timer::start();
            state = READY;
          }
          break;
        case ALARM:
          Melody::run();
          Rainbow::run();
          if (SwWatcher::isDown()) {
            Melody::stop();
            Light::turnOn(Color(0, 0, 255));
            Timer::start();
            state = READY;
          }
          break;
        default:
          break;
      }
      int8_t level = Synth::clock();
      AudioOut::write(level);
    }
  }
}

