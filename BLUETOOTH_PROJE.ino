#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <DHT.h>

#define sicaklikPin   2
#define DHTType       DHT11

#define yesilLedPin   3
#define kirmiziLedPin 4
#define alarm         5

DHT sicaklikSensor(sicaklikPin, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial port(12, 13);

float sicaklikDeger;
float geciciSicaklik = 0;
char gelenMesaj;
bool alarmDurum = true;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  port.begin(9600);
  sicaklikSensor.begin();

  pinMode(yesilLedPin, OUTPUT);
  pinMode(kirmiziLedPin, OUTPUT);
  pinMode(alarm, OUTPUT);

  lcd.setCursor(2, 0);
  lcd.print("DHT11 & BLT");
  lcd.setCursor(4, 1);
  lcd.print("PROJESI");
  port.print("DHT11 & BLT PROJESI \n\r");

  delay(2000);
  lcd.clear();

}

void loop() {
  // sıcaklık değerimi okudum
  sicaklikDeger = sicaklikSensor.readTemperature();

  // sıcaklık değerimi seri, lcd ve blt ekranında yazdırdım
  Serial.println("Sıcaklık değeri : " + String(sicaklikDeger));
  lcd.setCursor(0, 0);
  lcd.print("Sicaklik : " + String(sicaklikDeger));
  if (geciciSicaklik != sicaklikDeger) {
    port.println("  SICAKLIK : " + String(sicaklikDeger));
    geciciSicaklik = sicaklikDeger;
  }

  // blt'den gelen veriye göre alarmı açtım kapadım. default olarak açık başlattım
  if (port.available()) {
    gelenMesaj = port.read();
    if (gelenMesaj == 'R') {
      alarmDurum = false;
      lcd.setCursor(0, 1);
      lcd.print("ALARM KAPATILDI");
      port.println(" ALARM KAPATILDI");
    } else if (gelenMesaj == 'S') {
      alarmDurum = true;
      lcd.setCursor(0, 1);
      lcd.print("ALARM ACILDI       ");
      port.println(" ALARM ACILDI");
    }
  }

  delay(200);

  // alarm durumuna göre sıcaklık kontrolü yapılmıştır.
  if (alarmDurum == true) { // alarm açık
    lcd.setCursor(0, 1);
    lcd.print("Alarm acik         ");
    if (sicaklikDeger >= 25) { // tehlike var
      digitalWrite(kirmiziLedPin, HIGH);
      digitalWrite(alarm, HIGH);
      digitalWrite(yesilLedPin, LOW);
      lcd.setCursor(0, 1);
      lcd.print("  !!!ALARM!!! ");
      port.println("  !!!ALARM!!!  ");
    } else { // tehlike yok
      digitalWrite(kirmiziLedPin, LOW);
      digitalWrite(alarm, LOW);
      digitalWrite(yesilLedPin, HIGH);
    }
  } else if (alarmDurum == false) { // alarm kapalı
    lcd.setCursor(0, 1);
    lcd.print("Alarm kapali           ");
    digitalWrite(kirmiziLedPin, LOW);
    digitalWrite(alarm, LOW);
    digitalWrite(yesilLedPin, LOW);
  }
}
