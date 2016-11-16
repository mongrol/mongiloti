#include "control.h"
#include <MIDI.h>
#include "Wire.h"

//set Midi channel
#define CHANNEL 1

Control::Control(const char* name, byte cc)
{
    _name = name;
    _cc = cc;
}

Control::Control(){}

const char* Control::get_name() const
{
        return _name;
}

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
