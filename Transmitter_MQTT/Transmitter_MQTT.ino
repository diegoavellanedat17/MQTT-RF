#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include "config_values.h"

const int pinCE = 9;
const int pinCSN = 10;
const int button=8;
RF24 radio(pinCE, pinCSN);
bool sended=false;
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

char dataON[16]="L1:ON";
char dataOFF[16]="L1:OFF";
 
void setup(void)
{
   pinMode(button,INPUT);
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(pipe);
   radio.write(dataOFF, sizeof dataOFF);
}
 
void loop(void)
{
  if(digitalRead(button)==HIGH){
    Serial.println("Pressed");
    sended= radio.write(dataON, sizeof dataON);
  }
  if(sended==true){
    sended=false;
    Serial.println("correctly received");
    Serial.println(key);
  }
   delay(1000);
}
