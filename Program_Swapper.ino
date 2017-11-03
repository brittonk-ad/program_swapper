/*
 Program Swapper

 Uses State Change Detection on a button counter to swap between any number of programs.
 Could also be rewritten to use 

 The circuit:
 * LEDs attached from pins 4-8 to ground
 * pushbutton attached to pin 2 from +5V
 * Pull-down 10K resistor attached to pin 2 from ground

 cobbled together imperfectly 2017
 by Britton Kroessler

 This example code is in the public domain.

 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  4;     //LED array only necessary for the example, swap out components as needed
const int ledPin2 =  5;
const int ledPin3 =  6;
const int ledPin4 =  7;
const int ledPin5 =  8;

// variables will change:
int buttonState = 0;
int lastButtonState = 0;
int ctr = 0; //counts the amount of button presses

void setup() {
  // initialize the LED pins as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);  
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); //setting up the serial monitor for easier debugging
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
        // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      ctr++;
      
      //Serial.print("number of button pushes: ");
      //Serial.println(ctr);
      
    if(ctr > 5){ //integrate modulo here?
        ctr=1; //resets the counter back to 0 to the start of each program
      }
      
    } else {
      // if the current state is LOW then the button went from on to off:
      
    }
    // Delay a little bit to avoid bouncing
    delay(150);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  //vvvvvvvv everything below will determine what programs are run vvvvvvvvv
  
  if(ctr == 1){ 
    //insert individual program here
    digitalWrite(ledPin1, HIGH);
}
  else if(ctr == 2){
    digitalWrite(ledPin2, HIGH);
}

  else if(ctr == 3){
    digitalWrite(ledPin3, HIGH);
}

  else if(ctr == 4){
    digitalWrite(ledPin4, HIGH);
}

  else if(ctr == 5){
    digitalWrite(ledPin5, HIGH);
}

  else
   ctr = 1;
   digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin3, LOW);
   digitalWrite(ledPin4, LOW);
   digitalWrite(ledPin5, LOW);

}

