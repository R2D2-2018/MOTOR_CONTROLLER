/**
 * @file
 * @brief     This file contains a class for the motor controller
 * @author    Nick Bout & Olivier Verwoerd
 * @license   MIT License
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "dc_interface.hpp"
#include "motor_interface.hpp"
#include "servo_interface.hpp"
#include "stepper_interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Controller for motor logic
 * This class is used to control a motor using the motor_Interface superclass.
 * The Interface can be set to DC, Stepper and servo. by the selected Interface to set speed, direction or angle of a motor
 *
 * This controller controls where the input needs to go. for more explaination what each function does
 * Please read the motor_interface class
 */
class Controller {
  public:
    enum class Interface { DC, Stepper, Servo, None }; ///< Enum class with all available motor Interfaces

  private:
    MotorInterface *selectedInterface = nullptr;
    ///< The Interface that is currently selected
    DcInterface dcInterface;
    ///< The Interface for dc motor, we initialize this in the contructor because we have no heap and can't do polymorphism that way
    ///< for selected Interface
    StepperInterface stepperInterface;
    ///< The Interface for stepper motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected Interface
    ServoInterface servoInterface;
    ///< The Interface for servo motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected Interface

  public:
    /**
     * @brief Default constructor
     */
    Controller();

    /**
     *  @brief getter for selectedInterface
     * @param[out] selected interface
     */
    Interface getSelectedInterface() const;
    /**
     * @brief setter for selectedInterface
     * @param[in] interface enum
     * @param[out] bool if set was succes
     */
    bool setSelectedInterface(const Interface interface);
    /**
     * @brief getter for speed
     * @param[out] speed -100 / 100
     */
    int8_t getSpeed() const;
    /**
     * @brief setter for speed
     * @param[in] speed -100 / 100
     */
    void setSpeed(const int8_t speed);
    /**
     * @brief getter for angle
     * @param[out] angle in degree 0 / 360
     */
    uint16_t getAngle() const;
    /**
     * @brief setter for angle
     * @param[in] angle in degree 0 / 360
     */
    void setAngle(const int16_t newAngle);
    /**
     * @brief getter for stepperMethod
     * @param[out] stepperMethod 0: fullstep, 1: halfstep (default)
     */
    uint8_t getStepperMethod() const;
    /**
     * @brief setter for stepperMethod
     * @param[in] stepperMethod 0: fullstep, 1: halfstep (default)
     */
    void setStepperMethod(const uint8_t newMethod);
    /**
     * @brief getter for maxsteps
     * @param[out] amount of steps that the stepper can make
     */
    uint16_t getMaxSteps() const;
    /**
     * @brief setter for maxSteps direct
     * @param[in] amount of steps that the stepper can make
     */
    void setMaxSteps(const uint16_t newMaxSteps);
    /**
     * @brief setter for maxSteps indirect
     * @param[in] amount of steps that the stepper can make
     */
    void setMaxSteps(const double stride, const double gearRatio);
};
} // namespace MotorController

#endif ///< CONTROLLER_HPP