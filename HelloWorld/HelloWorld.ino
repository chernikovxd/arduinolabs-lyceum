#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

char symbol=0;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Меня зовут");
  lcd.setCursor(0, 1);
  lcd.print("Черников");
}

void loop() {
}
