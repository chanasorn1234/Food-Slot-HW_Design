int bit0 = 2;
int bit1 = 3;
int bit2 = 4;
int bit3 = 5;
int bit4 = 6;
int cmd = 7;
int statemoney = false;
void setup() {
  Serial.begin(115200);
  pinMode(bit0,INPUT);
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  pinMode(bit3,INPUT);
  pinMode(bit4,INPUT);
  pinMode(cmd,OUTPUT);

}

void loop() {
 while(statemoney == false){
  statemoney = true;
  delay(1000);
 }
 digitalWrite(cmd,HIGH);
 int digit0 = digitalRead(bit0);
 int digit1 = digitalRead(bit1);
 int digit2 = digitalRead(bit2);
 int digit3 = digitalRead(bit3);
 int digit4 = digitalRead(bit4);
 while(digit4 == LOW && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
   digit0 = digitalRead(bit0);
   digit1 = digitalRead(bit1);
   digit2 = digitalRead(bit2);
   digit3 = digitalRead(bit3);
   digit4 = digitalRead(bit4);
  Serial.println("Wait Reasult");
  delay(1000);
 }

  if(digit4 == LOW && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ข้าวผัด");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวผัดกะเพรา");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ราดหน้าชายสี่");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
    Serial.println("ต้มยำกุ้ง");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
    Serial.println("พิซซ่า");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวต้มเป็ด");
  }
  else if(digit4 == LOW && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("โอริโอ 10 บาท");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("บะหมี่เกี๋ยวชายห้า");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("Jakpot");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ส้มตำ");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ส้มตำไม่ใส่มะละกอ");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
    Serial.println("ข้าวผัดไม่ใส่ข้าว");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ข้าวผัดใส่เส้นใหญ่");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวผัดใส่เส้นเล็ก");
  }
  else if(digit4 == LOW && digit3 == HIGH && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("คอหมูย่าง");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("น้ำตก");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("น้ำขึ้น");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ข้าวผัดปู");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("หอยนางรม");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == LOW ){
    Serial.println("กุ้งเผา");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ปลาสลิดบางบ่อ");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == LOW ){
    Serial.println("ปลาช่อนนึ่งมะนาว");
  }
  else if(digit4 == HIGH && digit3 == LOW && digit2 == HIGH && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ก๋วยเตี๋ยวตราอิ่มเจริญ");
  }
  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == LOW ){
    Serial.println("นมสด");
  }
  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == LOW && digit0 == HIGH ){
    Serial.println("ทุเรียนทอด");
  }
  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == LOW ){
    Serial.println("หมูแดดเดียว");
  }
  else if(digit4 == HIGH && digit3 == HIGH && digit2 == LOW && digit1 == HIGH && digit0 == HIGH ){
    Serial.println("ผมอ่ะอืมม");
  }
delay(1000);
}
