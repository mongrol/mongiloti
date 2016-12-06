/* control object. Represents a cc, knob or button */

#ifndef CONTROL_H
#define CONTROL_H


#include "MIDI.h"

class Control
{
public:
        Control();
        Control(byte cc);
        byte get_cc() const;
        byte get_cv() const;
        void set_cv(byte);
        void push_cv() const;

protected:

        byte _cc;
        byte _cv;
};


#endif /* end of include guard: CONTROL_H */
