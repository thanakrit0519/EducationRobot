#include <Arduino.h>
#include "Motor.h"

Motor motor=Motor(8,9,10,11); //เหลือง เขียว ส้ม น้ำเงิน
void setup() {
  motor.begin();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    int inp = Serial.readStringUntil('\n');
    int speed = inp.toInt();
    if(inp <= 255 && inp >= -255){
      motor.setspeed(inp);
      Serial.println(inp);
    }
  }
}

