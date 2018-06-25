#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &_pin) : pin(_pin) {
    pin = 0;
}

void PWMcontroller::setFreq(const uint32_t &setFreq) {
    hwlib::cout << "set freq called" << hwlib::endl;
}

void PWMcontroller::setDutyCycle(const double &setDutyCycle) {
    hwlib::cout << "set duty called" << hwlib::endl;
}

uint32_t PWMcontroller::getFreq() {
    return freq;
}

double PWMcontroller::getDutyCycle() {
    return dutyCycle;
}
