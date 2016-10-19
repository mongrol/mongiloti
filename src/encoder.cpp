#include "encoder.h"
#include "display.h"

//extern MenuSystem ms;

//set Encoder pins
Encoder myEnc(7, 6);
long oldEncoderPosition  = -999;
long newEncoderPosition = 10;

void processButton(){

        // read button
        if (digitalRead(BUTTON) == HIGH) {
                //draw("button pressed");
                Serial.print("Button Pressed\n\r");
                //ms.select();
                //draw();
        } else {
                // Serial.println("Button Not Pressed");
        }
}

void processEncoder(){

        newEncoderPosition = myEnc.read();
        if (newEncoderPosition != oldEncoderPosition) {
                oldEncoderPosition = newEncoderPosition;
                Serial.print(newEncoderPosition);
                //ms.next();
                //draw();
        }
}

void setupEncoder(){

        // init button - PULLDOWN
        pinMode(BUTTON, INPUT_PULLDOWN);

}
