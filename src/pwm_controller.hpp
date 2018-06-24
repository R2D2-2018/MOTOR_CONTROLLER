#ifndef PWM_controller_HPP
#define PWM_controller_HPP

#include "wrap-hwlib.hpp"
// enum for all the avaible pwm pins on the arduino due.

enum PWMpin : uint8_t {
    // PWM_CH0
    H0_RX0,
    H0_SDA,
    H0_D35,
    L0_LEDTX,
    L0_DAC1,
    L0_D34,

    // PWM_CH1
    H1_D42,
    H1_SCL,
    H1_D37,
    L1_RX2,
    L1_A8,
    L1_D36,

    // PWM_CH2
    H2_TX2,
    H2_D53,
    H2_D39,
    L2_D43,
    L2_A9,
    L2_D38,

    // PWM_CH3
    H3_TX0,
    H3_DAC0,
    H3_D41,
    L3_CANTX0,
    L3_PB19,
    L3_D40,

    // PWM_CH4
    H4_PC20, // No Physical pinout
    L4_D9,

    // PWM_CH5
    H5_D44,
    L5_D9,

    // PWM_CH6
    H6_D45,
    L6_D7,

    // PWM_CH7
    L7_D6
};

class PWMcontroller {
  private:
    uint8_t channel_id;
    double dutyCycle = 0;
    uint32_t freq = 0;
    uint32_t pin;

  public:
    PWMcontroller(const PWMpin &_pin);
    /**
     * @brief setDutyCycle
     *
     * paramin [] in hz. needs to be 4 or more
     */
    void setFreq(const uint32_t &setFreq);
    void setDutyCycle(const double &setDutyCycle);
    uint32_t getFreq();
    double getDutyCycle();
};

#endif // PWM_controller_HPP