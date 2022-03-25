#The arduino-ultrasonic-servo motor code
#include<SoftwareSerial.h> 
#include <Servo.h> 
int trigPin=9; 
int echoPin=10; 
int servoControlPin=12; 
float pingTime; 

float targetDistance; 
float speedOfSound=0.034; 
float p=0.0; //Variable for the value we want to set servo to. float n; 
Servo myPointer; 
void setup() { 
// put your setup code here, to run once: 
Serial.begin(9600); 
pinMode(servoControlPin, OUTPUT); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
myPointer.attach(servoControlPin); //Tell arduino where the servo is attached. 
} 

void loop() { 
// put your main code here, to run repeatedly: 
for(p=30;p<=120;p++) 
{ 
myPointer.write(p); 
delay(10000); 
ultrasonic(); 
n=((p-30)/6.20)+3; 
//Serial.println("The distance should be:"); 
//Serial.print(n); 
p=p+29; 
} 
} 
void ultrasonic() 
{ 

digitalWrite(trigPin, LOW); //Set trigger pin low delayMicroseconds(2000); //Let signal settle 
digitalWrite(trigPin, HIGH); //Set trigPin high delayMicroseconds(15); //Delay in high state 
digitalWrite(trigPin, LOW); //ping has now been sent delayMicroseconds(10); //Delay in low state 
pingTime = pulseIn(echoPin, HIGH); 
targetDistance= speedOfSound * pingTime; 
targetDistance=targetDistance/2; 
//Serial.print("The Distance to Target is: "); 
Serial.print(targetDistance); 
//Serial.println(" cms"); 
delay(1000); 
//Serial.print("The servo angle is: "); 
//Serial.println(p); 
delay(1000); 
} 
