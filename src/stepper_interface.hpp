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
     * @brief getter for speed.Speed is set in the speed to change angle.
     * This function does NOT MOVE THE STEPPER!
     * @param[out] speed -100 / 100
     */
    int8_t getSpeed() const override;
    /**
     * @brief setter for speed. Speed is set in the speed to change angle.
     * This function does NOT MOVE THE STEPPER!
     * @param[in] speed -100 / 100
     */
    void setSpeed(const int8_t speed) override;
    /**
     * @brief getter for angle
     * @param[in] angle that the stapper shuould rotate. -720 is 2 rounds counter clockwise
     */
    uint16_t getAngle() const override;
    /**
     * @brief setter for angle
     * @param[out] angle of stepper in degree 0 / 360
     */
    void setAngle(const int16_t newAngle);
    /**
     * @brief getter for steppermethod, 0: whole step, 1: Halve step
     * @param[out] 0 or 1
     */
    uint8_t getStepperMethod() const;
    /**
     * @brief setter for steppermethod, 0: whole step, 1: Halve step
     * The set stepper method also sets the frequency to 25khz
     * This is so you wont hear the stepper motor when microstepping is implemented.
     * @param[in] 0 or 1
     */
    void setStepperMethod(const uint8_t newMethod);
    /**
     * @brief getter for maxsteps
     * @param[out] maximum of steps the stepper can make
     */
    uint16_t getMaxSteps() const;
    /**
     * @brief setter for steps direct
     * @param[in] maximum of steps the stepper can make
     */
    void setMaxSteps(const uint16_t newMaxSteps);
    /**
     * @brief setter for indirect
     * @param[in] stepper stride and gear ratio(1/?) for example 5.625, 64
     */
    void setMaxSteps(const double stride, const double gearRatio);
    /**
     * @brief pinout setter to define the sequence in a swich case used internally.
     * Can NOT be accesed with the use of the motor interface.
     * @param[in] the step of the stepper sequence 0 / 7
     */
    void gotoStep(uint8_t step);
    /**
     * @brief The fullstepper logic used internally.
     * Can NOT be accesed with the use of the motor interface.
     * @param[in] how many steps it should do where negative is counter clockwise
     * for example -4000 is almost a full rotation backwards
     */
    void doFullStep(int stepsToDo);
    /**
     * @brief The halfstep logic used internally.
     * Can NOT be accesed with the use of the motor interface.
     * @param[in] how many steps it should do where negative is counter clockwise
     * for example -4000 is almost a full rotation backwards
     */
    void doHalfStep(int stepsToDo);

}; ///< namespace MotorController
} ///< namespace MotorController

#endif ///< Stepper_Interface_HPP