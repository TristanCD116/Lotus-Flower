// IRremote - Version: Latest 
#include <IRremote.hpp>

const int RECPIN = 10;

IRrecv irrecv(RECPIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
}

void loop() {
  if(irrecv.decode(&results)) {
     Serial.println(results.value, HEX);
     irrecv.resume();
    
  }
}
