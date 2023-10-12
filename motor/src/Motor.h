#include <Arduino.h>
class Motor
{
public:
    uint16_t Motor1;
    uint16_t Motor2;
    uint16_t Motor3;
    uint16_t MotorPWM = 0;
    Motor(uint16_t Motor1, uint16_t Motor2, uint16_t Motor3, uint16_t MotorPWM);
    ~Motor();
    void setspeed(int spd);
    void begin();
};
