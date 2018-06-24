#ifndef PWM_controller_HPP
#define PWM_controller_HPP

#include "wrap-hwlib.hpp"
#include <assert.h>
// struct for all the avaible pwm pins on the arduino due.

enum PWMpin : uint32_t {
    // PWM_CH0
    H0_RX0 = PIO_PA8,
    H0_SDA = PIO_PB12,
    H0_D35 = PIO_PC3,
    L0_LEDTX = PIO_PA21,
    L0_DAC1 = PIO_PB16,
    L0_D34 = PIO_PC2,

    // PWM_CH1
    H1_D42 = PIO_PA19,
    H1_SCL = PIO_PB13,
    H1_PC5 = PIO_PC5,
    L1_D37 = PIO_PA12,
    L1_A8 = PIO_PB17,
    L1_D36 = PIO_PC4,

    // PWM_CH2
    H2_TX2 = PIO_PA13,
    H2_D53 = PIO_PB14,
    H2_D39 = PIO_PC7,
    L2_D43 = PIO_PA20,
    L2_A9 = PIO_PB18,
    L2_D38 = PIO_PC6,

    // PWM_CH3
    H3_TX0 = PIO_PA9,
    H3_DAC0 = PIO_PB15,
    H3_D41 = PIO_PC9,
    L3_CANTX0 = PIO_PA0,
    L3_PB19 = PIO_PB19,
    L3_D40 = PIO_PC8,

    // PWM_CH4
    H4_PC20 = PIO_PC20, // No phisical pinout
    L4_D9 = PIO_PC21,

    // PWM_CH5

    H5_D44 = PIO_PC19,
    L5_D9 = PIO_PC22,

    // PWM_CH6
    H6_D45 = PIO_PC18,
    L6_D7 = PIO_PC23,

    // PWM_CH7
    L7_D6 = PIO_PC24
};

class PWMcontroller {
  private:
    uint8_t channel_id;
    double dutyCycle = 0;
    uint32_t freq = 0;
    uint32_t pin;

  public:
    PWMcontroller(const PWMpin &_pin);

    void setFreq(const uint32_t &setFreq);
    void setDutyCycle(const double &setDutyCycle);
    uint32_t getFreq();
    double getDutyCycle();
};

#endif // PWM_controller_HPP