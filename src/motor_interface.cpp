#include "MotorInterface.hpp"

MotorInterface::MotorInterface() {
}

MotorInterface::INTERFACE MotorInterface::getSelectedInterface() const {
    return selectedInterface;
}