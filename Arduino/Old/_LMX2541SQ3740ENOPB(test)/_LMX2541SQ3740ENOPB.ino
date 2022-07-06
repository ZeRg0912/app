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

byte  R7=0x07;
byte  R13=0x13;
byte  R12=0x12;
byte  R9=0x09;
byte  R8=0x08;
byte  R6=0x06;
byte  R5=0x05;
byte  R4=0x04;
byte  R3=0x03;
byte  R2=0x02;
byte  R1=0x01;
byte  R0=0x00;
byte  VCO_DIV_OPT=0x00;//RFout Disable(0x00)/Enable(0x04)
byte  AC_TEMP_COMP=0x24;//Dynamic(0x05)/Fixed(0x18) frequency
byte  RFOUT=0x00;//Комбинация с пином RFout, физическое подключение к микосхеме не важно:0x00-Disabled/0x02-Enabled, контроль внешним подключением к микросхеме:0x01/0x03;
byte  DIVTERMVCOGAIN=0x18;//VCO_DIV=1:OUTTERM, VCOGAIN         VCO_DIV>1:OUTTERM,DIVGAIN
byte  FL_TOC=0x00;//FASTLOCK 0..16383 (Disabled..16383x2 Detector cycles)
byte  FL_R3_LF=0x01;//Resistor R3 Fastlock 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  FL_R4_LF=0x00;//Resistor R4 Fastlock 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  FL_CPG=0x00;//Charge Pump Current for Fastlock 0..31=x1..x32
byte  OSC_FREQ=0x20;//Частота опорного генератора 1..255 MHz
byte  VCO_DIV=0x01;//Делитель VCO 1..63= 1-bypass 2=divide by 2..63=divide by 63
byte  R3_LF=0x01;//Loop Filter Resistor R3 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  R4_LF=0x00;//Loop Filter Resistor R4 0=200 Ohm; 1=1k Ohm; 2=2k Ohm; 3=4k Ohm; 4=16k Ohm; 5-7=reserved
byte  C3_LF=0x08;//loop filter resistor C3_LF 0..15; 0=0,1=1,2=5,3=6,4=10,5=11,6=15,7=16,8=20,9=21,10=25,11=26,12=30,13=31,14=35,15=36 pF
byte  C4_LF=0x08;//loop filter resistor C4_LF 0..15; 0=0,1=5,2=20,3=25,4=40,5=45,6=60,7=65,8=100,9=105,10=120,11=125,12=140,13=145,14=160,15=165 pF
byte  MODE=0x01;//Operational Mode 0..3 0-Full, 1-Externall VCO, 2-Divider only, 3-TEST
byte  POWERDOWN=0x00;//1=down
byte  XO=0x01;//Crystal Oscillator Mode Select
byte  CPG=0x00;//Charge Pump Current 0..31=x1..x32=100uA..3200uA
byte  MUX=0x10;//Multiplexed Output for Ftest/LD Pin 0..15
byte  CPP=0x01;//Charge Pump Polarity 0-Negative для FULL CHIP MODE 1-POSITIVE 
byte  OSC_2X=0x00;//OSCin Frequency Doubler 0-без 1-с
byte  FDM=0x01;// Fractional Denominator Mode Enable 0-10bit 1-22bit(default)
byte  ORDER=0x00;//Delta-Sigma Modulator Order 0-disable
byte  DITH=0x03;//Dithering 3-disabled
byte  CPT=0x00;//Charge Pump TRI-STATE
byte  DLOCK=0x00;//Controls for Digital Lock Detect - 0
byte  FSK=0x00;//Frequency Shift Keying
byte  DEN=0x00;//Дробный знаменатель
byte  PLL_RR1=0x10;//R делитель
byte  PLL_NR1=0x01;//N делитель
byte  PLL_NUMR1=0x01;//Дробный числитель
byte  PLL_NR0=0x01;//N делитель
byte  PLL_NUMR0=0x01;//Дробный числитель

