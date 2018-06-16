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
  public:
    /**
     * @brief Default constructor
     */
    StepperInterface();
    /**
     * @brief getter for Enable
     */
<<<<<<< HEAD
    bool getEnable() const override;
=======
    Direction getDirection() const override;
>>>>>>> development
    /**
     * @brief setter for Enable
     */
<<<<<<< HEAD
    void setEnable(const bool state) override;
=======
    void setDirection(const Direction direction) override;
>>>>>>> development
    /**
     * @brief getter for speed
     */
    int16_t getSpeed() const override;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int16_t speed) override;
    /**
     * @brief getter for speed
     */
    int16_t getAngle() const override;
    /**
     * @brief setter for speed
     */
    void setAngle(const int16_t newAngle);
};
} // namespace MotorController

#endif // Stepper_Interface_HPP