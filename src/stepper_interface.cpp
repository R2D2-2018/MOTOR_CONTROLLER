#include "stepper_Interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

<<<<<<< HEAD
bool MotorController::StepperInterface::getEnable() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return 0;
}

void MotorController::StepperInterface::setEnable(const bool state) {
=======
MotorController::MotorInterface::Direction MotorController::StepperInterface::getDirection() const {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    return MotorController::MotorInterface::Direction::Forward;
}

void MotorController::StepperInterface::setDirection(const MotorController::MotorInterface::Direction newDirection) {
>>>>>>> development
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