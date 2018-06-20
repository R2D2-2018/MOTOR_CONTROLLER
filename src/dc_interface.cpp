#include "dc_interface.hpp"

MotorController::DcInterface::DcInterface() {
}

int16_t MotorController::DcInterface::getSpeed() const {
    return speed;
}

void MotorController::DcInterface::setSpeed(const int16_t newSpeed) {
    // Speed can only be -255 / 255
    if (newSpeed == 0) {
        speed = newSpeed;
        // forwardPin.set(0);
        // backwardPin.set(0);
    } else if (newSpeed > 0 && newSpeed <= 255) {
        speed = newSpeed;
        // forwardPin.set(1);
        // backwardPin.set(0);
        hwlib::cout << "F";
    } else if (newSpeed < 0 && newSpeed >= -255) {
        speed = newSpeed;
        // forwardPin.set(0);
        // backwardPin.set(1);
        hwlib::cout << "B";
    }
}