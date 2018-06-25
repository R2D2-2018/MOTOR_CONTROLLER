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
 * The Interface can be set to DC or Stepper and uses the selected Interface to set speed, direction or angle of a motor
 *
 */
class Controller {
  public:
    ///< Enum class with all available motor Interfaces
    enum class Interface { DC, Stepper, Servo, None };

  private:
    ///< The Interface that is currently selected
    MotorInterface *selectedInterface = nullptr;

    ///< The Interface for dc motor, we initialize this in the contructor because we have no heap and can't do polymorphism that way
    ///< for selected Interface
    DcInterface dcInterface;
    ///< The Interface for stepper motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected Interface
    StepperInterface stepperInterface;
    ///< The Interface for servo motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected Interface
    ServoInterface servoInterface;

  public:
    /**
     * @brief Default constructor
     */
    Controller();

    /**
     *  @brief getter for selectedInterface
     */
    Interface getSelectedInterface() const;
    /**
     * @brief setter for selectedInterface
     */
    bool setSelectedInterface(const Interface interface);
    /**
     * @brief getter for speed
     */
    int8_t getSpeed() const;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int8_t speed);
    /**
     * @brief getter for angle
     */
    uint16_t getAngle() const;
    /**
     * @brief setter for angle
     */
    void setAngle(const int16_t newAngle);
    /**
     * @brief getter for stepperwires
     */
    uint8_t getStepperWires() const;
    /**
     * @brief setter for stepperwires
     */
    void setStepperWires(const uint8_t newAmount);
    /**
     * @brief getter for steps
     */
    uint16_t getSteps() const;
    /**
     * @brief setter for Steps direct
     */
    void setSteps(const uint16_t newSteps);
    /**
     * @brief setter for Steps indirect
     */
    void setSteps(const double stride, const double gearRatio);
};
} // namespace MotorController

#endif // CONTROLLER_HPP