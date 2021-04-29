#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

int led=2;
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
char data[16];
// Toogle Switch 
int ToggleSwitch=3; 
int switch_state=0;
int last_state=0;
 void setup(void)
{
  pinMode(ToggleSwitch,INPUT_PULLUP);
   pinMode(led,OUTPUT); 
   digitalWrite(led,LOW);
   Serial.begin(9600);
   Serial.println("Esperando datos");
   radio.begin();
   radio.openReadingPipe(1,pipe);
   radio.startListening();
}
 
void loop(void)
{
  // Read de switch
  
  //switch_state=digitalRead(ToggleSwitch);
  
   if (radio.available()){
      radio.read(data, sizeof data); 
      Serial.println(data);

   }

  
   delay(5);

}
