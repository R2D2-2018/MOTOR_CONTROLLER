#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

uint16_t MotorController::StepperInterface::getAngle() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setAngle(const uint16_t newAngle) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    if (newAngle < 360 && newAngle >= 0) {
        angle = newAngle;
    }
}