#include<SoftwareSerial.h>
int bit0 = 2;
int bit1 = 3;
int bit2 = 4;
int bit3 = 5;
//int bit4 = 6;
int cmd = 7;
int recive_cmd_fpga = 8;
int statemoney = false;
SoftwareSerial ArduinoSerial(10,11); //RX,TX
void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(4800);
  pinMode(bit0,INPUT);
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  pinMode(bit3,INPUT);
//  pinMode(bit4,INPUT);
  pinMode(cmd,OUTPUT);
  pinMode(recive_cmd_fpga,INPUT);

}

void loop() {
 while(statemoney == false){ //นับเหรียญจากเครื่องยอดเหรียญ
  statemoney = true;
  delay(1000);
 }
 digitalWrite(cmd,HIGH); // stateส่งไปfpga
 int digit0 = digitalRead(bit0);
 int digit1 = digitalRead(bit1);
 int digit2 = digitalRead(bit2);
 int digit3 = digitalRead(bit3);
// int digit4 = digitalRead(bit4);
int state_recive = digitalRead(recive_cmd_fpga);
while(state_recive == LOW){//รอค่าจาก fpga
    state_recive = digitalRead(recive_cmd_fpga);
    Serial.println("Wait Reasult");
    delay(1000);
}
// while(digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){//รอค่าจาก fpga
//   digit0 = digitalRead(bit0);
//   digit1 = digitalRead(bit1);
//   digit2 = digitalRead(bit2);
//   digit3 = digitalRead(bit3);
//   digit4 = digitalRead(bit4);
//  Serial.println("Wait Reasult");
//  delay(1000);
// }
digitalWrite(cmd,LOW); // stateส่งไปfpga
   if(digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("ส้มตำ");
    ArduinoSerial.print(10);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ข้าวผัด");
    ArduinoSerial.print(1);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวผัดกะเพรา");
    ArduinoSerial.print(2);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ราดหน้าชายสี่");
    ArduinoSerial.print(3);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
    Serial.println("ต้มยำกุ้ง");
    ArduinoSerial.print(4);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
    Serial.println("พิซซ่า");
    ArduinoSerial.print(5);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวต้มเป็ด");
    ArduinoSerial.print(6);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("โอริโอ 10 บาท");
    ArduinoSerial.print(7);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("บะหมี่เกี๋ยวชายห้า");
    ArduinoSerial.print(8);
    ArduinoSerial.print("\n");
  }
  else if(digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("Jakpot");
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
