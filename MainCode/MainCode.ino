#include "utils.h"

void setup() {
  Serial.begin(115200);
  setupMotors();
  setupLights();
}

void loop() {
  Serial.println("Forward and headlights on");
  toggleHeadlights(true);
  moveForward(100);
  delay(3000);
  Serial.println("Backward and headlights off");
  toggleHeadlights(false);
  moveBackward(100);
  delay(3000);
  Serial.println("Left and rearlights on");
  toggleRearlights(true);
  moveLeft(100);
  delay(3000);
  Serial.println("Right and rearlights off");
  toggleRearlights(false);
  moveRight(100);
  delay(3000);
  Serial.println("Diagonal forward left and both lights on");
  toggleHeadlights(true);
  toggleRearlights(true);
  diagonalForwardLeft(50);
  delay(3000);
  Serial.println("Diagonal forward right and both lights off");
  toggleHeadlights(false);
  toggleRearlights(false);
  diagonalForwardRight(50);
  delay(3000);
  Serial.println("Diagonal backwards left and both lights off");
  diagonalBackwardLeft(70);
  delay(3000);
  Serial.println("Diagonal backwards right and both lights off");
  diagonalBackwardRight(70);
  delay(3000);
}
