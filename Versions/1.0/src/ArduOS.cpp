// Yapılacaklar : Orta tuş ile break ve kodu yeniden başlatma

/* ArduOS v1.0 beta by Ebubekir Dirican
 * 
 * ArduOS Arduino üzerinde çalışabilir olarak tasarlanmış bir işletim sistemidir.
 * Şuanlık betadadır 
 * Şuanlık yapabildikleri : 
 * Seçtiğiniz bir pindeki LED'e "Blink" yaptırma 
 * 
 * Gerekenler : 
 * 1 tane 16x2 LCD 
 * 3 tane push buton 
 * 1 tane LED
 */
 
const int but1 = 6, but2 = 7, but3 = 8; //Butonlar için pin 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  //LCD nin pinleri
int pin = 13; // LED pini için değişken
int blinkpin;

#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Secilen Pin:");
  lcd.setCursor(0,1);
  lcd.print(pin);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Secilen Pin:");
  lcd.setCursor(0,1);

  if(digitalRead(but1) == 1){
    delay(100);
    pin = pin - 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Secilen Pin:");
    lcd.setCursor(0,1);
    lcd.print(pin);
    
  }
  else if(digitalRead(but3)== 1)
  {
    delay(100);
    pin = pin + 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Secilen Pin:");
    lcd.setCursor(0,1);
    lcd.print(pin);
  }
  else if (digitalRead(but2) == 1)
  {
    while(1)
    {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Secilen Pin:");
     lcd.setCursor(0,1);
     lcd.print(pin);
     Serial.print(pin);
     Serial.println(" üzerinden blink işlemi başladı. Kodu kullandığınız için teşekkür ederiz. ArduOS by Ebubekir Dirican");
     pinMode(pin, OUTPUT);
     digitalWrite(pin, 1);
     delay(1000);
     digitalWrite(pin, 0);
     delay(1000); 
     lcd.clear();
    }
  }   
}
