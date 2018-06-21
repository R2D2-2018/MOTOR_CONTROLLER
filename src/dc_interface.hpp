/**
 * @file
 * @brief     This file contains a class for the dc motor Interface
 * @author    Nick Bout & Olivier Verwoerd
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
     * @brief getter for speed
     */
    int16_t getSpeed() const override;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int16_t speed) override;
};
} // namespace MotorController

#endif // DC_Interface_HPP