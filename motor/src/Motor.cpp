#include "Motor.h"
Motor::Motor(uint16_t Motor1, uint16_t Motor2, uint16_t Motor3, uint16_t MotorPWM)
{
    this->Motor1 = Motor1; // เหลือง
    this->Motor2 = Motor2; // เขียว
    this->Motor3 = Motor3; // ส้ม
    this->MotorPWM = MotorPWM; // น้ำเงิน
}

Motor::~Motor()
{
}

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
    }
    else if (spd > 0)
    {
        digitalWrite(this->Motor1, 0);
        digitalWrite(this->Motor2, 1);
    }
    else
    {
        digitalWrite(this->Motor1, 0);
        digitalWrite(this->Motor2, 0);
        digitalWrite(this->Motor3, 0);
        analogWrite(this->MotorPWM, 255);
    }
    analogWrite(this->MotorPWM, 255-abs(spd));
}
