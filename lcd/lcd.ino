#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int y = 0;
int cnt = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop() {
  lcd.setCursor(0, y);
  for(int i = 0; i < (cnt+y)%16+1; i++)
    lcd.print("*");
    
  y = (y + 1) % 2;

  if(y == 0){
    cnt = cnt % 16 + 1;
    delay(500);
    lcd.clear();
  }
}
