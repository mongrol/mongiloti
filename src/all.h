#ifndef __ALL_H__
#define __ALL_H__

#include <Arduino.h>

#include <Metro.h> 
#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>

#include "top.h"

#include "encoder.h"
#include "pot.h"
//#include "trellis.h"
#include "display.h"

enum DSTATE { DIALS, BIGDIAL, MAIN_LABEL };

struct Control {
  const char* _name;
  byte cc;
  byte cv;
};

struct Instrument {
        const char* _name;
        Control Controls[10];
};

#endif /* end of include guard: __ALL_H__ */
