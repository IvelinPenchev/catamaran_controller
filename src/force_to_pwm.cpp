#include "catamaran_controller/force_to_pwm.h"

ForceToPWM::ForceToPWM(){ }
ForceToPWM::~ForceToPWM(){ }

//Calculates the PWM signal based on the desired force
float ForceToPWM::calculateLeftPWM(float left_motor_force)
{
  float pwm = 0.0;
  
  if (left_motor_force == 0){
    pwm = 0;
  }else if(left_motor_force > 0){
    pwm = FUNCTION_LEFT_MOTOR_FORWARD_[0]*left_motor_force*left_motor_force + FUNCTION_LEFT_MOTOR_FORWARD_[1]*left_motor_force + FUNCTION_LEFT_MOTOR_FORWARD_[2];
  }else if(left_motor_force < 0){
    pwm = FUNCTION_LEFT_MOTOR_BACKWARD_[0]*left_motor_force*left_motor_force + FUNCTION_LEFT_MOTOR_BACKWARD_[1]*left_motor_force + FUNCTION_LEFT_MOTOR_BACKWARD_[2];
  }
  return pwm;
}

//Calculates the PWM signal based on the desired force
float ForceToPWM::calculateRightPWM(float right_motor_force)
{
  float pwm = 0.0;
  
  if (right_motor_force == 0){
    pwm = 0;
  }else if(right_motor_force > 0){
    pwm = FUNCTION_RIGHT_MOTOR_FORWARD_[0]*right_motor_force*right_motor_force + FUNCTION_RIGHT_MOTOR_FORWARD_[1]*right_motor_force + FUNCTION_RIGHT_MOTOR_FORWARD_[2];
  }else if(right_motor_force < 0){
    pwm = FUNCTION_RIGHT_MOTOR_BACKWARD_[0]*right_motor_force*right_motor_force + FUNCTION_RIGHT_MOTOR_BACKWARD_[1]*right_motor_force + FUNCTION_RIGHT_MOTOR_BACKWARD_[2];
  }
  return pwm;
}