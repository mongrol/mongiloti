#include "all.h"

extern Pot pots[];
extern Instrument Instruments[];
extern bool needDisplayUpdate;
extern int activePot;
extern DSTATE dstate;
extern Metro displayTimer;

void processPots() {
  // scan pots for change
  // Serial.printf("Scanning %d pots\n", POTCOUNT);
  for (int i = 0; i < POTCOUNT; i++) {
    // Serial.printf("Pot %d \n",i );
    if (pots[i].read() != Instruments[0].Controls[i].cv) {
      // pot has changed so set new cc value
      Instruments[0].Controls[i].cv = pots[i].read();
      // push the cc to axoloti
      push_cv(Instruments[0].Controls[i].cc, Instruments[0].Controls[i].cv);
      // set the pot that's just been moved so we can draw it.
      activePot = i;
      dstate = BIGDIAL;
      needDisplayUpdate = true;
      displayTimer.reset();
      Serial.printf(
          "Setting %s CC:%d to %d\n", Instruments[0].Controls[i]._name,
          Instruments[0].Controls[i].cc, Instruments[0].Controls[i].cv);
    }
  }
}

Pot::Pot(int pin) {
  _pin = pin;
  _index = -1;
  _mapMax = 1024;
  _mapMin = 0;
  _res = 1;
  attach(_pin);
}

void Pot::attach(int pin) {
  _pin = pin;
  _index = 0;

  int start = analogRead(pin);
  for (int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
    _samples[i] = start;
  }
}

void Pot::scale(int min, int max) {
  if (max <= min) {
    return;
  }

  _mapMin = min;
  _mapMax = max;

  _res = 1024 / (max - min) * 2;
}

int Pot::raw() {
  if (_pin == -1) {
    return -1;
  }

  int value = analogRead(_pin);
  int last = _samples[_index];
  if (abs(value - last) <= _res) {
    value = last;
  }

  _index = (_index + 1) % SMOOTH_ANALOG_INPUT_SIZE;
  _samples[_index] = value;

  return value;
}

int Pot::read() {
  raw();

  int total = 0;
  for (int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
    total += _samples[i];
  }

  int current = total / SMOOTH_ANALOG_INPUT_SIZE;
  return map(current, 0, 1024, _mapMin, _mapMax);
}
