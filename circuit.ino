#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
#define MQ2_DO_PIN 3
#define IR_PIN 2
#define BUZZER_PIN 4

// 15 Seconds
#define ACK_DURATION 15000UL

bool alertActive = false;
bool ackActive = false;
bool irLocked = false;

unsigned long ackStartTime = 0;

void setup() {
  pinMode(MQ2_DO_PIN, INPUT);
  pinMode(IR_PIN, INPUT_PULLUP);   // stabilize IR
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Gas Detector");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasDetected = digitalRead(MQ2_DO_PIN); // LOW = gas
  int irState = digitalRead(IR_PIN);

  // 🔥 GAS DETECTION (only if not acknowledged)
  if (!ackActive && gasDetected == LOW) {
    alertActive = true;
  }

  // ✋ IR ACKNOWLEDGE
  if (alertActive && !irLocked && irState == LOW) {
    irLocked = true;
    alertActive = false;
    ackActive = true;
    ackStartTime = millis();

    noTone(BUZZER_PIN);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alert");
    lcd.setCursor(0, 1);
    lcd.print("Acknowledged");
  }

  // TIMER
  if (ackActive) {
    if (millis() - ackStartTime >= ACK_DURATION) {
      ackActive = false;
      irLocked = false;
      lcd.clear();
    }
    return;
  }

  // ALERT
  if (alertActive) {
    tone(BUZZER_PIN, 1000);

    lcd.setCursor(0, 0);
    lcd.print("!!! GAS ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("Gas Detected    ");
  }
  // SAFE
  else {
    noTone(BUZZER_PIN);

    lcd.setCursor(0, 0);
    lcd.print("Status: SAFE    ");
    lcd.setCursor(0, 1);
    lcd.print("No Gas Detected ");
  }

  delay(200);
}
