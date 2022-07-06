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

//unsigned int NB_CNTR=0x0109, R_CNTR = 0x00C8;         // B=109 A=14 (850)   B=8B A=02 (445)
//byte  NA_CNTR=0x14, CURS1=0x00, CURS2=0x00, MUX = 0x02, CMOS=0x03, PRESC = 0x02; 
unsigned int IF_R_CNTR=0x0073, IF_B_CNTR=0x007D, RF_R_CNTR=0x0073, RF_B_CNTR=0x002A; // 850 B=0x0109 A=0x14  // 830 B=0x0103 A=0x0C
byte IF_LD=0x01, RF_LD=0x02, RF_CP=0x00, IF_CP=0x00, IF_pres=0x00, RF_pres=0x03,  IF_A_CNTR=0x01, RF_A_CNTR=0x01;                           // 820 B=0x0100 A=0x08
boolean IF_PWDN = _0;
boolean RF_PWDN = _0;
boolean IF_CPG = _1;
boolean RF_CPG = _1;
boolean IF_TCP = _0; 
boolean RF_TCP = _0;
boolean IF_pol = _1;
boolean RF_pol = _1;
boolean flag = _0;
/////////////////////////////////////////

//unsigned char value, bit_ctr;


//////////////IF_R register///////////////
void IF_R (void){
byte bit_ctr;
unsigned int value=0;
////////IF_CP/////////
  value = IF_CP;
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
////////IF_LD/////////
  value = IF_LD;
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
 ////////IF_TCP bit/////////
   if (IF_TCP==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
////////IF_pol bit/////////
   if (IF_pol==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }   
   ////////IF_R_CNTR/////////
  value = IF_R_CNTR;
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
   value = (value << 1);  
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

//////////////////IF_N////////////////////////
void IF_N (void){
byte bit_ctr;
unsigned int value=0;
////////IF_CPG bit/////////
   if (IF_CPG==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////IF_PWDN bit/////////
   if (IF_PWDN==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////IF_pres/////////
  value = IF_pres;
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
   ////////IF_B_CNTR/////////
  value = IF_B_CNTR;
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
        if(value & 0x0800)
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
   
////////IF_A_CNTR/////////
  value = IF_A_CNTR;
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
   value = (value << 1);  
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

//////////////RF_R///////////////
void RF_R (void){
byte bit_ctr;
unsigned int value=0;
////////RF_CP/////////
  value = RF_CP;
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
////////RF_LD/////////
  value = RF_LD;
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
////////RF_TCP bit/////////
   if (RF_TCP==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   } 
////////RF_pol bit/////////
   if (RF_pol==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }   
   ////////RF_R_CNTR/////////
  value = RF_R_CNTR;
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
   value = (value << 1);  
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

//////////////////RF_N////////////////////////
void RF_N (void){
byte bit_ctr;
unsigned int value=0;
////////RF_CPG bit/////////
   if (RF_CPG==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////RF_PWDN bit/////////
   if (RF_PWDN==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////RF_pres/////////
  value = RF_pres;
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
   ////////RF_B_CNTR/////////
  value = RF_B_CNTR;
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
        if(value & 0x0800)
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
   
////////RF_A_CNTR/////////
  value = RF_A_CNTR;
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
   value = (value << 1);  
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

///////////////////////////////////////////////

void SINTprog(void) {
le0;
IF_R();
le1;
delayMicroseconds(10);
le0;
IF_N();
le1;
delayMicroseconds(10);
le0;
RF_R();
le1;
delayMicroseconds(10);
le0;
RF_N();
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

//ce1;
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
delayMicroseconds(1000);
SINTprog();

attachInterrupt(0, RESINT, RISING);
}

void loop() {
//  delay(1); 
//  SINTprog();
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
//   ce0;
   delay(200);
//   ce1;
   delay(500); 
   SINTprog();
   flag = _0; 
   }   
}

void RESINT() {
flag = _1;             
}
