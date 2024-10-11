int ledPin = 2; // Pin, kam je připojena LED
int dotDuration = 50; // Délka tečky (ms)
int dashDuration = 200; // Délka čárky (ms)
int pauseDuration = dotDuration; // Mezera mezi tečkami a čárkami (stejná jako délka tečky)
int letterPause = dotDuration * 3; // Mezera mezi písmeny (3x délka tečky)
int wordPause = dotDuration * 7; // Mezera mezi slovy (7x délka tečky)
 
void setup() {
  pinMode(ledPin, OUTPUT); // Nastavení LED pinu jako výstupu
  Serial.begin(9600); // Zahájení komunikace se sériovým monitorem
  Serial.println("Enter a message to convert to Morse code:");
}
 
void loop() {
  // Zkontroluje, zda je k dispozici vstup ze sériové linky
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Čte vstup, dokud nenarazí na nový řádek
    Serial.print("Converting to Morse: ");
    Serial.println(input);
    for (int i = 0; i < input.length(); i++) {
      char c = toupper(input[i]); // Převádí písmeno na velké, protože morseovka je většinou definována pro velká písmena
      sendMorse(c);
      delay(letterPause); // Pauza mezi jednotlivými písmeny
    }
    Serial.println("Message finished.");
    delay(2000); // Pauza před další zprávou
    Serial.println("Enter a message to convert to Morse code:");
  }
}
 
void sendMorse(char c) {
  switch(c) {
    case 'A': morseDot(); morseDash(); break;
    case 'B': morseDash(); morseDot(); morseDot(); morseDot(); break;
    case 'C': morseDash(); morseDot(); morseDash(); morseDot(); break;
    case 'D': morseDash(); morseDot(); morseDot(); break;
    case 'E': morseDot(); break;
    case 'F': morseDot(); morseDot(); morseDash(); morseDot(); break;
    case 'G': morseDash(); morseDash(); morseDot(); break;
    case 'H': morseDot(); morseDot(); morseDot(); morseDot(); break;
    case 'I': morseDot(); morseDot(); break;
    case 'J': morseDot(); morseDash(); morseDash(); morseDash(); break;
    case 'K': morseDash(); morseDot(); morseDash(); break;
    case 'L': morseDot(); morseDash(); morseDot(); morseDot(); break;
    case 'M': morseDash(); morseDash(); break;
    case 'N': morseDash(); morseDot(); break;
    case 'O': morseDash(); morseDash(); morseDash(); break;
    case 'P': morseDot(); morseDash(); morseDash(); morseDot(); break;
    case 'Q': morseDash(); morseDash(); morseDot(); morseDash(); break;
    case 'R': morseDot(); morseDash(); morseDot(); break;
    case 'S': morseDot(); morseDot(); morseDot(); break;
    case 'T': morseDash(); break;
    case 'U': morseDot(); morseDot(); morseDash(); break;
    case 'V': morseDot(); morseDot(); morseDot(); morseDash(); break;
    case 'W': morseDot(); morseDash(); morseDash(); break;
    case 'X': morseDash(); morseDot(); morseDot(); morseDash(); break;
    case 'Y': morseDash(); morseDot(); morseDash(); morseDash(); break;
    case 'Z': morseDash(); morseDash(); morseDot(); morseDot(); break;
    case '1': morseDot(); morseDash(); morseDash(); morseDash(); morseDash(); break;
    case '2': morseDot(); morseDot(); morseDash(); morseDash(); morseDash(); break;
    case '3': morseDot(); morseDot(); morseDot(); morseDash(); morseDash(); break;
    case '4': morseDot(); morseDot(); morseDot(); morseDot(); morseDash(); break;
    case '5': morseDot(); morseDot(); morseDot(); morseDot(); morseDot(); break;
    case '6': morseDash(); morseDot(); morseDot(); morseDot(); morseDot(); break;
    case '7': morseDash(); morseDash(); morseDot(); morseDot(); morseDot(); break;
    case '8': morseDash(); morseDash(); morseDash(); morseDot(); morseDot(); break;
    case '9': morseDash(); morseDash(); morseDash(); morseDash(); morseDot(); break;
    case '0': morseDash(); morseDash(); morseDash(); morseDash(); morseDash(); break;
    case ' ': delay(wordPause); break; // Pauza mezi slovy
    default: break; // Nepodporovaný znak
  }
}
 
void morseDot() {
  digitalWrite(ledPin, HIGH); // Zapnutí LED
  delay(dotDuration); // Délka tečky
  digitalWrite(ledPin, LOW); // Vypnutí LED
  delay(pauseDuration); // Mezera mezi znaky
}
 
void morseDash() {
  digitalWrite(ledPin, HIGH); // Zapnutí LED
  delay(dashDuration); // Délka čárky
  digitalWrite(ledPin, LOW); // Vypnutí LED
  delay(pauseDuration); // Mezera mezi znaky
}