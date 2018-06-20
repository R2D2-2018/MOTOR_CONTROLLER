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
    ///< Almount of stepper wires to define what sequence should be used
    uint8_t stepperWires = 4;
    ///< Stride angle is the angle
    double stride = 0;
    ///< ratio to devide degrees of turnment. Used in stepper with stride angle;
    uint8_t gearRatio = 0;

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
    virtual void setStepperWires(const uint8_t newAlmount) {
        hwlib::cout << "ERROR: This motor interface does NOT support stepeprwires" << hwlib::endl;
    };
    /**
     * @brief getter for stride
     */
    virtual double getStride() const {
        hwlib::cout << "ERROR: This motor interface does NOT support stride" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for stride
     */
    virtual void setStride(const double newStride) {
        hwlib::cout << "ERROR: This motor interface does NOT support stride" << hwlib::endl;
    };
    /**
     * @brief getter for gear ratio
     */
    virtual uint8_t getGearRatio() const {
        hwlib::cout << "ERROR: This motor interface does NOT support ratio" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for gear ratio
     */
    virtual void setGearRatio(const uint8_t newRatio) {
        hwlib::cout << "ERROR: This motor interface does NOT support ratio" << hwlib::endl;
    };
};
} // namespace MotorController

#endif // MOTOR_Interface_HPP