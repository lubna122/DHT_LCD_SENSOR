#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DHT dht(8, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print(h);
  Serial.print("Humidity: " + String(h) + " %");

  lcd.setCursor(0, 1);
  lcd.print(t);
  Serial.print("Temperature: " + String(t) + " *C");

  delay(1000);


}
