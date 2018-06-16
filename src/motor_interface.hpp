/**
 * @file
 * @brief     This file contains a class for the motor Interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef MOTOR_Interface_HPP
#define MOTOR_Interface_HPP

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
    bool enable = true;
    ///< Motor rotation speed, 0 - 255
    int16_t speed = 0;
    ///< Motor angle, 0 - 360
    int16_t angle = 0;
    ///< Pinout Enable
    hwlib::pin_out &enablePin = hwlib::pin_out_dummy;

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
    virtual bool getEnable() const = 0;
    /**
     * @brief setter for Enable
     */
    virtual void setEnable(const bool state) = 0;
    /**
     * @brief getter for speed
     */
    virtual int16_t getSpeed() const = 0;
    /**
     * @brief setter for speed
     */
    virtual void setSpeed(const int16_t speed) = 0;
    /**
     * @brief getter for speed
     */
    virtual int16_t getAngle() const = 0;
    /**
     * @brief setter for speed
     */
    virtual void setAngle(const int16_t newAngle) = 0;
};
} // namespace MotorController

#endif // MOTOR_Interface_HPP