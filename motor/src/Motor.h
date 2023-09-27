#include <Arduino.h>
class Motor
{
    // private:
    //     /* data */
    //     uint32_t _temp_int_private;
public:
    // uint16_t temp_int_public;
    uint16_t Motor1;
    uint16_t Motor2;
    uint16_t Motor3;
    uint16_t MotorPWM = 0; // PWM 0-100
    Motor(uint16_t Motor1, uint16_t Motor2, uint16_t Motor3, uint16_t MotorPWM);
    ~Motor();
    void setspeed(int spd);
    void begin();
};
