// Pin Definitions
const int gasSensorPin = A0; // Analog pin for gas sensor
const int relayPin = 8;      // Digital pin for relay control

// Threshold for gas detection (adjust according to your sensor)
const int gasThreshold = 400; // Adjust based on calibration

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Turn off relay initially
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasSensorPin);
  
  // Print gas value for debugging
  Serial.print("Gas Value: ");
  Serial.println(gasValue);
  
  // Check if gas value is above threshold
  if (gasValue > gasThreshold) {
    // Activate the relay to ring the doorbell
    digitalWrite(relayPin, LOW);
    delay(500); // Adjust delay for how long the doorbell rings
    digitalWrite(relayPin, HIGH);
    delay(8000); // Turn off relay
  }
  
  // Add a delay before the next loop iteration
  delay(400); // Adjust as needed
}
