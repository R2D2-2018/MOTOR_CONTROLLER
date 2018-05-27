#include "motor_interface.hpp"

MotorController::MotorInterface::MotorInterface() {
}

MotorController::MotorInterface::INTERFACE MotorController::MotorInterface::getSelectedInterface() const {
    return selectedInterface;
}

void MotorController::MotorInterface::setSelectedInterface(const MotorController::MotorInterface::INTERFACE interface) {
    selectedInterface = interface;
}