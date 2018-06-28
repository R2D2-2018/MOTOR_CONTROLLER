/**
 * @file
 * @brief     This file contains a class for the motor Interface
 * @author    Nick Bout & Olivier Verwoerd
 * @license   MIT License
 */

#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "pwm_controller.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Abstract Interface class used by other Interfaces
 *
 * This class is a super class for Interfaces for all supported motor types
 */
class MotorInterface {
  protected:
    int8_t speed = 0;                                  ///< Motor rotation speed, 0 - 100
    uint16_t angle = 0;                                ///< Motor angle, 0 - 180 or 360 in stepper
    uint16_t steps = 0;                                ///< almount of steps currently
    int8_t stepSequenceTracker = 0;                    ///< counter to track where we are in the sequence
    uint16_t maxSteps = 10;                            ///< Almount of staps that the setepper has
    uint8_t stepperMethod = 1;                         ///< stepper Method, 0: whole step, 1: Halve step
    PWMcontroller pwm1 = PWMcontroller(PWMpin::L7_D6); ///< Pin 6. used as DC motor 1 forward, Stepper wire 1, Servo 1
    PWMcontroller pwm2 = PWMcontroller(PWMpin::L6_D7); ///< Pin 7. used as DC motor 1 backward, Stepper wire 2, Servo 2
    PWMcontroller pwm3 = PWMcontroller(PWMpin::L5_D8); ///< Pin 8. used as DC motor 2 forward, Stepper wire 3, Servo 3
    PWMcontroller pwm4 = PWMcontroller(PWMpin::L4_D9); ///< Pin 9. used as DC motor 2 backward, Stepper wire 4, Servo 4

  public:
    /**
     * @brief Default constructor
     */
    MotorInterface(){};

    /**
     * @brief getter for speed set the dc speed in % where negative value means backwards.
     * for the stepper speed controls the speed off the interval when changeing to the next step.
     * for the stepper to go backwards fill in setAngle with a negative value. speed is always positive.
     * @param[out] speed -100 / 100
     */
    virtual int8_t getSpeed() const {
        hwlib::cout << "ERROR: This motor interface does NOT support speed control" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for speed set the dc speed in % where negative value means backwards.
     * for the stepper speed controls the speed off the interval when changeing to the next step.
     * for the stepper to go backwards fill in setAngle with a negative value. speed is always positive.
     * @param[in] speed -100 / 100
     */
    virtual void setSpeed(const int8_t speed) {
        hwlib::cout << "ERROR: This motor interface does NOT support speed control" << hwlib::endl;
    };
    /**
     * @brief getter for angle. returns the current angle.
     * Keep in mind that angle resets by reboot of the stepper.
     * @param[out] angle in degrees 0 / 360
     */
    virtual uint16_t getAngle() const {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for angle in range 0 - 180 for servo and stepper how much it should turn
     * for example setAngle(90) will center a servo and will turn the stepper 90 degrees clockwise
     * setAngle(-720) will make the stepper turn 2 turns counter clockwise
     * @param[in] angle in degrees
     */
    virtual void setAngle(const int16_t newAngle) {
        hwlib::cout << "ERROR: This motor interface does NOT support angles" << hwlib::endl;
    };
    /**
     * @brief getter for stepperMethod. 0: full step, 1: halfstep (default)
     * @param[out] 0 or 1
     */
    virtual uint8_t getStepperMethod() const {
        hwlib::cout << "ERROR: This motor interface does NOT support stepperwires" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for stepperMethod. 0: full step, 1: halfstep (default)
     * @param[in] 0 or 1
     */
    virtual void setStepperMethod(const uint8_t newMethod) {
        hwlib::cout << "ERROR: This motor interface does NOT support stepperwires" << hwlib::endl;
    };
    /**
     * @brief getter for maxSteps expressed in the amount of steps for 1 full rotation
     * @param[out] amount of steps.
     */
    virtual uint16_t getMaxSteps() const {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
        return 0;
    };
    /**
     * @brief setter for Maxsteps direct by entering the steps
     * @param[in] amount of steps.
     */
    virtual void setMaxSteps(const uint16_t newMaxSteps) {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
    };
    /**
     * @brief setter for Maxsteps indirect by entering the stride and the gear ratio of the stepper.
     * @param[in] stepper moter stride and gear ratio
     */
    virtual void setMaxSteps(const double stride, const double gearRatio) {
        hwlib::cout << "ERROR: This motor interface does NOT support steps" << hwlib::endl;
    };
};
} ///< namespace MotorController

#endif ///< MOTOR_Interface_HPP