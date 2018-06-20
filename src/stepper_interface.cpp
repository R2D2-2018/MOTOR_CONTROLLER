#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

uint16_t MotorController::StepperInterface::getAngle() const {
    return angle;
}

void MotorController::StepperInterface::setAngle(const uint16_t newAngle) {
    if (newAngle >= 0 && newAngle < 360) {
        angle = newAngle;
    }
}

uint8_t MotorController::StepperInterface::getStepperWires() const {
    return stepperWires;
}

void MotorController::StepperInterface::setStepperWires(const uint8_t newAlmount) {
    if (newAlmount >= 3 && newAlmount <= 5) {
        stepperWires = newAlmount;
    }
}

double MotorController::StepperInterface::getStride() const {
    return stride;
}

void MotorController::StepperInterface::setStride(const double newStride) {
    if (newStride > 0 && newStride < 360) {
        stride = newStride;
    }
}

uint8_t MotorController::StepperInterface::getGearRatio() const {
    return gearRatio;
}

void MotorController::StepperInterface::setGearRatio(const uint8_t newRatio) {
    hwlib::cout << "Function not supported yet" << hwlib::endl;
    if (newRatio > 0 && newRatio <= 255) {
        gearRatio = newRatio;
    }
}