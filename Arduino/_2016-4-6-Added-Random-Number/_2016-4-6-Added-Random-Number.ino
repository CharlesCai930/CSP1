#include <Servo.h>
//Tutorial: https://www.arduino.cc/en/Tutorial/Sweep 

Servo yServo;
Servo xServo;

int randomxDelay;
int randomyDelay;
int randomyServo;
int randomxServo;

int calibrationTime = 30;

int pirPin = 6;
int laserPin = 13;

void setup() {
  // put your setup code here, to run once:
  yServo.attach(9);
  xServo.attach(3);
  
  pinMode(laserPin,OUTPUT);
  pinMode(pirPin, INPUT);
  
  Serial.begin(9600);
  
  Serial.print("calibrating sensor");
    for(int i=0;i<calibrationTime;i++){
      Serial.print(".");
      delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pirPin) == HIGH){
    
    randomyDelay = random(100,500);
    randomxDelay = random(10);
    randomyServo = random(30,65);
    randomxServo = random(45,100);
    
    digitalWrite(laserPin,HIGH);

    yServo.write(randomyServo);
    delay(randomyDelay);
    
    xServo.write(randomxServo);
    delay(randomyDelay);

      //delay(randomDelay);
   }else{
      digitalWrite(laserPin,LOW);
    }
   

}
