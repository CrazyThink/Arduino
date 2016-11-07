int sw1 = 0;
int sw2 = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial1.begin(9600);
}

void loop() {
  if((digitalRead(2) == LOW || digitalRead(3) == LOW) && sw1 == 0 && sw2 == 0){
    if(digitalRead(2) == LOW) sw1 = 1;
    if(digitalRead(3) == LOW) sw2 = 1;
    Serial1.print(2500), Serial1.print(' '); //시작 부분을 2500으로 알림
    for(int i = 0; i < 5; i++){
      int data;
      if(sw1 == 1) data = analogRead(A0); 
      if(sw2 == 1) data = analogRead(A1); 
      
      Serial1.print(data);                                   //데이터 전송
      Serial1.print(' ');                                    //공백을 전송해줘야 parseInt가 제대로 읽음
      if(i == 4){                                           //마지막에 어떤 스위치인지 알려줌
        if(sw1 == 1) Serial1.print(2000);       //2번은 2000
        if(sw2 == 1) Serial1.print(3000);       //3번은 3000
      }
      delay(200); //200ms 휴식
    }
  }
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH)      //아무것도 안눌리면 cnt 초기화
    sw1 = 0, sw2 = 0;
}
