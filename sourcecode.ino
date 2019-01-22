#include <LiquidCrystal.h>
 
#define trigger 18
#define echo 19
int buz=10;
 
LiquidCrystal lcd(12,11,5,4,3,2);
 
float time=0,distance=0;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(buz,OUTPUT);
 digitalWrite(buz,LOW);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 lcd.print("Ultra Sonic");
 lcd.setCursor(0,2);
 lcd.print("Distance Meter");
 delay(2000);
 lcd.clear();
 lcd.print("     EUREKA");
 lcd.setCursor(0,2);
 lcd.print("  AMAN & ROHIT");
 delay(2000);
}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 lcd.clear();
/* lcd.print("Distance:");
 lcd.print(distance);
 lcd.print("cm");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print("m");*/
 if(distance < 10)
 {
    digitalWrite(buz,HIGH);
    lcd.print("     ALERT");
    lcd.setCursor(0,1);
    lcd.print("Distance:");
    lcd.print(distance);
    lcd.print("cm");
    delay(3000);
 }
 else
 {
    digitalWrite(buz,LOW);
    lcd.print("  SAFE ZONE");
    lcd.setCursor(0,1);
    lcd.print("Distance:");
    lcd.print(distance);
    lcd.print("cm");
 }
 delay(1000);
}
 


