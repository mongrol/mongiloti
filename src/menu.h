#ifndef _MENU_H_
#define _MENU_H_

#include "all.h"

#define MENU_COUNT 4
#define MENU_TIMEOUT 5

class MenuItem
{
public:
        MenuItem();
        MenuItem(const char* name, byte cc);
        const char* get_name();
        Control * controls[4];

protected:
        const char* _name;
};

#endif /* end of include guard: _MENU_H_ */
