#include "dc_interface.hpp"

MotorController::DcInterface::DcInterface() {
}

int8_t MotorController::DcInterface::getSpeed() const {
    return speed;
}

void MotorController::DcInterface::setSpeed(const int8_t newSpeed) {
    ///< Speed can only be -255 / 255
    if (pwm1.getFreq() != 1000 || pwm2.getFreq() != 1000 || pwm3.getFreq() != 1000 || pwm4.getFreq() != 1000) {
        pwm1.setFreq(1000);
        pwm2.setFreq(1000);
        pwm3.setFreq(1000);
        pwm4.setFreq(1000);
    }
    if (newSpeed == 0) {
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(0);
        speed = newSpeed;
    } else if (newSpeed > 0 && newSpeed <= 100) {
        pwm1.setDutyCycle(newSpeed);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(newSpeed);
        pwm4.setDutyCycle(0);
        speed = newSpeed;
    } else if (newSpeed < 0 && newSpeed >= -100) {
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(newSpeed * -1);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(newSpeed * -1);
        speed = newSpeed;
    }
}