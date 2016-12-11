#ifndef __TOP_H__
#define __TOP_H__

#include "all.h"

enum State {
  STATE_TOP,
  STATE_OSC1,
  STATE_OSC2
};

void setupState();
void updateState();

#endif /* end of include guard: __TOP_H__ */
