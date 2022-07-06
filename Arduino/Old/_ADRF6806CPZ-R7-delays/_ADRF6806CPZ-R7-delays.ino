#define clk0 digitalWrite(4,LOW)
#define clk1 digitalWrite(4,HIGH)
#define dat0 digitalWrite(3,LOW)
#define dat1 digitalWrite(3,HIGH)
#define le0 digitalWrite(5,LOW)
#define le1 digitalWrite(5,HIGH)
#define _0 false;
#define _1 true;

int DM = 0x01; // DIVIDE MODE R0
int IDR = 0x38; // INTEGER DIVIDE RATIO R0


int MDR = 0x600; // MODULUS DIVIDE RATIO R1


int FDR = 0x00; // FRACTIONAL DIVIDE RATIO R2


int DI_MAG = 0x00; // DITHER MAGNITUDE R3
int DI_E = 0x00; // DITHER ENABLE R3
int DI_RE = 0x01; // DITHER RESTART VALUE R3


int OUT_MUX = 0x03; // OUPUT MUX SOURCE R4
int IN_REF = 0x03; // INPUT REF PATH SOURCE R4
int CH_P_REF = 0x00; // CHARGE PUMP REF R4
int PFD_PHASE = 0x01; // PFD PHASE OFFSET POLARITY R4
int PFD_PHASE_MP = 0x06; // PFD PHASE OFFSET MULTIPLAYER VALUE R4
int CP_CUR = 0x01; // CHARGE PUMP CURRENT MULTIPLAYER R4
int CP_CNTL = 0x01; // CP CNTL SRC R4
int CP_CONTROL = 0x03; // CHARGE PUMP CONTROL R4
int PFD_SENSE = 0x00; // PFD EDGE SENSETIVITY R4
int PFD_ANTI = 0x00; // PFD ANTI-BLACKLASH DELAY R4


int DEMODE_BIAS_EN = 0x01; // DEMODE BIAS ENABLE R5
int LPM_EN = 0x00; // LOW POWER MODE ENABLE R5
int LO_IN_OUT_CTRL = 0x00; // LO IN/OUT CTRL R5
int LO_OUT_EN = 0x00; // LO OUTPUT DRIVER ENABLE R5


int CP_EN = 0x01; // CHARGE PUMP ENABLE R6
int three_EN = 0x01; // 3.3V SWITCH ENABLE R6
int VCO_LDO_EN = 0x01; // VCO LDO ENABLE R6
int VCO_EN = 0x01; // VCO ENABLE R6
int VCO_SWITCH = 0x00; // VCO SWITCH R6
int VCO_AMP = 0x08; // VCO AMPLITUDE R6
int VCO_BS_CSR = 0x00; // VCO_BS_CSR R6
int VCO_BAND_SEL = 0x20; // VCO BAND SELECT R6


int DIV_AB_CNTRL = 0x00; // DIV A/B CONTROL R7
int DIV_SEL = 0x00; // DIVIDER SELECT R7
int OUT_DIV_CNTRL = 0x00; // OUTPUT DIV CONTROL R7


