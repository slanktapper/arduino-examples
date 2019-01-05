//Henry's Bench
// HC-SR501 Motion Detector
// Sample Sketch

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value

int warnTime = 30;
int warnOn = 0;
int alreadyHigh = 0;
int delayMs = 100;
int delayedTime = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
}

void loop() {
  pirValue = digitalRead(pirPin);
  warn(pirValue);
  delay(delayMs);

  delayedTime = (delayedTime + delayMs) % 1000;
}

void warn(int input){
  
  if ((input == HIGH) && (alreadyHigh != 1))
  {
    warnOn = warnTime*(1000/delayMs);
  }
  alreadyHigh = input;
  if (warnOn > 0)
  {
    if (delayedTime < delayMs)
    {
      digitalWrite(ledPin,HIGH);
    }
    else
    {
      digitalWrite(ledPin,LOW);
    }
    warnOn -= 1;
  }
  else
  {
      digitalWrite(ledPin,LOW);
  }
}
