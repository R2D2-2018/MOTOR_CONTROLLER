#ifndef PWM_controller_HPP
#define PWM_controller_HPP

#include "wrap-hwlib.hpp"
#include <assert.h>
// struct for all the avaible pwm pins on the arduino due.

enum PWMpin : uint32_t {
    // PWM_CH0
    H0_RX0 = PIO_PA8,
    H0_PB12 = PIO_PB12,
    H0_PC3 = PIO_PC3,
    L0_PA21 = PIO_PA21,
    L0_PB16 = PIO_PB16,
    L0_PC2 = PIO_PC2,

    // PWM_CH1
    H1_PA19 = PIO_PA19,
    H1_PB13 = PIO_PB13,
    H1_PC5 = PIO_PC5,
    L1_PA12 = PIO_PA12,
    L1_PB17 = PIO_PB17,
    L1_PC4 = PIO_PC4,

    // PWM_CH2
    H2_PA13 = PIO_PA13,
    H2_PB14 = PIO_PB14,
    H2_PC7 = PIO_PC7,
    L2_PA20 = PIO_PA20,
    L2_PB18 = PIO_PB18,
    L2_PC6 = PIO_PC6,

    // PWM_CH3
    H3_PA9 = PIO_PA9,
    H3_PB15 = PIO_PB15,
    H3_PC9 = PIO_PC9,
    L3_PA0 = PIO_PA0,
    L3_PB19 = PIO_PB19,
    L3_PC8 = PIO_PC8,

    // PWM_CH4
    H4_PC20 = PIO_PC20,
    L4_PC21 = PIO_PC21,

    // PWM_CH5

    H5_PC19 = PIO_PC19,
    L5_PC22 = PIO_PC22,

    // PWM_CH6
    H6_PC18 = PIO_PC18,
    L6_PC23 = PIO_PC23,

    // PWM_CH7
    L7_PC24 = PIO_PC24
};

class PWMcontroller {
  private:
    uint8_t channel_id;
    double dutyCycle;
    uint8_t freq;
    PWMpin pin;

  public:
    PWMcontroller(const PWMpin &pin);

    void setFreq(const uint8_t &setFreq);
    void setDutyCycle(const double &setDutyCycle);
    uint8_t getFreq();
    uint16_t getDutyCycle();
};

#endif // PWM_controller_HPP