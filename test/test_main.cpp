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
    motorController.setSpeed(255);
    REQUIRE(motorController.getSpeed() == 255);
}

TEST_CASE("Controller dcInterface selected: setSpeed negative") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    motorController.setSpeed(-60);
    REQUIRE(motorController.getSpeed() == -60);
    motorController.setSpeed(-255);
    REQUIRE(motorController.getSpeed() == -255);
}

TEST_CASE("Controller dcInterface selected: setSpeed, no overflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(400);

    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("Controller dcInterface selected: setSpeed, no underflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(-300);
    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("Controller dcInterface selected: setAngle") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    motorController.setAngle(360);
    REQUIRE(motorController.getAngle() == 0);

    motorController.setAngle(0);
    REQUIRE(motorController.getAngle() == 0);

    motorController.setAngle(244);
    REQUIRE(motorController.getAngle() == 0);
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

    motorInterface.setSpeed(300);
    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setSpeed, no underflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setSpeed(-265);

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setAngle") {
    MotorController::DcInterface motorInterface;

    motorInterface.setAngle(360);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(0);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(244);
    REQUIRE(motorInterface.getAngle() == 0);
}
//----------------STEPPER----------------
TEST_CASE("Stepper Interface: set wires") {
    MotorController::StepperInterface motorInterface;
    REQUIRE(motorInterface.getStepperWires() == 4);
    motorInterface.setStepperWires(0);
    REQUIRE(motorInterface.getStepperWires() == 4);
    motorInterface.setStepperWires(2);
    REQUIRE(motorInterface.getStepperWires() == 2);
    motorInterface.setStepperWires(6);
    REQUIRE(motorInterface.getStepperWires() == 2);
    motorInterface.setStepperWires(5);
    REQUIRE(motorInterface.getStepperWires() == 5);
}

TEST_CASE("Stepper Interface: set gearratio") {
    MotorController::StepperInterface motorInterface;
    REQUIRE(motorInterface.getGearRatio() == 1);
    motorInterface.setGearRatio(0);
    REQUIRE(motorInterface.getGearRatio() == 1);
    motorInterface.setGearRatio(3);
    REQUIRE(motorInterface.getGearRatio() == 3);
}

TEST_CASE("Stepper Interface: set stride") {
    MotorController::StepperInterface motorInterface;
    REQUIRE(motorInterface.getStride() == 0.1);
    motorInterface.setStride(0);
    REQUIRE(motorInterface.getStride() == 0.1);
    motorInterface.setStride(3);
    REQUIRE(motorInterface.getStride() == 3);
    motorInterface.setStride(3.14);
    REQUIRE(motorInterface.getStride() == 3.14);
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

    motorInterface.setAngle(244);
    REQUIRE(motorInterface.getAngle() == 244);
}