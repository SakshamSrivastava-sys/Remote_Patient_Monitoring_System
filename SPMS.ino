#include <Wire.h>
#include <PulseOximeter.h>
#include <LiquidCrystal_I2C.h>

#define REPORTING_PERIOD_MS 1000
#define BUZZER_PIN 8
#define LM35_PIN A0

PulseOximeter pox;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change to 0x3F if needed

uint32_t tsLastReport = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Initializing...");

  if (!pox.begin()) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MAX30100 ERROR");
    while (1);
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

  lcd.clear();
  lcd.print("System Ready");
  delay(1500);
}

void loop() {
  pox.update();

  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

    float hr = pox.getHeartRate();
    float spo2 = pox.getSpO2();

    int raw = analogRead(LM35_PIN);
    float mv = raw * (5000.0 / 1023.0);
    float tempC = mv / 10.0;

    Serial.print("HR: "); Serial.print(hr);
    Serial.print("  SpO2: "); Serial.print(spo2);
    Serial.print("  Temp: "); Serial.println(tempC);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HR:");
    if (hr > 0) lcd.print((int)hr);
    else lcd.print("--");

    lcd.print(" SpO2:");
    if (spo2 > 0) lcd.print((int)spo2);
    else lcd.print("--");

    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(tempC,1);
    lcd.print("C");

    bool alarm = false;
    if (hr > 120 || hr < 50) alarm = true;
    if (spo2 < 92 && spo2 > 0) alarm = true;
    if (tempC > 38.0) alarm = true;

    if (alarm) digitalWrite(BUZZER_PIN, HIGH);
    else digitalWrite(BUZZER_PIN, LOW);

    tsLastReport = millis();
  }
}