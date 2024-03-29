#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
//#include "config_values.h"

const int pinCE = 9;
const int pinCSN = 10;
const int buttonON=8;
const int buttonOFF=7;
RF24 radio(pinCE, pinCSN);
bool sended=false;
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

char dataON[16]="L1:ON";
char dataOFF[16]="L1:OFF";
char mensaje[10]="Hola Hola";
 
void setup(void)
{
   pinMode(buttonON,INPUT);
   pinMode(buttonOFF,INPUT);
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(pipe);
   radio.setPALevel(RF24_PA_MAX);   
}
 
void loop(void)
{

    sended= radio.write(mensaje, sizeof mensaje);
    Serial.println("Enviando Paquete");

    if(sended==true){
      sended=false;
      Serial.println("correctly received");
    }
    else{
      
        Serial.println("Notbody Listening");
 
    }
  
  
   delay(2000);
}
