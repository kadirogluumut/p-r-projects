# 🚨 Arduino Smart Home Security System with PIR & Buzzer

A simple, effective, and budget-friendly DIY smart home security system. This project detects any human motion using a PIR sensor, instantly flashes the interior lights of a house model, and triggers a loud buzzer alarm.

Perfect for electronics hobbyists and beginners learning Arduino!

---

## 🚀 Features
- **Real-time Motion Detection:** Uses a high-sensitivity PIR sensor.
- **Visual Alert:** Instantly turns on the house interior LED when motion is detected.
- **Audio Alarm:** Triggers a pulsing buzzer alert to scare off intruders.
- **Serial Monitoring:** Displays security status on the Arduino IDE Serial Monitor.

---

## 🛠️ Components Needed
* Arduino Uno (or any compatible Arduino board)
* PIR Motion Sensor (HC-SR501)
* 5V Buzzer
* LED (for house interior light)
* 220Ω Resistor (for the LED)
* Breadboard & Jumper Wires

---

## 🔌 Circuit Connection (Wiring)

| Component | Arduino Pin |
| :--- | :--- |
| **PIR Sensor OUT** | Pin 2 |
| **Buzzer (+)** | Pin 8 |
| **House LED (+)** | Pin 13 |
| **All GND Pins** | GND |

---

## 💻 Code

```cpp
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
```

---

## 📸 Video Demonstration
*(Optional: You can link your YouTube Shorts video here to get more views!)*

[Watch the project in action on YouTube Shorts! 🍿](YOUR_YOUTUBE_SHORTS_LINK_HERE)

---

## 📝 License
This project is open-source and available under the [MIT License](LICENSE).
