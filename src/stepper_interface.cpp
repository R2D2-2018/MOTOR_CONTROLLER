#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

int8_t MotorController::StepperInterface::getSpeed() const {
    return speed;
}

void MotorController::StepperInterface::setSpeed(const int8_t newSpeed) {
    // Speed can only be -255 / 255
    if (newSpeed == 0) {
        speed = newSpeed;
    } else if (newSpeed > 0 && newSpeed <= 100) {
        speed = newSpeed;
    } else if (newSpeed < 0 && newSpeed >= -100) {
        speed = newSpeed;
    }
}

uint16_t MotorController::StepperInterface::getAngle() const {
    return angle;
}

void MotorController::StepperInterface::setAngle(const int16_t newAngle) {
    if (newAngle < 360) {
        angle = newAngle;
    }
}

uint8_t MotorController::StepperInterface::getStepperMethod() const {
    return stepperMethod;
}

void MotorController::StepperInterface::setStepperMethod(const uint8_t newMethod) {
    if (newMethod <= 2) {
        stepperMethod = newMethod;
    }
}

uint16_t MotorController::StepperInterface::getMaxSteps() const {
    return maxSteps;
}

void MotorController::StepperInterface::setMaxSteps(const uint16_t newMaxSteps) {
    if (newMaxSteps > 4) {
        maxSteps = newMaxSteps;
    }
}

void MotorController::StepperInterface::setMaxSteps(const double stride, const double gearRatio) {
    if (stride > 0) {
        maxSteps = (360 / stride) * gearRatio;
    }
}