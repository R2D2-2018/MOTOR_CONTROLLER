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
<<<<<<< HEAD
 * This class is used to control a motor using the motor_Interface superclass.
 * The Interface can be set to DC or Stepper and uses the selected Interface to set speed, direction or angle of a motor
=======
 * This class is used to control a motor using the motor_interface superclass.
 * The interface can be set to DC or Stepper and uses the selected interface to set speed, direction or angle of a motor
>>>>>>> development
 *
 */
class Controller {
  public:
<<<<<<< HEAD
    ///< Enum class with all available motor Interfaces
=======
    ///< Enum class with all available motor interfaces
>>>>>>> development
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
<<<<<<< HEAD
    bool setSelectedInterface(const Interface Interface);
=======
    bool setSelectedInterface(const Interface interface);
>>>>>>> development
    /**
     * @brief getter for Enable
     */
<<<<<<< HEAD
    bool getEnable() const;
=======
    MotorInterface::Direction getDirection() const;
>>>>>>> development
    /**
     * @brief setter for Enable
     */
<<<<<<< HEAD
    void setEnable(const bool state);
=======
    void setDirection(const MotorInterface::Direction direction);
>>>>>>> development
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