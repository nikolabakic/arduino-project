#include <DHT.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
ThreeWire myWire(5, 6, 4);
RtcDS1302<ThreeWire> Rtc(myWire);
LiquidCrystal lcd(9, 10, 11, 12, 13, A0);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Rtc.Begin();
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  lcd.setCursor(0, 0);
  if(now.Hour() < 10) lcd.print("0");
  lcd.print(now.Hour());
  lcd.print(":");
  if(now.Minute() < 10) lcd.print("0");
  lcd.print(now.Minute());
  lcd.print(":");
  if(now.Second() < 10) lcd.print("0");
  lcd.print(now.Second());
  lcd.print(" ");
  if(now.Day() < 10) lcd.print("0");
  lcd.print(now.Day());
  lcd.print("/");
  if(now.Month() < 10) lcd.print("0");
  lcd.print(now.Month());

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(tempC, 1);
  lcd.print("C H:");
  lcd.print(humidity, 1);
  lcd.print("%");

  delay(1000);
}
