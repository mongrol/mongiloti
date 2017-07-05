#include "all.h"

extern Pot pots[];


void processPots(){
        //scan pots for change
        //for (int i = 0; i < POTCOUNT; i++) {
           // if (pots[i].read() != pots[i].p_control->cv) {
              // pot has changed so set new cc value
             //   pots[i].p_control->cv=(pots[i].read());
                // push the cc to axoloti
             //   push_cv(pots[i].p_control->cc, pots[i].p_control->cv);
                // switch menu to that controls
             //   menuIndex = pots[i]._menuNum;

                //Serial.printf("Setting %s CC:%d to %d\n",pots[i].p_control->_name, pots[i].p_control->cc, pots[i].p_control->cv );
                //draw(pots[i].p_control->cc, pots[i].read());
        //     } else {
        //         //draw(pots[i].get_name(), pots[0].read());
        //     }
        // }
}

Pot::Pot(int pin)
{
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
        for(int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
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
        for(int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
                total += _samples[i];
        }

        int current = total / SMOOTH_ANALOG_INPUT_SIZE;
        return map(current, 0, 1024, _mapMin, _mapMax);
}
