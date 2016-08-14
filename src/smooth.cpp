#include "smooth.h"

SmoothAnalogInput::SmoothAnalogInput() {
    _pin = -1;
    _index = -1;
    _mapMax = 1024;
    _mapMin = 0;
    _res = 1;
}

void SmoothAnalogInput::attach(int pin) {
    _pin = pin;
    _index = 0;

    int start = analogRead(pin);
    for(int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
        _samples[i] = start;
    }
}

void SmoothAnalogInput::scale(int min, int max) {
    if (max <= min) {
        return;
    }

    _mapMin = min;
    _mapMax = max;

    _res = 1024 / (max - min) * 2;
}

int SmoothAnalogInput::raw() {
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

int SmoothAnalogInput::read() {
    raw();

    int total = 0;
    for(int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
        total += _samples[i];
    }

    int current = total / SMOOTH_ANALOG_INPUT_SIZE;
    return map(current, 0, 1024, _mapMin, _mapMax);
}
