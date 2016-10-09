#include "pot.h"

SmoothAnalogInput pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9;
SmoothAnalogInput pots[POTCOUNT] = {
  pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9
};
int potValues[POTCOUNT];

void setupPots(){
  //Attach pots A0-A3
  for (int i = 0;i<=4;i++){
    pots[i].attach(i);
    potValues[i] = pots[i].read();
    Serial.println("Reading pot:" + i );
  }

  //Attach pots A6-A11
  for (int i = 4;i<=9;i++){
    pots[i].attach(i+2);
    potValues[i] = pots[i].read();
    Serial.println("Reading pot:" + i );
  }
}

void processPots(){
  //scan pots for change
  for (int i = 0;i<=POTCOUNT;i++){
    int potValue = pots[i].read();
    if (potValues[i] != potValue){
      String label = "pot:";
      label += i;
      label += ":";
      label += potValue;
//      draw(label);
      potValues[i] = potValue;
      if (i == 7){
        //send filter CC
//        MIDI.sendControlChange(21, potValue, channel);
      }
    } else {
      /* draw(999); */
    }
  }
}
