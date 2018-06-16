/**
 * @file
 * @brief     This file contains a class for the stepper motor Interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef Stepper_Interface_HPP
#define Stepper_Interface_HPP

#include "motor_Interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface for stepper motor
 *
 * This class contains functionalirt to control a stepper motor and is used in the motor controller to do so
 *
 */
class StepperInterface : public MotorInterface {
    ///< Motor angle, 0 - 360
    int16_t angle = 0;

  public:
    /**
     * @brief Default constructor
     */
    StepperInterface();
    /**
     * @brief getter for angle
     */
    int16_t getAngle() const override;
    /**
     * @brief setter for angle
     */
    void setAngle(const int16_t newAngle);
};
} // namespace MotorController

#endif // Stepper_Interface_HPP