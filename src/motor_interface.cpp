#include "motor_interface.hpp"

MotorController::MotorInterface::MotorInterface() {
}

MotorController::MotorInterface::INTERFACE MotorController::MotorInterface::getSelectedInterface() const {
    return selectedInterface;
}

void MotorController::MotorInterface::setSelectedInterface(const MotorController::MotorInterface::INTERFACE interface) {
    selectedInterface = interface;
}

MotorController::MotorInterface::DIRECTION MotorController::MotorInterface::getDirection() const {
    return direction;
}

void MotorController::MotorInterface::setDirection(const MotorController::MotorInterface::DIRECTION newDirection) {
    direction = newDirection;
}

uint8_t MotorController::MotorInterface::getSpeed() const {
    return speed;
}

void MotorController::MotorInterface::setSpeed(const uint8_t newSpeed) {
    // Speed can only be 0 - 100%
    if (newSpeed <= 100) {
        speed = newSpeed;
    }
}