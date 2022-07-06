#define RS0 digitalWrite(10,LOW)
#define RS1 digitalWrite(10,HIGH)
#define E0 digitalWrite(9,LOW)
#define E1 digitalWrite(9,HIGH)
#define CS0 digitalWrite(12,LOW)
#define CS1 digitalWrite(12,HIGH)
#define RW0 digitalWrite(11,LOW)
#define RW1 digitalWrite(11,HIGH)
#define LCDATA PORTD 
#define _0 false;
#define _1 true;
/////////////////////////////////////////
char text_prog_1[16]={'S','-', ' ',' ',' ', ' ',' ',' ','E','-',' ',' ',' ',' ',' ',' '};
char text_prog_2[16]={'F' ,'s', '-',' ',' ',' ','T','-',' ',' ',' ','P','-',' ',' ',' '};
////////////////////////////////////////////////
//>>>LCD functions>>>//
void LcdWriteCom(char num_lcd,char _data){
  CS0;
  delayMicroseconds(10);
  RS0;
  LCDATA = _data;
  delayMicroseconds(100);
  E1;
  delayMicroseconds(100);
  E0;
  delayMicroseconds(200);
  CS1;
}
void LcdWriteData(char num_lcd,char _data){
  CS0;
  delayMicroseconds(10);
  RS1;
  LCDATA = _data;
  delayMicroseconds(100);
  E1;
  delayMicroseconds(100);
  E0;
  delayMicroseconds(200);
  RS0;
  delayMicroseconds(10);
  CS1;
}
void Print(char num_lcd, char lcd_line,char ch16[16]){
   char i;
 //  LcdWriteCom(num_lcd,0b00000010);delay_ms(2);
   if (lcd_line==1) {
    // 1st line
   LcdWriteCom(num_lcd,0b10000000);delay (2);
   for(i=0;i<8;i++) LcdWriteData(num_lcd,ch16[i]);
   LcdWriteCom(num_lcd,0b10001000);delay (2);
   for(i=8;i<16;i++) LcdWriteData(num_lcd,ch16[i]);}
    // 2nd line
   else  {
   LcdWriteCom(num_lcd,0b11000000);delay (2);
   for(i=0;i<8;i++) LcdWriteData(num_lcd,ch16[i]);
   LcdWriteCom(num_lcd,0b11001000);delay (2);
   for(i=8;i<16;i++) LcdWriteData(num_lcd,ch16[i]); }

}
void LcdWritePattern(char num_lcd,unsigned char addr,char pattern[8]){
   char i;
   LcdWriteCom(num_lcd, 0b01000000+addr);
   for(i=0;i<8;i++) LcdWriteData(num_lcd,pattern[i]);
}
void InitLCDs(void){
   RS0;E0;CS1; //Initial state...
   delay (200);
   LcdWriteCom(0,0b00111000);
   LcdWriteCom(0,0b00001100);
   LcdWriteCom(0,0b00000001);
   delay (100);
   LcdWriteCom(0,0b00000110);
   LcdWriteCom(0,0b00000010);//return home
   delay (100);
} 

void RefreshLCD(void){ 
   Print(1,1, text_prog_1); // enter on LCD
   Print(1,2, text_prog_2);
}

///////////////////////////////////////////////

///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  delay (1000);  
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
DDRD = B11111111;
  CS1;
  RW0;

InitLCDs();

//LcdWriteCom(0,0b00111110);  //0x3E self test
}

void loop() {
//delayMicroseconds(100);
//RefreshLCD();
//LCDATA = B11111111;
//delay (1000);
//LCDATA = B00000000;
//InitLCDs();
delay (10000); 
LcdWriteCom(0,0b00111110);
 
}
