#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

class ForceToPWM
{ 
  private:

  const float FUNCTION_LEFT_MOTOR_FORWARD_[3] = {-241.2, 833.3, 1669}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the left motor conversion to PWM in forward motion
  const float FUNCTION_LEFT_MOTOR_BACKWARD_[3] = {158.8, 712.6, 1345}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the left motor conversion to PWM in backward motion
  const float FUNCTION_RIGHT_MOTOR_FORWARD_[3] = {-172.1, 760.3, 1621}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the right motor conversion to PWM in forward motion
  const float FUNCTION_RIGHT_MOTOR_BACKWARD_[3] = {105.7, 641.8, 1357}; // the three parameters a,b,c of the quadratic function ax^2 + bx + c of the right motor conversion to PWM in backward motion

  public:

  ForceToPWM();
  ~ForceToPWM();

  float left_motor_force_;
  float right_motor_force_;
  
  bool isLeftForcePossible();
  bool isRightForcePossible();
  float calculateRightPWM();
  float calculateLeftPWM();
    

};