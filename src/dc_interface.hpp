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
     * @brief getter for Enable
     */
    bool getEnable() const override;
    /**
     * @brief setter for Enable
     */
    void setEnable(const bool state) override;
    /**
     * @brief getter for direction
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

#endif // DC_INTERFACE_HPP