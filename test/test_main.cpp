#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "motor_interface.hpp"

// cppcheck-suppress unusedFunction
TEST_CASE("MotorInterface: Default interface") {
    MotorController::MotorInterface motorInterface;
    REQUIRE(motorInterface.getSelectedInterface() == MotorController::MotorInterface::INTERFACE::DC);
    REQUIRE(motorInterface.getSelectedInterface() != MotorController::MotorInterface::INTERFACE::STEPPER);
}

TEST_CASE("MotorInterface: setInterface") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setSelectedInterface(MotorController::MotorInterface::INTERFACE::STEPPER);

    REQUIRE(motorInterface.getSelectedInterface() == MotorController::MotorInterface::INTERFACE::STEPPER);
    REQUIRE(motorInterface.getSelectedInterface() != MotorController::MotorInterface::INTERFACE::DC);
}

TEST_CASE("MotorInterface: Default direction") {
    MotorController::MotorInterface motorInterface;

    REQUIRE(motorInterface.getDirection() == MotorController::MotorInterface::DIRECTION::FORWARD);
    REQUIRE(motorInterface.getDirection() != MotorController::MotorInterface::DIRECTION::BACKWARD);
}

TEST_CASE("MotorInterface: setDirection") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setDirection(MotorController::MotorInterface::DIRECTION::BACKWARD);

    REQUIRE(motorInterface.getDirection() == MotorController::MotorInterface::DIRECTION::BACKWARD);
    REQUIRE(motorInterface.getDirection() != MotorController::MotorInterface::DIRECTION::FORWARD);
}

TEST_CASE("MotorInterface: Default speed") {
    MotorController::MotorInterface motorInterface;

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("MotorInterface: setSpeed") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setSpeed(60);

    REQUIRE(motorInterface.getSpeed() == 60);
}

TEST_CASE("MotorInterface: setSpeed, no overflow") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setSpeed(101);

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("MotorInterface: setSpeed, no underflow") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setSpeed(-1);

    REQUIRE(motorInterface.getSpeed() == 0);
}

TEST_CASE("MotorInterface: setAngle") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setAngle(360);
    REQUIRE(motorInterface.getAngle() == 360);

    motorInterface.setAngle(-360);
    REQUIRE(motorInterface.getAngle() == -360);

    motorInterface.setAngle(0);
    REQUIRE(motorInterface.getAngle() == 0);

    motorInterface.setAngle(244);
    REQUIRE(motorInterface.getAngle() == 244);
}

TEST_CASE("MotorInterface: no overflow") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setAngle(0);

    motorInterface.setAngle(361);
    REQUIRE(motorInterface.getAngle() == 0);
    motorInterface.setAngle(3601);
    REQUIRE(motorInterface.getAngle() == 0);
}

TEST_CASE("MotorInterface: no underflow") {
    MotorController::MotorInterface motorInterface;

    motorInterface.setAngle(0);

    motorInterface.setAngle(-361);
    REQUIRE(motorInterface.getAngle() == 0);
    motorInterface.setAngle(-3601);
    REQUIRE(motorInterface.getAngle() == 0);
}