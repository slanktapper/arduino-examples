int relayOn = LOW;
int relayOff = HIGH;
void setup() {
  // put your setup code here, to run once:

  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,relayOff);
  Serial.println("Off");
  delay(1000);
  digitalWrite(2,relayOn);
  Serial.println("On");
  delay(1000);
}
