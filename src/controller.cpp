#include "controller.hpp"

MotorController::Controller::Controller() : dcInterface(), stepperInterface(), servoInterface() {
}

MotorController::Controller::Interface MotorController::Controller::getSelectedInterface() const {
    // Getting while interface is nullptr
    if (selectedInterface == nullptr) {
        hwlib::cout << "Error:: Trying to get an nullptr interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
        return MotorController::Controller::Interface::None;
    }

    // Convert the Interface to enum
    if (selectedInterface == &servoInterface) {
        return MotorController::Controller::Interface::Servo;
    } else if (selectedInterface == &stepperInterface) {
        return MotorController::Controller::Interface::Stepper;
    }
    return MotorController::Controller::Interface::DC;
}

bool MotorController::Controller::setSelectedInterface(const MotorController::Controller::Interface newInterface) {
    // Prevent setting the Interface a second time
    if (selectedInterface != nullptr) {
        return false;
    }

    switch (newInterface) {
    case MotorController::Controller::Interface::DC:
        selectedInterface = &dcInterface;
        return true;
    case MotorController::Controller::Interface::Stepper:
        selectedInterface = &stepperInterface;
        return true;
    case MotorController::Controller::Interface::Servo:
        selectedInterface = &servoInterface;
        return true;
    default:
        // Interface not supported
        hwlib::cout << "Error: Trying to set and not supported Interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
        return false;
    }
}

int8_t MotorController::Controller::getSpeed() const {
    return selectedInterface->getSpeed();
}

void MotorController::Controller::setSpeed(const int8_t newSpeed) {
    selectedInterface->setSpeed(newSpeed);
}

uint16_t MotorController::Controller::getAngle() const {
    return selectedInterface->getAngle();
}

void MotorController::Controller::setAngle(const int16_t newAngle) {
    return selectedInterface->setAngle(newAngle);
}

uint8_t MotorController::Controller::getStepperMethod() const {
    return selectedInterface->getStepperMethod();
}

void MotorController::Controller::setStepperMethod(const uint8_t newMethod) {
    return selectedInterface->setStepperMethod(newMethod);
}

uint16_t MotorController::Controller::getSteps() const {
    return selectedInterface->getSteps();
}

void MotorController::Controller::setSteps(const uint16_t newSteps) {
    return selectedInterface->setSteps(newSteps);
}

void MotorController::Controller::setSteps(const double stride, const double gearRatio) {
    return selectedInterface->setSteps(stride, gearRatio);
}