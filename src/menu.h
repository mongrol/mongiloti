#ifndef SYMBOL
#define _MENU_H_

#define MENU_COUNT 4
#define MENU_TIMEOUT 5

struct MenuItem
{
        const char* name;
        int testValue;
};

static MenuItem menu[MENU_COUNT];

#endif /* end of include guard: _MENU_H_ */
