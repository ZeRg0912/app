#define CS0 digitalWrite(2,LOW)
#define CS1 digitalWrite(2,HIGH)
#define SCLK0 digitalWrite(3,LOW)
#define SCLK1 digitalWrite(3,HIGH)
#define SDIO0 digitalWrite(4,LOW)
#define SDIO1 digitalWrite(4,HIGH)
#define RST0 digitalWrite(5,LOW)
#define RST1 digitalWrite(5,HIGH)
#define FSK0 digitalWrite(6,LOW)
#define FSK1 digitalWrite(6,HIGH)
#define UCLK0 digitalWrite(7,LOW)
#define UCLK1 digitalWrite(7,HIGH)

#define _0 false
#define _1 true

int Phase1_1 = 0x00;
int Phase1_2 = 0x80;

int Phase2_1 = 0x00;
int Phase2_2 = 0x80;

int FTW1_1 = 0x00;
int FTW1_2 = 0x00;
int FTW1_3 = 0x00;
int FTW1_4 = 0x00;
int FTW1_5 = 0x80;
int FTW1_6 = 0x80;

int FTW2_1 = 0x00;
int FTW2_2 = 0x00;
int FTW2_3 = 0x00;
int FTW2_4 = 0x00;
int FTW2_5 = 0x80;
int FTW2_6 = 0x80;

int Delta_1 = 0x00;
int Delta_2 = 0x00;
int Delta_3 = 0x00;
int Delta_4 = 0x00;
int Delta_5 = 0x80;
int Delta_6 = 0x80;

int UCR_1 = 0x00;
int UCR_2 = 0x00;
int UCR_3 = 0x00;
int UCR_4 = 0x80;

int RRC_1 = 0x00;
int RRC_2 = 0x00;
int RRC_3 = 0x80;

int CR_1 = 0x20;
int CR_2 = 0x01;
int CR_3 = 0x04;
int CR_4 = 0x00;

int I_1 = 0x00;
int I_2 = 0x80;

int Q_1 = 0x00;
int Q_2 = 0x80;

int Snaped_1 = 0x80;

int QDac_1 = 0x80;
int QDac_2 = 0x80;

/////////////////////////////////////////
//======== Phase Offset Word Register 1 ==========
void Phase1 (void){
int bit_ctr;
int value=0;
      ////////ADRESS/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }   
   ////////DATA/////////
   value = Phase1_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }
      ////////DATA/////////
   value = Phase1_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Phase Offset Word Register 2 ==========
void Phase2 (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x01;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }  
   ////////DATA/////////
   value = Phase2_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x00)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = Phase2_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }      
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 1 ==========
void FTW1 (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x02;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   } 
   ////////DATA/////////
   value = FTW1_6;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = FTW1_5;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = FTW1_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }   
   ////////DATA/////////
   value = FTW1_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = FTW1_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = FTW1_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }       
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 2 ==========
void FTW2 (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x03;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = FTW2_6;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }    
   ////////DATA/////////
   value = FTW2_5;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }
   ////////DATA/////////
   value = FTW2_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }      
   ////////DATA/////////
   value = FTW2_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }   
   ////////DATA/////////
   value = FTW2_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }   
   ////////DATA/////////
   value = FTW2_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }   
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Delta frequency register  ==========
void Delta (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x04;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }   
   ////////DATA/////////
   value = Delta_6;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
   ////////DATA/////////
   value = Delta_5;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
   ////////DATA/////////
   value = Delta_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
   ////////DATA/////////
   value = Delta_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
   ////////DATA/////////
   value = Delta_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
   ////////DATA/////////
   value = Delta_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Update clock rate register  ==========
void UClockRate (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x05;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   } 
   ////////DATA/////////
   value = UCR_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = UCR_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = UCR_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = UCR_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Ramp rate clock register  ==========
void RampRateClock (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x06;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }   
   ////////DATA/////////
   value = RRC_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }
   ////////DATA/////////
   value = RRC_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }
   ////////DATA/////////
   value = RRC_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Control register  ==========
void ControlReg (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x07;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }  
   ////////DATA/////////
   value = CR_4;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }
   ////////DATA/////////
   value = CR_3;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }
   ////////DATA/////////
   value = CR_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }
   ////////DATA/////////
   value = CR_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }   
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== I path digital multiplier register  ==========
void IReg (void){
int bit_ctr;
int value=0; 
   ////////ADRESS/////////
   value = 0x08;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = I_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = I_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q path digital multiplier register  ==========
void QReg (void){
int bit_ctr;
int value=0; 
   ////////ADRESS/////////
   value = 0x09;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);    
   }    
   ////////DATA/////////
   value = Q_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = Q_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Shaped on/off keying ramp rate register  ==========
void Snaped (void){
int bit_ctr;
int value=0; 
   ////////ADRESS/////////
   value = 0x0A;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);  
   }  
   ////////DATA/////////
   value = Snaped_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q DAC  ==========
void QDac (void){
int bit_ctr;
int value=0;
   ////////ADRESS/////////
   value = 0x0B;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }    
   ////////DATA/////////
   value = QDac_2;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   }
   ////////DATA/////////
   value = QDac_1;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        SDIO1;
        }
        else
        {
        SDIO0;
        }
   value = (value << 1);  
   SCLK1;
   delay(10);   
   SCLK0;delay(10);   
   } 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SINTprog(void) {
CS0;
delay(10);
ControlReg();
CS1;
delay(10);  
CS0;
delay(10);
Phase1();
CS1;
delay(10);  
CS0;
delay(10);
Phase2();
CS1;
delay(10);
CS0;
delay(10);
FTW1();
CS1;
delay(10);
CS0;
delay(10);
FTW2();
CS1;
delay(10);
CS0;
delay(10);
Delta();
CS1;
delay(10);
CS0;
delay(10);
UClockRate();
CS1;
delay(10);
CS0;
delay(10);
RampRateClock();
CS1;
delay(10);
CS0;
delay(10);
IReg();
CS1;
delay(10);
CS0;
delay(10);
QReg();
CS1;
delay(10);
CS0;
delay(10);
Snaped();
CS1;
delay(10);
CS0;
delay(10);
QDac();
CS1;
delay(10);
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  RST1;
  delay(100);
  RST0;  
  SINTprog();
  UCLK1;
  delay(10);
  UCLK0;
}

void loop() {
  FSK1;
  delay(2000);
  FSK0;
  delay(2000);
}
