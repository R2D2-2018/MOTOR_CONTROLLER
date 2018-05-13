#include "motor_interface.hpp"

MotorInterface::MotorInterface() {
}

MotorInterface::INTERFACE MotorInterface::getSelectedInterface() const {
    return selectedInterface;
}

void MotorInterface::setSelectedInterface(const INTERFACE interface) {
    selectedInterface = interface;
}