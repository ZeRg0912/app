#define clk0 digitalWrite(5,LOW)
#define clk1 digitalWrite(5,HIGH)
#define dat0 digitalWrite(4,LOW)
#define dat1 digitalWrite(4,HIGH)
#define cs0 digitalWrite(2,LOW)
#define cs1 digitalWrite(2,HIGH)
#define _0 false;
#define _1 true;

int WRITE_COMMAND = 0xD4;
int READ_COMMAND = 0xD5;

int data = 0x00;
int adress = 0x00;

int FRAC_WORD_4 = 0x00; // LSB
int FRAC_WORD_3 = 0x00;
int FRAC_WORD_2 = 0x00;
int FRAC_WORD_1 = 0x04; // MSB
int REF_DIV = 0x10; // 0x00 - R_DIV_by2 disable || 0x10 - R_DIV_by2 enable
int INT_WORD_2 = 0x28; // 0x1E - 150; 0x28 - 200; 0x32 - 500
int INT_WORD_1_MUX = 0xD0; // первые полбайта MUX = D - REF/2 || вторые полбайта продолжение INT 
int CHARGE_PUMP_CURRENT = 0xF0;
int REF_FREQ_CTRL = 0x43; // первые полбайта Div & Doubler REF || вторые полбайта Rdiv set = 1..32
int PLL_POWER_UP = 0x18;
int LD_CTRL_2 = 0xE8;
int TXDIS_CTRL = 0x00;
int LD_CTRL_1 = 0x70; 
int AUTOCALIBR = 0x18;
int AUTOCALIB_TIMER = 0x64;
int LOMON_OUT = 0x07; // 0x07 - 100..1155, 0x17 - 1155..2400
int LO_SEL = 0x0B;    // 0x0C - 100..144.375(/16), 0x0B - 144.375..288.75(/8), 0x0A - 288.75..577.5(/4), 0x09 - 577.5..1155(/2), 0x08 - 1155..2400(/1)
int MODULATOR = 0x81;
int ATTENUATOR = 0x00;
int REVISION = 0x00;

////////////////////////////////////////////////
void CR0 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////FRAC_WORD_4 8bit////////  
   value = FRAC_WORD_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR1 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x01;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////FRAC_WORD_3 8bit////////  
   value = FRAC_WORD_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}   
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR2 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x02;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////FRAC_WORD_2 8bit////////  
   value = FRAC_WORD_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR3 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x03;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////FRAC_WORD_1 8bit////////  
   value = FRAC_WORD_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR5 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x05;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////REF_DIV 8bit////////  
   value = REF_DIV;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR6 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x06;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////INT_WORD_2 8bit////////  
   value = INT_WORD_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR7 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x07;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////INT_WORD_1_MUX 8bit////////  
   value = INT_WORD_1_MUX;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR9 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x09;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////CHARGE_PUMP_CURRENT 8bit////////  
   value = CHARGE_PUMP_CURRENT;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR10 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0A;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////REF_FREQ_CTRL 8bit////////  
   value = REF_FREQ_CTRL;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR12 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0C;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////PLL_POWER_UP 8bit////////  
   value = PLL_POWER_UP;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR13 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0D;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////LD_CTRL_2 8bit////////  
   value = LD_CTRL_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR14 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0E;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////TXDIS_CTRL 8bit////////  
   value = TXDIS_CTRL;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR23 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x17;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////LD_CTRL_1 8bit////////  
   value = LD_CTRL_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR24 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x18;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////AUTOCALIBR 8bit////////  
   value = AUTOCALIBR;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR25 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x19;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////AUTOCALB_TIMER 8bit////////  
   value = AUTOCALIB_TIMER;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR27 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x1B;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////LOMON_OUT 8bit////////  
   value = LOMON_OUT;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR28 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x1C;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////LO_SEL 8bit////////  
   value = LO_SEL;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR29 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x1D;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////MODULATOR 8bit////////  
   value = MODULATOR;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR30 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x1E;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ATTENUATOR 8bit////////  
   value = ATTENUATOR;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
////////////////////////////////////////////////
void CR33 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x21;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////REVISION 8bit////////  
   value = REVISION;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////

/////////RESERVED_REGS/////////////////////////
///////////////////////////////////////////////
void CR26 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x1A;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
void CR22 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x16;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x80;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
void CR21 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x15;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
void CR20 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x14;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR19 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x13;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x80;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR18 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x12;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x60;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR17 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x11;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR16 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x10;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR15 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0F;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}
///////////////////////////////////////////////
void CR11 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x0B;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
void CR8 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x08;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////
void CR4 (void){
char bit_ctr;
unsigned int value = 0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////  
   value = 0x04;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////res////////  
   value = 0x01;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
}    
///////////////////////////////////////////////

