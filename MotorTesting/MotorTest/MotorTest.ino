#define MOT_A1_PIN 4
#define MOT_A2_PIN 5
#define MOT_B1_PIN 18
#define MOT_B2_PIN 19

#define PWM_FREQ 1000      // 1 kHz PWM
#define PWM_RES 8          // 8-bit resolution (0-255)

void setMotorPwm(int pin1, int pin2, int pwm);

void setup() {
  Serial.begin(115200);

  ledcAttach(MOT_A1_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_A2_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_B1_PIN, PWM_FREQ, PWM_RES);
  ledcAttach(MOT_B2_PIN, PWM_FREQ, PWM_RES);

  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 0);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
}

void loop() {
  Serial.println("Motor A and B forward");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 100);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 100);
  delay(2000);
  Serial.println("Motor A and B stopped");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 0);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
  delay(2000);
  Serial.println("Motor A and B reversed");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, -100);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, -100);
  delay(2000);
  Serial.println("Motor A forward and motor B stopped");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 50);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
  delay(2000);
  Serial.println("Motor A reversed and motor B stopped");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, -50);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 0);
  delay(2000);
  Serial.println("Motor B forward and motor A stopped");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 0);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, 50);
  delay(2000);
  Serial.println("Motor B reversed and motor A stopped");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 0);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, -50);
  delay(2000);
  Serial.println("Motor A forward and motor B reversed");
  setMotorPwm(MOT_A1_PIN, MOT_A2_PIN, 100);
  setMotorPwm(MOT_B1_PIN, MOT_B2_PIN, -100);
  delay(2000);
}

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
