#include <LiquidCrystal.h>
#define BUTTON_PIN0 39
#define BUTTON_PIN2 41
#define BUTTON_PIN3 43
#define BUTTON_PIN4 45
#define BUTTON_PIN5 47
#define BUTTON_PIN6 49
#define BUTTON_PIN7 51
#define BUTTON_PIN1 53

LiquidCrystal lcd(11, 12, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(BUTTON_PIN0, INPUT_PULLUP);
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  pinMode(BUTTON_PIN7, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  lcd.print("balls");
  checkPush(BUTTON_PIN7);
  checkPush(BUTTON_PIN6);
  checkPush(BUTTON_PIN5);
  checkPush(BUTTON_PIN4);
  checkPush(BUTTON_PIN3);
  checkPush(BUTTON_PIN2);
  checkPush(BUTTON_PIN1);
  checkPush(BUTTON_PIN0);
}

void checkPush(int pinNumber){
  int buttonPushed = digitalRead(pinNumber);
  if (buttonPushed == HIGH){
    lcd.print(pinNumber);
    delay(100);
  }
  else{}
}
