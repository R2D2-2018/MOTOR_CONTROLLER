#include "MotorInterface.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    MotorInterface motorInterface;

    hwlib::cout << "Selected interface:" << hwlib::endl;

    if (motorInterface.getSelectedInterface() == MotorInterface::INTERFACE::DC) {
        hwlib::cout << "DC motor" << hwlib::endl;
    }

    return 0;
}
