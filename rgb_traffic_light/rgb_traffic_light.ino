const int buttonPin = 3;
const int red = 11;
const int green = 10;
const int blue = 9;
int buttonState = 0;
int lastButtonState = 0;
int counter = 1;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {
      counter++;
    }

    delay(50);
  }

  lastButtonState = buttonState;
  Serial.println(counter);

  if (counter == 1) {
    //YELLOW off, YELLOW on for 3 seconds
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  }

  if (counter == 2) {
    //RED off, YELLOW on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  }

  if (counter == 3) {
    //GREEN off, YELLOW on for 3 seconds
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }  

  if (counter == 4) {
    counter = 1;
  }
  
}
