#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
 
const int pinCE = 9;
const int pinCSN = 10;
const int button=8;
RF24 radio(pinCE, pinCSN);
bool sended=false;
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

char data[16]="Hola mundo" ;
 
void setup(void)
{
   pinMode(button,INPUT);
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(pipe);
}
 
void loop(void)
{
  if(digitalRead(button)==HIGH){
    Serial.println("Presionado");
    sended= radio.write(data, sizeof data);
  }
  if(sended==true){
    sended=false;
    Serial.println("Recivido Correctamente");
  }
   delay(1000);
}
