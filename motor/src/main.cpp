#include <Arduino.h>
#include "Motor.h"
// put function declarations here:
Motor motor=Motor(8,9,10,11);
void setup() {
  // put your setup code here, to run once:
  motor.begin();
  Serial.begin(9600);
  //motor.setspeed(100);
}

void loop() {
  //put your main code here, to run repeatedly:  stop 255 -255 -50 : 1 - 160
  if(Serial.available() > 0){
    int inp = Serial.parseInt();
    
    if(inp <= 255 && inp != 0){
      motor.setspeed(inp);
      Serial.println(inp);
    }
    else if(inp > 255){
      motor.setspeed(0);
      Serial.println(0);
    }
  }
//   for(int i=255;i>0;i-=5){
//     motor.setspeed(i);
//     delay(100);
//   }
// delay(1000);
//   for(int i=0;i<255;i+=5){
//     motor.setspeed(-i);
//     delay(100);
//   }

}

