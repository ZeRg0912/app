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
#define RFout0 digitalWrite(8,LOW)
#define RFout1 digitalWrite(8,HIGH)
#define _0 false
#define _1 true

boolean flag = _1;
unsigned int value=0;
byte  R7=7;
byte  R13=13;
byte  R12=12;
byte  R9=9;
byte  R8=8;
byte  R6=6;
byte  R5=5;
byte  R4=4;
byte  R3=3;
byte  R2=2;
byte  R1=1;
byte  R0=0;
byte  VCO_DIV_OPT=0;//RFout Disable(0x00)/Enable(0x04)
byte  AC_TEMP_COMP=05;//Dynamic(0x05)/Fixed(0x24) frequency
byte  RFOUT=0;//Комбинация с пином RFout, физическое подключение к микосхеме не важно:0x00-Disabled/0x02-Enabled, контроль внешним подключением к микросхеме:0x01/0x03;
byte  DIVTERMVCOGAIN=18;//VCO_DIV=1:OUTTERM, VCOGAIN         VCO_DIV>1:OUTTERM,DIVGAIN
byte  FL_TOC=3;//FASTLOCK 0..16383 (Disabled..16383x2 Detector cycles)
byte  FL_R3_LF=1;//Resistor R3 Fastlock 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  FL_R4_LF=0;//Resistor R4 Fastlock 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  FL_CPG=0;//Charge Pump Current for Fastlock 0..31=x1..x32
byte  OSC_FREQ=15;//Частота опорного генератора 1..255 MHz
byte  VCO_DIV=1;//Делитель VCO 1..63= 1-bypass 2=divide by 2..63=divide by 63
byte  R3_LF=1;//Loop Filter Resistor R3 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  R4_LF=0;//Loop Filter Resistor R4 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  C3_LF=8;//loop filter resistor C3_LF 0..15; 0=0,1=1,2=5,3=6,4=10,5=11,6=15,7=16,8=20,9=21,10=25,11=26,12=30,13=31,14=35,15=36 pF
byte  C4_LF=8;//loop filter resistor C4_LF 0..15; 0=0,1=5,2=20,3=25,4=40,5=45,6=60,7=65,8=100,9=105,10=120,11=125,12=140,13=145,14=160,15=165 pF
byte  MODE=1;//Operational Mode 0..3 0-Full, 1-Externall VCO, 2-Divider only, 3-TEST
byte  POWERDOWN=0;//1=down
byte  XO=0;//Crystal Oscillator Mode Select
byte  CPG=0;//Charge Pump Current 0..31=x1..x32=100uA..3200uA
byte  MUX=10;//Multiplexed Output for Ftest/LD Pin 0..15
byte  CPP=1;//Charge Pump Polarity 0-Negative для FULL CHIP MODE 1-POSITIVE 
byte  OSC_2X=0;//OSCin Frequency Doubler 0-без 1-с
byte  FDM=1;// Fractional Denominator Mode Enable 0-10bit 1-22bit(default)
byte  ORDER=0;//Delta-Sigma Modulator Order 0-disable
byte  DITH=3;//Dithering 3-disabled
byte  CPT=0;//Charge Pump TRI-STATE
byte  DLOCK=0;//Controls for Digital Lock Detect - 0
byte  FSK=0;//Frequency Shift Keying
byte  DEN=1;//Дробный знаменатель
byte  PLL_RR1=10;//R делитель
byte  PLL_NR1=1;//N делитель
byte  PLL_NUMR1=1;//Дробный числитель
byte  PLL_NR0=1;//N делитель
byte  PLL_NUMR0=1;//Дробный числитель

/////////////////////////////////////////

unsigned char bit_ctr;


/////////////////////////////
void R7_reg (void){
byte bit_ctr;
//////31-5////////
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;
   delay(10);
   clk0;
   delay(10); 
   }
//////4////////      
   dat1;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10);
//======== R7 register(3-0)==========
   value = R7;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R13_reg (void){
byte bit_ctr;
//////31-7////////   
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10); 
   }     
//////VCO_DIV_OPT(6-4)////////
value = VCO_DIV_OPT;
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x08){
   dat1;
   delay(10);  
   } 
   else {
   dat0;
   delay(10); 
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
//======== R13 register(3-0)==========
   value = R13;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
   value = 0;
   }
////////////////////////////////////////////////
void R12_reg (void){
byte bit_ctr;
//////31-5////////   
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10); 
   }
//////4////////    
   dat1;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10);
   //======== R12 register(3-0)==========
   value = R12;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);    
   }
   value = 0;     
}
////////////////////////////////////////////////
void R9_reg (void){
byte bit_ctr;
//////31////////    
   dat0;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10);
   //////30////////    
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   //////29////////    
   dat1;
   delay(10);
   clk1; 
   delay(10);  
   clk0;
   delay(10);
