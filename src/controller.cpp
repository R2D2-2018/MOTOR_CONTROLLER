#include "controller.hpp"

MotorController::Controller::Controller() : dcInterface(), stepperInterface() {
}

MotorController::Controller::INTERFACE MotorController::Controller::getSelectedInterface() const {
    // Getting while interface is nullptr
    if (selectedInterface == nullptr) {
        hwlib::cout << "Error:: Trying to get an nullptr interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
        // Better not continue
        while (1) {
        }
    }

    // Convert the interface to enum
    if (selectedInterface == &dcInterface) {
        return MotorController::Controller::INTERFACE::DC;
    }

    return MotorController::Controller::INTERFACE::STEPPER;
}

void MotorController::Controller::setSelectedInterface(const MotorController::Controller::INTERFACE newInterface) {
    // Prevent setting the interface a second time
    if (selectedInterface != nullptr) {
        return;
    }

    switch (newInterface) {
    case MotorController::Controller::INTERFACE::DC:
        selectedInterface = &dcInterface;
        break;
    case MotorController::Controller::INTERFACE::STEPPER:
        selectedInterface = &stepperInterface;
        break;
    default:
        // Interface not supported
        hwlib::cout << "Error: Trying to set and not supported interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
        // Better not continue
        while (1) {
        }
        break;
    }
}

bool MotorController::Controller::getEnable() const {
    return selectedInterface->getEnable();
}

void MotorController::Controller::setEnable(const bool state) {
    selectedInterface->setEnable(state);
}

int16_t MotorController::Controller::getSpeed() const {
    return selectedInterface->getSpeed();
}

void MotorController::Controller::setSpeed(const int16_t newSpeed) {
    selectedInterface->setSpeed(newSpeed);
}

uint16_t MotorController::Controller::getAngle() const {
    return selectedInterface->getAngle();
}

void MotorController::Controller::setAngle(const uint16_t newAngle) {
    return selectedInterface->setAngle(newAngle);
}