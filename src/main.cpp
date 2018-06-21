#include "controller.hpp"
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
        hwlib::cout << "Select your Interface (0: DC, 1: Stepper)" << hwlib::endl;
        char number;
        hwlib::cin >> number;

        if (number >= min && number <= max) {
            // char to int and then cast that to a MotorInterface::Interface
            return number - '0';
        }
    }
}

/**
 * @brief Prints selected Interface
 *
 * NOTE: This function will be replace in the future with a task, if rtos works
 * Prints the selected Interface of the given motorInterface
 *
 * @param[in]     MotorController::Controller     The motor Interface object
 *
 */
void printInterface(MotorController::Controller &motorController);
void printInterface(MotorController::Controller &motorController) {
    hwlib::cout << "Selected Interface:" << hwlib::endl;
    switch (motorController.getSelectedInterface()) {
    case MotorController::Controller::Interface::DC:
        hwlib::cout << "DC motor" << hwlib::endl;
        break;
    case MotorController::Controller::Interface::Stepper:
        hwlib::cout << "Stepper motor" << hwlib::endl;
        break;
    default:
        break;
    }
}

/**
 * @brief Main logic for motor controller module
 *
 * NOTE: This function will be replace in the future with a task, if rtos works
 * Prints current state (direction, angle and speed) of the motor Interface object,
 * then asks for a new direction, angle and speed.
 *
 * @param[in]     MotorController::Controller     The motor Interface object
 *
 */
void mainLogic(MotorController::Controller &motorController);
void mainLogic(MotorController::Controller &motorController) {
    while (true) {
        char answer;
        // Output current state
        hwlib::cout << ", speed: " << static_cast<int>(motorController.getSpeed())
                    << "%, angle: " << static_cast<int>(motorController.getAngle()) << hwlib::endl;

        // Ask new motor speed (hwlib cin does not support int so we use char and multiply by 10 for now)
        hwlib::cout << "Give a new motor speed (0 - 9): " << hwlib::endl;
        hwlib::cin >> answer;
        if (answer >= '0' && answer <= '9') { // Set direction if valid answer
            motorController.setSpeed((answer - '0') * 50 - 250);
        }

        // Ask new motor angle (hwlib cin does not support int so we use char and multiply by 36 for now)
        hwlib::cout << "Give a new motor angle (0 - 9): " << hwlib::endl;
        hwlib::cin >> answer;
        if (answer >= '0' && answer <= '9') { // Set direction if valid answer
            motorController.setAngle((answer - '0') * 36);
        }

        hwlib::cout << hwlib::endl;
    }
}

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    /**
    MotorController::Controller motorController;
    // Ask user which Interface should be used
    constexpr const char question[] = "Select your Interface (0: DC, 1: Stepper)";
    motorController.setSelectedInterface(static_cast<MotorController::Controller::Interface>(askNumber(question)));

    // Print selected Interface
    printInterface(motorController);

    // TODO: We should see if we can make rtos work, then we can make this function a task
    mainLogic(motorController);
    */

    MotorController::Controller motorController;
    constexpr const char question[] = "Select your Interface (0: DC, 1: Stepper)";
    motorController.setSelectedInterface(static_cast<MotorController::Controller::Interface>(askNumber(question)));
    while (1) {
        motorController.setSpeed(10);
        hwlib::wait_ms(5000);
        motorController.setSpeed(0);

        motorController.setAngle(0);
        hwlib::wait_ms(2000);
        motorController.setSpeed(-10);
        hwlib::wait_ms(5000);
    }
    return 0;
}
