#include "encoder.h"

//set Encoder pins
Encoder myEnc(7, 6);
long oldEncoderPosition  = -999;
long newEncoderPosition = 10;

void processButton(){

  // read button
  if (digitalRead(BUTTON) == HIGH) {
    //draw("button pressed");
  } else {
    // Serial.println("Button Not Pressed");
  }
}

void processEncoder(){

  newEncoderPosition = myEnc.read();
  if (newEncoderPosition != oldEncoderPosition) {
    oldEncoderPosition = newEncoderPosition;
    String label = "Enc:";
    label += myEnc.read();
    //draw(label);
  }
}

void setupEncoder(){

  // init button - PULLDOWN
  pinMode(BUTTON, INPUT_PULLDOWN);

}
