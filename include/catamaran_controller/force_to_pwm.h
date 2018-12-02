#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

class ForceToPWM
{ 
  private:
    const float FUNCTION_LEFT_MOTOR_FORWARD_[2] = {833.3, 1669}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the left motor conversion to PWM in forward motion
    const float FUNCTION_LEFT_MOTOR_BACKWARD_[2] = {158.8, 712.6}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the left motor conversion to PWM in backward motion
    const float FUNCTION_RIGHT_MOTOR_FORWARD_[2] = {-172.1, 760.3}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the right motor conversion to PWM in forward motion
    const float FUNCTION_RIGHT_MOTOR_BACKWARD_[2] = {105.7, 641.8}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the right motor conversion to PWM in backward motion
    const float MIN_MAX_LEFT_MOTOR_FORCE_[2] = {-1.47*9.8, 1.38*9.8};
    const float MIN_MAX_RIGHT_MOTOR_FORCE_[2] = {-1.48*9.8, 1.43*9.8};
    float left_motor_force_;
    float right_motor_force_;
    bool setLeftMotorForce_(float left_force);
    bool setRightMotorForce_(float right_force);
  
  public:
    ForceToPWM();
    ~ForceToPWM();    
    float getRightPWM(float force);
    float getLeftPWM(float force);
};
