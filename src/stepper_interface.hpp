/**
 * @file
 * @brief     This file contains a class for the stepper motor interface
 * @author    Nick Bout
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
     * @brief getter for direction
     */
    Direction getDirection() const override;
    /**
     * @brief setter for direction
     */
    void setDirection(const Direction direction) override;
    /**
     * @brief getter for speed
     */
    uint8_t getSpeed() const override;
    /**
     * @brief setter for speed
     */
    void setSpeed(const uint8_t speed) override;
    /**
     * @brief getter for speed
     */
    uint16_t getAngle() const override;
    /**
     * @brief setter for speed
     */
    void setAngle(const uint16_t newAngle);
};
} // namespace MotorController

#endif // STEPPER_INTERFACE_HPP