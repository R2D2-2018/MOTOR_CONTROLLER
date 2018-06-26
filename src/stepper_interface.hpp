/**
 * @file
 * @brief     This file contains a class for the stepper motor Interface
 * @author    Nick Bout & Olivier Verwoerd
 * @license   MIT License
 */

#ifndef STEPPER_INTERFACE_HPP
#define STEPPER_INTERFACE_HPP

#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface for stepper motor
 *
 * This class contains functionalirt to control a stepper motor and is used in the motor controller to do so
 * The stepper interface uses PWM for future Microstepping (Not implemented yet)
 *
 * More explaination of fucntios in the motor_interface class
 */
class StepperInterface : public MotorInterface {
  public:
    /**
     * @brief Default constructor
     */
    StepperInterface();
    /**
     * @brief getter for speed.Speed is set in the speed to change angle. This function does NOT MOVE THE STEPPER!
     */
    int8_t getSpeed() const override;
    /**
     * @brief setter for speed. Speed is set in the speed to change angle. This function does NOT MOVE THE STEPPER!
     */
    void setSpeed(const int8_t speed) override;
    /**
     * @brief getter for angle
     */
    uint16_t getAngle() const override;
    /**
     * @brief setter for angle
     */
    void setAngle(const int16_t newAngle);
    /**
     * @brief getter for steppermethod, 0: whole step, 1: Halve step
     */
    uint8_t getStepperMethod() const;
    /**
     * @brief setter for steppermethod, 0: whole step, 1: Halve step
     * The set stepper method also sets the frequency to 25khz
     * This is so you wont hear the stepper motor when microstepping is implemented.
     */
    void setStepperMethod(const uint8_t newMethod);
    /**
     * @brief getter for maxsteps
     */
    uint16_t getMaxSteps() const;
    /**
     * @brief setter for steps direct
     */
    void setMaxSteps(const uint16_t newMaxSteps);
    /**
     * @brief setter for indirect
     */
    void setMaxSteps(const double stride, const double gearRatio);
    /**
     * @brief pinout setter to define the sequence in a swich case used internally.
     * Can NOT be accesed with the use of the motor interface.
     */
    void gotoStep(uint8_t step);
    /**
     * @brief The fullstepper logic used internally.
     * Can NOT be accesed with the use of the motor interface.
     */
    void doFullStep(int stepsToDo);
    /**
     * @brief The halfstep logic used internally.
     * Can NOT be accesed with the use of the motor interface.
     */
    void doHalfStep(int stepsToDo);

}; // namespace MotorController
} // namespace MotorController

#endif // Stepper_Interface_HPP