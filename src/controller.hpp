/**
 * @file
 * @brief     This file contains a class for the motor controller
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "dc_Interface.hpp"
#include "motor_Interface.hpp"
#include "stepper_Interface.hpp"
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Controller for motor logic
 *
 * This class is used to control a motor using the motor_Interface superclass.
 * The Interface can be set to DC or Stepper and uses the selected Interface to set speed, direction or angle of a motor
 *
 */
class Controller {
  public:
    ///< Enum class with all available motor Interfaces
    enum class Interface { DC, Stepper, None };

  private:
    ///< The Interface that is currently selected
    MotorInterface *selectedInterface = nullptr;

    ///< The Interface for dc motor, we initialize this in the contructor because we have no heap and can't do polymorphism that way
    ///< for selected Interface
    DcInterface dcInterface;
    ///< The Interface for stepper motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected Interface
    StepperInterface stepperInterface;

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
    bool setSelectedInterface(const Interface Interface);
    /**
     * @brief getter for Enable
     */
    bool getEnable() const;
    /**
     * @brief setter for Enable
     */
    void setEnable(const bool state);
    /**
     * @brief getter for speed
     */
    int16_t getSpeed() const;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int16_t speed);
    /**
     * @brief getter for speed
     */
    uint16_t getAngle() const;
    /**
     * @brief setter for speed
     */
    void setAngle(const uint16_t newAngle);
};
} // namespace MotorController

#endif // CONTROLLER_HPP