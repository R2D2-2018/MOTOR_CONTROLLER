#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &pin) : pin(pin) {
    Pio *pointerPIO;
    switch (pin) {
    case H0_RX0:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    default:
        hwlib::cout << "Pin not implemented for pwm\n";
        break;
    }
    hwlib::wait_ms(1);              // sets mck to 84mhz
    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.

    // assert(!(PWM->PWM_SR & mask)); // assert if channel is already in use.
    pointerPIO->PIO_PDR = pin;
    pointerPIO->PIO_ABSR |= pin;
    pointerPIO->PIO_OER = pin;

    PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(42);
    PWM->PWM_CH_NUM[channel_id].PWM_CMR |= PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
    PWM->PWM_ENA = PWM->PWM_SR | mask; // enable channel with mask based off channel id
}

void PWMcontroller::setFreq(const uint8_t &setFreq) {
    freq = setFreq;
    uint8_t i = 1;
    while (84 / i > setFreq) {
        ++i;
    }
    PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(i - 1);  // setting up right clk divider
    PWM->PWM_CH_NUM[channel_id].PWM_CPRD = freq * 1000000; // setting pwm freq
}

void PWMcontroller::setDutyCycle(const double &setDutyCycle) {
    if (setDutyCycle > 0 && setDutyCycle < 100) {
        dutyCycle = 100 / setDutyCycle;

        // if for some reason the channel is disabled write to CDTY instead of CDTYUPD
        if (PWM->PWM_SR & (1 << channel_id)) {
            PWM->PWM_CH_NUM[channel_id].PWM_CDTYUPD = PWM->PWM_CH_NUM[channel_id].PWM_CPRD / dutyCycle;
        } else {
            PWM->PWM_CH_NUM[channel_id].PWM_CDTY = PWM->PWM_CH_NUM[channel_id].PWM_CPRD / dutyCycle;
        }
    }
}

inline uint8_t PWMcontroller::getFreq() {
    return freq;
}

inline uint16_t PWMcontroller::getDutyCycle() {
    return dutyCycle;
}