/////////////////////////////////////////

unsigned char value, bit_ctr;


/////////////////////////////
void R7_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R7 register(3-0)==========
   value = R7;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////4////////      
   dat1;
   clk1;   
   clk0;
//////31-5////////
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }      
}
////////////////////////////////////////////////
void R13_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R13 register(3-0)==========
   value = R13;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////VCO_DIV_OPT(6-4)////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++){
   value = VCO_DIV_OPT;   
   if (VCO_DIV_OPT==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////31-7////////   
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }   
}  
////////////////////////////////////////////////
void R12_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R12 register(3-0)==========
   value = R12;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////4////////    
   dat1;
   clk1;   
   clk0;
//////31-5////////   
for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }     
}
////////////////////////////////////////////////
void R9_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R9 register(3-0)==========
   value = R9;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////9-4////////   
for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }
//////10////////    
   dat1;
   clk1;   
   clk0;
//////11////////    
   dat0;
   clk1;   
   clk0;
//////12////////    
   dat1;
   clk1;   
   clk0;
//////26-13////////   
for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   } 
//////27////////    
   dat1;
   clk1;   
   clk0;
//////28////////    
   dat0;
   clk1;   
   clk0;
//////29////////    
   dat1;
   clk1;   
   clk0;
//////30////////    
   dat0;
   clk1;   
   clk0;
//////31////////    
   dat0;
   clk1;   
   clk0;        
}
////////////////////////////////////////////////
void R8_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R8 register(3-0)==========
   value = R8;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////AC_TEMP_COMP(8-4)////////
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {
    value = AC_TEMP_COMP;   
   if (AC_TEMP_COMP==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////11-9////////   
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   dat1;
   clk1;   
   clk0; 
   }
//////13-12////////   
for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }
//////16-14////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat1;
   clk1;   
   clk0; 
   }
