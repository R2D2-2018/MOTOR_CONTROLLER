/**
 * @file
 * @brief     This file contains a class for the stepper motor Interface
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
     * @brief setter for stepperwires. Needed for correct stepper sequence.
     */
    void setStepperWires(const uint8_t newAlmount);
    /**
     * @brief getter for stride
     */
    double getStride() const;
    /**
     * @brief setter for stride
     */
    void setStride(const double newStride);
    /**
     * @brief getter for gear ratio
     */
    uint8_t getGearRatio() const;
    /**
     * @brief setter for gear ratio
     */
    void setGearRatio(const uint8_t newRatio);
};
} // namespace MotorController

#endif // Stepper_Interface_HPP