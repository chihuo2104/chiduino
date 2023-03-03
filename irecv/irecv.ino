#include <IRremote.hpp>

IRrecv irrecv(2);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn(); // 初始化红外接收器  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode()) {
    // String data = irrecv.decodedIRData.decodedRawData;
    Serial.println(irrecv.decodedIRData.decodedRawData);
    irrecv.resume();    
  }
}
