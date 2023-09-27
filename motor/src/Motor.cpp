#include "Motor.h"
Motor::Motor(uint16_t Motor1, uint16_t Motor2, uint16_t Motor3, uint16_t MotorPWM)
{
    this->Motor1 = Motor1;
    this->Motor2 = Motor2;
    this->Motor3 = Motor3;
    this->MotorPWM = MotorPWM;
}

Motor::~Motor()
{
}

/// @brief tempFunc is template lib
/// @param a is param frist
/// @param b is param second

void Motor::begin()
{
    pinMode(this->Motor1, OUTPUT);
    pinMode(this->Motor2, OUTPUT);
    pinMode(this->Motor3, OUTPUT);
    pinMode(this->MotorPWM, OUTPUT);
    digitalWrite(this->Motor1, 0);
    digitalWrite(this->Motor2, 0);
    digitalWrite(this->Motor3, 0);
    analogWrite(this->MotorPWM, 255);
}

void Motor::setspeed(int spd)
{
    digitalWrite(this->Motor3, 1);
    if (spd < 0)
    {
        digitalWrite(this->Motor1, 1);
        digitalWrite(this->Motor2, 0);

        // pinMode(this->Motor2, OUTPUT);

        // digitalWrite(this->Motor1, 1);
        // digitalWrite(this->Motor2, 0);
        // analogWrite(this->MotorPWM, spd);
        
    }
    else if (spd > 0)
    {
        digitalWrite(this->Motor1, 0);
        digitalWrite(this->Motor2, 1);

        // pinMode(this->Motor2, INPUT);
        // digitalWrite(this->Motor1, 0);
        // analogWrite(this->MotorPWM, spd);
    }
    else
    {
        //pinMode(this->Motor2, OUTPUT);
        digitalWrite(this->Motor1, 0);
        digitalWrite(this->Motor2, 0);
        digitalWrite(this->Motor3, 0);
        analogWrite(this->MotorPWM, 255);
    }
    analogWrite(this->MotorPWM, 255-abs(spd));
    // digitalWrite(this->MotorPWM, 1);
}
