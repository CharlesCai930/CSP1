#include <Servo.h>
//Tutorial: https://www.arduino.cc/en/Tutorial/Sweep 

Servo myservo1;
Servo myservo2;

int pos = 0;
int delta = 1;
int calibrationTime = 30;
int pirPin = 6;

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(9);
  myservo2.attach(3);

    // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin, INPUT);

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
     for(pos = 90; pos<=180;pos += 1){
        myservo1.write(pos);
        delay(5);
     }
     
     for(pos=180;pos>=90;pos -= 1){
        myservo1.write(pos);
        delay(5);
     }
   }
   
  /*
  myservo1.write(pos);
  myservo2.write(pos);
  
  pos = pos + delta;

  if(pos == 0 || pos == 90){
      delta = -delta;                                                                                                                     
    }
  delay(1);
*/

}
