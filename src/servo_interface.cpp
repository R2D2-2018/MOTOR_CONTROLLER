#include "servo_interface.hpp"

MotorController::ServoInterface::ServoInterface() {
}

uint16_t MotorController::ServoInterface::getAngle() const {
    return angle;
}

void MotorController::ServoInterface::setAngle(const uint16_t newAngle) {
    if (newAngle < 360) {
        angle = newAngle;
    }
}