#define MOT_A1_PIN 4
#define MOT_A2_PIN 5
#define MOT_B1_PIN 18
#define MOT_B2_PIN 19

#define PWM_FREQ 1000      // 1 kHz PWM
#define PWM_RES 8          // 8-bit resolution (0-255)

#define CH_A1 0
#define CH_A2 1
#define CH_B1 2
#define CH_B2 3

void set_motor_pwm(int pwm, int ch1, int ch2);

void setup() {
  Serial.begin(9600);
  Serial.println("ESP32 Motor Test Starting...");

  // Configure PWM channels
  ledcSetup(CH_A1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_A2, PWM_FREQ, PWM_RES);
  ledcSetup(CH_B1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_B2, PWM_FREQ, PWM_RES);

  // Attach pins to channels
  ledcAttachPin(MOT_A1_PIN, CH_A1);
  ledcAttachPin(MOT_A2_PIN, CH_A2);
  ledcAttachPin(MOT_B1_PIN, CH_B1);
  ledcAttachPin(MOT_B2_PIN, CH_B2);

  // Stop motors initially
  set_motor_pwm(0, CH_A1, CH_A2);
  set_motor_pwm(0, CH_B1, CH_B2);
}

void loop() {

  Serial.println("-----------------------------");
  Serial.println("Motor A: FORWARD  | Motor B: REVERSE");
  set_motor_pwm(50, CH_A1, CH_A2);
  set_motor_pwm(-50, CH_B1, CH_B2);
  delay(2000);

  Serial.println("-----------------------------");
  Serial.println("Motor A: STOP     | Motor B: FORWARD");
  set_motor_pwm(0, CH_A1, CH_A2);
  set_motor_pwm(50, CH_B1, CH_B2);
  delay(2000);

  Serial.println("-----------------------------");
  Serial.println("Motor A: REVERSE  | Motor B: STOP");
  set_motor_pwm(-50, CH_A1, CH_A2);
  set_motor_pwm(0, CH_B1, CH_B2);
  delay(2000);

  Serial.println("-----------------------------");
  Serial.println("Motor A: REVERSE  | Motor B: FORWARD");
  set_motor_pwm(-50, CH_A1, CH_A2);
  set_motor_pwm(50, CH_B1, CH_B2);
  delay(2000);

  Serial.println("-----------------------------");
  Serial.println("Motor A: STOP     | Motor B: STOP");
  set_motor_pwm(0, CH_A1, CH_A2);
  set_motor_pwm(0, CH_B1, CH_B2);
  delay(2000);
}

/// pwm = -255..255
/// ch1 = PWM channel for IN1, ch2 = PWM channel for IN2
void set_motor_pwm(int pwm, int ch1, int ch2)
{
  pwm = constrain(pwm, -255, 255);

  Serial.print("Motor channels ");
  Serial.print(ch1);
  Serial.print("/");
  Serial.print(ch2);
  Serial.print(" -> ");

  if (pwm < 0) { // reverse
    Serial.print("REVERSE | speed: ");
    Serial.println(-pwm);
    ledcWrite(ch1, -pwm);
    ledcWrite(ch2, 0);
  }
  else if (pwm > 0) { // forward
    Serial.print("FORWARD | speed: ");
    Serial.println(pwm);
    ledcWrite(ch1, 0);
    ledcWrite(ch2, pwm);
  }
  else { // stop
    Serial.println("STOP");
    ledcWrite(ch1, 0);
    ledcWrite(ch2, 0);
  }
}