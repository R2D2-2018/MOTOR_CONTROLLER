#include "motor_interface.hpp"

MotorInterface::MotorInterface() {
}

MotorInterface::INTERFACE MotorInterface::getSelectedInterface() const {
    return selectedInterface;
}

void MotorInterface::setSelectedInterface() {
    selectedInterface = MotorInterface::INTERFACE::DC;
}