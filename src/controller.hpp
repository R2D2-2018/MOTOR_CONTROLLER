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
 *
 * This class is used to control a motor using the motor_interface superclass.
 * The interface can be set to DC or Stepper and uses the selected interface to set speed, direction or angle of a motor
 *
 */
class Controller {
  public:
    ///< Enum class with all available motor interfaces
    enum class Interface { DC, Stepper, None };

  private:
    ///< The interface that is currently selected
    MotorInterface *selectedInterface = nullptr;

    ///< The interface for dc motor, we initialize this in the contructor because we have no heap and can't do polymorphism that way
    ///< for selected interface
    DcInterface dcInterface;
    ///< The interface for stepper motor, we initialize this in the contructor because we have no heap and can't do polymorphism
    ///< that way for selected interface
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
     * @brief getter for direction
     */
    MotorInterface::Direction getDirection() const;
    /**
     * @brief setter for direction
     */
    void setDirection(const MotorInterface::Direction direction);
    /**
     * @brief getter for speed
     */
    uint8_t getSpeed() const;
    /**
     * @brief setter for speed
     */
    void setSpeed(const uint8_t speed);
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