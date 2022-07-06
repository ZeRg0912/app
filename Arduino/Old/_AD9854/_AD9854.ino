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

int Phase1_1 = 0x10;
int Phase1_2 = 0x00;
int Phase2_1 = 0x10;
int Phase2_2 = 0x00;

int FTW1_1 = 0x50;
int FTW1_2 = 0x00;
int FTW1_3 = 0x00;
int FTW1_4 = 0x00;
int FTW1_5 = 0x00;
int FTW1_6 = 0x50;

int FTW2_1 = 0x00;
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

//======== Mode Register ==========
void ModeReg (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x1F;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x01;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Phase Adjust Register 1 ==========
void PhaseAdjustReg1 (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = Phase1_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x01;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = Phase1_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Phase Adjust Register 2 ==========
void PhaseAdjustReg2 (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x02;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = Phase1_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x03;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = Phase1_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 1 ==========
void FrequencyTuningWord1 (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x04;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x05;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x05;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x07;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x08;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x09;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW1_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Frequency Tuning Word 2 ==========
void FrequencyTuningWord2 (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x0A;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x0B;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x0C;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x0D;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x0E;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x0F;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = FTW2_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Delta Frequency Word  ==========
void DeltaFrequencyWord (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x10;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x11;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x12;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x13;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x14;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_5;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x15;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = DFW_6;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Update Clock  ==========
void UpdateClock (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x16;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = UC_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x17;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = UC_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x18;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = UC_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x19;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = UC_4;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Ramp Rate Clock  ==========
void RampRateClock (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x1A;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = RRC_1;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x1B;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = RRC_2;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x1C;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = RRC_3;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Const Register 1  ==========
void ConstReg1 (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x1D;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x10;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x1E;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x64;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x1F;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x01;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x20;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x20;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q multiplier ==========
void IMult (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x21;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x22;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q multiplier ==========
void QMult (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x23;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x24;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== Q multiplier ==========
void RampRate (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x25;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x80;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//======== QDAC ==========
void QDAC (void){
int bit_ctr;
unsigned int value=0;
WR1;
////////Adress/////////
value = 0x26;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
////////Adress/////////
value = 0x27;
for(bit_ctr=0;bit_ctr<6;bit_ctr++){
  if(value & 0x20)
  {
    digitalWrite(Adress_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Adress_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
WR0;
////////Data/////////
value = 0x00;
for(bit_ctr=0;bit_ctr<8;bit_ctr++){
  if(value & 0x80)
  {
    digitalWrite(Data_pin[bit_ctr],HIGH);
  }
  else
  {
    digitalWrite(Data_pin[bit_ctr],LOW);
  }
  delay(10); value = (value << 1); 
}
UCLK0;
delay(10);
UCLK1;
WR1;
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
