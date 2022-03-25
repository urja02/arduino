#Code for communicating the data from sensor to cloud: 
#include<SoftwareSerial.h> 
#include <ESP8266WiFi.h> 
#include<ThingSpeak.h> 
SoftwareSerial SUART (4); //connected to D2 
WiFiClient client; 
long mychannelnumber=1530225; 
const char myapi[]="4L7SRAWG2XTU1UT4"; 
void setup() { 
// put your setup code here, to run once: 
Serial.begin(9600); 
WiFi.mode(WIFI_STA); 
ThingSpeak.begin(client); 
WiFi.begin("Gunjan","gunjan123"); 
SUART.begin(9600); 
} 
char mydata[100]; 
void loop() { 
while (SUART.available()) 

{ 
//char x= SUART.read(); 
String x=SUART.readString(); 
Serial.print(x); 
delay(1000); 
ThingSpeak.writeField(mychannelnumber,1,x,myapi); 







