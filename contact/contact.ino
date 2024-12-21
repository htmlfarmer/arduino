int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // remove any leading / trailing white space!
    Serial.print("Received: ");
    Serial.println(command);  // Echo back the received data
    digitalWrite(LED_BUILTIN, HIGH);
    if (command.equalsIgnoreCase("high")) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (command.equalsIgnoreCase("low")) {
      digitalWrite(LED_BUILTIN, LOW);
    } else {
      Serial.println("new command?");
    }

    // check input button pins a & b
    if (digitalRead(buttonApin) == LOW)
    {
      Serial.println("A PIN!\n");
      digitalWrite(ledPin, HIGH);
    }
    if (digitalRead(buttonBpin) == LOW)
    {
      Serial.println("B PIN!\n");
      digitalWrite(ledPin, HIGH);
    }
  }
}