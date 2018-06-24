#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &_pin) : pin(_pin) {
    Pio *pointerPIO = NULL;
    switch (pin) {
        // channel 1
    case H0_RX0:
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case H0_SDA:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case H0_D35:
        pointerPIO = PIOC;
        channel_id = 0;
        break;
    case L0_LEDTX:
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case L0_DAC1:
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case L0_D34:
        pointerPIO = PIOC;
        channel_id = 0;
        break;
        // channel 1
    case H1_D42:
        pointerPIO = PIOA;
        channel_id = 1;
        break;
    case H1_SCL:
        pointerPIO = PIOB;
        channel_id = 1;
        break;
    case H1_D37:
        pointerPIO = PIOC;
        channel_id = 1;
        break;
    case L1_RX2:
        pointerPIO = PIOA;
        channel_id = 1;
        break;
    case L1_A8:
        pointerPIO = PIOB;
        channel_id = 1;
        break;
    case L1_D36:
        pointerPIO = PIOC;
        channel_id = 1;
        break;
        // channel 2
    case H2_TX2:
        pointerPIO = PIOA;
        channel_id = 2;
        break;
    case H2_D53:
        pointerPIO = PIOB;
        channel_id = 2;
        break;
    case H2_D39:
        pointerPIO = PIOC;
        channel_id = 2;
        break;
    case L2_D43:
        pointerPIO = PIOA;
        channel_id = 2;
        break;
    case L2_A9:
        pointerPIO = PIOB;
        channel_id = 2;
        break;
    case L2_D38:
        pointerPIO = PIOC;
        channel_id = 2;
        break;
        // channel 3
    case H3_TX0:
        pointerPIO = PIOA;
        channel_id = 3;
        break;
    case H3_DAC0:
        pointerPIO = PIOB;
        channel_id = 3;
        break;
    case H3_D41:
        pointerPIO = PIOC;
        channel_id = 3;
        break;
    case L3_CANTX0:
        pointerPIO = PIOA;
        channel_id = 3;
        break;
    case L3_PB19:
        pointerPIO = PIOB;
        channel_id = 3;
        break;
    case L3_D40:
        pointerPIO = PIOC;
        channel_id = 3;
        break;
        // channel 4
    case H4_PC20:
        pointerPIO = PIOC;
        channel_id = 4;
        break;
    case L4_D9:
        pointerPIO = PIOC;
        channel_id = 4;
        break;
        // channel 5
    case H5_D44:
        pointerPIO = PIOC;
        channel_id = 5;
        break;
    case L5_D9:
        pointerPIO = PIOC;
        channel_id = 5;
        break;
        // channel 6
    case H6_D45:
        pointerPIO = PIOC;
        channel_id = 6;
        break;
    case L6_D7:
        pointerPIO = PIOC;
        channel_id = 6;
        break;
        // channel 7
    case L7_D6:
        pointerPIO = PIOC;
        channel_id = 7;
        break;
    default:
        hwlib::cout << "Pin not implemented for pwm\n";
        break;
    }
    uint8_t mask = 1 << channel_id; // make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2 in
                                    // PWM_ENA register.
    if (!(PWM->PWM_SR & mask)) {
        REG_PMC_PCER1 |= PMC_PCER1_PID36; // Enable PWM

        pointerPIO->PIO_ABSR |= pin; // PWM is always on b
        pointerPIO->PIO_PDR |= pin;  // enable pin for pwm

        PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(42);                      // default 2mhz
        PWM->PWM_CH_NUM[channel_id].PWM_CMR = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA; // enable clock a for channel x
        PWM->PWM_CH_NUM[channel_id].PWM_CPRD = 20000;                           // default 50hz
        PWM->PWM_CH_NUM[channel_id].PWM_CDTY = 1500;                            // default 20% dutycycle
        PWM->PWM_ENA = (PWM->PWM_SR | mask);                                    // enable channel x
    } else {
        hwlib::cout << "This channel is already in use by another controller" << hwlib::endl;
    }
}

void PWMcontroller::setFreq(const uint32_t &setFreq) {
    if (setFreq > 0) {
        uint8_t i = 1;
        uint32_t maxCPRD = 65535;
        uint32_t newCPRD = (84000000 / (2 * setFreq));
        while (newCPRD > maxCPRD) {
            newCPRD = static_cast<uint32_t>((84000000 / i) / (2 * setFreq)); // calculate new CRPD value
            ++i;
            if (i == 0) {
                break; // break, no clock can be used for this freq.
            }
        }
        if (i != 0) {
            PWM->PWM_WPSR;                                    // enable permissions to change clock
            PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(i); // setting up right clk divider
            PWM->PWM_CH_NUM[channel_id].PWM_CPRD = newCPRD;   // setting pwm freq
            setDutyCycle(dutyCycle);                          // update dutycycle
            freq = setFreq;
        } else {
            hwlib::cout << "This freq can't be used" << hwlib::endl;
        }
    }
}

void PWMcontroller::setDutyCycle(const double &setDutyCycle) {
    if (setDutyCycle > 0 && setDutyCycle < 100) {
        dutyCycle = PWM->PWM_CH_NUM[channel_id].PWM_CPRD / (100 / setDutyCycle);
        if (dutyCycle < 65535) {
            PWM->PWM_CH_NUM[channel_id].PWM_CDTY = dutyCycle;
            dutyCycle = setDutyCycle;
        }
    }
}

inline uint32_t PWMcontroller::getFreq() {
    return freq;
}

inline double PWMcontroller::getDutyCycle() {
    return dutyCycle;
}