//////28////////    
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   //////27////////    
   dat1;
   delay(10);
   clk1;
   delay(10);   
   clk0;
   delay(10);
   //////26-13////////   
for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0;
   delay(10); 
   }
   //////12////////    
   dat1;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10);
   //////11////////    
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   //////10////////    
   dat1;
   delay(10);
   clk1;   
   delay(10);
   clk0;
   delay(10);
//////9-4////////   
for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;  
   delay(10); 
   clk0; 
   delay(10);
   }
//======== R9 register(3-0)==========
value = R9;
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
{  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0; 
   delay(10);  
   }
   value = 0;        
}
////////////////////////////////////////////////
void R8_reg (void){
byte bit_ctr;
//////31-25////////   
for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10);
   }
//////24////////   
dat1;
   delay(10);
clk1; 
   delay(10);  
clk0;
   delay(10);
//////23-21////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10);
   }
//////20////////   
dat1;
   delay(10);
clk1; 
   delay(10);  
clk0; 
   delay(10); 
//////19-17////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10);
   }
//////16-14////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat1;
   delay(10);
   clk1;  
   delay(10); 
   clk0; 
   delay(10);
   }
//////13-12////////   
for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;
   delay(10);   
   clk0; 
   delay(10);
   }
//////11-9////////   
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   dat1;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10);
   }
//////AC_TEMP_COMP(8-4)////////
   value = AC_TEMP_COMP; 
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {   
   if (value & 0x10){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
} 
value = 0;
   //======== R8 register(3-0)==========
   value = R8;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;   
   delay(10);
   clk0;   
   delay(10); 
   }
    value = 0; 
                 
}
////////////////////////////////////////////////
void R6_reg (void){
byte bit_ctr;
//////31-21////////   
for(bit_ctr=0;bit_ctr<11;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;  
   delay(10); 
   clk0; 
   delay(10);
   }
//////20-18////////   
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   dat1;
   delay(10);
   clk1;
   delay(10);   
   clk0; 
   delay(10);
   }
//////DIVGAIN 17-6////////
   value = DIVTERMVCOGAIN;
