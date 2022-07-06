#define clk0 digitalWrite(5,LOW)
#define clk1 digitalWrite(5,HIGH)
#define dat0 digitalWrite(4,LOW)
#define dat1 digitalWrite(4,HIGH)
#define le0 digitalWrite(3,LOW)
#define le1 digitalWrite(3,HIGH)
#define ce0 digitalWrite(2,LOW)
#define ce1 digitalWrite(2,HIGH)
#define _0 false;
#define _1 true;
/////////////////////////////////////////
unsigned int INT=0x0918, FRAC=0x0000, PHASE=0x0001, MOD=0x0002, R_CNTR = 0x0019, CLKDIV = 0x0096;         //INT=0xBFE0 рту P R= 200 (?8) 20???
byte  CURS=0x07, MUX = 0x03, CLKDIVMODE = 0x00, DIVSEL = 0x03, BANDSEL = 0x08, AUXOUTPOW = 0x03, OUTPOW = 0x00;
boolean CNT_RST = _0; 
boolean PRESC = _1;
boolean PDpol = _1;
boolean RDOUB = _0;
boolean RDIV = _0;
boolean DOUBBUFF = _0;
boolean LDF = _1;
boolean LDP = _1;
boolean PD = _0;
boolean CPTS = _0;
boolean FEEDBS = _1;
boolean VCOPWD = _0;
boolean MTLD = _0;
boolean AUXOUTS = _0;
boolean AUXOUTE = _0;
boolean RFOUTE = _1;

unsigned char value, bit_ctr;



////////////////////////////////////////////////
void R0 (void){
byte bit_ctr;
unsigned int value=0;
//======== R0 register==========
    //////DB31//////// 
   dat0;
   clk1;   
   clk0; 
   ///////  

   //////INT 16bit////////  
   value = INT;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0x8000)
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
   //////FRAC 12bit////////  
   value = FRAC;
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
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   } 
   //////address 3 bit////////    
   dat0;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////
void R1 (void){
byte bit_ctr;
unsigned int value=0;
//======== R1 register==========
//////4 zero bit////////  
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   } 
   
   ////////PRESC/////////
   if (PRESC==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  

   //////PHASE 12bit////////  
   value = PHASE;
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
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   } 
   //////MOD 12bit////////  
   value = MOD;
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
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   } 
   //////address 3 bit////////    
   dat0;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////
void R2 (void){
byte bit_ctr;
unsigned int value=0;
//======== R2 register==========
//////3 zero bit////////  
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
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
   
   ////////RDOUB/////////
   if (RDOUB==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////RDIV/////////
   if (RDIV==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  

   //////R_CNTR 10bit////////  
   value = R_CNTR;
   for(bit_ctr=0;bit_ctr<10;bit_ctr++)   
   {  
        if(value & 0x0200)
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
   ////////DOUBBUFF////////
   if (DOUBBUFF==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }
   //////CURS 4bit////////  
   value = CURS;
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
   ////////LDF////////
   if (LDF==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   ////////LDP////////
   if (LDP==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }   
   ////////PDpol////////
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
   ////////PD////////
   if (PD==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }
   ////////CPTS////////
   if (CPTS==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   } 
   ////////CNT_RST////////
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
   //////address 3 bit////////    
   dat0;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////
void R3 (void){
byte bit_ctr;
unsigned int value=0;
//======== R3 register==========
//////15 zero bit////////  
   for(bit_ctr=0;bit_ctr<15;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   } 
   //////CLKDIVMODE//////// 
   value = CLKDIVMODE;
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
   
   //////CLKDIV 12bit////////  
   value = CLKDIV;
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
   value = (value << 1);  // shift next bit into MSB..
   clk1;   
   clk0;  
   } 
   
   //////address 3 bit////////    
   dat0;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////
void R4 (void){
byte bit_ctr;
unsigned int value=0;
//======== R4 register==========
//////8 zero bit////////  
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   }  
   ////////FEEDBS/////////
   if (FEEDBS==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   } 
   //////DIVSEL//////// 
   value = DIVSEL;
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
   

   //////BANDSEL 8bit////////  
   value = BANDSEL;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x0080)
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
   ////////VCOPWD////////
   if (VCOPWD==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   } 
   ////////MTLD////////
   if (MTLD==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }   
   ////////AUXOUTS////////
   if (AUXOUTS==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }   
   ////////AUXOUTE////////
   if (AUXOUTE==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   } 
   //////AUXOUTPOW 2bit////////  
   value = AUXOUTPOW;
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
   ////////RFOUTE////////
   if (RFOUTE==1){
   dat1; 
   clk1;
   clk0;
   } 
   else {
   dat0; 
   clk1;
   clk0;
   }  
   //////OUTPOW 2bit////////  
   value = OUTPOW;
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
   //////address 3 bit////////    
   dat1;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////
void R5 (void){
byte bit_ctr;
unsigned int value=0;
//======== R5 register==========
//////11 zero bit////////  
   for(bit_ctr=0;bit_ctr<11;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   } 
//////2 higt bit////////  
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
   dat1;
   clk1;   
   clk0;   
   } 
//////16 zero bit////////  
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
   dat0;
   clk1;   
   clk0;   
   } 
   
   //////address 3 bit////////    
   dat1;
   clk1;   
   clk0; 
   ///////  
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
///////////////////////////////////////////////

void SINTprog(void) {
le0;
R5();
le1;
delayMicroseconds(10);
le0;
R4();
le1;
delayMicroseconds(10);
le0;
R3();
le1;
delayMicroseconds(10);
le0;
R2();
le1;
delayMicroseconds(10);
le0;
R1();
le1;
delayMicroseconds(10);
le0;
R0();
le1;
}  
///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
ce1;
OUTPOW = 0x00;
INT=0xFA0;    //C80 =400דצ //  D70=430דצ // f00=240 // e54=229.25 // bb8=3000
DIVSEL = 0x03;
SINTprog();
//========100========= -------- ADL5535 / PSA4-5043+
//INT=0xC80;          
//DIVSEL = 0x05;
//========200=========
//INT=0xC80;          
//DIVSEL = 0x04;
//========400=========
//INT=0xC80;          
//DIVSEL = 0x03;
//========430=========
//INT=0xD70;          
//DIVSEL = 0x03;
//========240========= -------- ADRF6755
//INT=0xF00;          
//DIVSEL = 0x04;
//========104========= -------- ADRF6806
//INT=0xD00;          
//DIVSEL = 0x05;
//========500========= -------- HMC992
//INT=0xFA0;          
//DIVSEL = 0x03;
//========229.3=======
//INT=0xE54;          
//DIVSEL = 0x04;
//========800=========
//INT=0xC80;          
//DIVSEL = 0x02;
//========1250=========
//INT=0x9C4;          
//DIVSEL = 0x01;
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
//========2700========= -------- HMC713
//INT=0xA8C;          
//DIVSEL = 0x00;
//========1000========= -------- PSA4-5043+
//INT=0xFA0;          
//DIVSEL = 0x02;
//========380========== -------- ADL5535
//INT=0xBE0;          
//DIVSEL = 0x03;
}

void loop() {
delayMicroseconds(100);

//delay (1);
  
}
