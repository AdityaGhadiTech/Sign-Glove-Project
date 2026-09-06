#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int flexPins[5] = {A1, A2, A3, A4, A5};

// Your sensors:
// Straight ≈ 256
// Bent ≈ 99
// Therefore threshold = 180
const int thresholds[5] = {180, 180, 180, 180, 180};

int fingerState[5];

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.clear();
  lcd.print("Sign Glove Ready");
  lcd.setCursor(0, 1);
  lcd.print("Bend a finger");

  for (int i = 0; i < 5; i++) {
    pinMode(flexPins[i], INPUT);
  }

  delay(1000);
}

void loop() {

  // Read all 5 flex sensors
  for (int i = 0; i < 5; i++) {

    int value = analogRead(flexPins[i]);

    // IMPORTANT:
    // Your value DECREASES when the sensor bends
    if (value < thresholds[i]) {
      fingerState[i] = 1;
    } 
    else {
      fingerState[i] = 0;
    }
  }

  // Serial Monitor
  Serial.print("VALUES: ");

  for (int i = 0; i < 5; i++) {
    Serial.print(analogRead(flexPins[i]));
    Serial.print(" ");
  }

  Serial.print(" STATES: ");

  for (int i = 0; i < 5; i++) {
    Serial.print(fingerState[i]);
    Serial.print(" ");
  }

  Serial.println();


  // =========================
  // THUMB
  // =========================

  if (fingerState[0] == 1 &&
      fingerState[1] == 0 &&
      fingerState[2] == 0 &&
      fingerState[3] == 0 &&
      fingerState[4] == 0) {

    lcd.clear();
    lcd.print("STATUS MESSAGE:");
    lcd.setCursor(0, 1);
    lcd.print("I NEED WATER");
  }


  // =========================
  // INDEX
  // =========================

  else if (fingerState[0] == 0 &&
           fingerState[1] == 1 &&
           fingerState[2] == 0 &&
           fingerState[3] == 0 &&
           fingerState[4] == 0) {

    lcd.clear();
    lcd.print("URGENT MESSAGE:");
    lcd.setCursor(0, 1);
    lcd.print("PLEASE HELP ME");
  }


  // =========================
  // MIDDLE
  // =========================

  else if (fingerState[0] == 0 &&
           fingerState[1] == 0 &&
           fingerState[2] == 1 &&
           fingerState[3] == 0 &&
           fingerState[4] == 0) {

    lcd.clear();
    lcd.print("STATUS MESSAGE:");
    lcd.setCursor(0, 1);
    lcd.print("I AM HUNGRY");
  }


  // =========================
  // RING
  // =========================

  else if (fingerState[0] == 0 &&
           fingerState[1] == 0 &&
           fingerState[2] == 0 &&
           fingerState[3] == 1 &&
           fingerState[4] == 0) {

    lcd.clear();
    lcd.print("STATUS MESSAGE:");
    lcd.setCursor(0, 1);
    lcd.print("NEED RESTROOM");
  }


  // =========================
  // PINKY
  // =========================

  else if (fingerState[0] == 0 &&
           fingerState[1] == 0 &&
           fingerState[2] == 0 &&
           fingerState[3] == 0 &&
           fingerState[4] == 1) {

    lcd.clear();
    lcd.print("RESPONSE:");
    lcd.setCursor(0, 1);
    lcd.print("THANK YOU!");
  }


  delay(200);
}
