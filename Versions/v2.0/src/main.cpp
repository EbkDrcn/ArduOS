// 2.0 Yenilikler : Karaşimşek menüsü eklendi

/* ArduOS v2.0 beta by Ebubekir Dirican
 * 
 * ArduOS Arduino üzerinde çalışabilir olarak tasarlanmış bir işletim sistemidir.
 * Şuanlık betadadır 
 * Şuanlık yapabildikleri : 
 * Seçtiğiniz bir pindeki LED'e "Blink" yaptırma 
 * 
 * Gerekenler : 
 * 1 tane 16x2 LCD 
 * 3 tane push buton 
 * 2 tane LED
 */
 
const int but1 = 6, but2 = 7, but3 = 8; //Butonlar için pin 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  //LCD nin pinleri
int pin = 13; // LED pini için değişken
int pin2 = 14; // LED pini için değişken
int secenekler = 0; // Seçenek geçişi için değişken

#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("ArduOS v2.0");
  lcd.setCursor(0,1);
  lcd.print("Ebubekir Dirican");
  delay(5000);
  lcd.clear();
  lcd.home();
  lcd.print("Youtube :");
  lcd.setCursor(0, 1);
  lcd.print("Ebubekir Dirican");
  delay(5000);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
}

void loop() 
{
  if (digitalRead(but1) == 1)
  {
    secenekler--;
  }
  else if (digitalRead(but3) == 1)
  {
    secenekler++;
  }
  if (secenekler == 2)
  {
    secenekler = 0;
  }
  else if (secenekler == -1)
  {
    secenekler = 1;
  }
  
  if (secenekler == 0)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Blink Menusu");
    lcd.setCursor(0, 1);
    lcd.print("Orta tus");
  }
  else if (secenekler == 1)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Karasimsek Menusu");
    lcd.setCursor(0, 1);
    lcd.print("Orta tus");
  }
  if (digitalRead(but2) == 1 && secenekler == 0)
  {
    
    delay(100);
    lcd.clear();
    while (digitalRead(but2) == 0)
    {
          lcd.setCursor(0, 0);
    lcd.print("Blink pini");
    lcd.setCursor(0, 1);
    if (digitalRead(but1) == 1)
    {
      delay(100);
      pin--;
      lcd.print(pin);
    }
    else if (digitalRead(but3) == 1)
    {
      delay(100);
      pin++;
      lcd.print(pin);
    }
    }
    
    if (digitalRead(but2) == 1)
    {
     delay(500);
     if (digitalRead(but2) == 1)
     {
       while (1)
       {
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Pin blink");
         lcd.setCursor(0, 1);
         lcd.print("ediliyor");
         pinMode(pin, OUTPUT);
         digitalWrite(pin, HIGH);
         delay(1000);
         digitalWrite(pin, LOW);
         delay(1000);
       }
     }
     else
     {
       for (int i = 0; i < 10; i++)
       {
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Pin 10 kere");
         lcd.setCursor(0, 1);
         lcd.print("blink ediliyor");
         pinMode(pin , OUTPUT);
         digitalWrite(pin, HIGH);
         delay(1000);
         digitalWrite(pin, LOW);
         delay(1000);
       }   
     } 
    }  
  }
  if (digitalRead(but2) == 1 && secenekler == 1)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Karasimsek pini");
    lcd.setCursor(0,1);
    lcd.print("seciniz...");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pin 1 :");
    lcd.setCursor(0, 1);
    Serial.print("1.pini sec");
    delay(1000);
    while (digitalRead(but2) == 0)
    {
        if (digitalRead(but1) == 1)
      {
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Pin 1 :");
       lcd.setCursor(0, 1);
       delay(100);
       pin--;
       lcd.print(pin);
     }
     else if (digitalRead(but3) == 1)
     {
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Pin 1 :");
       lcd.setCursor(0, 1);
       delay(100);
       pin++; 
       lcd.print(pin);
     }
    }
    if (digitalRead(but2) == 1)
    {
      delay(100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1.pin : ");
      lcd.print(pin);
      delay(1000);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pin 2 :");
    lcd.setCursor(0, 1);
    Serial.print("2.pini sec");
    delay(1000);
    while (digitalRead(but2) == 0)
    {
        if (digitalRead(but1) == 1)
      {
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Pin 2 :");
       lcd.setCursor(0, 1);
       delay(100);
       pin2--;
       lcd.print(pin2);
     }
     else if (digitalRead(but3) == 1)
     {
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Pin 2 :");
       lcd.setCursor(0, 1);
       delay(100);
       pin2++; 
       lcd.print(pin2);
     }
    }
    if (digitalRead(but2) == 1)
    {
      delay(100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("2.pin : ");
      lcd.print(pin2);
      delay(1000);
    }
    pinMode(pin, OUTPUT);
    pinMode(pin2, OUTPUT);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Secilenler 10 ");
    lcd.setCursor(0, 1);
    lcd.print("KS yapiliyor");
    for(int j=7;j>-1; j--)
    {
      digitalWrite(pin, HIGH);     
      delay(50);
      digitalWrite(pin, LOW);
      digitalWrite(pin2, HIGH);
      delay(50);
      digitalWrite(pin2, LOW);
    }
  }
}