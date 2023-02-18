#define BUTTON_PIN0 7
#define BUTTON_PIN2 8
#define BUTTON_PIN3 9
#define BUTTON_PIN4 10
#define BUTTON_PIN5 11
#define BUTTON_PIN6 22
#define BUTTON_PIN7 30
#define BUTTON_PIN1 42



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
    Serial.println(pinNumber);
  }
  else{}
}
