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
    // Print selected interface
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
        char answer;
        // Output current state
        hwlib::cout << "Motor direction: "
                    << (motorInterface.getDirection() == MotorController::MotorInterface::DIRECTION::FORWARD ? "Forward"
                                                                                                             : "Backward")
                    << ", speed: " << static_cast<int>(motorInterface.getSpeed()) << "%" << hwlib::endl;

        // Ask new direction
        hwlib::cout << "Give a new direction (0: forward, 1: backward): " << hwlib::endl;
        hwlib::cin >> answer;
        if (answer == '0' || answer == '1') { // Set direction if valid answer
            motorInterface.setDirection(static_cast<MotorController::MotorInterface::DIRECTION>(answer - '0'));
        }

        // Ask new motor speed (hwlib cin does not support int so we use char and multiply by 10 for now)
        hwlib::cout << "Give a new motor speed (0 - 9): " << hwlib::endl;
        hwlib::cin >> answer;
        if (answer >= '0' && answer <= '9') { // Set direction if valid answer
            motorInterface.setSpeed((answer - '0') * 10);
        }
    }

    return 0;
}
