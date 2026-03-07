void set_motor_pwm(int pwm, int ch1, int ch2)
{
  pwm = constrain(pwm, -255, 255);

  Serial.print("Motor channels ");
  Serial.print(ch1);
  Serial.print("/");
  Serial.print(ch2);
  Serial.print(" -> ");

  if (pwm > 0) { // forward
    Serial.print("FORWARD | speed: ");
    Serial.println(pwm);
    ledcWrite(ch1, pwm);   // PWM on IN1
    ledcWrite(ch2, 0);     // IN2 LOW
  }
  else if (pwm < 0) { // reverse
    Serial.print("REVERSE | speed: ");
    Serial.println(-pwm);
    ledcWrite(ch1, 0);     // IN1 LOW
    ledcWrite(ch2, -pwm);  // PWM on IN2
  }
  else { // stop
    Serial.println("STOP");
    ledcWrite(ch1, 0);
    ledcWrite(ch2, 0);
  }
}