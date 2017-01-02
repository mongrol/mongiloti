#include "all.h"


MenuItem::MenuItem(const char* name)
{
        _name = name;
}

MenuItem::MenuItem(){
}

const char* MenuItem::get_name()
{
        return _name;
}
