#include "stepper_Interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

bool MotorController::StepperInterface::getEnable() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setEnable(const bool state) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}

int16_t MotorController::StepperInterface::getSpeed() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setSpeed(const int16_t newSpeed) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}

int16_t MotorController::StepperInterface::getAngle() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setAngle(const int16_t newAngle) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}