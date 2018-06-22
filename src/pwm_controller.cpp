#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &pin) : pin(pin) {

    switch (pin) {
    case H0_PA8 || H0_PB12 || H0_PC3:
        channel_id = 0;
        break;
    }

    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.

    assert(!(PWM->PWM_SR & mask)); // assert if channel is already in use.
    PIOB->PIO_PDR = pin;
    PIOB->PIO_ABSR |= pin;
    PIOB->PIO_OER = pin;
    PWM->PWM_ENA = PWM->PWM_SR | mask; // enable channel with mask based off channel id
};

void PWMcontroller::setPwmFreq(const uint8_t &setFreq) {
    freq = setFreq;
}

void PWMcontroller::setDutyCycle(const uint8_t &setDutyCycle) {
    dutyCycle = setDutyCycle;
    // Do stuff here with registers
    /*
    PWM->PWM_CH_NUM[channel_id].PWM_CDTY;
    */
}

inline uint8_t PWMcontroller::getPwmFreq() {
    return freq;
}

inline uint8_t PWMcontroller::getDutyCycle() {
    return dutyCycle;
}