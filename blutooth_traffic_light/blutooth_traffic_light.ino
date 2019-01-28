const int red = 11;
const int green = 10;
const int blue = 9;

int counter = 1;

char junk;
String inputString="";

void setup() {
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  
   
  if (Serial.available()) {
    while(Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString += inChar;
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }  
        
    if(inputString == "g"){         
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);  
    }else if(inputString == "r"){   
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
    } else if(inputString == "y"){   
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
    }
    inputString = "";
  } 

}
