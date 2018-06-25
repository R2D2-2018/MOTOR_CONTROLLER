#include "servo_interface.hpp"

MotorController::ServoInterface::ServoInterface() {
}

uint16_t MotorController::ServoInterface::getAngle() const {
    return angle;
}

void MotorController::ServoInterface::setAngle(const uint16_t newAngle) {
    if (newAngle <= 180) {
        angle = newAngle;
        // if (pwm1.getFreq() != 50 || pwm2.getFreq() != 50 || pwm3.getFreq() != 50 || pwm4.getFreq() != 50) {
        pwm1.setFreq(50);
        pwm2.setFreq(50);
        pwm3.setFreq(50);
        pwm4.setFreq(50);
        //}
    }
}