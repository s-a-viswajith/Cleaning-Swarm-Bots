int distance;
long duration;
int trigpin=6;
int echopin=5;
int m1A=2;
int m1B=4;
int m2A=7;
int m2B=8;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(m1A,OUTPUT);
  pinMode(m1B,OUTPUT);
  pinMode(m2A,OUTPUT);
  pinMode(m2B,OUTPUT);
}

void loop() {
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
duration=pulseIn(echopin,HIGH);
distance=duration*0.01715;  
Serial.print("distance ");
Serial.println(distance);
delay(500);
digitalWrite(m1A,HIGH);
digitalWrite(m1B,HIGH);   //forward
digitalWrite(m2A,HIGH);
digitalWrite(m2B,HIGH);

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
