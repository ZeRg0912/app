#define clk0 digitalWrite(6,LOW)
#define clk1 digitalWrite(6,HIGH)
#define dat0 digitalWrite(5,LOW)
#define dat1 digitalWrite(5,HIGH)
#define le0 digitalWrite(4,LOW)
#define le1 digitalWrite(4,HIGH)
#define ce0 digitalWrite(7,LOW)
#define ce1 digitalWrite(7,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
#define _0 false
#define _1 true

unsigned int NB_CNTR=0x0103, R_CNTR = 0x0014;         // B=109 A=14 (850)   B=8B A=02 (445)// B=103 A=0C (830)
byte  NA_CNTR=0x0C, CURS1=0x00, CURS2=0x00, MUX = 0x03, CMOS=0x03, PRESC = 0x02; 
//bit PWDN1 = 0,PWDN2 = 0, CNT_RST = 0, PDpol = 1, flag = 0;
boolean PWDN1 = _0;
boolean PWDN2 = _0;
boolean CNT_RST = _0;
boolean PDpol = _1;
boolean flag = _1;
/////////////////////////////////////////

unsigned char value, bit_ctr;


/////////////////////////////
void INTREG (void){
byte bit_ctr;
unsigned int value=0;
//======== INT register==========
   ////////PRESC/////////
   value = PRESC;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;   
   } 
   //////PWDN2////////
   if (PWDN2==1){
   dat1; 
   clk1;   
   clk0; 
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }  
   //////CURS2//////// 
   value = CURS2;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   } 
    //////CURS1//////// 
   value = CURS1;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;   
   }  
    //////Time contr//////// 
   value = 0x01;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   } 
   //////3 zero bit////////  
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;  
   } 
   //////PDpol////////
   if (PDpol==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }  
   //////MUX//////// 
   value = MUX;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   } 
   //////PWD1////////    
   if (PWDN1==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }  
   //////CNT_RST////////    
   if (CNT_RST==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   } 
   //////address 2 bit////////    
   dat1;
   clk1;   
   clk0;
   ///////  
   dat1;
   clk1;   
   clk0;
   ///////
   dat0;   
}
////////////////////////////////////////////////
void FUNREG (void){
byte bit_ctr;
unsigned int value=0;
//======== FUN register==========
   ////////PRESC/////////
   value = PRESC;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   } 
   //////PWDN2////////
   if (PWDN2==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }  
   //////CURS2//////// 
   value = CURS2;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;
   } 
    //////CURS1//////// 
   value = CURS1;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   }  
    //////Time contr//////// 
   value = 0x01;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;   
   } 
   //////3 zero bit////////  
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;  
   } 
   //////PDpol////////
   if (PDpol==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }
   //////MUX//////// 
   value = MUX;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;   
   clk0;  
   } 
   //////PWD1////////    
   if (PWDN1==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   }  
   //////CNT_RST////////    
   if (CNT_RST==1){
   dat1; 
   clk1;   
   clk0;
   } 
   else {
   dat0; 
   clk1;   
   clk0;
   } 
   //////address 2 bit////////    
   dat1;
   clk1;   
   clk0; 
   ///////  
   dat0;
   clk1;   
   clk0; 
   ///////
   dat0;    
}
////////////////////////////////////////////////
void RREG (void){
byte bit_ctr;
unsigned int value=0;
//======== R register==========
    //////8 zero bit////////  
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   } 

   //////R_CNTR 15bit////////  
   value = R_CNTR;
   for(bit_ctr=0;bit_ctr<15;bit_ctr++)   
   {  
        if(value & 0x4000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   }   
   //////address 2 bit////////    
   dat0;
   clk1;   
   clk0;
   ///////  
   dat0;
   clk1;   
   clk0;
   ///////
   dat0;   
}
////////////////////////////////////////////////
void NREG (void){
byte bit_ctr;
unsigned int value=0;
//======== N register==========
    //////3 zero bit////////  
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;  
   } 

   //////NB_CNTR 13 bit//////// 
   value = NB_CNTR;
   for(bit_ctr=0;bit_ctr<13;bit_ctr++)   
   {  
        if(value & 0x1000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   } 
   //////NA_CNTR 6 bit////////  
   value = NA_CNTR;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;
   }           
 
   //////address 2 bit////////    
   dat0;
   clk1;   
   clk0;
   ///////  
   dat1;
   clk1;   
   clk0;
   ///////
   dat0;   
} 
////////////////////////////////////////////////
///////////////////////////////////////////////

void SINTprog(void) {
le0;
INTREG();
le1;
delayMicroseconds(10);
le0;
FUNREG();
le1;
delayMicroseconds(10);
le0;
RREG();
le1;
delayMicroseconds(10);
le0;
NREG();
le1;
delayMicroseconds(10);
}  


///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);

ce1;
//OUTPOW = 0x03;
// Установка частоты
// для установки частоты необходимо оставить рабочими только две нужные строчки
//========200=========
//INT=0xC80;          
//DIVSEL = 0x04;
//========400=========
//INT=0xC80;          
//DIVSEL = 0x03;
//========430=========
//INT=0xD70;          
//DIVSEL = 0x03;
//========240=========
//INT=0xF00;          
//DIVSEL = 0x04;
//========229.3=======
//INT=0xE54;          
//DIVSEL = 0x04;
//========800=========
//INT=0xC80;          
//DIVSEL = 0x02;
//========1600=========
//INT=0xC80;          
//DIVSEL = 0x01;
//========1500=========
//INT=0xBB8;          
//DIVSEL = 0x01;
//========2380=========
//INT=0x94C;          
//DIVSEL = 0x00;
//========2500=========
//INT=0x9C4;          
//DIVSEL = 0x00;
SINTprog();

attachInterrupt(0, RESINT, RISING);
}

void loop() {
  led1;  
  delay(1000);              
  led0;    
  delay(1000); 
  led1;  
  delay(1000);              
  led0;    
  delay(1000); 
//cli();
//sei();
   if (flag == _0){
   } 
   else { 
   ce0;
   delay(200);
   ce1;
   delay(500); 
   SINTprog();
   flag = _0; 
   }   
}

void RESINT() {
flag = _1;             
}
