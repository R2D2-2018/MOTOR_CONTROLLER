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
 * @brief Interface class for motor controller
 *
 * This class is used to select and return a motor interface.
 * The default selected interface is DC.
 *
 */
class MotorInterface {
  public:
    ///< Enum class with all available motor interfaces
    enum class INTERFACE { DC, STEPPER };
    ///< Enum class with all possible motor directions
    enum class DIRECTION { FORWARD, BACKWARD };

  private:
    ///< The interface that is currently selected
    INTERFACE selectedInterface = INTERFACE::DC;

    ///< The direction of the motor rotation, forward by default
    DIRECTION direction = DIRECTION::FORWARD;
    ///< Motor rotation speed, 0 - 100%
    uint8_t speed = 0;
    ///< Motor angle, 0 - 360
    uint16_t angle = 0;

  public:
    /**
     * @brief Default constructor
     */
    MotorInterface();

    /**
     * @brief getter for selectedInterface
     */
    INTERFACE getSelectedInterface() const;
    /**
     * @brief setter for selectedInterface
     */
    void setSelectedInterface(const INTERFACE interface);
    /**
     * @brief getter for direction
     */
    DIRECTION getDirection() const;
    /**
     * @brief setter for direction
     */
    void setDirection(const DIRECTION direction);
    /**
     * @brief getter for speed
     */
    uint8_t getSpeed() const;
    /**
     * @brief setter for speed
     */
    void setSpeed(const uint8_t speed);
    /**
     * @brief getter for speed
     */
    uint16_t getAngle() const;
    /**
     * @brief setter for speed
     */
    void setAngle(const uint16_t newAngle);
};
} // namespace MotorController

#endif