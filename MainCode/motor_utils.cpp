#include <Arduino.h>
#include "motor_utils.h"

void setMotorPwm(int pin1, int pin2, int pwm) {
  pwm = constrain(pwm, -255, 255);

  if (pwm < 0) { // reverse
    ledcWrite(pin1, -pwm);
    ledcWrite(pin2, 0);
  }
  else if (pwm > 0) { // forward
    ledcWrite(pin1, 0);
    ledcWrite(pin2, pwm);
  }
  else { // stop
    ledcWrite(pin1, 0);
    ledcWrite(pin2, 0);
  }
}

void setupMotors() {
  ledcAttach(MOT_A1_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_A2_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_B1_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_B2_PIN, PWM_FREQ, PWM_RES);

  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 0);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
}

void moveForward(int speed) {
  speed = constrain(speed, -255, 255);
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, speed);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, speed);
}

void moveBackward(int speed) {
  moveForward(-speed);
}

void moveLeft(int speed) {
  speed = constrain(speed, -255, 255);
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, speed);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
}

void moveRight(int speed) {
  moveLeft(-speed);
}

void diagonalForwardLeft(int speed) { 
  speed = constrain(speed, -255, 255);
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, speed * (255 / 120.0));
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, speed);
}

void diagonalForwardRight(int speed) { 
  speed = constrain(speed, -255, 255);
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, speed);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, speed * (255 / 120.0));
}

void diagonalBackwardLeft(int speed) {
  diagonalForwardLeft(-speed);
}

void diagonalBackwardRight(int speed) {
  diagonalForwardRight(-speed);
}