#include "control.h"
#include <MIDI.h>
#include "Wire.h"

//set Midi channel
#define CHANNEL 1

Control::Control(byte cc)
{
    _cc = cc;
}

Control::Control(){}

byte Control::get_cc() const
{
        return _cc;
}

byte Control::get_cv() const
{
        return _cv;
}

void Control::set_cv(byte cv)
{
        _cv = cv;
}

void Control::push_cv() const
{
    MIDI.sendControlChange(_cc, _cv, CHANNEL);
}
