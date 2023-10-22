#include <Servo.h>
#define echoPin 4 //Echo Pin
#define trigPin 3 //Trigger Pin

Servo myservo;
long duration, distance;
const int servoPin = 10;

void setup() {
  Serial.begin (9600);
  myservo.attach(servoPin);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  myservo.write(180);
  delay(1000);
  myservo.detach();
}

void loop() {
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(distance);
  distance = duration/58.2;
  if(distance <= 10) {
    myservo.attach(servoPin);
    myservo.write(0);
    delay(2000);
    myservo.write(90);
    delay(1500);
    myservo.detach();

  }
  delay(13);
}
