#include <Servo.h>

#define PROXIMITY_SENSOR_PIN 2  // Pin connected to the inductive proximity sensor
#define SERVO_PIN 9             // Pin connected to the servo motor
#define IRsen 3

Servo servoMotor;

void setup() {
  pinMode(PROXIMITY_SENSOR_PIN, INPUT);
  pinMode(IRsen,INPUT);
  servoMotor.attach(SERVO_PIN);
  servoMotor.write(0);  // Move servo to initial position (0 degrees)
  delay(1000);          // Wait for servo to reach initial position
}

void loop() {
  if (digitalRead(IRsen) == HIGH) {
    digitalWrite(4,HIGH);
    delay(2000);
  if (digitalRead(PROXIMITY_SENSOR_PIN) == HIGH) { // If metal detected
    rotateServoClockwise();
    delay(5000);  // Stay in rotated position for 5 seconds
    rotateServoCounterClockwise();
    
  }else{
    rotateServoCounterClockwise();
    delay(5000);
    rotateServoClockwise();
  }
  digitalWrite(4,LOW);
}
}
void rotateServoClockwise() {
  servoMotor.write(55); // Rotate servo 55 degrees clockwise
}

void rotateServoCounterClockwise() {
  servoMotor.write(0);  // Rotate servo back to original position (0 degrees)
}
