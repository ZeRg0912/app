#define clk0 digitalWrite(5,LOW)
#define clk1 digitalWrite(5,HIGH)
#define dat0 digitalWrite(4,LOW)
#define dat1 digitalWrite(4,HIGH)
#define le0 digitalWrite(3,LOW)
#define le1 digitalWrite(3,HIGH)
#define sdo digitalRead(2)
#define _0 false;
#define _1 true;

int filter_freq = 0x0F;
int preamplifer = 0x00;
int postamplifer = 0x00;
int vga_gain = 0x00;

int data = 0x00;
int check = 0xF0;

////////////////////////////////////////////////
void Write_reg (void){
char bit_ctr;
unsigned int value = 0;
le0;
//========register==========
   //////WRITE_BIT////////  
   dat1;
   clk1;   
   clk0;
   dat0;     
   //////VGA_GAIN////////
   value = vga_gain;
   if(value == 1)
   {
   dat1;
   }
   else
   {
   dat0;
   }
   clk1;
   clk0;
   dat0;
   //////POSTAMPLIFER////////
   value = postamplifer;
   if(value == 1)
   {
   dat1;
   }
   else
   {
   dat0;
   }
   clk1;
   clk0;
   dat0;
   //////PREAMPLIFER////////
   value = preamplifer;
   if(value == 1)
   {
   dat1;
   }
   else
   {
   dat0;
   }
   clk1;
   clk0;
   dat0;    
   //////FILTER_FREQ 5bit////////  
   value = filter_freq;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x10)
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
   le1;
}        
///////////////////////////////////////////////
void Read_reg (void){
char bit_ctr;
unsigned int value = 0;
le0;
//========register==========
   //////READ_REG////////  
   dat0;
   clk1;   
   clk0;
   //////READ_DATA 8bit//////// 
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(sdo == HIGH)
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
   if (data != check){
    Serial.print("/"); 
    Serial.print(data, HEX);
    Serial.print("/");
    digitalWrite(13, HIGH);    
   }
le1;
  data = 0x00;   
}    
///////////////////////////////////////////////*/
      
void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(2, INPUT);
pinMode(3, OUTPUT);
pinMode(13, OUTPUT); 
Write_reg();
}

void loop() {
  Read_reg();
  delay(10);
}
