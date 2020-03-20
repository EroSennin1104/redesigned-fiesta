#include <VarSpeedServo.h>
#define lmt1 A0
#define lmt2 A1
#define rmt1 A2
#define rmt2 A3
VarSpeedServo stservo;
int servoPin=4;
int trigPin[5];
int echoPin[5];
long duration[5];
int distance[5];
int i;
int j=12;
int k=13;


void setup() {
  stservo.attach(servoPin);
  stservo.write(45,255);
  for(i=0;i<5;i++)
  {
    trigPin[i]=k;
    echoPin[i]=j;
    k=k-2;
    j=j-2;
  }
  for(i=0;i<5;i++)
  {
   pinMode(trigPin[i], OUTPUT); 
   pinMode(echoPin[i], INPUT);
  }  
   Serial.begin(9600); 
}

void loop() {
  for(i=0;i<5;i++)
  {
   digitalWrite(trigPin[i], LOW);
   delayMicroseconds(2); 
   digitalWrite(trigPin[i], HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin[i], LOW); 
   duration[i]=pulseIn(echoPin[i], HIGH); 
   distance[i]=duration*0.034/2;
  }
   front();
   if(distance[1]<=9&&distance[2]<=9)
   {
    while(distance[3]>=7)
    rright();
    while(distance[4]>=3)
    rleft();
    rest();
    delay(2000);
    while(distance[3]>=7)
    fright();
    fleft();
    front();
    delay(1000)
    rest();
    delay(5000);
   }
}

void front()
{
  stservo.write(45,100);
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW);
}

void reverse()
{
  stservo.write(45,100);
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,HIGH);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,HIGH);
}

void fright()
{
  stservo.write(0,100);
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW);
}

void fleft()
{
  stsevo.write(90,100);
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW);
}

void rright()
{
  stservo.write(0,100);
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,HIGH);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,HIGH);
}

void rleft()
{
  stservo.write(90,100);
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,HIGH);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,HIGH);
}

void rest()
{
  stservo.write(45,255);
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,LOW);
}
