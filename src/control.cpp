#include "all.h"

//set Midi channel
#define CHANNEL 1

Control::Control(const char* name, byte cc)
{
    _cc = cc;
    _name = name;
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

const char* Control::get_name()
{
      return _name;
}

void Control::set_cv(byte cv)
{
        _cv = cv;
}

void Control::push_cv() const
{
    MIDI.sendControlChange(_cc, _cv, CHANNEL);
}
