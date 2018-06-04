#include "dc_interface.hpp"

MotorController::DcInterface::DcInterface() {
}

MotorController::MotorInterface::DIRECTION MotorController::DcInterface::getDirection() const {
    return direction;
}

void MotorController::DcInterface::setDirection(const MotorController::MotorInterface::DIRECTION newDirection) {
    direction = newDirection;
}

uint8_t MotorController::DcInterface::getSpeed() const {
    return speed;
}

void MotorController::DcInterface::setSpeed(const uint8_t newSpeed) {
    // Speed can only be 0 - 100%
    if (newSpeed <= 100) {
        speed = newSpeed;
    }
}

uint16_t MotorController::DcInterface::getAngle() const {
    return angle;
}

void MotorController::DcInterface::setAngle(const uint16_t newAngle) {
    // Speed can only be 0 - 360
    if (newAngle <= 360) {
        angle = newAngle;
    }
}