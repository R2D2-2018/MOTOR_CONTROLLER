/**
 * @file
 * @brief     This file contains a class for the motor interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Abstract interface class used by other interfaces
 *
 * This class is a super class for interfaces for all supported motor types
 *
 */
class MotorInterface {
  public:
    ///< Enum class with all possible motor directions
    enum class Direction { Forward, Backward };

  protected:
    ///< The direction of the motor rotation, forward by default
    Direction direction = Direction::Forward;
    ///< Motor rotation speed, 0 - 100%
    uint8_t speed = 0;
    ///< Motor angle, 0 - 360
    uint16_t angle = 0;

  public:
    /**
     * @brief Default constructor
     */
    MotorInterface(){};
    /**
     * @brief getter for direction
     */
    virtual Direction getDirection() const = 0;
    /**
     * @brief setter for direction
     */
    virtual void setDirection(const Direction direction) = 0;
    /**
     * @brief getter for speed
     */
    virtual uint8_t getSpeed() const = 0;
    /**
     * @brief setter for speed
     */
    virtual void setSpeed(const uint8_t speed) = 0;
    /**
     * @brief getter for speed
     */
    virtual uint16_t getAngle() const = 0;
    /**
     * @brief setter for speed
     */
    virtual void setAngle(const uint16_t newAngle) = 0;
};
} // namespace MotorController

#endif // MOTOR_INTERFACE_HPP