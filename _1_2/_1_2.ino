int cnt = 0;
int t = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  analogWrite(2, t * 25.5 );
  delay(10);
  cnt = (cnt + 1) % 10;
  if(cnt == 0){
    if(digitalRead(12) == LOW){
      t++;
      if(t == 11) t = 10;
    }
    else {
      t--;
      if(t == -1) t = 0;
    }
  }
}
