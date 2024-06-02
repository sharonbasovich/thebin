// Now turn this trash into treasure!
#include <LiquidCrystal.h>

#define VERT_PIN 26
#define HORZ_PIN 27
#define SEL_PIN  17
#define BUTTON 14
int on = 1; 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  //pinMode(POWER, OUTPUT);
  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);
  pinMode(BUTTON, INPUT);
  lcd.begin(16, 2);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation
  //digitalWrite(POWER, HIGH);
  int vert = analogRead(VERT_PIN);
  int horz = analogRead(HORZ_PIN);
  vert /= 511;
  vert--;
  horz /= -511;
  horz++;
  bool buttonPressed = digitalRead(BUTTON) == LOW;
  bool selPressed = digitalRead(SEL_PIN) == LOW;
  lcd.clear();
  if (buttonPressed == 0) {
    on *= -1;
  }
  
  if (on == 1) {
    lcd.display();
  } else {
    lcd.noDisplay();
  }

  lcd.setCursor(0, 0);
  lcd.print("Y: ");
  lcd.print(vert);
  lcd.setCursor(0, 1);
  lcd.print("X: ");
  lcd.print(horz);
  //Serial1.pri/ntln(horz);
  //Serial1.println(selPressed);
  //Serial1.println(buttonPressed);
  delay(500);
  // horz goes from 0 (right) to 1023 (left)
  // vert goes from 0 (bottom) to 1023 (top)
  // selPressed is true is the joystick is pressed
}