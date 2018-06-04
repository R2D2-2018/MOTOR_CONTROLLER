#include <cstdint>

#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

/**
 * @brief Asks for a number
 *
 * NOTE: This function will be replace in the future with a task, if rtos works
 * Asks for a number between min and max, using hwlib::cin and the given question
 *
 * @param[in]     *question     The question that gets displayed to the console
 * @param[in]     min           The minimum number that can be entered
 * @param[in]     max           The maximum number that can be entered
 *
 */
char askNumber(const char *question, char min = '0', char max = '1');
char askNumber(const char *question, char min, char max) {
    while (true) {
        hwlib::cout << "Select your interface (0: DC, 1: Stepper)" << hwlib::endl;
        char number;
        hwlib::cin >> number;

        if (number >= min && number <= max) {
            // char to int and then cast that to a MotorInterface::INTERFACE
            return number - '0';
        }
    }
}

/**
 * @brief Prints selected interface
 *
 * NOTE: This function will be replace in the future with a task, if rtos works
 * Prints the selected interface of the given motorInterface
 *
 * @param[in]     MotorController::MotorInterface     The motor interface object
 *
 */
void printInterface(MotorController::MotorInterface &motorInterface);
void printInterface(MotorController::MotorInterface &motorInterface) {
    hwlib::cout << "Selected interface:" << hwlib::endl;
    switch (motorInterface.getSelectedInterface()) {
    case MotorController::MotorInterface::INTERFACE::DC:
        hwlib::cout << "DC motor" << hwlib::endl;
        break;
    case MotorController::MotorInterface::INTERFACE::STEPPER:
        hwlib::cout << "Stepper motor" << hwlib::endl;
        break;
    }
}

/**
 * @brief Main logic for motor controller module
 *
 * NOTE: This function will be replace in the future with a task, if rtos works
 * Prints current state (direction, angle and speed) of the motor interface object,
 * then asks for a new direction, angle and speed.
 *
 * @param[in]     MotorController::MotorInterface     The motor interface object
 *
 */
void mainLogic(MotorController::MotorInterface &motorInterface);
void mainLogic(MotorController::MotorInterface &motorInterface) {
    while (true) {
        char answer;
        // Output current state
        hwlib::cout << "Motor direction: "
                    << (motorInterface.getDirection() == MotorController::MotorInterface::DIRECTION::FORWARD ? "Forward"
                                                                                                             : "Backward")
                    << ", speed: " << static_cast<int>(motorInterface.getSpeed())
                    << "%, angle: " << static_cast<int>(motorInterface.getAngle()) << hwlib::endl;

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

        // Ask new motor angle (hwlib cin does not support int so we use char and multiply by 36 for now)
        hwlib::cout << "Give a new motor angle (0 - 9): " << hwlib::endl;
        hwlib::cin >> answer;
        if (answer >= '0' && answer <= '9') { // Set direction if valid answer
            motorInterface.setAngle((answer - '0') * 36);
        }

        hwlib::cout << hwlib::endl;
    }
}

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    MotorController::MotorInterface motorInterface;

    // Ask user which interface should be used
    constexpr const char question[] = "Select your interface (0: DC, 1: Stepper)";
    motorInterface.setSelectedInterface(static_cast<MotorController::MotorInterface::INTERFACE>(askNumber(question)));

    // Print selected interface
    printInterface(motorInterface);

    // TODO: We should see if we can make rtos work, then we can make this function a task
    mainLogic(motorInterface);

    return 0;
}
