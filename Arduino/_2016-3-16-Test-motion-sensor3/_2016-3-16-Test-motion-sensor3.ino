int calibrationTime = 30;

int pirPin = 6;
int ledPin = 13;
int val = 0;

boolean trigged = false;
int triggedTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW);

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

  if(trigged){
    if(millis()-triggedTime > 100){
      Serial.println("Current time---");
      Serial.print(millis());
      Serial.println("last Triggend time---");
      Serial.print(triggedTime);
      Serial.println("different---");
      Serial.print(millis()-triggedTime);
      trigged = false;
    }
  }

  if(digitalRead(pirPin) == HIGH){
    if(!trigged){
      trigged = true;
    }
    triggedTime = millis();
    Serial.println("triggend time---");
    Serial.print(triggedTime);
  }

  if(trigged){
          digitalWrite(ledPin,HIGH);
          Serial.println("led is high");
    }else{
          digitalWrite(ledPin,LOW);
          Serial.println("led is low");
      }

}
