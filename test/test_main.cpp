#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "motor_interface.hpp"

// cppcheck-suppress unusedFunction
TEST_CASE("MotorInterface: Default interface") {
    MotorInterface motorInterface;
    REQUIRE(motorInterface.getSelectedInterface() == MotorInterface::INTERFACE::DC);
    REQUIRE(motorInterface.getSelectedInterface() != MotorInterface::INTERFACE::STEPPER);
}
