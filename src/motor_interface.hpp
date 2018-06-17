/**
 * @file
 * @brief     This file contains a class for the motor Interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Abstract Interface class used by other Interfaces
 *
 * This class is a super class for Interfaces for all supported motor types
 *
 */
class MotorInterface {
  public:
    /**
     * @brief Default constructor
     */
    MotorInterface(){};
    /**
     * @brief Default constructor
     */
    // MotorInterface(hwlib::pin_out &enablePin) : enablePin(enablePin){};
    /**
     * @brief getter for speed
     */
    virtual bool getEnable() const {
        return 0;
    };
    /**
     * @brief setter for Enable
     */
    virtual void setEnable(const bool state){};
    /**
     * @brief getter for speed
     */
    virtual int16_t getSpeed() const {
        return 0;
    };
    /**
     * @brief setter for speed
     */
    virtual void setSpeed(const int16_t speed){};
    /**
     * @brief getter for speed
     */
    virtual int16_t getAngle() const {
        return 0;
    };
    /**
     * @brief setter for speed
     */
    virtual void setAngle(const int16_t newAngle){};
    /**
     * @brief setter for forward pin in PWM
     */
    virtual void setForwardPin(hwlib::pin_out &newForwardPwmPin){};
    /**
     * @brief setter for backwards pin in PWM
     */
    virtual void setBackwardPin(hwlib::pin_out &newBackwardPwmPin){};
    /**
     * @brief setter for enable pin
     */
    virtual void setEnablePin(hwlib::pin_out &newEnablePin){};
};
} // namespace MotorController

#endif // MOTOR_Interface_HPP