#include <ros/console.h>
#include "ros/ros.h"
#include "catamaran_controller/force_to_pwm.h"

int main(int argc, char const *argv[])
{
    ForceToPWM exampleCalculator;

    do 
    {
        std::cout<< "Select force for left motor" << std::endl;
        std::cin >>  exampleCalculator.left_motor_force_;
    }
    while (exampleCalculator.isLeftForcePossible() == false);

    do
    {
        std::cout<< "Select force for right motor" << std::endl;
        std::cin >>  exampleCalculator.right_motor_force_;
    }
    while (exampleCalculator.isRightForcePossible() == false);

    std::cout << "The PWM for the Left motor is: " << exampleCalculator.calculateLeftPWM() << std::endl;
    std::cout << "The PWM for the Right motor is: " << exampleCalculator.calculateRightPWM() << std::endl;

    return 0;
}