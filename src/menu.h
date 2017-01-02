#ifndef _MENU_H_
#define _MENU_H_

#include "all.h"


class MenuItem
{
public:
        MenuItem();
        MenuItem(const char* name);
        const char* get_name();
        Control * controls[4];

protected:
        const char* _name;
};

#endif /* end of include guard: _MENU_H_ */
