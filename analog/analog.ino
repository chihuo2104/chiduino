#include <math.h>
#define TEMP 0
double Thermister(int RawADC) {
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp;
}
void setup() {
  // put your setup code here, to run once:
  // pinMode(TEMP, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Thermister(analogRead(0))); // display Fahrenheit Serial.println("c"); delay(500);
  delay(500);
}
