#define OPT0 digitalWrite(8,LOW)
#define OPT1 digitalWrite(8,HIGH)
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
/////////////////////////////////////////
int count=0;
////////////////////////////////////////////////
/*void OPT(void){ 
   delay (3000);
   OPT0;
   count++;
   delay (3000);
   OPT1;
   count++;
}*/
///////////////////////////////////////////////

///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  delay (1000);
  count=0;
  OPT0;  
  pinMode(8, OUTPUT);
}

void loop() {
lcd.setCursor(0, 0);
lcd.print("Switches");
   delay (60000);
   OPT0;
   count++;
lcd.setCursor(0, 1);
lcd.print(count);
   delay (60000);
   OPT1;
   count++;
lcd.setCursor(0, 1);
lcd.print(count);
}
