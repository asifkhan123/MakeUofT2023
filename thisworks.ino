#include <LiquidCrystal.h>
#define R0 23
#define R1 25
#define R2 27
#define R3 29
#define R4 31
#define R5 33
#define R6 35
#define R7 37
#define C0 36
#define C1 34
#define C2 32
#define C3 30
#define C4 28
#define C5 26
#define C6 24
#define C7 22

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPins[] = { 41, 50, 39, 52, 43, 45, 47, 49, 51, 53 };
int buttonStates[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
String notes[] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "G", "A", "B", "C" };
byte notes_lcd[10][8] = {
  { B00111110, B01111110, B01100000, B01100000, B01100000, B01100000, B01111110, B00111110 },  //C
  { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 },  //C#(NONE)
    { B01111000, B01111100, B01100110, B01100110, B01100110, B01100110, B01111100, B01111000 },  //D
    { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 },  //D#(NONE)
    { B01111110, B01111110, B01100000, B01111110, B01111110, B01100000, B01111110, B01111110 },  //E
    { B01100000, B01100000, B01100000, B01111100, B01111100, B01100000, B01111100, B01111100 },  //F
    {B00011100, B01111100, B01100100, B01100000, B01101110, B01100100, B01111100, B0011100},    //G
    { B01100110, B01100110, B01111110, B01111110, B01100110, B01100110, B00111100, B00011000 },  //A
    { B01111100, B01100110, B01100110, B01111100, B01111110, B01100110, B01100110, B00111110 },  //B
    { B00111110, B01111110, B01100000, B01100000, B01100000, B01100000, B01111110, B00111110 }  //C
};
String chords[] = { "C major", "C minor", "D major", "D minor", "E major", "E minor" };
int numButtons = 10;
//int playingNotes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int numPlayingNotes = 0;

// byte alphabet[8][8] = { { B00011000, B00111100, B01100110, B01100110, B01111110, B01111110, B01100110, B01100110 },    //A
//                         { B00111110, B01100110, B01100110, B01111110, B00111110, B01100110, B01100110, B00111110 },    //B
//                         { B01111100, B01111110, B00000110, B00000110, B00000110, B00000110, B01111110, B01111100 },    //C
//                         { B00011110, B00111110, B01100110, B01100110, B01100110, B01100110, B00111110, B00011110 },    //D
//                         { B01111110, B01111110, B00000110, B01111110, B01111110, B00000110, B01111110, B01111110 },    //E
//                         { B01111110, B01111110, B00000110, B00111110, B00111110, B00000110, B00000110, B00000110 },    //F
//                         { B00011100, B00111110, B00100110, B00000110, B01110110, B00100110, B00111110, B00011100 },    //G
//                         { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 } };  //NONE

//FLIPPED VERSION
byte alphabet[8][8] = {
  { B01100110, B01100110, B01111110, B01111110, B01100110, B01100110, B00111100, B00011000 },  //A
  { B01111100, B01100110, B01100110, B01111100, B01111110, B01100110, B01100110, B00111110 },  //B
  { B00111110, B01111110, B01100000, B01100000, B01100000, B01100000, B01111110, B00111110 },  //C
  { B01111000, B01111100, B01100110, B01100110, B01100110, B01100110, B01111100, B01111000 },  //D
  { B01111110, B01111110, B01100000, B01111110, B01111110, B01100000, B01111110, B01111110 },  //E
  { B01100000, B01100000, B01100000, B01111100, B01111100, B01100000, B01111100, B01111100 },  //F
  { B00111000, B01111100, B01100100, B01101110, B01100000, B01100000, B01111100, B00111000 },  //G
  { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 }   //NONE
};

