  void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
  }

  void loop() {
    if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n');
      Serial.print("Received: ");
      Serial.println(data);  // Echo back the received data
      digitalWrite(LED_BUILTIN, HIGH);

      // You can also control hardware based on received data here!
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
