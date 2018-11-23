#include "catamaran_controller/force_to_pwm.h"

ForceToPWM::ForceToPWM(){ }
ForceToPWM::~ForceToPWM(){ }

//Calculates the PWM signal based on the desired force
float ForceToPWM::calculateLeftPWM()
{
  float pwm = 0.0;
  
  if (left_motor_force_ == 0){
    pwm = 0;
  }else if(left_motor_force_ > 0){
    pwm = FUNCTION_LEFT_MOTOR_FORWARD_[0]*left_motor_force_*left_motor_force_ + FUNCTION_LEFT_MOTOR_FORWARD_[1]*left_motor_force_ + FUNCTION_LEFT_MOTOR_FORWARD_[2];
  }else if(left_motor_force_ < 0){
    pwm = FUNCTION_LEFT_MOTOR_BACKWARD_[0]*left_motor_force_*left_motor_force_ + FUNCTION_LEFT_MOTOR_BACKWARD_[1]*left_motor_force_ + FUNCTION_LEFT_MOTOR_BACKWARD_[2];
  }
  return pwm;
}

//Calculates the PWM signal based on the desired force
float ForceToPWM::calculateRightPWM()
{
  float pwm = 0.0;
  
  if (right_motor_force_ == 0){
    pwm = 0;
  }else if(right_motor_force_ > 0){
    pwm = FUNCTION_RIGHT_MOTOR_FORWARD_[0]*right_motor_force_*right_motor_force_ + FUNCTION_RIGHT_MOTOR_FORWARD_[1]*right_motor_force_ + FUNCTION_RIGHT_MOTOR_FORWARD_[2];
  }else if(right_motor_force_ < 0){
    pwm = FUNCTION_RIGHT_MOTOR_BACKWARD_[0]*right_motor_force_*right_motor_force_ + FUNCTION_RIGHT_MOTOR_BACKWARD_[1]*right_motor_force_ + FUNCTION_RIGHT_MOTOR_BACKWARD_[2];
  }
  return pwm;
}

bool ForceToPWM::isLeftForcePossible()
{
if (left_motor_force_ < -1.47 || left_motor_force_ > 1.38)
  {
  std::cout<<"Force in the left motor is not realistic. ";
  return false;
  }
  else
    return true;
}

bool ForceToPWM::isRightForcePossible()
{

  if (right_motor_force_ < -1.48 || right_motor_force_ > 1.43)
  {
    std::cout<<"Force in the right motor is not realistic. ";
    return false;
  }
  else
    return true;
}
