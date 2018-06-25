#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "controller.hpp"
#include "dc_interface.hpp"
#include "motor_interface.hpp"
#include "servo_interface.hpp"
#include "stepper_interface.hpp"

// cppcheck-suppress unusedFunction

//----------------CONTROLLER----------------

TEST_CASE("Controller: setInterface Servo") {
    MotorController::Controller motorController;
    motorController.setSelectedInterface(MotorController::Controller::Interface::Servo);

    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::Stepper);
    REQUIRE(motorController.getSelectedInterface() == MotorController::Controller::Interface::Servo);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::DC);
}
TEST_CASE("Controller: setInterface DC") {
    MotorController::Controller motorController;
    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::Stepper);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::Servo);
    REQUIRE(motorController.getSelectedInterface() == MotorController::Controller::Interface::DC);
}
TEST_CASE("Controller: setInterface Stepper") {
    MotorController::Controller motorController;
    motorController.setSelectedInterface(MotorController::Controller::Interface::Stepper);

    REQUIRE(motorController.getSelectedInterface() == MotorController::Controller::Interface::Stepper);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::Servo);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::DC);
}

//----------------DC----------------

TEST_CASE("DCIntController dcInterface selectedrface: Default speed") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("Controller dcInterface selected: setSpeed") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    motorController.setSpeed(60);
    REQUIRE(motorController.getSpeed() == 60);
}

TEST_CASE("Controller dcInterface selected: setSpeed negative") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    motorController.setSpeed(-60);
    REQUIRE(motorController.getSpeed() == -60);
}

TEST_CASE("Controller dcInterface selected: setSpeed, no overflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(120);

    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("Controller dcInterface selected: setSpeed, no underflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(-120);
    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("DCInterface: Default speed") {
    MotorController::DcInterface motorInterface;

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setSpeed") {
    MotorController::DcInterface motorInterface;

    motorInterface.setSpeed(60);

    REQUIRE(motorInterface.getSpeed() == 60);
}

TEST_CASE("DCInterface: setSpeed, no overflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setSpeed(120);
    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setSpeed, no underflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setSpeed(-120);

    REQUIRE(motorInterface.getSpeed() == 0);
}

//----------------STEPPER----------------
TEST_CASE("Stepper Interface: setSpeed") {
    MotorController::StepperInterface motorInterface;
    motorInterface.setSpeed(60);
    REQUIRE(motorInterface.getSpeed() == 60);
}

TEST_CASE("Stepper Interface: set method") {
    MotorController::StepperInterface motorInterface;
    REQUIRE(motorInterface.getStepperMethod() == 0);
    motorInterface.setStepperMethod(7);
    REQUIRE(motorInterface.getStepperMethod() == 0);
    motorInterface.setStepperMethod(2);
    REQUIRE(motorInterface.getStepperMethod() == 2);
}

TEST_CASE("Stepper Interface: set steps") {
    MotorController::StepperInterface motorInterface;
    REQUIRE(motorInterface.getMaxSteps() == 4);
    motorInterface.setMaxSteps(0);
    REQUIRE(motorInterface.getMaxSteps() == 4);
    motorInterface.setMaxSteps(8);
    REQUIRE(motorInterface.getMaxSteps() == 8);
    motorInterface.setMaxSteps(5.625, 64);
    REQUIRE(motorInterface.getMaxSteps() == 4096);
}

//----------------SERVO----------------

TEST_CASE("Servo Interface: setAngle") {
    MotorController::ServoInterface motorInterface;

    motorInterface.setAngle(360);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(0);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(-5);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(120);
    REQUIRE(motorInterface.getAngle() == 120);
}