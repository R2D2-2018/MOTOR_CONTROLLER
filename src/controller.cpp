#include "controller.hpp"

MotorController::Controller::Controller() : dcInterface(), stepperInterface() {
}

MotorController::Controller::Interface MotorController::Controller::getSelectedInterface() const {
<<<<<<< HEAD
    // Getting while Interface is nullptr
    if (selectedInterface == nullptr) {
        hwlib::cout << "Error:: Trying to get an nullptr Interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
=======
    // Getting while interface is nullptr
    if (selectedInterface == nullptr) {
        hwlib::cout << "Error:: Trying to get an nullptr interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
        return MotorController::Controller::Interface::None;
>>>>>>> development
    }

    // Convert the Interface to enum
    if (selectedInterface == &dcInterface) {
        return MotorController::Controller::Interface::DC;
    }

    return MotorController::Controller::Interface::Stepper;
}

bool MotorController::Controller::setSelectedInterface(const MotorController::Controller::Interface newInterface) {
<<<<<<< HEAD
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
    default:
        // Interface not supported
        hwlib::cout << "Error: Trying to set and not supported Interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
=======
    // Prevent setting the interface a second time
    if (selectedInterface != nullptr) {
        return true;
    }

    if (newInterface == MotorController::Controller::Interface::DC) {
        selectedInterface = &dcInterface;
        return true;
    } else if (newInterface == MotorController::Controller::Interface::Stepper) {
        selectedInterface = &stepperInterface;
        return true;
    } else {
        hwlib::cout << "Error: Trying to set and not supported interface (controller.cpp, line: " << __LINE__ << ")" << hwlib::endl;
>>>>>>> development
        return false;
    }
}

<<<<<<< HEAD
bool MotorController::Controller::getEnable() const {
    return selectedInterface->getEnable();
}

void MotorController::Controller::setEnable(const bool state) {
    selectedInterface->setEnable(state);
=======
MotorController::MotorInterface::Direction MotorController::Controller::getDirection() const {
    return selectedInterface->getDirection();
}

void MotorController::Controller::setDirection(const MotorController::MotorInterface::Direction newDirection) {
    selectedInterface->setDirection(newDirection);
>>>>>>> development
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