#include "motor_utils.h"

void setup() {
  Serial.begin(115200);
  setupMotors();
}

void loop() {
  Serial.println("Forward");
  moveForward(100);
  delay(3000);
  Serial.println("Backward");
  moveBackward(100);
  delay(3000);
  Serial.println("Left");
  moveLeft(100);
  delay(3000);
  Serial.println("Right");
  moveRight(100);
  delay(3000);
  Serial.println("Diagonal forward left");
  diagonalForwardLeft(50);
  delay(3000);
  Serial.println("Diagonal forward right");
  diagonalForwardRight(50);
  delay(3000);
  Serial.println("Diagonal backwards left");
  diagonalBackwardLeft(70);
  delay(3000);
  Serial.println("Diagonal backwards right");
  diagonalBackwardRight(70);
  delay(3000);
}
