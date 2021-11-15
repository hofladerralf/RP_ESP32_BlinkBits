
#include "src/RP_ESP32_BlinkBits.h"

bool toggle = false;

void setup() {
  //Timer
  INIT_RPtimer1();
  Serial.begin(115200);

}

void loop() {
  if(blink.tm500 == true){
    if(toggle == false){
      toggle = true;
      Serial.println("Toggled");
    }
  }
  else{
    toggle = false;
  }


  
}
