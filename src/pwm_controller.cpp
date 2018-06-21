#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &pin) : pin(pin) {

    uint8_t channel_id;
    switch (pin) {
    case PWMpin::H0_PA8:
        PIOB->PIO_PDR = PIO_PA8;
        PIOB->PIO_ABSR |= PIO_PA8;

        // enable output on PA8
        PIOB->PIO_OER = PIO_PA8;
        channel_id = 0;
        break;
    case PWMpin::H0_PB12:
        channel_id = 0;
        break;
    case PWMpin::H0_PC3:
        channel_id = 0;
        break;
    case PWMpin::L0_PA21:
        channel_id = 0;
        break;
    case PWMpin::L0_PB16:
        channel_id = 0;
        break;
    case PWMpin::L0_PC2:
        channel_id = 0;
        break;
    }
    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.
    PWM->PWM_ENA = PWM->PWM_SR | mask; // enable channel with mask based off channel id
    PWM->PWM_CH_NUM[channel_id].PWM_CDTY;
};

void PWMcontroller::setPwmFreq(const uint8_t &setFreq) {
    freq = setFreq;
}

void PWMcontroller::setDutyCycle(const uint8_t &setDutyCycle) {
    dutyCycle = setDutyCycle;
}

inline uint8_t PWMcontroller::getPwmFreq() {
    return freq;
}

inline uint8_t PWMcontroller::getDutyCycle() {
    return dutyCycle;
}