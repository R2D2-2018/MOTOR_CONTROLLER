#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &pin) : pin(pin) {
    switch (pin) {
    case PWMpin::PWMpin2:
        break;
    case PWMpin::PWMpin3:
        break;
    case PWMpin::PWMpin4:
        break;
    case PWMpin::PWMpin5:
        break;
    case PWMpin::PWMpin6:
        break;
    case PWMpin::PWMpin7:
        break;
    case PWMpin::PWMpin8:
        break;
    case PWMpin::PWMpin9:
        break;
    case PWMpin::PWMpin10:
        break;
    case PWMpin::PWMpin11:
        break;
    case PWMpin::PWMpin12:
        break;
    case PWMpin::PWMpin13:
        break;
    }
};

void PWMcontroller::setPwmFreq(const uint8_t &setPwmFreq) {
}

inline uint8_t PWMcontroller::getPwmFreq() {
    return dutyCycle;
}