//////19-17////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }
//////20////////   
dat1;
clk1;   
clk0;  
//////23-21////////   
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }
//////24////////   
dat1;
clk1;   
clk0; 
//////31-25////////   
for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }                 
}
////////////////////////////////////////////////
void R6_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R6 register(3-0)==========
   value = R6;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////RFOUT 4//////// 
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {
    value = RFOUT;   
   if (RFOUT==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
} 
//////DIVGAIN 17-6////////
for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {
    value = DIVTERMVCOGAIN;   
   if (DIVTERMVCOGAIN==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////20-18////////   
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
   dat1;
   clk1;   
   clk0; 
   }
//////31-21////////   
for(bit_ctr=0;bit_ctr<11;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0; 
   }                      
}
////////////////////////////////////////////////
void R5_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R5 register(3-0)==========
   value = R5;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////FL_TOC 17-4//////// 
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {
    value = FL_TOC;   
   if (FL_TOC==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////FL_R3_LF 20-18////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {
    value = FL_R3_LF;   
   if (FL_R3_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////FL_R4_LF 23-21////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
    value = FL_R4_LF; 
   if (FL_R4_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////FL_CPG 28-24////////
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {
    value = FL_CPG;    
   if (FL_CPG==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////29////////   
dat1;
clk1;   
clk0;
//////30////////   
dat0;
clk1;   
clk0;
//////31////////   
dat1;
clk1;   
clk0;
}
////////////////////////////////////////////////
void R4_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R4 register(3-0)==========
   value = R4;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////OSC_FREQ 11-4//////// 
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
    value = OSC_FREQ; 
   if (OSC_FREQ==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////VCO_DIV 17-12////////
for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
    value = VCO_DIV;
   if (VCO_DIV==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////R3_LF 20-18////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
    value = R3_LF;
   if (R3_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////R4_LF 28-24////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
    value = R4_LF; 
   if (R4_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////C3_LF 28-24////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
    value = C3_LF; 
   if (C3_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////C4_LF 28-24////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
    value = C4_LF; 
   if (C4_LF==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
}
////////////////////////////////////////////////
void R3_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R3 register(3-0)==========
   value = R3;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////MODE 5-4//////// 
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
    value = OSC_FREQ; 
   if (OSC_FREQ==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////POWERDOWN 6//////// 
   value = VCO_DIV;
   if (VCO_DIV==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////XO 7////////
   value = XO;
   if (XO==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////CPG 12-8////////
for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
    value = CPG; 
   if (CPG==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////MUX 16-13////////
for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
    value = MUX; 
   if (MUX==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////CPP 17////////
   value = CPP;
   if (CPP==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////OSC_2X 18////////
   value = OSC_2X;
   if (OSC_2X==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////FDM 19////////
   value = FDM;
   if (FDM==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////ORDER 22-20////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {
    value = ORDER;   
   if (ORDER==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////DITH 24-23////////
for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
    value = DITH; 
   if (DITH==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////CPT 25////////
  value = CPT; 
   if (CPT==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
//////DLOCK 28-26////////
for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {   
    value = DLOCK; 
   if (DLOCK==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////29////////
   dat0;   
   clk1;   
   clk0;
//////30////////
   dat0;   
   clk1;   
   clk0;
//////FSK 31////////
   value = FSK; 
   if (FSK==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;                 
}
////////////////////////////////////////////////
void R2_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R2 register(3-0)==========
   value = R2;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////DEN 25-4//////// 
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {   
    value = DEN;
   if (DEN==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////26////////
   dat1;   
   clk1;   
   clk0;
//////31-27////////
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0;  
   }           
}
////////////////////////////////////////////////
void R1_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R1 register(3-0)==========
   value = R1;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////PLL_RR1 15-4//////// 
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {   
    value = PLL_RR1;
   if (PLL_RR1==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////PLL_NR1 21-16//////// 
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
    value = PLL_NR1;
   if (PLL_NR1==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////PLL_NUMR1 27-22//////// 
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {   
   value = PLL_NUMR1;
   if (PLL_NUMR1==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////31-28////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {   
   dat0;
   clk1;   
   clk0;  
   }           
}
////////////////////////////////////////////////
void R0_reg (void){
byte bit_ctr;
unsigned int value=0;
//======== R0 register(3-0)==========
   value = R0;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
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
//////PLL_NR0 15-4//////// 
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {   
    value = PLL_NR0;
   if (PLL_NR0==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}
//////PLL_NUMR0 31-16//////// 
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {   
    value = PLL_NUMR0;
   if (PLL_NUMR0==1){
   dat1;  
   } 
   else {
   dat0; 
   }
   value = (value << 1);  
   clk1;   
   clk0;
}       
}                 
////////////////////////////////////////////////
///////////////////////////////////////////////

void SINTprog(void) {
ce0;
delay(100);
ce1;
le0;
R7_reg();
le1;
delayMicroseconds(10000);
le0;
R13_reg();
le1;
delayMicroseconds(10000);
le0;
R12_reg();
le1;
delayMicroseconds(10000);
le0;
R9_reg();
le1;
delayMicroseconds(10000);
le0;
R8_reg();
le1;
delayMicroseconds(10000);
le0;
R6_reg();
le1;
delayMicroseconds(10000);
le0;
R5_reg();
le1;
delayMicroseconds(10000);
le0;
R4_reg();
le1;
delayMicroseconds(10000);
le0;
R3_reg();
le1;
delayMicroseconds(10000);
le0;
R2_reg();
le1;
delayMicroseconds(10000);
le0;
R1_reg();
le1;
delayMicroseconds(10000);
le0;
R12_reg();
le1;
delayMicroseconds(10000);
le0;
R0_reg();
le1;
delayMicroseconds(10000);
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
  delay(3000);
    SINTprog();
ce1;
RFout0;

attachInterrupt(0, RESINT, RISING);
}

void loop() {

}

void RESINT() {           
}
