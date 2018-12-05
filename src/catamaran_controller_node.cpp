#include <ros/console.h>
#include "ros/ros.h"
#include "catamaran_controller/force_to_pwm.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    ForceToPWM exampleCalculator;

    float l;
    float r;
    std::cout<< "Select force for left motor" << std::endl;
    std::cin >> l;
    
    std::cout<< "Select force for right motor" << std::endl;
    std::cin >>  r;

    l = exampleCalculator.getLeftPWM(l);
    r = exampleCalculator.getRightPWM(r);

    std::cout<< "Left PWM is: " << l << std::endl;
    std::cout<< "Right PWM is: " << r << std::endl;

    return 0;
}