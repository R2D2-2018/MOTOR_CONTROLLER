#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &_pin) : pin(_pin) {
    Pio *pointerPIO;
    switch (pin) {
    case H0_RX0:
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case H0_PB12:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case H0_PC3:
        pointerPIO = PIOC;
        channel_id = 0;
        break;
    case L0_PA21:
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case L0_PB16:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case L0_PC2:
        pointerPIO = PIOC;
        channel_id = 0;
        break;
    default:
        hwlib::cout << "Pin not implemented for pwm\n";
        break;
    }
    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.
    REG_PMC_PCER1 |= PMC_PCER1_PID36; // Enable PWM
    // assert(!(PWM->PWM_SR & mask)); // assert if channel is already in use.

    pointerPIO->PIO_ABSR |= pin; // PWM is always on b
    pointerPIO->PIO_PDR |= pin;  // enable pin for pwm

    PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(42);
    PWM->PWM_CH_NUM[channel_id].PWM_CMR = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
    PWM->PWM_CH_NUM[channel_id].PWM_CPRD = 20000;
    PWM->PWM_CH_NUM[channel_id].PWM_CDTY = 1500;
    PWM->PWM_ENA = (PWM->PWM_SR | mask); // enable channel with mask based off channel id
}

void PWMcontroller::setFreq(const uint32_t &setFreq) {
    freq = setFreq;
    uint8_t i = 1;
    uint32_t maxCPRD = 16777214;
    uint32_t newCPRD = (84000000 / (2 * setFreq));
    while (newCPRD > maxCPRD && i != 0) {
        newCPRD = ((84000000 / i) / (2 * setFreq));
        ++i;
    }
    // check for overflow
    if (i != 0) {
        hwlib::cout << +i << hwlib::endl;
        PWM->PWM_WPSR;
        PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(i); // setting up right clk divider
        PWM->PWM_CH_NUM[channel_id].PWM_CPRD = newCPRD;   // setting pwm freq
    }
}

void PWMcontroller::setDutyCycle(const double &setDutyCycle) {
    if (setDutyCycle > 0 && setDutyCycle < 100) {
        dutyCycle = PWM->PWM_CH_NUM[channel_id].PWM_CPRD / (100 / setDutyCycle);
        if (dutyCycle < 65535) {
            PWM->PWM_CH_NUM[channel_id].PWM_CDTY = dutyCycle;
        }
    }
}

inline uint8_t PWMcontroller::getFreq() {
    return freq;
}

inline uint16_t PWMcontroller::getDutyCycle() {
    return dutyCycle;
}