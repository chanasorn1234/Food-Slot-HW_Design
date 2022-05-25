#include<SoftwareSerial.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <MD_UISwitch.h>

const uint16_t WAIT_TIME = 1000;
int bit0 = 2;
int bit1 = 3;
int bit2 = 4;
int bit3 = 5;
//int bit4 = 6;
int cmd = 7;
int recive_cmd_fpga = 8;
int statemoney = false;
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13
#define DATA_PIN  12
#define CS_PIN    9

#define DATA_PIN2  14
#define CLK_PIN2   15
#define CS_PIN2   16

SoftwareSerial ArduinoSerial(10,11); //RX,TX
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
MD_Parola P2 = MD_Parola(HARDWARE_TYPE, DATA_PIN2, CLK_PIN2, CS_PIN2, MAX_DEVICES);
void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(4800);
  P.begin();
  P2.begin();
  pinMode(bit0,INPUT);
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  pinMode(bit3,INPUT);
//  pinMode(bit4,INPUT);
  pinMode(cmd,OUTPUT);
  pinMode(recive_cmd_fpga,INPUT);

}

void loop() {
  P.print("");
  P2.print("");
  statemoney = false;
 while(statemoney == false){ //นับเหรียญจากเครื่องยอดเหรียญ
  statemoney = true;
  delay(1000);
 }
 digitalWrite(cmd,HIGH); // stateส่งไปfpga

int state_recive = digitalRead(recive_cmd_fpga);
while(state_recive == LOW){//รอค่าจาก fpga
    state_recive = digitalRead(recive_cmd_fpga);
    Serial.println("Wait Reasult");
    delay(1000);
}
 int digit0 = digitalRead(bit0);
 int digit1 = digitalRead(bit1);
 int digit2 = digitalRead(bit2);
 int digit3 = digitalRead(bit3);


digitalWrite(cmd,LOW); // stateส่งไปfpga
   if(digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("ส้มตำ");
    P.print("Somtum");
    ArduinoSerial.print(10);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ข้าวผัด");
    P.print("CaoPad");
    ArduinoSerial.print(1);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวผัดกะเพรา");
    P.print("   Pad");
    delay(WAIT_TIME);
    P2.print("Krapow");
    ArduinoSerial.print(2);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ราดหน้าชายสี่");
    P.print(" RadNa");
    ArduinoSerial.print(3);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
    Serial.println("ต้มยำกุ้ง");
    P.print("Tomyum");
    delay(WAIT_TIME);
    P2.print("  Kung");
    ArduinoSerial.print(4);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
    Serial.println("พิซซ่า");
    P.print("  Pizza");
    ArduinoSerial.print(5);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวต้มเป็ด");
    P.print("CaoTom");
    delay(WAIT_TIME);
    P2.print("   Ped");
    ArduinoSerial.print(6);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("โอริโอ 10 บาท");
    P.print("  OREO");
    ArduinoSerial.print(7);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("บะหมี่เกี๋ยวชายห้า");
    P.print("Noodles");
    ArduinoSerial.print(8);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("Jakpot");
    P.print("  MAMA");
    ArduinoSerial.print(9);
    ArduinoSerial.print("\n");
  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
//    Serial.println("ส้มตำ");
//    ArduinoSerial.print(10);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
//    Serial.println("ส้มตำไม่ใส่มะละกอ");
//    ArduinoSerial.print(11);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
//    Serial.println("ข้าวผัดไม่ใส่ข้าว");
//    ArduinoSerial.print(12);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
//    Serial.println("ข้าวผัดใส่เส้นใหญ่");
//    ArduinoSerial.print(13);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
//    Serial.println("ข้าวผัดใส่เส้นเล็ก");
//    ArduinoSerial.print(14);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
//    Serial.println("คอหมูย่าง");
//    ArduinoSerial.print(15);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
//    Serial.println("น้ำตก");
//    ArduinoSerial.print(16);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
//    Serial.println("น้ำขึ้น");
//    ArduinoSerial.print(17);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
//    Serial.println("ข้าวผัดปู");
//    ArduinoSerial.print(18);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
//    Serial.println("หอยนางรม");
//    ArduinoSerial.print(19);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
//    Serial.println("กุ้งเผา");
//    ArduinoSerial.print(20);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
//    Serial.println("ปลาสลิดบางบ่อ");
//    ArduinoSerial.print(21);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
//    Serial.println("ปลาช่อนนึ่งมะนาว");
//    ArduinoSerial.print(22);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
//    Serial.println("ก๋วยเตี๋ยวตราอิ่มเจริญ");
//    ArduinoSerial.print(23);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
//    Serial.println("นมสด");
//    ArduinoSerial.print(24);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
//    Serial.println("ทุเรียนทอด");
//    ArduinoSerial.print(25);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
//    Serial.println("หมูแดดเดียว");
//    ArduinoSerial.print(26);
//    ArduinoSerial.print("\n");
//  }
//  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
//    Serial.println("ผมอ่ะอืมม");
//    ArduinoSerial.print(27);
//    ArduinoSerial.print("\n");
//  }
delay(1000);
}
