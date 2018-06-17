/**
 * @file
 * @brief     This file contains a class for the dc motor Interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef DC_Interface_HPP
#define DC_Interface_HPP

#include "motor_Interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface for DC motor
 *
 * This class contains functionalirt to control a DC motor and is used in the motor controller to do so
 *
 */
class DcInterface : public MotorInterface {
    ///< Motor rotation speed, 0 - 255
    bool enable = true;
    ///< Motor rotation speed, 0 - 255
    int16_t speed = 0;
    hwlib::target::pin_out enablePin = hwlib::target::pin_out(hwlib::target::pins::d13);
    hwlib::target::pin_out forwardPin = hwlib::target::pin_out(hwlib::target::pins::d3);
    hwlib::target::pin_out backwardPin = hwlib::target::pin_out(hwlib::target::pins::d4);
    // auto led = hwlib::target::pin_out(hwlib::target::pins::d13);

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
     * @brief setter for forward pin in PWM
     */
    // void setForwardPin(hwlib::pin_out &newForwardPwmPin);
    /**
     * @brief setter for backwards pin in PWM
     */
    // void setBackwardPin(hwlib::pin_out &newBackwardPwmPin);
    /**
     * @brief setter for enable pin
     */
    // void setEnablePin(hwlib::pin_out &newEnablePin) override;
};
} // namespace MotorController

#endif // DC_Interface_HPP