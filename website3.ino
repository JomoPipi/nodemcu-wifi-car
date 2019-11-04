void setup() {
  Serial.begin(9600);
}

String readString;

void loop() {
  //expect a string like wer,qwe rty,123 456,hyre kjhg,
  //or like hello world,who are you?,bye!,
  delay(1000);
  Serial.println("ok");
  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      if (readString.length() > 0) {
        Serial.print(readString); //prints string to serial port out
        Serial.println(','); //prints delimiting ","
        //do stuff with the captured readString
        readString = ""; //clears variable for new input
      }
    }
    else {
      readString += c; //makes the string readString
    }
  }
}
