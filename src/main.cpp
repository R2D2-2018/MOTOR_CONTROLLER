#include <cstdint>

#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    MotorController::MotorInterface motorInterface;

    // Ask user which interface should be used
    constexpr const char numberOfOptions = '1';
    while (true) {
        hwlib::cout << "Select your interface (0: DC, 1: Stepper)" << hwlib::endl;
        char interface;
        hwlib::cin >> interface;

        if (interface >= '0' && interface <= numberOfOptions) {
            // char to int and then cast that to a MotorInterface::INTERFACE
            motorInterface.setSelectedInterface(static_cast<MotorController::MotorInterface::INTERFACE>(interface - '0'));
            break;
        }
    }
    hwlib::cout << "Selected interface:" << hwlib::endl;

    switch (motorInterface.getSelectedInterface()) {
    case MotorController::MotorInterface::INTERFACE::DC:
        hwlib::cout << "DC motor" << hwlib::endl;
        break;
    case MotorController::MotorInterface::INTERFACE::STEPPER:
        hwlib::cout << "Stepper motor" << hwlib::endl;
        break;
    }

    while (true) {
    }

    return 0;
}
