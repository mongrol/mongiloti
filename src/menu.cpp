#include "all.h"


Control::Control(const char* name, byte cc)
{
        _name = name;
}

Control::Control(){
}

const char* Control::get_name()
{
        return _name;
}
