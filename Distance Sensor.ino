#include <NewPing.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
NewPing sonar (9, 10, 50);

void setup() {
  Serial.begin(9600);
  delay(50);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("INCH:    CM: ");

}

void loop() {
  char buf[20];
  int fl = sonar.ping_in();
  int fr = sonar.ping_cm();
  sprintf(buf, " %3d    %3d ", fl, fr);

  lcd.setCursor(1,1);
  lcd.print(buf);
  delay(200);
}