#define sck0 digitalWrite(6,LOW)
#define sck1 digitalWrite(6,HIGH)
#define sdi0 digitalWrite(5,LOW)
#define sdi1 digitalWrite(5,HIGH)
#define scsn0 digitalWrite(4,LOW)
#define scsn1 digitalWrite(4,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
/////////////////////////////////////////
unsigned int IFR = 115;
char IFPD = 1;
char IFCP = 0;
char IFLD = 0;
char IFFO = 1;
char IFCPCUR = 0;

unsigned int IFNA = 1;
unsigned int IFNB = 3;
char IFPRE = 0;
char IFPDWN = 0;
char IFCPGAIN = 0;

unsigned int RFR = 115;
char RFPD = 1;
char RFCP = 0;
char RFLD = 0;
char RFFO = 0;
char RFCPCUR = 0;

unsigned int RFNA = 1;
unsigned int RFNB = 3;
char RFPRE = 0;
char RFPDWN = 0;
char RFCPGAIN = 0;

char res = 0;                                  

/////////////////////////////////////////

unsigned char value, bit_ctr;

/////////////////////////////////////////

/////////////////////////////
//======== IF R COUNTER LATCH ==========
void IF_R (void){
int bit_ctr;
unsigned int value=0;
   //////IFCPCUR//////// 
   value = IFCPCUR;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }                          
   //////IFFO//////// 
        if(IFFO == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFLD//////// 
        if(IFLD == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFCP//////// 
        if(IFCP == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFPD//////// 
        if(IFPD == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFR counter//////// 
   value = IFR;
   for(bit_ctr=0;bit_ctr<15;bit_ctr++)   
   {  
        if(value & 0x04000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////adress//////// 
   value = 0;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
}
/////////////////////////////
//======== IF N COUNTER LATCH ==========
void IFN (void){
int bit_ctr;
unsigned int value=0;
   //////IFCPGAIN//////// 
        if(IFCPGAIN == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFPDWN//////// 
        if(IFPDWN == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////IFPRE//////// 
   value = IFPRE;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////IFNB counter//////// 
   value = IFNB;
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
        if(value & 0x0800)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////IFNA counter//////// 
   value = IFNA;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x020)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }   
   //////adress//////// 
   value = 1;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
}   
/////////////////////////////
//======== RF R COUNTER LATCH ==========
void RF_R (void){
int bit_ctr;
unsigned int value=0;
   //////RFCPCUR//////// 
   value = RFCPCUR;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }                          
   //////RFFO//////// 
        if(RFFO == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFLD//////// 
        if(RFLD == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFCP//////// 
        if(RFCP == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFPD//////// 
        if(RFPD == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFR counter//////// 
   value = RFR;
   for(bit_ctr=0;bit_ctr<15;bit_ctr++)   
   {  
        if(value & 0x04000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////adress//////// 
   value = 3;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
}
/////////////////////////////
//======== RF N COUNTER LATCH ==========
void RFN (void){
int bit_ctr;
unsigned int value=0;
   //////RFCPGAIN//////// 
        if(RFCPGAIN == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFPDWN//////// 
        if(RFPDWN == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFPRE//////// 
   value = RFPRE;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////RFNB counter//////// 
   value = RFNB;
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
        if(value & 0x0800)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////RFNA counter//////// 
   value = RFNA;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x020)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }   
   //////adress//////// 
   value = 4;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
} 
////////////////////////////////////////////////
///////////////////////////////////////////////

void SINTprog(void) {
scsn0;
IF_R();
scsn1;
delayMicroseconds(10);
scsn0;
IFN();
scsn1;
delayMicroseconds(10);
scsn0;
RF_R();
scsn1;
delayMicroseconds(10);
scsn0;
RFN();
scsn1;
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

SINTprog();
}

void loop() {
  led1;
  delay(1000);              
  led0;      
  delay(1000);                
}
