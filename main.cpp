/*
=====================================================
LESSON 2 - Read Code Like a Pro
=====================================================
PURPOSE:
Demonstrates comments, code organization, OLED help
screens, and button input handling.

BUTTONS:
A (Left)  → Show "About" screen
B (Center) → Show "Controls" screen
C (Right) → Show "Status" screen

HARDWARE:
- Zumo 32U4 with OLED display
- Buttons A, B, C
- Yellow LED (visual feedback)

AUTHOR: [Your Name]
DATE: [Today's Date]
=====================================================
*/

#include <Zumo32U4.h>

// ===== HARDWARE OBJECTS =====
Zumo32U4ButtonA buttonA;   // Left button
Zumo32U4ButtonB buttonB;   // Center button
Zumo32U4ButtonC buttonC;   // Right button
Zumo32U4OLED display;      // OLED screen

// ===== PROGRAM INFORMATION =====
const char* PROGRAM_NAME = "Help Demo";
const char* VERSION = "2.0";
const char* AUTHOR = "Amy ";

// ===== HELPER FUNCTIONS =====

void showAboutScreen() {
  display.clear();
  display.setLayout21x8();
  display.gotoXY(0, 0); display.print(F("=== ABOUT ==="));
  display.gotoXY(0, 2); display.print(F("Program:"));
  display.gotoXY(0, 3); display.print(PROGRAM_NAME);
  display.gotoXY(0, 5); display.print(F("Version: "));
  display.print(VERSION);
  display.gotoXY(0, 7); display.print(F("By: "));
  display.print(AUTHOR);
}

void showControlsScreen() {
  display.clear();
  display.setLayout21x8();
  display.gotoXY(0, 0); display.print(F("=== CONTROLS ==="));
  display.gotoXY(0, 2); display.print(F("A: About info"));
  display.gotoXY(0, 3); display.print(F("B: This screen"));
  display.gotoXY(0, 4); display.print(F("C: Status info"));
  display.gotoXY(0, 6); display.print(F("Press any button"));
  display.gotoXY(0, 7); display.print(F("to switch screens"));
}

void showStatusScreen() {
  display.clear();
  display.setLayout21x8();
  display.gotoXY(0, 0); display.print(F("=== STATUS ==="));
  display.gotoXY(0, 2); display.print(F("Uptime (sec):"));
  display.gotoXY(0, 3); display.print(millis() / 1000);
  display.gotoXY(0, 5); display.print(F("Sensors: N/A"));
  display.gotoXY(0, 6); display.print(F("Battery: N/A"));
  display.gotoXY(0, 7); display.print(F("(More in L4+)"));
}

void showWelcomeScreen() {
  display.clear();
  display.setLayout21x8();
  display.gotoXY(0, 0); display.print(F("LESSON 2"));
  display.gotoXY(0, 1); display.print(F("Read Code Like"));
  display.gotoXY(0, 2); display.print(F("a Pro!"));
  display.gotoXY(0, 4); display.print(F("Press A, B, or C"));
  display.gotoXY(0, 5); display.print(F("for help screens"));
  display.gotoXY(0, 7); display.print(F("Serial @ 115200"));
}

void blinkLED() {
  ledYellow(1);
  delay(100);
  ledYellow(0);
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println(F(""));
  Serial.println(F("========================="));
  Serial.println(F("LESSON 2 - Help Screens"));
  Serial.println(F("========================="));
  Serial.println(F("Press A, B, or C..."));

  showWelcomeScreen();
}

// ===== LOOP =====
void loop() {

  if (buttonA.getSingleDebouncedPress()) {
    Serial.println(F("[BTN] A pressed -> About"));
    blinkLED();
    showAboutScreen();
  }

  if (buttonB.getSingleDebouncedPress()) {
    Serial.println(F("[BTN] B pressed -> Controls"));
    blinkLED();
    showControlsScreen();
  }

  if (buttonC.getSingleDebouncedPress()) {
    Serial.println(F("[BTN] C pressed -> Status"));
    blinkLED();
    showStatusScreen();
  }

  delay(10);
}
