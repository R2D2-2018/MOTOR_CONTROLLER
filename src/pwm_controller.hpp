#ifndef PWM_controller_HPP
#define PWM_controller_HPP

#include "warp-hwlib.hpp"

// Enum class for all the avaible pwm pins on the arduino due.
enum class PWMpin {
    PWMpin2,
    PWMpin3,
    PWMpin4,
    PWMpin5,
    PWMpin6,
    PWMpin7,
    PWMpin8,
    PWMpin9,
    PWMpin10,
    PWMpin11,
    PWMpin12,
    PWMpin13
}

class PWMcontroller {
  private:
    uint8_t dutyCycle;
    PWMpin pin;

  public:
    PWMcontroller(const PWMpin &pin);

    void setPwmFreq(const uint8_t &setDutyCycle);
    uint8_t getPwmFreq();
};

#endif // PWM_controller_HPP