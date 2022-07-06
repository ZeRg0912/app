#define sck0 digitalWrite(6,LOW)
#define sck1 digitalWrite(6,HIGH)
#define sdi0 digitalWrite(5,LOW)
#define sdi1 digitalWrite(5,HIGH)
#define scsn0 digitalWrite(4,LOW)
#define scsn1 digitalWrite(4,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
/////////////////////////////////////////
char AUXSEL = 0x03;
char IFDIV = 0x00;
char LPWR = 0x00;
char AUTOPDB = 0x00;
char AUTOKP = 0x00;
char RFPWR = 0x00;
char KPI = 0x03;
char KP2 = 0x00;
char KP1 = 0x00;
char PDIB = 0x01;
char PDRB = 0x00;
long NRF1 = 0x00;
long NRF2 = 0x00;
unsigned int NIF = 952;
unsigned int RRF1 = 0x00;
unsigned int RRF2 = 0x00;
unsigned int RIF = 15;

char res = 0;                                  

/////////////////////////////////////////

unsigned char value, bit_ctr;

/////////////////////////////////////////

/////////////////////////////
//======== main configuration ==========
void mainr (void){
int bit_ctr;
unsigned int value=0;
   ////////zero 4/////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////AUXSEL//////// 
   value = AUXSEL;
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
   //////IFDIV//////// 
   value = IFDIV;
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
   ////////zero 4/////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////LPWR//////// 
        if(LPWR == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   ////////zero 1///////// 
   res;  
   sck1;   
   sck0;
   //////AUTOPDB//////// 
        if(AUTOPDB == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////AUTOKP//////// 
        if(AUTOKP == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////RFPWR//////// 
        if(RFPWR == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   ////////zero 1///////// 
   res;  
   sck1;   
   sck0;   
   //////adress//////// 
   value = 0x00;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== phase detector gain ==========
void pdg (void){
int bit_ctr;
unsigned int value=0;
   ////////zero 12/////////
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////KPI//////// 
   value = KPI;
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
   //////KP2//////// 
   value = KP2;
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
   //////KP1//////// 
   value = KP1;
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
   //////adress//////// 
   value = 0x01;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== powerdown ==========
void pdwn (void){
unsigned int bit_ctr;
unsigned int value=0;
   ////////zero 12/////////
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////PDIB//////// 
        if(PDIB == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////PDRB//////// 
        if(PDRB == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////adress//////// 
   value = 0x02;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== NDIV1 ==========
void ndiv1 (void){
long bit_ctr;
unsigned int value=0;
   ////////zero 18/////////
   for(bit_ctr=0;bit_ctr<18;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////adress//////// 
   value = 0x03;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== NDIV2 ==========
void ndiv2 (void){
long bit_ctr;
unsigned int value=0;
   ////////zero 18/////////
   for(bit_ctr=0;bit_ctr<18;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////adress//////// 
   value = 0x04;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== NIF ==========
void nif (void){
long bit_ctr;
long value=0;
   ////////zero 2/////////
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////NIF//////// 
   value = NIF;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0x08000)
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
   value = 0x05;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== RFRDIV1 ==========
void rfrdiv1 (void){
long bit_ctr;
unsigned int value=0;
   ////////zero 18/////////
   for(bit_ctr=0;bit_ctr<18;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////adress//////// 
   value = 0x06;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== RFRDIV2 ==========
void rfrdiv2 (void){
long bit_ctr;
unsigned int value=0;
   ////////zero 18/////////
   for(bit_ctr=0;bit_ctr<18;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////adress//////// 
   value = 0x07;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
//======== RIFdiv ==========
void Rifdiv (void){
long bit_ctr;
unsigned int value=0;
   ////////zero 5/////////
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////RIF//////// 
   value = RIF;
   for(bit_ctr=0;bit_ctr<13;bit_ctr++)   
   {  
        if(value & 0x01000)
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
   value = 0x08;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
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
mainr();
scsn1;
delayMicroseconds(10);
scsn0;
pdg();
scsn1;
delayMicroseconds(10);
scsn0;
pdwn();
scsn1;
delayMicroseconds(10);
scsn0;
ndiv1();
scsn1;
delayMicroseconds(10);
scsn0;
ndiv2();
scsn1;
delayMicroseconds(10);
scsn0;
nif();
scsn1;
delayMicroseconds(10);
scsn0;
rfrdiv1();
scsn1;
delayMicroseconds(10);
scsn0;
rfrdiv2();
scsn1;
delayMicroseconds(10);
scsn0;
Rifdiv();
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
