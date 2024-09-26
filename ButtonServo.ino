//Jordan Pesavento

#include <ESP32Servo.h>
#include <Adafruit_NeoPixel.h>

// Pin definitions
#define BUTTON_PIN A4  // GPIO A4 for the button
#define SERVO_PIN 3    // GPIO 3 for the servo
#define NEOPIXEL_PIN 33 // GPIO for the onboard NeoPixel (usually pin 33 for built-in)
#define NUM_PIXELS 1   // Number of NeoPixels

// Servo and NeoPixel objects
Servo myServo;
Adafruit_NeoPixel strip(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Servo states
bool isServoOpen = false;
bool buttonState = false;
bool lastButtonState = HIGH;  // To track previous button state for debouncing

int servoPosOpen = 180;  // Open position of the servo
int servoPosClosed = 0;  // Closed position of the servo

void setup() {
  Serial.begin(115200);              // Initialize serial for debugging
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with pull-up
  myServo.attach(SERVO_PIN);         // Attach the servo
  strip.begin();                     // Initialize the NeoPixel strip
  strip.show();                      // Initialize all pixels to 'off'

  // Start with servo closed and NeoPixel red
  myServo.write(servoPosClosed);
  setNeoPixelColor(255, 0, 0); // Red for closed
  Serial.println("Setup complete! Servo closed, NeoPixel red.");
}

void loop() {
  // Read the button state
  int reading = digitalRead(BUTTON_PIN);

  // Check if the button was pressed (transition from HIGH to LOW)
  if (reading == LOW && lastButtonState == HIGH) {
    buttonState = !buttonState;  // Toggle the button state
    Serial.println("Button pressed!");

    if (isServoOpen) {
      // Close the servo and set NeoPixel to red
      myServo.write(servoPosClosed);
      setNeoPixelColor(255, 0, 0);  // Red for closed
      Serial.println("Servo closed, NeoPixel red.");
    } else {
      // Open the servo and set NeoPixel to green
      myServo.write(servoPosOpen);
      setNeoPixelColor(0, 255, 0);  // Green for open
      Serial.println("Servo opened, NeoPixel green.");
    }

    isServoOpen = !isServoOpen;  // Toggle the servo state
    delay(200);  // Debounce delay
  }

  // Update lastButtonState for next loop iteration
  lastButtonState = reading;
}

// Function to set NeoPixel color
void setNeoPixelColor(uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(0, strip.Color(r, g, b));
  strip.show();
}

