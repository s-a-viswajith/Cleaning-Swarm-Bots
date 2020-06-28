#include <Servo.h>
Servo servo
const int echopin=5;
const int trigpin=6;
const int m1a=2;
const int m1b=4;
const int m2a=7;
const int m2b=8;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Servo.attach(3);
  Servo.write(0);
  pinMode(echopin,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(m1a,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2a,OUTPUT);
  pinMode(m2b,OUTPUT);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,HIGH);   //forward motion
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,HIGH);
  Servo.write(180);
  delay(500);
  Servo.write(0);
  delay(500);
  
  if(distance<20)
{
  digitalWrite(m1A,LOW);
  digitalWrite(m1B,LOW);   //stop
  digitalWrite(m2A,LOW);
  digitalWrite(m2B,LOW);
  delay(500);
  digitalWrite(m1A,LOW);
  digitalWrite(m1B,HIGH);  //reverse
  digitalWrite(m2A,LOW);
  digitalWrite(m2B,HIGH);
  delay(500);
  digitalWrite(m1A,LOW);
  digitalWrite(m1B,LOW);   //stop
  digitalWrite(m2A,LOW);
  digitalWrite(m2B,LOW);
  delay(500);
  digitalWrite(m1A,HIGH);
  digitalWrite(m1B,LOW);  //right
  digitalWrite(m2A,LOW);
  digitalWrite(m2B,HIGH);
  delay(500);
}
}
