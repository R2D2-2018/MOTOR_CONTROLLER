/**
 * @file
 * @brief     This file contains a class for the motor interface
 * @author    Nick Bout
 * @license   MIT License
 */

#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "wrap-hwlib.hpp"

/**
 * @brief Interface class for motor controller
 *
 * This sets the selected interface to DC motor and tells the user which interface is selected
 *
 */
class MotorInterface {
  public:
    ///< Enum class with all available motor interfaces
    enum class INTERFACE { DC };

  private:
    ///< The interface that is currently selected
    const INTERFACE selectedInterface = INTERFACE::DC;

  public:
    /**
     * @brief Default constructor
     */
    MotorInterface();
    /**
     * @brief getter for selectedInterface
     */
    INTERFACE getSelectedInterface() const;
};

#endif