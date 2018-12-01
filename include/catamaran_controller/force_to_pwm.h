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
  const float MIN_MAX_LEFT_MOTOR_FORCE_[2] = {-1.47*9.8, 1.38*9.8};
  const float MIN_MAX_RIGHT_MOTOR_FORCE_[2] = {-1.48*9.8, 1.43*9.8};
  float left_motor_force_;
  float right_motor_force_;
  
  public:

  ForceToPWM();
  ~ForceToPWM();
  
  // bool isLeftForcePossible();
  // bool isRightForcePossible();
  float getRightPWM();
  float getLeftPWM();
  bool setLeftMotorForce(float left_force);
  bool setRightMotorForce(float right_force);   

};