#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &pin) : pin(pin) {
    Pio *pointerPIO;
    switch (pin) {
    case H0_RX0:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    }

    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.

    assert(!(PWM->PWM_SR & mask)); // assert if channel is already in use.
    pointerPIO->PIO_PDR = pin;
    pointerPIO->PIO_ABSR |= pin;
    pointerPIO->PIO_OER = pin;
    PWM->PWM_ENA = PWM->PWM_SR | mask; // enable channel with mask based off channel id
};

void PWMcontroller::setFreq(const uint8_t &setFreq) {
    freq = setFreq;
    PWM->PWM_CLK;
}

void PWMcontroller::setDutyCycle(const uint16_t &setDutyCycle) {
    dutyCycle = setDutyCycle;
    PWM->PWM_CH_NUM[channel_id].PWM_CDTY = dutyCycle;
}

inline uint8_t PWMcontroller::getFreq() {
    return freq;
}

inline uint16_t PWMcontroller::getDutyCycle() {
    return dutyCycle;
}