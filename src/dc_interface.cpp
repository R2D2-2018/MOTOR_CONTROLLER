#include "dc_interface.hpp"

MotorController::DcInterface::DcInterface() {
}

bool MotorController::DcInterface::getEnable() const {
    return enable;
}

void MotorController::DcInterface::setEnable(const bool state) {
    enable = state;
    enablePin.set(state);
}

int16_t MotorController::DcInterface::getSpeed() const {
    return speed;
}

void MotorController::DcInterface::setSpeed(const int16_t newSpeed) {
    // Speed can only be -255 / 255
    /**
    if (newSpeed == 0) {
        forwardPin.set(0);
        backwardPin.set(0);
    } else if (newSpeed > 0 || newSpeed <= 255) {
        forwardPin.set(1);
        backwardPin.set(0);
    } else if (newSpeed < 0 || newSpeed >= 255) {
        forwardPin.set(0);
        backwardPin.set(1);
    }
    */
}

void setForwardPin(hwlib::pin_out &newForwardPwmPin) {
    forwardPin = newForwardPwmPin;
}
void setBackwardPin(hwlib::pin_out &newBackwardPwmPin) {
    backwardPin = newBackwardPwmPin;
}
void setEnablePin(hwlib::pin_out &newEnablePin) {
    enablePin = newEnablePin;
}