/////////////////Read_REGS/////////////////////
///////////////////////////////////////////////
void RCR6 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit//////// 
   adress = 0x00; 
   value = 0x06;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != INT_WORD_2){
    Serial.print("06");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }
}    
///////////////////////////////////////////////
void RCR7 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x07;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != INT_WORD_1_MUX){
   //if (data == INT_WORD_1_MUX){
    Serial.print("07");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }   
}    
///////////////////////////////////////////////
void RCR10 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x0A;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != REF_FREQ_CTRL){
    Serial.print("0A");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }
}    
///////////////////////////////////////////////
void RCR12 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x0C;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != PLL_POWER_UP){
    Serial.print("0C");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }
}    
///////////////////////////////////////////////
void RCR27 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x1B;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != LOMON_OUT){
    Serial.print("1B");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }
}    
///////////////////////////////////////////////
void RCR28 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x1C;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != LO_SEL){
    Serial.print("1C");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH);    
   }
}    
///////////////////////////////////////////////
void RCR29 (void){
char bit_ctr;
unsigned int value = 0;
cs0;
//========register==========
   //////WRITE_COMMAND 8bit////////  
   value = WRITE_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////ADDRESS 8bit////////
   adress = 0x00;  
   value = 0x1D;
   adress = value;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   cs1;
   cs0; 
   //////READ_COMMAND 8bit////////  
   value = READ_COMMAND;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
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
   //////READ_DATA 8bit//////// 
   pinMode(3, INPUT);
   data = 0x00;
   for(bit_ctr=7;bit_ctr>-1;bit_ctr--)   
   {  
        if(digitalRead(3) == HIGH)
        {
        bitWrite(data, bit_ctr, 1);
        }
        else
        {
        bitWrite(data, bit_ctr, 0);
        }
   clk1;   
   clk0;  
   }
   cs1;
   pinMode(3, OUTPUT);
   if (data != MODULATOR){
    Serial.print("1D");
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("|");
    digitalWrite(13, HIGH); 
   }
}    
///////////////////////////////////////////////

void REG_SEQ (void){
  cs0;
  CR30();
  cs1;
/////////
MODULATOR = 0x80;
  cs0;
  CR29();
  cs1;
/////////
  cs0;
  CR28();
  cs1;
/////////
  cs0;
  CR27();
  cs1;
/////////
  cs0;
  CR26();
  cs1;
/////////
  cs0;
  CR25();
  cs1;
/////////
  cs0;
  CR24();
  cs1;
/////////
  cs0;
  CR23();
  cs1;
/////////
  cs0;
  CR22();
  cs1;
/////////
  cs0;
  CR21();
  cs1;
/////////
  cs0;
  CR20();
  cs1;
/////////
  cs0;
  CR19();
  cs1;
/////////
  cs0;
  CR18();
  cs1;
/////////
  cs0;
  CR17();
  cs1;
/////////
  cs0;
  CR16();
  cs1;
/////////
  cs0;
  CR15();
  cs1;
/////////
  cs0;
  CR14();
  cs1;
/////////
  cs0;
  CR13();
  cs1;
/////////
  cs0;
  CR12();
  cs1;
/////////
  cs0;
  CR11();
  cs1;
/////////
  cs0;
  CR10();
  cs1;
/////////
  cs0;
  CR9();
  cs1;
/////////
  cs0;
  CR8();
  cs1;
/////////
  cs0;
  CR7();
  cs1;
/////////
  cs0;
  CR6();
  cs1;
/////////
  cs0;
  CR5();
  cs1;
/////////
  cs0;
  CR4();
  cs1;
/////////
  cs0;
  CR3();
  cs1;
/////////
  cs0;
  CR2();
  cs1;
/////////
  cs0;
  CR1();
  cs1;
/////////
  cs0;
  CR0();
  cs1;
/////////
  cs0;
  CR27();
  cs1;
/////////
MODULATOR = 0x81;;
  cs0;
  CR29();
  cs1;
/////////
  cs0;
  CR0();
  cs1;
/////////
}

void REG_SEQ_READ (void){
  RCR6();
  RCR7();
  RCR10();
  RCR12();
  RCR27();
  RCR28();
  RCR29();  
}
      
void setup() {
Serial.begin(9600);
cs0;
cs1;
cs0;
cs1;
cs0;
cs1;
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(13, OUTPUT); 
cs0;
dat0;
clk0;
REG_SEQ();
}

void loop() {
 //REG_SEQ;
 //delay(1000);
 REG_SEQ_READ();
 //RCR7();
 //delay(500);
 digitalWrite(13, LOW);
 //delay(1000); 
}
