/**
 * @file
 * @brief     This file contains a class for the dc motor interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef DC_INTERFACE_HPP
#define DC_INTERFACE_HPP

#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface for DC motor
 *
 * This class contains functionalirt to control a DC motor and is used in the motor controller to do so
 *
 */
class DcInterface : public MotorInterface {
  public:
    /**
     * @brief Default constructor
     */
    DcInterface();
    /**
     * @brief getter for direction
     */
    DIRECTION getDirection() const override;
    /**
     * @brief setter for direction
     */
    void setDirection(const DIRECTION direction) override;
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

#endif