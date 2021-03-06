#include <TimerOne.h>

int row_pin[] = {22, 23, 24, 25, 26, 27, 28, 29};
int col_pin[] = {32, 33, 34, 35, 36, 37, 38, 39};

int led[][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 0, 0, 1, 1, 1},
                {1, 1, 0, 0, 0, 0, 1, 1},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {0, 0, 1, 1, 1, 1, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 0}};
int i = 0;
int pos = 0;

void setup() {
  int i;
  for(i = 0; i < 8; i++) pinMode(row_pin[i], OUTPUT);
  for(i = 0; i < 8; i++) pinMode(col_pin[i], OUTPUT);
  for(i = 0; i < 8; i++) digitalWrite(row_pin[i], LOW);
  for(i = 0; i < 8; i++) digitalWrite(col_pin[i], HIGH);
  Timer1.initialize(300000);
  Timer1.attachInterrupt(blink);
}

void loop() {
  int row = (i + pos) % 8;
  
  digitalWrite(row_pin[i], HIGH);
  for(int j = 0; j < 8; j++)
    digitalWrite(col_pin[j], led[row][j]);
  delayMicroseconds(1000);
  digitalWrite(row_pin[i], LOW);
 
  i = (i + 1) % 8;
}

void blink(){
  pos = (pos + 1) % 8;
}
