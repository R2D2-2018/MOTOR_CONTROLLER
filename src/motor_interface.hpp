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
        hwlib::cout << "ERROR: This motor interface does NOT support speed control" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for speed
     */
    virtual void setSpeed(const int16_t speed) {
        hwlib::cout << "ERROR: This motor interface does NOT support speed control" << hwlib::endl;
    };
    /**
     * @brief getter for speed
     */
    virtual uint16_t getAngle() const {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for speed
     */
    virtual void setAngle(const uint16_t newAngle) {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
    };
};
} // namespace MotorController

#endif // MOTOR_Interface_HPP