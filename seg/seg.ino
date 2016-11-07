int seg[][8] = {{1, 1, 1, 1, 1, 1, 0, 0},     //0
                {0, 1, 1, 0, 0, 0, 0, 0},     //1
                {1, 1, 0, 1, 1, 0, 1, 0},     //2
                {1, 1, 1, 1, 0, 0, 1, 0},     //3
                {0, 1, 1, 0, 0, 1, 1, 0},     //4
                {1, 0, 1, 1, 0, 1, 1, 0},     //5
                {1, 0, 1, 1, 1, 1, 1, 0},     //6
                {1, 1, 1, 0, 0, 0, 0, 0},     //7
                {1, 1, 1, 1, 1, 1, 1, 0},     //8
                {1, 1, 1, 1, 0, 1, 1, 0} };   //9
  int seg_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  int sel_pins[] = {14, 15, 16, 17, 18, 19};
  int com[4] = {0};
  int sel = 0;

void setup() {
  int i;
  for(int i = 0; i < 8; i++) pinMode(seg_pins[i],OUTPUT);
  for(int i = 0; i < 4; i++) pinMode(sel_pins[i],OUTPUT);
  for(int i = 0; i < 8; i++) digitalWrite(seg_pins[i], LOW);
  for(int i = 0; i < 4; i++) digitalWrite(sel_pins[i], HIGH);
}
void loop() {
  if(com[sel] == 10){ //자리올림
    com[sel] = 0;
    if(sel < 3) com[sel+1]++;
  }
  com[3] %= 6;        //60초이면 0으로
  
  digitalWrite(sel_pins[sel], LOW);
  for(int j = 0; j < 8; j++)
    digitalWrite(seg_pins[j], seg[com[sel]][j]);
  if(sel == 2)         //1초자리에 점 표시
    digitalWrite(9, HIGH);
  delayMicroseconds(2500);
  digitalWrite(9, LOW);//점 제거
  digitalWrite(sel_pins[sel], HIGH);
  
  sel = (sel + 1) % 4; //4개만 사용
  if(sel == 0) com[0]++;
}
