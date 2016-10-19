#include "pot.h"
#include "Wire.h"
#include "control.h"
#include "display.h"


Pot pot0 = Pot(POT_A0, "OSC1", 21);

// Pot pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9;
// Pot pots[POTCOUNT] = {
//         pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9
// };
int potValues[POTCOUNT];

void setupPots(){



        //Attach pots A0-A3
        // for (int i = 0; i<=4; i++) {
        //         pots[i].attach(i);nst
        //         potValues[i] = pots[i].read();
        //         Serial.println("Reading pot:" + i );
        // }
        //
        // //Attach pots A6-A11
        // for (int i = 4; i<=9; i++) {
        //         pots[i].attach(i+2);
        //         potValues[i] = pots[i].read();
        //         Serial.println("Reading pot:" + i );
        // }
}

void processPots(){
        //scan pots for change
        Serial.print(pot0.get_name());
        Serial.print(pot0.get_cc());
        Serial.print(pot0.read());

        draw(pot0.get_name(), pot0.read());


//         for (int i = 0; i<=POTCOUNT; i++) {
//                 int potValue = pots[i].read();
//                 if (potValues[i] != potValue) {
//                         String label = "pot:";
//                         label += i;
//                         label += ":";
//                         label += potValue;
// //      draw(label);
//                         potValues[i] = potValue;
//                         if (i == 7) {
//                                 //send filter CC
// //        MIDI.sendControlChange(21, potValue, channel);
//                         }
//                 } else {
//                         /* draw(999); */
//                 }
//         }
}



Pot::Pot(int pin, const char* name, byte cc) : Control(name, cc)
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
