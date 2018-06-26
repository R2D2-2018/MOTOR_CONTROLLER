#ifndef PWM_controller_HPP
#define PWM_controller_HPP

#include "wrap-hwlib.hpp"
// enum for all the avaible pwm pins on the arduino due.

/**
 * @file
 * @brief     This file contains the PWMcontroller and PWMpin, it is the class used for hardware pwm.
 *
 * @author    Stein Bout & Olivier Verwoerd
 * @license   See LICENSE
 */

enum PWMpin : uint8_t {
    // PWM_CH0
    H0_RX0,
    H0_SDA,
    H0_D35,
    L0_LEDTX,
    L0_DAC1,
    L0_D34,

    // PWM_CH1
    H1_D42,
    H1_SCL,
    H1_D37,
    L1_RX2,
    L1_A8,
    L1_D36,

    // PWM_CH2
    H2_TX2,
    H2_D53,
    H2_D39,
    L2_D43,
    L2_A9,
    L2_D38,

    // PWM_CH3
    H3_TX0,
    H3_DAC0,
    H3_D41,
    L3_CANTX0,
    L3_PB19,
    L3_D40,

    // PWM_CH4
    H4_PC20, // No Physical pinout
    L4_D9,

    // PWM_CH5
    H5_D44,
    L5_D8,

    // PWM_CH6
    H6_D45,
    L6_D7,

    // PWM_CH7
    L7_D6
};

class PWMcontroller {
  private:
    ///< channel_id used to determine which channel is currently used by this class
    uint8_t channel_id;
    ///< dutCycle value between 0-100. Determines the duty cycle of the pwm signal.
    double dutyCycle = 0;
    ///< freq used to store the current frequency used by this class. NOTE: other pwm classes may change this value and it will not
    ///< be updated automaticly.
    uint32_t freq = 0;
    ///< pin used to send the pwm signal to.
    uint32_t pin;

  public:
    /**
     * @brief contructor used for the PWM controller class.
     *
     * @param[in] PWMpin : The pin used to output the hardware pwm. Each pin will start with an H or L. All H-type pins are
     * inverted. The H/L is followed with the channel number. Only one pin can be used for each channel.
     *
     */
    PWMcontroller(const PWMpin &_pin);
    /**
     * @brief sets the new frequency used for the pwm signal
     *
     * This function sets the registers needed to change the frequency of the hardware pwm.
     * It will change the frequency for all the pwm controllers!
     * The duty cycle of this channel used will automaticly be corrected, however the other dutyCycle from other channels/pins will
     * remain untouched and need to be updated. Giving invalid data will send a warning to the console.
     * @param[in] setFreq : the new frequency, needs to be at least 4hz and can not be any higher than the master clock (84Mhz).
     * Input in hz.
     */
    void setFreq(const uint32_t &setFreq);
    /**
     * @brief sets the new duty cycle used for the pwm signal
     *
     * This function sets the registers needed to change the dutycyle of the hardware pwm.
     * It will change only change the duty cycle of this channel/pin.
     * @param[in] setDutyCycle : the new duty cycle, needs to be between 0 and 100. Double is used so for example: "34.7" is
     * allowed.
     */
    void setDutyCycle(const double &setDutyCycle);

    /**
     * @brief returns the current frequency stored.
     * @return returns an integer holding the current frequency in hz
     */
    uint32_t getFreq();
    /**
     * @brief returns the current duty cycle used.
     * @return returns a double holding the current duty cycle, returned value is between 0 - 100%
     */
    double getDutyCycle();
};

#endif // PWM_controller_HPP