void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(1000);
  //start the SIM868 module
  pinMode(PA8, OUTPUT);
  digitalWrite(PA8, HIGH);
  delay(1000);
  digitalWrite(PA8, LOW);
  delay(1500);
  digitalWrite(PA8, HIGH);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}
