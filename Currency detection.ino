
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int red, green, blue;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Place Note...");
}

void loop() {

  red = getRed();
  green = getGreen();
  blue = getBlue();

  // 👉 Show RGB values (for debugging)
  lcd.setCursor(0,0);
  lcd.print("R:");
  lcd.print(red);
  lcd.print(" G:");
  lcd.print(green);

  lcd.setCursor(0,1);
  lcd.print("B:");
  lcd.print(blue);
  delay(1000);

  // 👉 Detect currency
  String result = detectCurrency(red, green, blue);

  // 👉 Show detected value
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Detected:");
  lcd.setCursor(0,1);
  lcd.print(result);

  delay(2000);
}

// -------- Color Reading Functions --------

int getRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  return pulseIn(sensorOut, LOW);
}

int getGreen() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}

int getBlue() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}

// -------- Currency Detection Logic --------

String detectCurrency(int r, int g, int b) {

  // ⚠️ These values are EXAMPLES → you MUST calibrate

  if (r < 80 && g < 90 && b > 100) {
    return "Rs 10";
  }
  else if (r > 100 && g > 120 && b < 80) {
    return "Rs 20";
  }
  else if (r > 90 && g < 80 && b < 70) {
    return "Rs 50";
  }
  else if (r > 120 && g > 100 && b > 100) {
    return "Rs 100";
  }
  else if (r < 70 && g > 90 && b < 60) {
    return "Rs 500";
  }
  else {
    return "Unknown";
  }
}
