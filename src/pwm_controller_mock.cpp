/**
 * @file
 * @brief     This file contains the PWMcontroller mock used to enable tests since they dont understand the arduino registers
 * This has no function when useing the code.
 * @author    Olivier Verwoerd
 * @license   See LICENSE
 */

#include "pwm_controller.hpp"

PWMcontroller::PWMcontroller(const PWMpin &_pin) : pin(_pin) {
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
