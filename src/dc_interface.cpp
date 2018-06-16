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
MotorController::MotorInterface::Direction MotorController::DcInterface::getDirection() const {
    return direction;
}

void MotorController::DcInterface::setDirection(const MotorController::MotorInterface::Direction newDirection) {
    direction = newDirection;
}

int16_t MotorController::DcInterface::getSpeed() const {
    return speed;
}

void MotorController::DcInterface::setSpeed(const int16_t newSpeed) {
    // Speed can only be -255 / 255
    if (newSpeed > 255 || newSpeed < -255) {
        return;
    } else {
        speed = newSpeed;
    }
}

int16_t MotorController::DcInterface::getAngle() const {
    return angle;
}

void MotorController::DcInterface::setAngle(const int16_t newAngle) {
    // Speed can only be 0 - 360
    if (newAngle < 360 && newAngle >= 0) {
        angle = newAngle;
    }
}