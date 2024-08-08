#include <Servo.h>
Servo servo1;
int vel=1000; 
int ledPin= 12;

void setup() {
  servo1.attach(3);
  pinMode(ledPin,OUTPUT);
  

}

void loop() {
    digitalWrite(ledPin,LOW);
    servo1.write(0);
    delay(vel); 
    delay(vel);
    delay(vel);
    servo1.write(180);
    digitalWrite(ledPin,HIGH);
    delay(vel);
    delay(vel);
    delay(vel);
     
   
}
