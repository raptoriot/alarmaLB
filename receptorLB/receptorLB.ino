
//Alarma para LB
//02 de septiembre
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 13;
int retardo = 5000;  //tiempo delay para la alarma
boolean estadorele=false;
double previousMillis=0;
boolean inicio=false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  delay(500);
    unsigned long currentMillis = millis();
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);

  
  if(buttonState==1 and inicio==false){
    previousMillis = currentMillis;
    estadorele=true;
    inicio=true;
  }

 if(buttonState==0){
    previousMillis = currentMillis;
    estadorele=false;
    inicio=false;
  }

  if(estadorele==false){
    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  }
    if(estadorele==true and  currentMillis>(previousMillis+retardo)){
    digitalWrite(7, HIGH);    // turn the LED off by making the voltage LOW
    Serial.println("inicio Alarma");
  }

}
