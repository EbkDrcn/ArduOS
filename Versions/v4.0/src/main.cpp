// HC-SR04 ile mesafe ölçümü eklendi. Şuanlık sadece sabit pinlerde yapılıyor. 

/* ArduOS v4.0 by Ebubekir Dirican
 * Youtube : Ebubekir Dirican
 * 
 * ArduOS Arduino üzerinde çalışabilir olarak tasarlanmış bir işletim sistemidir. 
 * Şuanlık yapabildikleri : 
 * İngilizce ve Türkçe arasında geçiş yapabilir
 * Seçtiğiniz bir pindeki LED'e "Blink" yaptırma 
 * Seçtiğiniz 2 lede karaşimşek yapma
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
int dil = 0; //Dil için değişken
int trigger = 17; //HC-SR04 Trig
int echo = 16; //HC-SR04 Echo 
int sure; //Mesafe ölçümü için süre
int mesafe; //Mesafe ölçümü için mesafe

#include <LiquidCrystal.h>
#include <Arduino.h>
#include <EEPROM.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("ArduOS v3.0 by");
  lcd.setCursor(0,1);
  lcd.print("Ebubekir Dirican");
  if (digitalRead(but3) == 1)
  {
    delay(100);
      while(digitalRead(but2) == 0)
      {
         if (digitalRead(but1) == 1)
         {
            dil--;
         }
         else if(digitalRead(but3) == 1)
         {
             dil++;
         }
         if (dil == 2)
         {
             dil = 0;
         }
         else if(dil == -1)
         {
             dil = 1;
         }
         if (dil == 0)
         {
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Dil:");
             lcd.setCursor(0,1);
             lcd.print("Turkce");
         }
         else if(dil == 1)
         {
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Language:");
             lcd.setCursor(0,1);
             lcd.print("English");
         }
   }
   if (dil == 0)
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Dil:");
     lcd.setCursor(0,1);
     lcd.print("Turkce");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("BIOS'tan");
     lcd.setCursor(0,1);
     lcd.print("Cikiliyor");
     delay(500);
     lcd.clear();
   }
   else if(dil == 1)
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Language:");
     lcd.setCursor(0,1);
     lcd.print("English");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Exiting");
     lcd.setCursor(0,1);
     lcd.print("BIOS");
     delay(500);
     lcd.clear();
   }
  }
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
  while (dil == 1)
  {
      if (digitalRead(but1) == 1)
    {
      secenekler--;
     }
     else if (digitalRead(but3) == 1)
     {
       secenekler++;
     }
     if (secenekler == 3)
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
        lcd.print("Blink Menu");
        lcd.setCursor(0, 1);
        lcd.print("Middle Button");
     }
    else if (secenekler == 1)
    {
        delay(100);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Blacklight Menu");
        lcd.setCursor(0, 1);
        lcd.print("Middle Button");
    }
    else if (secenekler == 2)
    {
      delay(100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("HC-SR04");
      lcd.setCursor(0, 1);
      lcd.print("Menu");
    }
    
    if (digitalRead(but2) == 1 && secenekler == 0)
    {
    delay(100);
    lcd.clear();
    while (digitalRead(but2) == 0)
        {
        lcd.setCursor(0, 0);
        lcd.print("Blink pin");
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
         lcd.print("Begining to");
         lcd.setCursor(0, 1);
         lcd.print("blink pin");
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
         lcd.print("Pin is blinking");
         lcd.setCursor(0, 1);
         lcd.print("for 10 times");
         pinMode(pin , OUTPUT);
         digitalWrite(pin, HIGH);
         delay(1000);
         digitalWrite(pin, LOW);
         delay(1000);
       }   
     } 
    }  
  }
  // Karaşimşek Başlıyor :D 
  if (digitalRead(but2) == 1 && secenekler == 1)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Select");
    lcd.setCursor(0,1);
    lcd.print("blacklight pin");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pin 1 :");
    lcd.setCursor(0, 1);
    Serial.print("Select 1st pin");
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
    Serial.print("Select 2nd one");
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
    lcd.print("BL for 10");
    lcd.setCursor(0, 1);
    lcd.print("times");
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
   if ((digitalRead(but2) == 1 && secenekler == 2))
   {
     delay(100);
     lcd.clear();
     lcd.setCursor(0, 1);
     lcd.print("Pins");
     delay(1000);
     lcd.clear();
     lcd.print("Trig:");
     lcd.setCursor(0, 1);
     lcd.print("A2");
     delay(1000);
     lcd.clear();
     lcd.print("Echo:");
     lcd.setCursor("A3");
     pinMode(trigger, OUTPUT);
     pinMode(echo, INPUT);
     digitalWrite(trigger_pin, HIGH);
     delayMicroseconds(1000);
     digitalWrite(trigger_pin, LOW);
     sure = pulseIn(echo_pin, HIGH);
     mesafe = (sure/2) / 29.1;
     lcd.clear();
     lcd.print("Dist = ");
     lcd.setCursor(0, 1);
     lcd.print(mesafe);
     lcd.print(" cm");
     }
     
   }
   
  } 
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
  // Karaşimşek Başlıyor :D 
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
  if ((digitalRead(but2) == 1 && secenekler == 2))
  {
  delay(100);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Pinler");
  delay(1000);
  lcd.clear();
  lcd.print("Trig:");
  lcd.setCursor(0, 1);
  lcd.print("A2");
  delay(1000);
  lcd.clear();
  lcd.print("Echo:");
  lcd.setCursor("A3");
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);
  sure = pulseIn(echo_pin, HIGH);
  mesafe = (sure/2) / 29.1;
  lcd.clear();
  lcd.print("Mesafe = ");
  lcd.setCursor(0, 1);
  lcd.print(mesafe);
  lcd.print(" cm");
  }
}