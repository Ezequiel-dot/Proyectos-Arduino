#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 termometroIR = Adafruit_MLX90614();
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinTrigger = 11;
const int pinEcho = 12;
const int pinBomba = 9;
const int pinBuzz = 5;
const int bott = 2;
int medir = 0;

void setup() {

  // Iniciar comunicación serie
  Serial.begin(9600);

  // Iniciar termómetro infrarrojo con Arduino
  termometroIR.begin();
  // Inicializar el LCD
  lcd.init();
  // Encender la luz de fondo.
  lcd.backlight();

  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinTrigger, LOW);

  pinMode(pinBomba, OUTPUT);
  pinMode(pinBuzz, OUTPUT);
  pinMode(bott, INPUT);


}

void loop() {

  Serial.println(digitalRead(bott));
  float temperaturaObjeto = termometroIR.readObjectTempC() + 15;

  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.print(temperaturaObjeto);
  lcd.print(" C");
  delay(200);

  unsigned long t;
  float d;
  digitalWrite(pinTrigger, HIGH);
  delay(5);
  digitalWrite(pinTrigger, LOW);
  t = pulseIn(pinEcho, HIGH);
  d = t * 0.000001 * 34300.0 / 2.0;

  if (digitalRead(bott) == 1) {
    medir = 1;
    delay(100);
  }
  if (medir == 1) {
    delay(1000);
    float temperaturaObjeto1 = termometroIR.readObjectTempC() + 14;
    delay(20);
    float temperaturaObjeto2 = termometroIR.readObjectTempC() + 14;
    delay(20);
    float temperaturaObjeto3 = termometroIR.readObjectTempC() + 14;
    delay(20);
    float temperaturaObjeto4 = termometroIR.readObjectTempC() + 12;
    delay(20);
    float tempfin((temperaturaObjeto1 + temperaturaObjeto2 + temperaturaObjeto3 + temperaturaObjeto4) / 4);

    if (tempfin >= 34 && tempfin <= 37.5) {
      lcd.setCursor(0, 1);
      lcd.print("CORRECTO ");
      lcd.print(tempfin);
      digitalWrite(pinBuzz, HIGH);
      delay(1500);
      digitalWrite(pinBuzz, LOW);
    } else {
      lcd.setCursor(0, 1);
      lcd.print("INCORRECTO ");
      lcd.print(tempfin);
      digitalWrite(pinBuzz, HIGH);
      delay(500);
      digitalWrite(pinBuzz, LOW);
      delay(500);
      digitalWrite(pinBuzz, HIGH);
      delay(1500);
      digitalWrite(pinBuzz, LOW);
    }
    medir = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TEMP: ");
    lcd.print(temperaturaObjeto);
    lcd.println("ºC");
    delay(200);
  }
  Serial.print("distancia ");
  Serial.println(d);

  if (d < 8) {
    digitalWrite(pinBomba, HIGH);
    delay(1000);
    digitalWrite(pinBomba, LOW);
    delay(3000);
  }
}
