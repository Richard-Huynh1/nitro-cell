#define MOT_A1_PIN 4
#define MOT_A2_PIN 5
#define MOT_B1_PIN 18
#define MOT_B2_PIN 19

void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN);

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(MOT_A1_PIN, OUTPUT);
  pinMode(MOT_A2_PIN, OUTPUT);
  pinMode(MOT_B1_PIN, OUTPUT);
  pinMode(MOT_B2_PIN, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(MOT_A1_PIN, LOW);
  digitalWrite(MOT_A2_PIN, LOW);
  digitalWrite(MOT_B1_PIN, LOW);
  digitalWrite(MOT_B2_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Motor test starting...");
}

// the loop function runs over and over again forever
void loop() {

  Serial.println("-----------------------------");
  Serial.println("Motor A: FORWARD  | Motor B: REVERSE");

  set_motor_pwm(50, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(-50, MOT_B1_PIN, MOT_B2_PIN);
  delay(2000);


  Serial.println("-----------------------------");
  Serial.println("Motor A: STOP     | Motor B: FORWARD");

  set_motor_pwm(0, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(50, MOT_B1_PIN, MOT_B2_PIN);
  delay(2000);


  Serial.println("-----------------------------");
  Serial.println("Motor A: REVERSE  | Motor B: STOP");

  set_motor_pwm(-50, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(0, MOT_B1_PIN, MOT_B2_PIN);
  delay(2000);


  Serial.println("-----------------------------");
  Serial.println("Motor A: REVERSE  | Motor B: FORWARD");

  set_motor_pwm(-50, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(50, MOT_B1_PIN, MOT_B2_PIN);
  delay(2000);


  Serial.println("-----------------------------");
  Serial.println("Motor A: STOP     | Motor B: STOP");

  set_motor_pwm(0, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(0, MOT_B1_PIN, MOT_B2_PIN);
  delay(2000);
}

/// pwm ranges from -255 (full reverse) to 255 (full forward)
/// IN1_PIN and IN2_PIN are the control pins for the motor
void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN)
{
  Serial.print("Motor pins ");
  Serial.print(IN1_PIN);
  Serial.print("/");
  Serial.print(IN2_PIN);
  Serial.print(" -> ");

  if (pwm < 0) {  // reverse
    Serial.print("REVERSE | speed: ");
    Serial.println(-pwm);

    analogWrite(IN1_PIN, -pwm);
    digitalWrite(IN2_PIN, LOW);

  } 
  else if (pwm > 0) { // forward
    Serial.print("FORWARD | speed: ");
    Serial.println(pwm);

    digitalWrite(IN1_PIN, LOW);
    analogWrite(IN2_PIN, pwm);
  } 
  else { // stop
    Serial.println("STOP");

    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
  }
}