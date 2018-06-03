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
#include "wrap-hwlib.hpp"

namespace MotorController {
/**
 * @brief Interface class for motor controller
 *
 * This class is used to select and return a motor interface.
 * The default selected interface is DC.
 *
 */
class Controller {
  public:
    ///< Enum class with all available motor interfaces
    enum class INTERFACE { DC, STEPPER };

  private:
    ///< The interface that is currently selected
    MotorInterface *selectedInterface = nullptr;

    ///< The interface for dc motor, we instanciate this because
    DcInterface dcInterface;

  public:
    /**
     * @brief Default constructor
     */
    Controller();

    /**
     *  @brief getter for selectedInterface
     */
    INTERFACE getSelectedInterface() const;
    /**
     * @brief setter for selectedInterface
     */
    void setSelectedInterface(const INTERFACE interface);
    /**
     * @brief getter for direction
     */
    MotorInterface::DIRECTION getDirection() const;
    /**
     * @brief setter for direction
     */
    void setDirection(const MotorInterface::DIRECTION direction);
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