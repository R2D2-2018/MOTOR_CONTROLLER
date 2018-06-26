/**
 * @file
 * @brief     This file contains a class for the stepper motor Interface
 * @author    Olivier Verwoerd
 * @license   MIT License
 */

#ifndef SERVO_INTERFACE_HPP
#define SERVO_INTERFACE_HPP

#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface for servo motor
 *
 * This class contains functions to control a servo motor and is used in the motor controller to do so
 *
 * More explaination of fucntios in the motor_interface class
 */
class ServoInterface : public MotorInterface {
  public:
    /**
     * @brief Default constructor
     */
    ServoInterface();
    /**
     * @brief getter for angle
     */
    uint16_t getAngle() const override;
    /**
     * @brief setter for angle
     *
     * @param[in] new angle in a range 0-180. if the servo is capable of 360 degees fill in 180.
     */
    void setAngle(const int16_t newAngle);
};
} // namespace MotorController

#endif // Servo_Interface_HPP