#define WR0 digitalWrite(10,LOW)
#define WR1 digitalWrite(10,HIGH)
#define OSK0 digitalWrite(A6,LOW)
#define OSK1 digitalWrite(A6,HIGH)
#define FSK0 digitalWrite(11,LOW)
#define FSK1 digitalWrite(11,HIGH)
#define RST0 digitalWrite(12,LOW)
#define RST1 digitalWrite(12,HIGH)
#define UCLK0 digitalWrite(13,LOW)
#define UCLK1 digitalWrite(13,HIGH)

#define _0 false
#define _1 true
/////////////////////////////////////////
int Adress_pin[6] = {14,15,16,17,18,19};
int Data_pin[8] = {8,9,2,3,4,5,6,7};

int Adress = 0x00;

int Phase1_1 = 0x00;
int Phase1_2 = 0x00;
int Phase2_1 = 0x00;
int Phase2_2 = 0x00;

int FTW1_1 = 0x50;
int FTW1_2 = 0x00;
int FTW1_3 = 0x00;
int FTW1_4 = 0x00;
int FTW1_5 = 0x00;
int FTW1_6 = 0x00;

int FTW2_1 = 0x50;
int FTW2_2 = 0x00;
int FTW2_3 = 0x00;
int FTW2_4 = 0x00;
int FTW2_5 = 0x00;
int FTW2_6 = 0x00;

int DFW_1 = 0x00;
int DFW_2 = 0x00;
int DFW_3 = 0x00;
int DFW_4 = 0x00;
int DFW_5 = 0x00;
int DFW_6 = 0x00;

int UC_1 = 0x00;
int UC_2 = 0x00;
int UC_3 = 0x00;
int UC_4 = 0x40;

int RRC_1 = 0x00;
int RRC_2 = 0x00;
int RRC_3 = 0x00;

int CONST_1 = 0x10;
int CONST_2 = 0x64;
int CONST_3 = 0x02;
int CONST_4 = 0x20;

//======== Mode Register ==========
void ModeReg (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x1F;
value_d = 0x01;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Phase Adjust Register 1 ==========
void PhaseAdjustReg1 (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x00;
value_d = Phase1_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x01;
value_d = Phase1_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Phase Adjust Register 2 ==========
void PhaseAdjustReg2 (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x02;
value_d = Phase2_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x03;
value_d = Phase2_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 1 ==========
void FrequencyTuningWord1 (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x04;
value_d = FTW1_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x05;
value_d = FTW1_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x06;
value_d = FTW1_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x07;
value_d = FTW1_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x08;
value_d = FTW1_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x09;
value_d = FTW1_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 2 ==========
void FrequencyTuningWord2 (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x0A;
value_d = FTW2_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x0B;
value_d = FTW2_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x0C;
value_d = FTW2_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x0D;
value_d = FTW2_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x0E;
value_d = FTW2_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x0F;
value_d = FTW2_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Delta Frequency Word  ==========
void DeltaFrequencyWord (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x10;
value_d = DFW_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x11;
value_d = DFW_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x12;
value_d = DFW_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x13;
value_d = DFW_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x14;
value_d = DFW_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x15;
value_d = DFW_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Update Clock  ==========
void UpdateClock (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x16;
value_d = UC_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x17;
value_d = UC_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x18;
value_d = UC_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x19;
value_d = UC_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Ramp Rate Clock  ==========
void RampRateClock (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x1A;
value_d = RRC_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x1B;
value_d = RRC_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x1C;
value_d = RRC_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Const Register 1  ==========
void ConstReg1 (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x1D;
value_d = CONST_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x1E;
value_d = CONST_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x1F;
value_d = CONST_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x20;
value_d = CONST_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== I multiplier ==========
void IMult (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x21;
value_d = 0x08;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x22;
value_d = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q multiplier ==========
void QMult (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x23;
value_d = 0x08;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x24;
value_d = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Output Shaping Rate ==========
void RampRate (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x25;
value_d = 0x80;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== QDAC ==========
void QDAC (void){
int bit_ctr;
unsigned int value_a=0;
unsigned int value_d=0;
WR0;
value_a = 0x26;
value_d = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
value_a = 0x27;
value_d = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  ////////Adress/////////
  if(value_a & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value_a = (value_a << 1);
  ////////Data/////////
  if(value_d & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value_d = (value_d << 1);
  WR1;
  delay(10);
  WR0; 
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SINTprog(void) {
UCLK1;
delay(10);
UCLK0;
ModeReg();
delayMicroseconds(10);  
PhaseAdjustReg1();
delayMicroseconds(10);
PhaseAdjustReg2();
delayMicroseconds(10);
FrequencyTuningWord1();
delayMicroseconds(10);
FrequencyTuningWord2();
delayMicroseconds(10);
DeltaFrequencyWord();
delayMicroseconds(10);
UpdateClock();
delayMicroseconds(10);
RampRateClock();
delayMicroseconds(10);
ConstReg1();
delayMicroseconds(10);
IMult();
delayMicroseconds(10);
QMult();
delayMicroseconds(10);
RampRate();
delayMicroseconds(10);
QDAC();
delayMicroseconds(10);
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
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
  OSK0;
  delay(1000);
  FSK0;
  OSK0;
  delay(1000);
//  led1;  
//  delay(1000);              
//  led0;    
//  delay(1000); 
//  led1;  
//  delay(1000);              
//  led0;    
//  delay(1000); 
//cli();
//sei();
//cli();
//sei();
 //SINTprog();
 //delay(15000);
//void RESINT() {
//flag = _1;              
}
