# ESP32-S2 Servo Control with NeoPixel

This project demonstrates the use of an ESP32-S2 microcontroller to control a micro-servo motor SG90 9G with a tactile button. The servo motor toggles between an open and closed position based on button presses, while an onboard NeoPixel provides visual feedback. The NeoPixel lights up green when the servo is open and red when it is closed.

## Features
- **Servo Control**: Moves between two positions (open and closed) based on button presses.
- **NeoPixel Indicator**: Changes color to indicate the current state of the servo.
- **Debouncing Logic**: Implements debouncing to ensure reliable button presses.  
*(To see debugging, open the Serial Monitor in Arduino IDE)*

## Components Used
- ESP32-S2
- Servo Motor
- NeoPixel LED

## Wiring
- Servo connected to GPIO 3 for Signal and USB Power pin for 5V
- NeoPixel connected to GPIO 33 (Onboard NeoPixel for Feather ESP32-S2 by Stemma QT; change to a different pin if an external LED is used)
- Tactile button connected to GPIO A4 & Ground

![459585501_527889510000985_4110360833687337223_n](https://github.com/user-attachments/assets/1da8cfed-265d-41fa-b963-f0e0f06f5029)
![461037920_2334817593539122_1505787611665946679_n](https://github.com/user-attachments/assets/f0a79a98-de86-4ebb-8612-1ba45485ffa5)
![460107861_8315029851896632_6758768629758994892_n](https://github.com/user-attachments/assets/c25113b9-0feb-4953-aa2d-6bd45cf4761e)
![460562070_898868688806466_6028677507470355139_n](https://github.com/user-attachments/assets/2efe1f8e-62f5-4f77-8216-b4c18d5d79cb)


// Function to set NeoPixel color
void setNeoPixelColor(uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(0, strip.Color(r, g, b));
  strip.show();
}
