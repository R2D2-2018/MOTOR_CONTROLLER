#include "stepper_interface.hpp"

MotorController::StepperInterface::StepperInterface() {
}

int8_t MotorController::StepperInterface::getSpeed() const {
    return speed;
}

void MotorController::StepperInterface::gotoStep(uint8_t step) {
    switch (step) {
    case 1:
        pwm1.setDutyCycle(100);
        pwm2.setDutyCycle(100);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(0);
        break;
    case 2:
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(100);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(0);
        break;
    case 3:
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(100);
        pwm3.setDutyCycle(100);
        pwm4.setDutyCycle(0);
        break;
    case 4:
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(100);
        pwm4.setDutyCycle(0);
        break;
    case 5:
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(100);
        pwm4.setDutyCycle(100);
        break;
    case 6:
        pwm1.setDutyCycle(0);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(100);
        break;
    case 7:
        pwm1.setDutyCycle(100);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(100);
        break;
    default:
        pwm1.setDutyCycle(100);
        pwm2.setDutyCycle(0);
        pwm3.setDutyCycle(0);
        pwm4.setDutyCycle(0);
    }
}

void MotorController::StepperInterface::doFullStep(int stepsToDo) {
    while (stepsToDo != 0) {
        if (stepsToDo > 0) {
            stepSequenceTracker += 2;
            if (stepSequenceTracker == 8) {
                stepSequenceTracker = 0;
            }
            stepsToDo -= 2;
        } else {
            stepSequenceTracker -= 2;
            if (stepSequenceTracker == -2) {
                stepSequenceTracker = 6;
            }
            stepsToDo += 2;
        }
        gotoStep(stepSequenceTracker);
        hwlib::wait_us(100000 / (speed / 5 + 1));
    }
    hwlib::wait_ms(50); ///< prevent motor not working with direct change
}

void MotorController::StepperInterface::doHalfStep(int stepsToDo) {
    while (stepsToDo != 0) {
        if (stepsToDo > 0) {
            stepSequenceTracker++;
            if (stepSequenceTracker == 8) {
                stepSequenceTracker = 0;
            }
            stepsToDo--;
        } else {
            stepSequenceTracker--;
            if (stepSequenceTracker == -1) {
                stepSequenceTracker = 7;
            }
            stepsToDo++;
        }
        gotoStep(stepSequenceTracker);
        hwlib::wait_us(100000 / (speed * 9 / 10 + 1));
    }
    hwlib::wait_ms(50); ///< prevent motor not working with direct change
}

void MotorController::StepperInterface::setSpeed(const int8_t newSpeed) {
    ///< Speed can only be -100 / 100
    if (newSpeed == 0) {
        speed = newSpeed;
    } else if (newSpeed > 0 && newSpeed <= 100) {
        speed = newSpeed;
    } else if (newSpeed < 0 && newSpeed >= -100) {
        speed = newSpeed;
    }
}

uint16_t MotorController::StepperInterface::getAngle() const {
    return maxSteps * 360 / steps;
}

void MotorController::StepperInterface::setAngle(const int16_t newAngle) {
    int stepsToDo = newAngle * maxSteps / 360;
    if (stepperMethod == 0) {
        doFullStep(stepsToDo);
    } else if (stepperMethod == 1) {
        doHalfStep(stepsToDo);
    }
}

uint8_t MotorController::StepperInterface::getStepperMethod() const {
    return stepperMethod;
}

void MotorController::StepperInterface::setStepperMethod(const uint8_t newMethod) {
    if (newMethod <= 1) {
        stepperMethod = newMethod;
        stepSequenceTracker = 0; ///< prevent missing step when swiching from half to full
        pwm1.setFreq(2500);
        pwm2.setFreq(2500);
        pwm3.setFreq(2500);
        pwm4.setFreq(2500);
    }
}

uint16_t MotorController::StepperInterface::getMaxSteps() const {
    return maxSteps;
}

void MotorController::StepperInterface::setMaxSteps(const uint16_t newMaxSteps) {
    if (newMaxSteps > 10) {
        maxSteps = newMaxSteps;
    }
}

void MotorController::StepperInterface::setMaxSteps(const double stride, const double gearRatio) {
    if (stride > 0) {
        maxSteps = (360 / stride) * gearRatio;
    }
}