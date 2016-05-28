int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 50;
boolean lockLow = true;
boolean takeLowTime;

int pirPin = 6;
int ledPin = 13;

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
  if(digitalRead(pirPin)==HIGH){
  	digitalWrite(ledPin,HIGH);
    delay(5);
    digitalWrite(ledPin,LOW);
  	if(lockLow){
  		lockLow = false;
  		Serial.println("---");
  		Serial.println("motion detected at ");
  		Serial.println(millis()/1000);
  		Serial.println(" sec");
  		//delay(50);
  	}
  	takeLowTime = true;
  }

  if(digitalRead(pirPin) == LOW){
  	digitalWrite(ledPin,LOW);

  	if(takeLowTime){
  		lowIn = millis();
  		takeLowTime = false;
  	}

  	if(!lockLow && millis() - lowIn > pause){
  		lockLow = true;
  		Serial.println("motion ended at ");
  		Serial.println((millis()-pause)/1000);
  		Serial.println(" sec");
  		//delay(50);
  	}
  }
}
