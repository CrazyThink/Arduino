int pins[] = {4, 5, 6, 7, 8, 9, 10, 11};
int on = 0;
int sw = 1;

void setup() {
  pinMode(2, INPUT);
  for(int i = 0; i < 8; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  attachInterrupt(0, move, FALLING);
}

void loop() {
  digitalWrite(pins[on], HIGH);
  delay(200);
  digitalWrite(pins[on], LOW);
  on = (on + sw + 8) % 8;
}

void move(){
  sw *= -1;
}