for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {   
   if (value & 0x800){
   dat1;
   delay(10);  
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = RFOUT; 
//////RFOUT 5-4////////
for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
   if (value & 0x02){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0; 
   //======== R6 register(3-0)==========
   value = R6;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;   
   clk0;    
   }
   value = 0;                      
}
////////////////////////////////////////////////
void R5_reg (void){
byte bit_ctr;
//////31////////   
dat1;
   delay(10);
clk1;  
   delay(10); 
clk0;
   delay(10);
//////30////////   
dat0;
   delay(10);
clk1; 
   delay(10);  
clk0;
   delay(10);
//////29////////   
dat1;
   delay(10);
clk1; 
   delay(10);  
clk0;
   delay(10);
//////FL_CPG 28-24////////
  value = FL_CPG;
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {   
   if (value & 0x10){
   dat1;
   delay(10);  
   } 
   else {
   dat0;
   delay(10); 
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
//////FL_R4_LF 23-21////////
value = FL_R4_LF;
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {    
   if (value & 0x08){
   dat1;
   delay(10);  
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = FL_R3_LF;
//////FL_R3_LF 20-18////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x04){
   dat1;
   delay(10);  
   } 
   else {
   dat0;
   delay(10); 
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = FL_TOC;
//////FL_TOC 17-4//////// 
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {   
   if (value & 0x2000){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
//======== R5 register(3-0)==========
   value = R5;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;   
   delay(10); 
   }
   value=0;
}
////////////////////////////////////////////////
void R4_reg (void){
byte bit_ctr;
value = 0;
value = C4_LF;
//////C4_LF 31-29////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   if (value & 0x08){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
value = C3_LF;
//////C3_LF 28-24////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   if (value & 0x08){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
value = R4_LF;
//////R4_LF 23-21////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x04){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
}
value = 0;
value = R3_LF;
//////R3_LF 20-18////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x04){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
}
value = 0;
value = VCO_DIV;
//////VCO_DIV 17-12////////
for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   if (value & 0x20){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
value = OSC_FREQ;
//////OSC_FREQ 11-4//////// 
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {   
   if (value & 0x80){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
//======== R4 register(3-0)==========
   value = R4;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0; 
   delay(10);   
   }
}
////////////////////////////////////////////////
void R3_reg (void){
byte bit_ctr;
value = 0;
value = FSK;
//////FSK 31////////
   if (FSK==1){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
//////30////////
   dat0; 
   delay(10);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
//////29////////
   dat0; 
   delay(10);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   value = 0;
value = DLOCK;
//////DLOCK 28-26////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x04){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
}
value = 0;
value = CPT;
//////CPT 25////////
   if (CPT==1){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;   
   delay(10);
   clk0;
   delay(10);
value = 0;
value = DITH;
//////DITH 24-23////////
for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
   if (value & 0x02){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = ORDER;
//////ORDER 22-20////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   if (value & 0x04){
   dat1;
   delay(10);  
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
value = FDM;
//////FDM 19////////
   if (FDM==1){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   value = 0;
value = OSC_2X;
//////OSC_2X 18////////
   if (OSC_2X==1){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
    value = 0;
value = CPP;
//////CPP 17////////
   if (CPP==1){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
    value = 0;
value = MUX;
//////MUX 16-13////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   if (value & 0x08){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;
   delay(10);
   clk0;
   delay(10);
}
value = 0;
value = CPG;
//////CPG 12-8////////
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {   
   if (value & 0x10){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = XO;
//////XO 7////////
   if (XO==1){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   value = 0;
value = POWERDOWN;
//////POWERDOWN 6//////// 
   if (POWERDOWN==1){
   dat1;
   delay(10);  
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   value = 0;
value = MODE;
//////MODE 5-4//////// 
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
   if (value & 0x02){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
   //======== R3 register(3-0)==========
   value = R3;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0; 
   delay(10);   
   }                 
}
////////////////////////////////////////////////
void R2_reg (void){
byte bit_ctr;
//////31-27////////
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1;
   delay(10);   
   clk0;  
   delay(10);
   } 

//////26////////
   dat1;
   delay(10);   
   clk1; 
   delay(10);  
   clk0;
   delay(10);
   value = 0;
value = DEN;
//////DEN 25-4//////// 
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
   if (value & 0x02){
   dat1;
   delay(10);  
   } 
   else {
   dat0;
   delay(10); 
   }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);
}
value = 0;
//======== R2 register(3-0)==========
   value = R2;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0; 
   delay(10);   
   }
}
////////////////////////////////////////////////
void R1_reg (void){
byte bit_ctr;
//////31-28////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   delay(10);
   clk1; 
   delay(10);  
   clk0; 
   delay(10); 
   }
   value = 0;
value = PLL_NUMR1;
//////PLL_NUMR1 27-22//////// 
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   if (value & 0x20){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;   
   delay(10);
   clk0;
   delay(10);
}
value = 0;
value = PLL_NR1;
//////PLL_NR1 21-16//////// 
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   if (value & 0x20){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
value = PLL_RR1;
//////PLL_RR1 15-4//////// 
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {   
   if (value & 0x800){
   dat1; 
   delay(10); 
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;
   delay(10);
}
value = 0;
//======== R1 register(3-0)==========
   value = R1;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0; 
   delay(10);   
   }           
}
////////////////////////////////////////////////
void R0_reg (void){
byte bit_ctr;
value = 0;
value = PLL_NUMR0;
//////PLL_NUMR0 31-16//////// 
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {   
   if (value & 0x8000){
   dat1;
   delay(10);  
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
} 
value = 0;
value = PLL_NR0;
//////PLL_NR0 15-4//////// 
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {   
   if (value & 0x800){
   dat1;  
   delay(10);
   } 
   else {
   dat0; 
   delay(10);
   }
   value = (value << 1);  
   clk1;  
   delay(10); 
   clk0;
   delay(10);
}
value = 0;
//======== R0 register(3-0)==========
   value = R0;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1; 
   delay(10);  
   clk0;  
   delay(10);  
   }      
}                 
////////////////////////////////////////////////
///////////////////////////////////////////////

void SINTprog(void) {
ce0;
delay(10);
ce1;
le0;
R7_reg();
le1;
delayMicroseconds(10);
le0;
R13_reg();
le1;
delayMicroseconds(10);
le0;
R12_reg();
le1;
delayMicroseconds(10);
le0;
R9_reg();
le1;
delayMicroseconds(10);
le0;
R8_reg();
le1;
delayMicroseconds(10);
le0;
R6_reg();
le1;
delayMicroseconds(10);
le0;
R5_reg();
le1;
delayMicroseconds(10);
le0;
R4_reg();
le1;
delayMicroseconds(10);
le0;
R3_reg();
le1;
delayMicroseconds(10);
le0;
R2_reg();
le1;
delayMicroseconds(10);
le0;
R1_reg();
le1;
delayMicroseconds(10);
le0;
R12_reg();
le1;
delayMicroseconds(10);
le0;
R0_reg();
le1;
delayMicroseconds(10);
}  


///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  delay(10);
SINTprog();
ce1;
RFout0;

attachInterrupt(0, RESINT, RISING);
}

void loop() {
/*if (flag == _0){
   } 
   else { 
   ce0;
   delay(200);
   ce1;
   delay(500); 
   SINTprog();
   flag = _0; 
   }*/
}

void RESINT() {
  flag = _1;            
}
