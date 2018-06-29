#include "servo_interface.hpp"

MotorController::ServoInterface::ServoInterface() {
}

uint16_t MotorController::ServoInterface::getAngle() const {
    return angle;
}

void MotorController::ServoInterface::setAngle(const int16_t newAngle) {
    if (newAngle >= 0 && newAngle <= 180) {
        angle = newAngle;
        double newDutyCycle = 3 + 8 * newAngle / 180; ///< this has a small offset to work
        if (pwm1.getFreq() != 50 || pwm2.getFreq() != 50 || pwm3.getFreq() != 50 || pwm4.getFreq() != 50) {
            pwm1.setFreq(50);
            pwm2.setFreq(50);
            pwm3.setFreq(50);
            pwm4.setFreq(50);
        }
        pwm1.setDutyCycle(newDutyCycle);
        pwm2.setDutyCycle(newDutyCycle);
        pwm3.setDutyCycle(newDutyCycle);
        pwm4.setDutyCycle(newDutyCycle);
    }
}