#include "control.h"
#include "Wire.h"

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