void setup() {
  // set up the devices needed
  Serial.begin(9600);
  lcd.begin(16, 2);
  // set up the "piano keys"
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  int buttonStates[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(C0, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);


  digitalWrite(R0, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  digitalWrite(R5, HIGH);
  digitalWrite(R6, HIGH);
  digitalWrite(R7, HIGH);

  digitalWrite(C0, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C4, LOW);
  digitalWrite(C5, LOW);
  digitalWrite(C6, LOW);
  digitalWrite(C7, LOW);

  //pinMode(22, OUTPUT);
  //pinMode(23, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Notes:");

  lcd.setCursor(0, 1);
  lcd.print("Chord:");
}


void SelectRow(int row) {
  if (row == 1) digitalWrite(R0, LOW);
  else digitalWrite(R0, HIGH);
  if (row == 2) digitalWrite(R1, LOW);
  else digitalWrite(R1, HIGH);
  if (row == 3) digitalWrite(R2, LOW);
  else digitalWrite(R2, HIGH);
  if (row == 4) digitalWrite(R3, LOW);
  else digitalWrite(R3, HIGH);
  if (row == 5) digitalWrite(R4, LOW);
  else digitalWrite(R4, HIGH);
  if (row == 6) digitalWrite(R5, LOW);
  else digitalWrite(R5, HIGH);
  if (row == 7) digitalWrite(R6, LOW);
  else digitalWrite(R6, HIGH);
  if (row == 8) digitalWrite(R7, LOW);
  else digitalWrite(R7, HIGH);
}

void SelectCol(int Col) {
  if (Col == 1) digitalWrite(C0, HIGH);
  else digitalWrite(C0, LOW);
  if (Col == 2) digitalWrite(C1, HIGH);
  else digitalWrite(C1, LOW);
  if (Col == 3) digitalWrite(C2, HIGH);
  else digitalWrite(C2, LOW);
  if (Col == 4) digitalWrite(C3, HIGH);
  else digitalWrite(C3, LOW);
  if (Col == 5) digitalWrite(C4, HIGH);
  else digitalWrite(C4, LOW);
  if (Col == 6) digitalWrite(C5, HIGH);
  else digitalWrite(C5, LOW);
  if (Col == 7) digitalWrite(C6, HIGH);
  else digitalWrite(C6, LOW);
  if (Col == 8) digitalWrite(C7, HIGH);
  else digitalWrite(C7, LOW);
}

void Set_LED_in_Active_Row(int column, int state) {
  if (column == 1) digitalWrite(C0, state);
  if (column == 2) digitalWrite(C1, state);
  if (column == 3) digitalWrite(C2, state);
  if (column == 4) digitalWrite(C3, state);
  if (column == 5) digitalWrite(C4, state);
  if (column == 6) digitalWrite(C5, state);
  if (column == 7) digitalWrite(C6, state);
  if (column == 8) digitalWrite(C7, state);
}

void setColumns(byte b, int erasing) {
  // Depending on the
  if (!erasing) {
    digitalWrite(C0, (b >> 0) & 0x01);  // Get the 1st bit: 10000000
    digitalWrite(C1, (b >> 1) & 0x01);  // Get the 2nd bit: 01000000
    digitalWrite(C2, (b >> 2) & 0x01);  // Get the 3rd bit: 00100000
    digitalWrite(C3, (b >> 3) & 0x01);  // Get the 4th bit: 00010000
    digitalWrite(C4, (b >> 4) & 0x01);  // Get the 5th bit: 00001000
    digitalWrite(C5, (b >> 5) & 0x01);  // Get the 6th bit: 00000100
    digitalWrite(C6, (b >> 6) & 0x01);  // Get the 7th bit: 00000010
    digitalWrite(C7, (b >> 7) & 0x01);  // Get the 8th bit: 00000001
  } else {
    digitalWrite(C0, LOW);  // Get the 1st bit: 10000000
    digitalWrite(C1, LOW);  // Get the 2nd bit: 01000000
    digitalWrite(C2, LOW);  // Get the 3rd bit: 00100000
    digitalWrite(C3, LOW);  // Get the 4th bit: 00010000
    digitalWrite(C4, LOW);  // Get the 5th bit: 00001000
    digitalWrite(C5, LOW);  // Get the 6th bit: 00000100
    digitalWrite(C6, LOW);  // Get the 7th bit: 00000010
    digitalWrite(C7, LOW);  // Get the 8th bit: 00000001
  }
}

void writeInMatrix(byte b[], int erasing) {
  for (byte i = 0; i < 8; i++) {
    setColumns(b[i], erasing);  // Set the columns for this specific row
    if (!erasing)
      SelectRow(i + 1);
    // Each row and column is set as HIGH and LOW, respectivelly, in a very small time interval
    // Set this delay to 100 to see the multiplexing effect!
    delay(2);
  }
}


void loop() {
  //initalize the number of notes being played
  numPlayingNotes = 0;
  int chordState = 0;
  int buttonStates[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  for (int i = 0; i < numButtons; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);
  }
  lcd.setCursor(7, 0);
  for (int i = 0; i < numButtons; i++) {
    if (buttonStates[i] == HIGH) {
      numPlayingNotes++;
      if (numPlayingNotes > 3) {
        break;
      }
      lcd.print(notes[i]);
      lcd.print(" ");
      writeInMatrix(notes_lcd[i], 0);
    }
  }
  Serial.println(numPlayingNotes);
  if (numPlayingNotes == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Notes:");
    lcd.setCursor(0, 1);
    lcd.print("Chord:");
    writeInMatrix(notes_lcd[1], 0);

  } else if (numPlayingNotes == 3) {
    lcd.setCursor(6, 1);
    if (buttonStates[0] && buttonStates[3] && buttonStates[6]) {
      lcd.print("C minor");
      Serial.println("C minor");
    } else if (buttonStates[0] && buttonStates[4] && buttonStates[6]) {
      lcd.print("C major");
      Serial.println("C major");
    } else if (buttonStates[2] && buttonStates[5] && buttonStates[7]) {
      lcd.print("D minor");
      Serial.println("D minor");
    } else if (buttonStates[4] && buttonStates[6] && buttonStates[8]) {
      lcd.print("E minor");
      Serial.println("E minor");
    } else if (buttonStates[5] && buttonStates[7] && buttonStates[9])
      lcd.print("F major");
    Serial.println("F minor");
  } else {
    //Serial.println("No chords being played");
  }

  // print out the chords being played
  //digitalWrite(22, HIGH);
  //digitalWrite(23, LOW);
  delay(50);
}
