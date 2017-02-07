#ifndef __TOP_H__
#define __TOP_H__

#include "all.h"

#define MENU_COUNT 3
#define POTCOUNT 3

enum State {
  STATE_TOP,
  STATE_OSC1,
  STATE_OSC2
};



struct MenuItem {
        const char* _name;
        int _cNum; //number of controls
        struct Control &_c1;
        struct Control &_c2;
        struct Control &_c3;
};

void push_cv(byte cc, byte cv);
void update();

#endif /* end of include guard: __TOP_H__ */
