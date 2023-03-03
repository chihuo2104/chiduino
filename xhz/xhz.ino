#define LED 3
void setup () {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

bool xhz = false;

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == "cxk") {
    Serial.println("niganmahaihaiaiyou");
    uint8_t ngm = 0;
    if (xhz == true) {
      xhz = false;
      ngm = LOW;
    } else {
      xhz = true;
      ngm = HIGH;
    }
    digitalWrite(LED, ngm);
  }
}
