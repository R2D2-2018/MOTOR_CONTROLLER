/**
 * @file
 * @brief     This file contains a class for the motor Interface
 * @author    Nick Bout & Olivier Verwoerd
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
    ///< almount of steps for the stepper motor
    uint16_t steps = 4;
    ///< Almount of stepper wires to define what sequence should be used
    uint8_t stepperWires = 4;
    ///< Stride angle is the angle

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
     * @brief getter for angle
     */
    virtual uint16_t getAngle() const {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for angle
     */
    virtual void setAngle(const uint16_t newAngle) {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
    };
    /**
     * @brief getter for stepperwires
     */
    virtual uint8_t getStepperWires() const {
        hwlib::cout << "ERROR: This motor interface does NOT support stepperwires" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for stepperwires
     */
    virtual void setStepperWires(const uint8_t newAmount) {
        hwlib::cout << "ERROR: This motor interface does NOT support stepperwires" << hwlib::endl;
    };
    /**
     * @brief getter for stride
     */
    virtual uint16_t getSteps() const {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for steps direct
     */
    virtual void setSteps(const double newStride) {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
    };
    /**
     * @brief setter for steps indirect
     */
    virtual void setSteps(const double stride, const double gearRatio) {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
    };
};
} // namespace MotorController

#endif // MOTOR_Interface_HPP