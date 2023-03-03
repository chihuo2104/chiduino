// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup()
// {
//   lcd.init();
//   lcd.backlight();
//   lcd.print("114514");
// }

// void loop()
// {
// }

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);  //配置LCD地址及行列
 
// void setup()
// {
//   lcd.init(); //初始化LCD
//   lcd.backlight(); //打开背光
//   Serial.begin(9600);
// }
 
// void loop()
// {
//   lcd.setCursor(0,0);//设置显示位置
//   lcd.print("1");
//   lcd.print("1");
//   lcd.print("4");
//   lcd.print("5");
//   lcd.print("1");
//   lcd.print("4");
//   lcd.print("1");
//   lcd.print("9");
//   lcd.print("1");
//   lcd.print("9");
//   lcd.print("8");
//   lcd.print("1");
//   lcd.print("0");
//   lcd.setCursor(0,1);
//   lcd.print("y");
//   lcd.print("a");
//   lcd.print("j");
//   lcd.print("u");
//   lcd.print("u");
//   lcd.print("s");
//   lcd.print("e");
//   lcd.print("n");
//   lcd.print("p");
//   lcd.print("a");
//   lcd.print("i");
// }

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
