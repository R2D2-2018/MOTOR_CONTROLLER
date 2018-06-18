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
  protected:
    ///< Motor rotation speed, 0 - 255
    int16_t speed = 0;
    ///< Motor angle, 0 - 360
    int16_t angle = 0;
    // hwlib::target::pin_out enablePin = hwlib::target::pin_out(hwlib::target::pins::d13);
    // hwlib::target::pin_out forwardPin = hwlib::target::pin_out(hwlib::target::pins::d3);
    // hwlib::target::pin_out backwardPin = hwlib::target::pin_out(hwlib::target::pins::d4);
    // auto led = hwlib::target::pin_out(hwlib::target::pins::d13);
  public:
    /**
     * @brief Default constructor
     */
    MotorInterface(){};

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