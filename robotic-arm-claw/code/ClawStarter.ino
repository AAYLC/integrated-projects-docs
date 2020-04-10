//DIH Starter
#define btmSVpin 8
#define topSVpin 9
#define gripSVpin 10
#define spinSVpin 11
#define btnActivePin 13
#define btnStartPin 12
#include <Servo.h>


int armState = 0;
Servo btmServo;
Servo topServo;
Servo gripServo;
Servo spinServo;

void setup() {
  btmServo.attach(btmSVpin);
  topServo.attach(topSVpin);
  gripServo.attach(gripSVpin);
  pinMode(btnActivePin, INPUT_PULLUP);
  pinMode(btnStartPin, INPUT_PULLUP);
  delay(1000);
  startPos();
}

void loop() {
  int btnActiveState = digitalRead(btnActivePin);
  int btnStartState = digitalRead(btnStartPin);
  Serial.println(btnActiveState);
  if (btnActiveState == HIGH) {
    activateEvent();
  }
  if (btnStartState == HIGH) {
    startPos();
  }
}

void startPos() {

    btmServo.write(45);
    topServo.write(120);
    gripServo.write(15);
    spinServo.write(90);
    spinServo.detach();

}

void activateEvent() {
  spinServo.attach(spinSVpin);
  btmServo.write(46);
  topServo.write(120);
  delay(1000);
  btmServo.write(100);
  topServo.write(85);
  delay(1000);
  spinServo.write(45);
  delay(325);
  spinServo.write(90);
  delay(1000);
  btmServo.write(55);
  topServo.write(55);
  delay(500);
  topServo.write(75);
  delay(1000);
  gripServo.write(40);
  spinServo.detach();
}
