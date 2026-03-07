#define MOT_A1_PIN 4
#define MOT_A2_PIN 5
#define MOT_B1_PIN 18
#define MOT_B2_PIN 19

void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN);

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
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
}

// the loop function runs over and over again forever
void loop() {
    set_motor_pwm(50,MOT_A1_PIN,MOT_A2_PIN);
    set_motor_pwm(-50,MOT_B1_PIN,MOT_B2_PIN);
    delay(2000);
    set_motor_pwm(0,MOT_A1_PIN,MOT_A2_PIN);
    set_motor_pwm(50,MOT_B1_PIN,MOT_B2_PIN);
    delay(2000);
    set_motor_pwm(-50,MOT_A1_PIN,MOT_A2_PIN);
    set_motor_pwm(0,MOT_B1_PIN,MOT_B2_PIN);
    delay(2000);
    set_motor_pwm(-50,MOT_A1_PIN,MOT_A2_PIN);
    set_motor_pwm(50,MOT_B1_PIN,MOT_B2_PIN);
    delay(2000);
    set_motor_pwm(0,MOT_A1_PIN,MOT_A2_PIN);
    set_motor_pwm(0,MOT_B1_PIN,MOT_B2_PIN);
    delay(2000); 
}

/// \param pwm    PWM duty cycle ranging from -255 full reverse to 255 full forward
/// \param IN1_PIN  pin number xIN1 for the given channel
/// \param IN2_PIN  pin number xIN2 for the given channel

// AKA pwm is the speed of the motor, 0 is not running
void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN)
{
  if (pwm < 0) {  // reverse speeds
    analogWrite(IN1_PIN, -pwm);
    digitalWrite(IN2_PIN, LOW);

  } else { // stop or forward
    digitalWrite(IN1_PIN, LOW);
    analogWrite(IN2_PIN, pwm);
  }
}
