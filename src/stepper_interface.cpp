#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

MotorController::MotorInterface::DIRECTION MotorController::StepperInterface::getDirection() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return MotorController::MotorInterface::DIRECTION::FORWARD;
}

void MotorController::StepperInterface::setDirection(const MotorController::MotorInterface::DIRECTION newDirection) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}

uint8_t MotorController::StepperInterface::getSpeed() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setSpeed(const uint8_t newSpeed) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}

uint16_t MotorController::StepperInterface::getAngle() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setAngle(const uint16_t newAngle) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
}