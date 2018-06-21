#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

int16_t MotorController::StepperInterface::getSpeed() const {
    return speed;
}

void MotorController::StepperInterface::setSpeed(const int16_t newSpeed) {
    // Speed can only be -255 / 255
    if (newSpeed == 0) {
        speed = newSpeed;
    } else if (newSpeed > 0 && newSpeed <= 255) {
        speed = newSpeed;
        hwlib::cout << "F";
    } else if (newSpeed < 0 && newSpeed >= -255) {
        speed = newSpeed;
        hwlib::cout << "B";
    }
}

uint16_t MotorController::StepperInterface::getAngle() const {
    return angle;
}

void MotorController::StepperInterface::setAngle(const uint16_t newAngle) {
    if (newAngle < 360) {
        angle = newAngle;
    }
}

uint8_t MotorController::StepperInterface::getStepperWires() const {
    return stepperWires;
}

void MotorController::StepperInterface::setStepperWires(const uint8_t newAlmount) {
    if (newAlmount == 2) {
        stepperWires = newAlmount;
    } else if (newAlmount == 4) {
        stepperWires = newAlmount;
    } else if (newAlmount == 5) {
        stepperWires = newAlmount;
    }
}

int16_t MotorController::StepperInterface::getSteps() const {
    return steps;
}

void MotorController::StepperInterface::setSteps(const int16_t newSteps) {
    if (newSteps > 4) {
        steps = newSteps;
    }
}

void MotorController::StepperInterface::setSteps(const double stride, const double gearRatio) {
    hwlib::cout << "NOT Inplementedd yet";
}