///////////////////========Register 0—Integer Divide Control==========///////////////////////////////
void R0 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 13==========//
  for (i = 0; i < 13; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========DIVIDE MODE==========//
  if (DM == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========INTEGER DIVIDE RATIO==========//
  value = IDR;
  for(bit_ctr=0;bit_ctr<7;bit_ctr++)   
  {  
    if(value & 0x40)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========CONTROL BITS==========//
  value = 0x00;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 1—Modulus Divide Control==========///////////////////////////////
void R1 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 13==========//
  for (i = 0; i < 10; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========MODULUS DIVIDE RATIO==========//
  value = MDR;
  for(bit_ctr=0;bit_ctr<11;bit_ctr++)   
  {  
    if(value & 0x400)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========CONTROL BITS==========//
  value = 0x01;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 2—Fractional Divide Control==========////////////////////////////
void R2 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 13==========//
  for (i = 0; i < 10; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========FRACTIONAL DIVIDE RATIO==========//
  value = FDR;
  for(bit_ctr=0;bit_ctr<11;bit_ctr++)   
  {  
    if(value & 0x400)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========CONTROL BITS==========//
  value = 0x02;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 3—Σ-Δ Modulator Dither Control==========/////////////////////////
void R3 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res==========//
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  //========DITHER MAGNITUDE==========//
  value = DI_MAG;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========DITHER ENABLE==========//
  if (DI_E == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10); 
  //========DITHER RESTART VALUE==========//
  value = DI_RE;
  for(bit_ctr=0;bit_ctr<17;bit_ctr++)   
  {  
    if(value & 0x10000)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }   
  //========CONTROL BITS==========//
  value = 0x03;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 4—Charge Pump, PFD, and Reference Path Control ==========////////
void R4 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========OUPUT MUX SOURCE==========//
  value = OUT_MUX;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========INPUT REF PATH SOURCE==========//
  value = IN_REF;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }  
  //========CHARGE PUMP REF==========//
  if (CH_P_REF == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10); 
  //========PFD PHASE OFFSET POLARITY==========//
  if (PFD_PHASE == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);   
  //========PFD PHASE OFFSET MULTIPLAYER VALUE==========//
  value = PFD_PHASE_MP;
  for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
  {  
    if(value & 0x10)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========CHARGE PUMP CURRENT MULTIPLAYER==========//
  value = CP_CUR;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========CP CNTL SRC==========//
  if (CP_CNTL == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========CHARGE PUMP CONTROL==========//
  value = CP_CONTROL;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========PFD EDGE SENSETIVITY==========//
  value = PFD_SENSE;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========PFD ANTI-BLACKLASH DELAY==========//
  value = PFD_ANTI;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }                 
  //========CONTROL BITS==========//
  value = 0x04;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 5—LO Path and Demodulator Control==========/////////////////////
void R5 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 16==========//
  for (i = 0; i < 16; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========DEMODE BIAS ENABLE==========//
  if (DEMODE_BIAS_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========res==========//
    dat1; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  //========LOW POWER MODE ENABLE==========//
  if (LPM_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========LO IN/OUT CTRL==========//
  if (LO_IN_OUT_CTRL == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========LO OUTPUT DRIVER ENABLE==========//
  if (LO_OUT_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);         
  //========CONTROL BITS==========//
  value = 0x05;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 6—VCO Control and Enables==========//////////////////////////////
void R6 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 3==========//
  for (i = 0; i < 3; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========CHARGE PUMP ENABLE==========//
  if (CP_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========3.3V SWITCH ENABLE==========//
  if (three_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========VCO LDO ENABLE==========//
  if (VCO_LDO_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========VCO ENABLE==========//
  if (VCO_EN == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========VCO SWITCH==========//
  if (VCO_SWITCH == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========VCO AMPLITUDE==========//
  value = VCO_AMP;
  for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
  {  
    if(value & 0x20)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========VCO BS CSR==========//
  if (VCO_BS_CSR == 1){
    dat1; delay(10);
  }
  else{
    dat0; delay(10);
  }
  clk1; delay(10);
  clk0; delay(10);
  //========VCO BAND SELECT==========//
  value = VCO_BAND_SEL;
  for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
  {  
    if(value & 0x20)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }                  
  //========CONTROL BITS==========//
  value = 0x06;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////
///////////////////========Register 7—LO Divider Control ==========//////////////////////////////////
void R7 (void){
char i = 0;  
char bit_ctr;
unsigned int value = 0;
  //========res 16==========//
  for (i = 0; i < 14; i++){
    dat0; delay(10);
    clk1; delay(10);
    clk0; delay(10);
  }
  //========DIV A/B CONTROL==========//
  value = DIV_AB_CNTRL;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  } 
  //========DIVIDER SELECT==========//
  value = DIV_SEL;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========OUTPUT DIV CONTROL==========//
  value = OUT_DIV_CNTRL;
  for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
  {  
    if(value & 0x02)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }
  //========RES==========//
  dat1; delay(10);
  clk1; delay(10);
  clk0; delay(10);                 
  //========CONTROL BITS==========//
  value = 0x07;
  for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
  {  
    if(value & 0x04)
    {
    dat1; delay(10);
    }
    else
    {
    dat0; delay(10);
    }
  value = (value << 1);  // shift next bit into MSB..
  clk1; delay(10);   
  clk0; delay(10);  
  }    
}    
//////////////////////////////////////////////////////////////////////////////

void REG_SEQ (void){
le0; delay(10);
R0();
le1; delay(10);
le0; delay(10);
R1();
le1; delay(10);
le0; delay(10);
R2();
le1; delay(10);
le0; delay(10);
R3();
le1; delay(10);
le0; delay(10);
R4();
le1; delay(10);
le0; delay(10);
R5();
le1; delay(10);
le0; delay(10);
R6();
le1; delay(10);
le0; delay(10);
R7();
le1; delay(10);
}
      
void setup() {
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);  
le0; delay(10);
dat0; delay(10);
clk0; delay(10);
REG_SEQ();
}

void loop() {
 //REG_SEQ;
 //delay(1000);
}
