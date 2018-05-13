#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "src/MotorInterface.hpp"

// cppcheck-suppress unusedFunction
TEST_CASE("Example Test Case") {
    MotorInterface motorInterface;
    REQUIRE(motorInterface.getSelectedInterface() == 1);
    REQUIRE(motorInterface.getSelectedInterface() == MotorInterface::INTERFACE::DC);
    REQUIRE(motorInterface.getSelectedInterface() != MotorInterface::INTERFACE::AC);
    REQUIRE(motorInterface.getSelectedInterface() != "AC");
    REQUIRE(motorInterface.getSelectedInterface() != 2);
    REQUIRE(motorInterface.getSelectedInterface() != NULL);
}
