int t = 0;
int sw1 = 0;
int sw2 = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {

  if(t != 0){
    digitalWrite(2, HIGH);
    delay(t);
    digitalWrite(2, LOW);
    delay(10 - t);
  }
  
  if(digitalRead(12) == LOW && sw1 == 0){
     t++;
     if(t == 11) t = 10;
     sw1 = 1;
  }
  if(digitalRead(13) == LOW && sw2 == 0){
     t--;
     if(t == -1) t = 0;
     sw2 = 1;
  }
  if(digitalRead(12) == HIGH)
    sw1 = 0;
  if(digitalRead(13) == HIGH)
    sw2 = 0;
}
