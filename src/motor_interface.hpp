#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "wrap-hwlib.hpp"

class MotorInterface {
  public:
    enum class INTERFACE { DC };

  private:
    const INTERFACE selectedInterface = INTERFACE::DC;

  public:
    MotorInterface();
    INTERFACE getSelectedInterface() const;
};

#endif