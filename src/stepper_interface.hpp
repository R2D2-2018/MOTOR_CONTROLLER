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
 *
 */
class StepperInterface : public MotorInterface {
  public:
    /**
     * @brief Default constructor
     */
    StepperInterface();
    /**
     * @brief getter for speed
     */
    int8_t getSpeed() const override;
    /**
     * @brief setter for speed
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
     * @brief getter for steppermethod, 0: whole step, 1: Halve step, 2 Microstepping.
     */
    uint8_t getStepperMethod() const;
    /**
     * @brief setter for steppermethod, 0: whole step, 1: Halve step, 2 Microstepping.
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

}; // namespace MotorController
} // namespace MotorController

#endif // Stepper_Interface_HPP