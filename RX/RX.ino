#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int data;
int sum = 0;
double avg, V;

void setup() {
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  Serial1.begin(9600);
  //Serial.begin(9600);
}

void loop() {
  if(Serial1.available() > 0){
    data = Serial1.parseInt();     //정수형으로 읽음
    //Serial.print(data);
    //Serial.println();
    sum += data;                    //데이터 합산
  }
  if(data == 2500)                  //시작부분이면 sum 초기화
    sum = 0;

  if(data == 2000 || data == 3000){ //입력을 마쳤으면
    lcd.clear();                    //화면 지우고
    if(data == 2000){               //2번 스위치
      lcd.print("photo transistor");
      avg = (sum-2000) / 5.0;       //마지막에 더해진 값 삭제 후 평균
    }
    else{                           //3번 스위치
      lcd.print("Cds");
      avg = (sum-3000) / 5.0;       //마지막에 더해진 값 삭제 후 평균
    }
    V = avg * 5.0 / 1024;           //전압
    data = sum = 0;                 //data와 sum 초기화
    lcd.setCursor(0, 1);            //아래줄에
    lcd.print(avg);                 //평균
    lcd.print(" ");
    lcd.print(V);                   //전압
    lcd.print("V");
  }
}
