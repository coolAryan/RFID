#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
SoftwareSerial rfid (2,3);
String tag;
String tags[]={"18008920AC1D","430077970DAE"};
String names[]={"Aryan","Akshat"};
int id[]={406,422};
int MS1 = 10;
int MS2 = 12;
int EN = 11;
RTC_DS1307 rtc;
int sd=A4;
int sc=A5;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int i=0;
void setup()
{
  pinMode(EN, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  rfid.begin(9600);
  Serial.print("Waiting For Input");
  lcd.print("Enter Input"); 
  if (!rtc.isrunning()) 
 {
   Serial.println("RTC is NOT running!");
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 }
}
void motor()
{
  digitalWrite(EN, HIGH);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
  delay(700);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  delay(100);
}
void reverse()
{
  digitalWrite(EN, HIGH);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, HIGH);
  delay(700);
}
void clock()
{   
  int y = now.year();
  int m=  now.month();
  int d= now.day();
  char dd=daysOfTheWeek[now.dayOfTheWeek()];
  int h=now.hour();
  int min=now.minute();
  int sec=now.second();
  struct time()
  {
    
    
    }
 Serial.print(now.year(),DEC);
 Serial.print('/');
 Serial.print(now.month(),DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print("(");
 Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
 Serial.print(" )");
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 lcd.print(now.year(),DEC);
}
void loop()
{
  
  if (rfid.available())
  {
    DateTime now = rtc.now();
    tag = rfid.readString();
    for(i=0;i<sizeof(tags);i++)
    {
      if(tag==tags[i])
      {
        return i;  
        lcd.clear();
       Serial.print("Access Granted");
      lcd.print("Access Granted");
      delay(100);
      lcd.clear();
      lcd.print("Welcome to");
      lcd.setCursor(0, 1);
      lcd.print("Xananoids");
      delay(100);
      Serial.print("\n");
      clock();
      }
      else
      {return -1;
       lcd.clear();
      lcd.print("Access Denied");
      }  
    }
      lcd.clear();
      lcd.setCursor(0, 0);
      
      lcd.print(name[i]);
    Serial.print(name[i]);
     lcd.setCursor(0,1);
      Serial.print("\n");
    Serial.print(id[i]);
    lcd.print(id[i]);
     delay(10);
      motor();
      tag = 1;
  }
}
