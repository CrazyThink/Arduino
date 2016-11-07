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
  int seg_pins[] = {22, 23, 24, 25, 26, 27, 28, 29};
  int sel_pins[] = {14, 15, 16, 17, 18, 19};
  int com[2] = {0};
  int sel = 0;

void setup() {
  pinMode(2, INPUT);
  for(int i = 0; i < 8; i++) pinMode(seg_pins[i],OUTPUT);
  for(int i = 0; i < 2; i++) pinMode(sel_pins[i],OUTPUT);
  for(int i = 0; i < 8; i++) digitalWrite(seg_pins[i], LOW);
  for(int i = 0; i < 2; i++) digitalWrite(sel_pins[i], HIGH);
  attachInterrupt(0, move, FALLING);
}
void loop() {
  if(com[sel] == 10){ //자리올림
    com[sel] = 0;
    if(sel < 1) com[sel+1]++;
  }
  
  digitalWrite(sel_pins[sel], LOW);
  for(int j = 0; j < 8; j++)
    digitalWrite(seg_pins[j], seg[com[sel]][j]);
  delayMicroseconds(2500);
  digitalWrite(sel_pins[sel], HIGH);
  
  sel = (sel + 1) % 2; //4개만 사용
}
void move(){
  com[0]++;
}

