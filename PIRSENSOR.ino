// Pin Definitions
const int pirPin = 2;     // PIR motion sensor signal pin
const int buzzerPin = 8;  // Buzzer pin
const int houseLedPin = 13; // House interior LED pin

int pirState = LOW; // Start with no motion detected

void setup() {
  pinMode(pirPin, INPUT);       // Set PIR sensor as input
  pinMode(buzzerPin, OUTPUT);    // Set Buzzer as output
  pinMode(houseLedPin, OUTPUT);  // Set House LED as output
  
  Serial.begin(9600);           // Initialize serial communication
  delay(2000);                  // Wait for PIR sensor calibration
}

void loop() {
  // Read the sensor value (HIGH = Motion, LOW = No Motion)
  pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    Serial.println("INTRUDER DETECTED! Alarm & Lights ON! 🚨🏠");
    
    digitalWrite(houseLedPin, HIGH); // Turn on the house light
    
    // Alert alarm effect (blinking sound)
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  } 
  else {
    Serial.println("Secure... Lights and alarm OFF. ✅");
    digitalWrite(houseLedPin, LOW);   // Turn off the house light
    digitalWrite(buzzerPin, LOW);    // Turn off the buzzer
    delay(200);                      // Small delay for system stability
  }
}
