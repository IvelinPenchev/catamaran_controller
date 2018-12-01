#include "catamaran_controller/force_to_pwm.h"

ForceToPWM::ForceToPWM(){
  left_motor_force_ = 0;
  right_motor_force_ = 0;
 }
ForceToPWM::~ForceToPWM(){ }

//Calculates the PWM signal based on the desired force
float ForceToPWM::getLeftPWM()
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
float ForceToPWM::getRightPWM()
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

// bool ForceToPWM::isLeftForcePossible()
// {
// if (left_motor_force_ < MIN_MAX_LEFT_MOTOR_FORCE_[0] || left_motor_force_ > MIN_MAX_LEFT_MOTOR_FORCE_[1])
//   {
//   std::cout<<"Force in the left motor is not realistic. ";
//   return false;
//   }
//   else
//     return true;
// }

// bool ForceToPWM::isRightForcePossible()
// {

//   if (right_motor_force_ < MIN_MAX_RIGHT_MOTOR_FORCE_[0] || right_motor_force_ > MIN_MAX_RIGHT_MOTOR_FORCE_[1])
//   {
//     std::cout<<"Force in the right motor is not realistic. ";
//     return false;
//   }
//   else
//     return true;
// }

bool ForceToPWM::setLeftMotorForce(float left_force)
{
if (left_force < MIN_MAX_LEFT_MOTOR_FORCE_[0] || left_force > MIN_MAX_LEFT_MOTOR_FORCE_[1])
  {
  std::cout<<"Force in the left motor is not realistic. ";
  return false;
  }
  else
    left_motor_force_ = left_force;
    return true;
}

bool ForceToPWM::setRightMotorForce(float right_force)
{
if (right_force < MIN_MAX_RIGHT_MOTOR_FORCE_[0] || right_force > MIN_MAX_RIGHT_MOTOR_FORCE_[1])
  {
  std::cout<<"Force in the right motor is not realistic. ";
  return false;
  }
  else
    right_motor_force_ = right_force;
    return true;
}
