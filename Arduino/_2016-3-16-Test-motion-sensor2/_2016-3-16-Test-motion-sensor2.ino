int pirPin = 6;
int ledPin = 13;
int pirState = LOW;
int val = 0;
int calibrationTime = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

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
  val = digitalRead(pirPin);
  if(val==HIGH){
  	digitalWrite(ledPin,HIGH);
    if(pirState == LOW){
      Serial.println("---motion detected---");   
      pirState = HIGH;
     }
  }else{
  	digitalWrite(ledPin,LOW);
   if(pirState == LOW){
          Serial.println("---no motion detected---");
          pirState = LOW;
    }
  }
}
