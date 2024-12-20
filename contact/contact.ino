  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n');
      Serial.print("Received: ");
      Serial.println(data);  // Echo back the received data

      // You can also control hardware based on received data here!
    }


  }
