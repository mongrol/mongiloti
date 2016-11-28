#ifndef _MENU_H_
#define _MENU_H_

#define MENU_COUNT 4
#define MENU_TIMEOUT 5

struct MenuItem
{
        const char* name;
        int testValue;
};
static MenuItem menu[MENU_COUNT] = {
        {"OSC1", 14},
        {"OSC2", 26},
        {"ENV1", 30},
        {"ENV2", 21}
};



#endif /* end of include guard: _MENU_H_ */
