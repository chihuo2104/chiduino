#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define AP_ssid   "WIFINAme" //这里改成你的设备当前环境下要连接的接入点名字
#define password  "passw0rd" //这里改成你的设备当前环境下要连接的接入点密码

#define LED 2

ESP8266WebServer server(80);
 
int i = 0;    //用来判定连接是否超时的累加量

void homepage () {
  // while (Serial.available() == 0) {}     //wait for data available
  // String teststr = Serial.readString();  //read until timeout
  // teststr.trim();
  server.send(200, "text/html;charset=utf8", "你干嘛嗨嗨哎哟");
  Serial.println("cxk");
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  // server.send(200, "text/html;charset=utf8", "你是一个一个一个啊啊啊啊啊啊啊啊啊啊啊啊啊啊<br><h1>Arduino返回：" + teststr + "</h1>");
}

void setup() {
  Serial.begin(9600);  // 启动串口通讯，波特率设置为9600

  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  //     delay(500);
  //     digitalWrite(LED_PIN,LOW);
  delay(500);

  Serial.println("Start Connection");
  
  //调用 WiFi.begin()函数，开始连接接入点
  WiFi.begin(AP_ssid, password);
  Serial.print("Connecting to");
  Serial.print(AP_ssid);
  
  //这里的循环用来判断是否连接成功的。连接过程中每隔500毫秒会检查一次是否连接成功，，并打一个点表示正在连接中
  //连接成功后会给出提示，但是若60秒后还是没有连接上，则会提示超时
  while (WiFi.status() != WL_CONNECTED) {
    i++;
    delay(500);
    Serial.print(".");
    if (i > 120) { //60秒后如果还是连接不上，就判定为连接超时
      Serial.print("Connect Failed!");
      break;
    }
  }
  
  Serial.println("Connect Successful!");
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
 
  //初始化WebServer
  server.on("/", homepage);
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop() {
  server.handleClient();
}

// #define LED_PIN 2
// void setup()
// {
//     pinMode(LED_PIN,OUTPUT);
// }
// void loop()
// {
//     digitalWrite(LED_PIN,HIGH);
//     delay(500);
//     digitalWrite(LED_PIN,LOW);
//     delay(500);
// }