#include <Servo.h>
//Tutorial: https://www.arduino.cc/en/Tutorial/Sweep 

Servo myservo1;
Servo myservo2;

int pos1 = 0;
int pos2 = 50;

int delta1 = 1;
int delta2 = 1;

int calibrationTime = 30;

int pirPin = 6;
int laserPin = 13;

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(9);
  myservo2.attach(3);
  pinMode(laserPin,OUTPUT);
  pinMode(pirPin, INPUT);
  
    // put your setup code here, to run once:
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
  //  original approach 
  if(digitalRead(pirPin) == HIGH){

      myservo1.write(pos1);
      myservo2.write(pos2);
      
      pos1 = pos1 + delta1;
      pos2 = pos2 + delta2;

      digitalWrite(laserPin,HIGH);
      Serial.println("laser should be on"); 
      Serial.println(pos1);
      
      if(pos1 == 0 || pos1 == 90){
          delta1 = -delta1;                                                                                                                  
        }

      if(pos2 == 135 || pos2 == 45){
          delta2 = -delta2;                                                                                                                     
        }
        
      delay(5);
   }else{
      digitalWrite(laserPin,LOW);
      Serial.println("laser should be off");
    }
   

}
