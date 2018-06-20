/**
 * @file
 * @brief     This file contains a class for the motor controller
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "dc_interface.hpp"
#include "motor_interface.hpp"
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
    bool setSelectedInterface(const Interface interface);
    /**
     * @brief getter for speed
     */
    int16_t getSpeed() const;
    /**
     * @brief setter for speed
     */
    void setSpeed(const int16_t speed);
    /**
     * @brief getter for angle
     */
    uint16_t getAngle() const;
    /**
     * @brief setter for angle
     */
    void setAngle(const uint16_t newAngle);
};
} // namespace MotorController

#endif // CONTROLLER_HPP