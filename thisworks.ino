#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPins[] = {39, 41, 43, 45, 47, 49, 51, 53};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
int notes[] = {262, 294, 330, 349, 392, 440, 494, 523};
// change the shit above to letter notes
int numButtons = 8;
int playingNotes[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int numPlayingNotes = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  numPlayingNotes = 0;
  for (int i = 0; i < numButtons; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);
    if (buttonStates[i] == HIGH) {
      playingNotes[numPlayingNotes] = notes[i];
      numPlayingNotes++;
      //tone(10, notes[i]);
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Notes:");
  for (int i = 0; i < numPlayingNotes; i++) {
    lcd.print(playingNotes[i]);
    delay(100);
    lcd.clear();
  }

}
