/* control object. Represents a cc, knob or button */

#ifndef CONTROL_H
#define CONTROL_H
#define CHANNEL 7


#include "MIDI.h"

class Control
{
public:
        Control();
        Control(const char* name, byte cc);

        const char* get_name() const;
        byte get_cc() const;
        byte get_cv() const;
        void set_cv(byte);
        void push_cv() const;

protected:
        const char* _name;
        byte _cc;
        byte _cv;
//void sendControlChange(byte ControlNumber, byte ControlValue,byte Channel);
};




#endif /* end of include guard: CONTROL_H */
