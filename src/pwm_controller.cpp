#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &_pin) : pin(_pin) {
    Pio *pointerPIO;
    switch (pin) {
        ///< channel 0
    case H0_RX0:
        pin = PIO_PA8;
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case H0_SDA:
        pin = PIO_PB12;
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case H0_D35:
        pin = PIO_PC3;
        pointerPIO = PIOC;
        channel_id = 0;
        break;
    case L0_LEDTX:
        pin = PIO_PA21;
        pointerPIO = PIOA;
        channel_id = 0;
        break;
    case L0_DAC1:
        pin = PIO_PB16;
        pointerPIO = PIOB;
        channel_id = 0;
        break;
    case L0_D34:
        pin = PIO_PC2;
        pointerPIO = PIOC;
        channel_id = 0;
        break;
        ///< channel 1
    case H1_D42:
        pin = PIO_PA19;
        pointerPIO = PIOA;
        channel_id = 1;
        break;
    case H1_SCL:
        pin = PIO_PB13;
        pointerPIO = PIOB;
        channel_id = 1;
        break;
    case H1_D37:
        pin = PIO_PC5;
        pointerPIO = PIOC;
        channel_id = 1;
        break;
    case L1_RX2:
        pin = PIO_PA12;
        pointerPIO = PIOA;
        channel_id = 1;
        break;
    case L1_A8:
        pin = PIO_PB17;
        pointerPIO = PIOB;
        channel_id = 1;
        break;
    case L1_D36:
        pin = PIO_PC4;
        pointerPIO = PIOC;
        channel_id = 1;
        break;
        ///< channel 2
    case H2_TX2:
        pin = PIO_PA13;
        pointerPIO = PIOA;
        channel_id = 2;
        break;
    case H2_D53:
        pin = PIO_PB14;
        pointerPIO = PIOB;
        channel_id = 2;
        break;
    case H2_D39:
        pin = PIO_PC7;
        pointerPIO = PIOC;
        channel_id = 2;
        break;
    case L2_D43:
        pin = PIO_PA20;
        pointerPIO = PIOA;
        channel_id = 2;
        break;
    case L2_A9:
        pin = PIO_PB18;
        pointerPIO = PIOB;
        channel_id = 2;
        break;
    case L2_D38:
        pin = PIO_PC6;
        pointerPIO = PIOC;
        channel_id = 2;
        break;
        ///< channel 3
    case H3_TX0:
        pin = PIO_PA9;
        pointerPIO = PIOA;
        channel_id = 3;
        break;
    case H3_DAC0:
        pin = PIO_PB15;
        pointerPIO = PIOB;
        channel_id = 3;
        break;
    case H3_D41:
        pin = PIO_PC9;
        pointerPIO = PIOC;
        channel_id = 3;
        break;
    case L3_CANTX0:
        pin = PIO_PA0;
        pointerPIO = PIOA;
        channel_id = 3;
        break;
    case L3_PB19:
        pin = PIO_PB19;
        pointerPIO = PIOB;
        channel_id = 3;
        break;
    case L3_D40:
        pin = PIO_PC8;
        pointerPIO = PIOC;
        channel_id = 3;
        break;
        ///< channel 4
    case H4_PC20:
        pin = PIO_PC20;
        pointerPIO = PIOC;
        channel_id = 4;
        break;
    case L4_D9:
        pin = PIO_PC21;
        pointerPIO = PIOC;
        channel_id = 4;
        break;
        ///< channel 5
    case H5_D44:
        pin = PIO_PC19;
        pointerPIO = PIOC;
        channel_id = 5;
        break;
    case L5_D8:
        pin = PIO_PC22;
        pointerPIO = PIOC;
        channel_id = 5;
        break;
        ///< channel 6
    case H6_D45:
        pin = PIO_PC18;
        pointerPIO = PIOC;
        channel_id = 6;
        break;
    case L6_D7:
        pin = PIO_PC23;
        pointerPIO = PIOC;
        channel_id = 6;
        break;
        ///< channel 7
    case L7_D6:
        pin = PIO_PC24;
        pointerPIO = PIOC;
        channel_id = 7;
        break;
    default:
        hwlib::cout << "This pwm pin is not implemented" << hwlib::endl;
        return;
        break;
    }
    uint8_t mask = 1 << channel_id; ///< make mask based off channel_id, example channel_id = 2, mask is 0000 0100. enabling CHID2
                                    ///< in PWM_ENA register.
    if (!(PWM->PWM_SR & mask)) {
        REG_PMC_PCER1 |= PMC_PCER1_PID36; ///< Enable PWM

        pointerPIO->PIO_ABSR |= pin; ///< PWM is always on b
        pointerPIO->PIO_PDR |= pin;  ///< enable pin for pwm

        PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(42);                      ///< default 2mhz 84 / 42 = 2Mhz
        PWM->PWM_CH_NUM[channel_id].PWM_CMR = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA; ///< enable clock a for channel x
        PWM->PWM_CH_NUM[channel_id].PWM_CPRD = 20000;                           ///< default 50hz
        PWM->PWM_CH_NUM[channel_id].PWM_CDTY = 1500;                            ///< default 20% dutycycle
        PWM->PWM_ENA = (PWM->PWM_SR | mask);                                    ///< enable channel x
    }                                                                           ///< else
      ///< hwlib::cout << "This channel can not be used" << hwlib::endl;
}

void PWMcontroller::setFreq(const uint32_t &setFreq) {
    if (setFreq > 0 && setFreq < 84000000) {
        uint8_t i = 1;
        uint32_t maxCPRD = 65535;
        uint32_t newCPRD = (84000000 / (2 * setFreq));
        while (newCPRD > maxCPRD) {
            newCPRD = static_cast<uint32_t>((84000000 / i) / (2 * setFreq)); ///< calculate new CRPD value
            ++i;
            if (i == 0) {
                break; ///< break, no clock can be used for this freq.
            }
        }
        if (i != 0) {
            PWM->PWM_WPSR;                                    ///< enable permissions to change clock
            PWM->PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(i); ///< setting up right clk divider
            PWM->PWM_CH_NUM[channel_id].PWM_CPRD = newCPRD;   ///< setting pwm freq
            setDutyCycle(dutyCycle);                          ///< update duty cycle
            freq = setFreq;
            return;
        }
    }
    hwlib::cout << "This freq can't be used" << hwlib::endl;
}

void PWMcontroller::setDutyCycle(const double &setDutyCycle) {
    if (setDutyCycle >= 0 && setDutyCycle <= 100) {
        dutyCycle =
            PWM->PWM_CH_NUM[channel_id].PWM_CPRD / (100 / setDutyCycle); ///< get current freq and calculate the new dutycylce
        if (dutyCycle < 65535) {
            PWM->PWM_CH_NUM[channel_id].PWM_CDTY = dutyCycle; ///< set new duty cycle
            dutyCycle = setDutyCycle;                         ///< store current duty cycle.
        }
    } else {
        hwlib::cout << "This duty cyle can't be used" << hwlib::endl;
    }
}

uint32_t PWMcontroller::getFreq() {
    return freq;
}

double PWMcontroller::getDutyCycle() {
    return dutyCycle;
}
