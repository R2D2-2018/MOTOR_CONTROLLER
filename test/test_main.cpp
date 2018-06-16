#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "controller.hpp"
#include "dc_interface.hpp"
#include "motor_interface.hpp"

// cppcheck-suppress unusedFunction
TEST_CASE("Controller: setInterface") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::Stepper);

    REQUIRE(motorController.getSelectedInterface() == MotorController::Controller::Interface::Stepper);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::DC);

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    REQUIRE(motorController.getSelectedInterface() == MotorController::Controller::Interface::Stepper);
    REQUIRE(motorController.getSelectedInterface() != MotorController::Controller::Interface::DC);
}

TEST_CASE("Controller dcInterface selected: Default direction") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    REQUIRE(motorController.getDirection() == MotorController::MotorInterface::Direction::Forward);
    REQUIRE(motorController.getDirection() != MotorController::MotorInterface::Direction::Backward);
}

TEST_CASE("Controller dcInterface selected: setDirection") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setDirection(MotorController::MotorInterface::Direction::Backward);

    REQUIRE(motorController.getDirection() == MotorController::MotorInterface::Direction::Backward);
    REQUIRE(motorController.getDirection() != MotorController::MotorInterface::Direction::Forward);
}

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

TEST_CASE("Controller dcInterface selected: setSpeed, no overflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(101);

    REQUIRE(motorController.getSpeed() == 0);
}

TEST_CASE("Controller dcInterface selected: setSpeed, no underflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setSpeed(-1);

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
    REQUIRE(motorController.getAngle() == 244);
}

TEST_CASE("Controller dcInterface selected: no overflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);
    motorController.setAngle(0);

    motorController.setAngle(361);
    REQUIRE(motorController.getAngle() == 0);
    motorController.setAngle(3601);
    REQUIRE(motorController.getAngle() == 0);
}

TEST_CASE("Controller dcInterface selected: no underflow") {
    MotorController::Controller motorController;

    motorController.setSelectedInterface(MotorController::Controller::Interface::DC);

    motorController.setAngle(0);

    motorController.setAngle(-361);
    REQUIRE(motorController.getAngle() == 0);
    motorController.setAngle(-3601);
    REQUIRE(motorController.getAngle() == 0);
}

TEST_CASE("DCInterface: Default direction") {
    MotorController::DcInterface motorInterface;

    REQUIRE(motorInterface.getDirection() == MotorController::MotorInterface::Direction::Forward);
    REQUIRE(motorInterface.getDirection() != MotorController::MotorInterface::Direction::Backward);
}

TEST_CASE("DCInterface: setDirection") {
    MotorController::DcInterface motorInterface;

    motorInterface.setDirection(MotorController::MotorInterface::Direction::Backward);

    REQUIRE(motorInterface.getDirection() == MotorController::MotorInterface::Direction::Backward);
    REQUIRE(motorInterface.getDirection() != MotorController::MotorInterface::Direction::Forward);
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

    motorInterface.setSpeed(101);

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setSpeed, no underflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setSpeed(-1);

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("DCInterface: setAngle") {
    MotorController::DcInterface motorInterface;

    motorInterface.setAngle(360);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(0);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(244);
    REQUIRE(motorInterface.getAngle() == 244);
}

TEST_CASE("DCInterface: no overflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setAngle(0);

    motorInterface.setAngle(361);
    REQUIRE(motorInterface.getAngle() == 0);
    motorInterface.setAngle(3601);
    REQUIRE(motorInterface.getAngle() == 0);
}

TEST_CASE("DCInterface: no underflow") {
    MotorController::DcInterface motorInterface;

    motorInterface.setAngle(0);

    motorInterface.setAngle(-361);
    REQUIRE(motorInterface.getAngle() == 0);
    motorInterface.setAngle(-3601);
    REQUIRE(motorInterface.getAngle() == 0);
}