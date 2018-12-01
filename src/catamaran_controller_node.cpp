#include <ros/console.h>
#include "ros/ros.h"
#include "catamaran_controller/force_to_pwm.h"

int main(int argc, char const *argv[])
{
    ForceToPWM exampleCalculator;

    exampleCalculator.setLeftMotorForce(4.5);
    exampleCalculator.setRightMotorForce(4.5);

    std::cout << "The PWM for the Left motor is: " << exampleCalculator.getLeftPWM() << std::endl;
    std::cout << "The PWM for the Right motor is: " << exampleCalculator.getRightPWM() << std::endl;

    return 0;
}