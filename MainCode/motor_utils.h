#ifndef MOTOR_UTILS_H
#define MOTOR_UTILS_H

#define MOT_A1_PIN 4
#define MOT_A2_PIN 5
#define MOT_B1_PIN 18
#define MOT_B2_PIN 19

#define PWM_FREQ 1000      // 1 kHz PWM
#define PWM_RES 8          // 8-bit resolution/motor speed range (0-255)

void setMotorPwm(int pin1, int pin2, int pwm);

void setupMotors();

void moveForward(int speed);
void moveBackward(int speed);

void moveLeft(int speed);
void moveRight(int speed);

void diagonalForwardLeft(int speed);
void diagonalForwardRight(int speed);

void diagonalBackwardLeft(int speed);
void diagonalBackwardRight(int speed);

#endif // MOTOR_UTILS_H
