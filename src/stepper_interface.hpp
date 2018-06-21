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
    int16_t getSpeed() const override;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int16_t speed) override;
    /**
     * @brief getter for angle
     */
    uint16_t getAngle() const override;
    /**
     * @brief setter for angle
     */
    void setAngle(const uint16_t newAngle);
    /**
     * @brief getter for stepperwires. Needed for correct stepper sequence.
     */
    uint8_t getStepperWires() const;
    /**
     * @brief setter for stepperwires. Needed for correct stepper sequence. Only 2, 4, and 5 are options
     */
    void setStepperWires(const uint8_t newAmount);
    /**
     * @brief getter for steps
     */
    uint16_t getSteps() const;
    /**
     * @brief setter for steps direct
     */
    void setSteps(const uint16_t newSteps);
    /**
     * @brief setter for indirect
     */
    void setSteps(const double stride, const double gearRatio);

}; // namespace MotorController
} // namespace MotorController

#endif // Stepper_Interface_HPP