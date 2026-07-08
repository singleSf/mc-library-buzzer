#include "BUZZER.h"

BUZZER::BUZZER(uint8_t _pin) {
  this->__pin = _pin;
  this->setEnable(true);

  pinMode(this->__pin, OUTPUT);
  digitalWrite(this->__pin, LOW);
}

BUZZER::~BUZZER() {
}

void BUZZER::setEnable(bool _isEnable) {
  this->__isEnable = _isEnable;
  if (!this->__isEnable) {
    this->__toneEnd();
  }
}

void BUZZER::__toneStart(uint16_t _frequency) {
  if (this->__isEnable) {
    tone(this->__pin, _frequency);
  }
}

void BUZZER::__toneEnd() {
  noTone(this->__pin);
}

void BUZZER::__delay(uint16_t _milliSeconds, uint16_t _microSeconds) {
  if (_milliSeconds > 0) {
    delay(_milliSeconds);
  } else if (_microSeconds > 0) {
    delayMicroseconds(_microSeconds);
  }
}

void BUZZER::__end(uint16_t _delayAfter) {
  this->__toneEnd();
  if (_delayAfter > 0) {
    this->__delay(_delayAfter);
  }
}

void BUZZER::question(uint16_t _delayAfter) {
  for (uint8_t i = 1; i < 4; i++) {
    this->__toneStart(500 * i);
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::no(uint16_t _delayAfter) {
  for (uint8_t i = 0; i < 2; i++) {
    this->__toneStart(500);
    this->__delay(100);
    this->__toneEnd();
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::ok(uint16_t _delayAfter) {
  for (uint16_t freq = 2000; freq <= 2500; freq += 100) {
    this->__toneStart(freq);
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::cancel(uint16_t _delayAfter) {
  for (uint16_t freq = 2500; freq >= 2000; freq -= 100) {
    this->__toneStart(freq);
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::alarm(uint16_t _delayAfter) {
  for (uint8_t i = 0; i < 4; i++) {
    for (uint16_t f = 1000; f < 3000; f += 40) {
      this->__toneStart(f);
      delayMicroseconds(500);
    }
    for (uint16_t f = 3000; f > 1000; f -= 40) {
      this->__toneStart(f);
      delayMicroseconds(500);
    }
  }
  this->__end(_delayAfter);
}

void BUZZER::done(uint16_t _delayAfter) {
  this->__toneStart(1500);
  this->__delay(100);
  this->__toneStart(2500);
  this->__delay(100);
  this->__end(_delayAfter);
}

void BUZZER::refuse(uint16_t _delayAfter) {
  for (uint8_t i = 0; i < 5; i++) {
    this->__toneStart(775);
    this->__delay(100);
    this->__toneEnd();
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::in(uint16_t _delayAfter) {
  for (uint16_t i = 700; i < 2000; i += 10) {
    this->__toneStart(i);
    delayMicroseconds(800);
  }
  this->__end(_delayAfter);
}

void BUZZER::out(uint16_t _delayAfter) {
  for (uint16_t i = 2000; i > 700; i -= 10) {
    this->__toneStart(i);
    delayMicroseconds(800);
  }
  this->__end(_delayAfter);
}

void BUZZER::ping(uint16_t _delayAfter) {
  this->__toneStart(1000);
  this->__delay(100);
  this->__end(_delayAfter);
}

void BUZZER::pong(uint16_t _delayAfter) {
  this->__toneStart(500);
  this->__delay(100);
  this->__end(_delayAfter);
}

void BUZZER::error(uint16_t _delayAfter) {
  this->__toneStart(250);
  this->__delay(300);
  this->__end(_delayAfter);
}

void BUZZER::click(uint16_t _delayAfter) {
  for (uint8_t i = 0; i < 2; i++) {
    this->__toneStart(3000);
    this->__delay(10);
    this->__toneEnd();
    this->__delay(50);
  }
  this->__end(_delayAfter);
}

void BUZZER::notify(uint16_t _delayAfter) {
  for (uint16_t f = 1500; f <= 2500; f += 500) {
    this->__toneStart(f);
    this->__delay(50);
  }
  this->__end(_delayAfter);
}

void BUZZER::lowBat(uint16_t _delayAfter) {
  this->__toneStart(1500);
  this->__delay(150);
  this->__toneStart(800);
  this->__delay(250);
  this->__end(_delayAfter);
}

void BUZZER::startup(uint16_t _delayAfter) {
  uint16_t notes[] = {1318, 1568, 2093, 2637}; // Mi, Sol, Do, Mi
  for (uint8_t i = 0; i < 4; i++) {
    this->__toneStart(notes[i]);
    this->__delay(100);
  }
  this->__end(_delayAfter);
}

void BUZZER::sleep(uint16_t _delayAfter) {
  this->__toneStart(1500);
  this->__delay(200);
  this->__toneStart(1000);
  this->__delay(300);
  this->__toneStart(500);
  this->__delay(400);
  this->__end(_delayAfter);
}

void BUZZER::critical(uint16_t _delayAfter) {
  for (uint8_t i = 0; i < 6; i++) {
    this->__toneStart(3500);
    this->__delay(50);
    this->__toneEnd();
    this->__delay(50);
  }
  this->__end(_delayAfter);
}

void BUZZER::scan(uint16_t _delayAfter) {
  this->__toneStart(2000);
  this->__delay(60);
  this->__toneStart(3000);
  this->__delay(60);
  this->__end(_delayAfter);
}

void BUZZER::key(uint16_t _delayAfter) {
  this->__toneStart(800);
  this->__delay(15);
  this->__end(_delayAfter);
}
