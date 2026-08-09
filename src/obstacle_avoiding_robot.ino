#include <Servo.h>

Servo servo;

#define TRIG A0
#define ECHO A1

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

int limitDistance = 30;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  servo.attach(10);
  servo.write(90);

  stopRobot();

  delay(1000);
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long time = pulseIn(ECHO, HIGH, 30000);

  if (time == 0) {
    return 400;
  }

  return time * 0.0343 / 2;
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(80);

  stopRobot();
  delay(80);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(250);

  stopRobot();
  delay(150);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(250);

  stopRobot();
  delay(150);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(250);

  stopRobot();
  delay(150);
}

void loop() {

  servo.write(90);
  delay(120);

  long front = getDistance();

  Serial.print("Front: ");
  Serial.println(front);

  if (front > limitDistance) {

    forward();

  } else {

    stopRobot();
    delay(300);

    backward();

    // Check left side
    servo.write(150);
    delay(500);
    long left = getDistance();

    // Check right side
    servo.write(30);
    delay(500);
    long right = getDistance();

    servo.write(90);
    delay(300);

    if (left > right) {
      turnLeft();
    } else {
      turnRight();
    }
  }
}
