#ifndef SmoothAnalogInput_h
#define SmoothAnalogInput_h

#include <Arduino.h>

#define SMOOTH_ANALOG_INPUT_SIZE 2

class SmoothAnalogInput {
 public:
  SmoothAnalogInput();
  void attach(int pin);
  void scale(int min, int max);
  int read();
  int raw();
 private:
  int _samples[SMOOTH_ANALOG_INPUT_SIZE];
  int _pin;
  int _index;
  int _mapMin;
  int _mapMax;
  int _res;
};

#endif
