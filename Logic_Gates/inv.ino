/* "INV" TI LaunchPad Energia Program
 *  Created by: Justin Russo
 *  
 *               SN74LS04N
 *              ___________
 *        1A  -| 1  |_|  14|- Vcc = 5V
 *        1Y  -| 2       13|- 6A
 *        2A  -| 3       12|- 6Y
 *        2Y  -| 4       11|- 5A
 *        3A  -| 5       10|- 5Y
 *        3Y  -| 6        9|- 4A
 *        GND -| 7        8|- 4Y      
 */

int buttonPin = PUSH2;                    // Using switch 2
int buttonState;  
int lastButtonState = LOW;  
long lastDebounceTime = 0;
long timer = 500;                         // Setting up the delay for the switch
int A = 19;                               // Using P2_5
int a = 0;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);       // Initialize the button pin as an input
  pinMode(A, OUTPUT);                     // The input to the INV gate
  digitalWrite(A, LOW);
  attachInterrupt(buttonPin, switchdelay, FALLING);
}

void switchdelay() {
  if ((millis() - lastDebounceTime) > timer){
    if (!a){                             // case A = 0
       digitalWrite(A, HIGH); a += 1;
    }
    else {                               // case A = 1
      digitalWrite(A, LOW); a -= 1; 
    }
  }
  lastDebounceTime = millis();
}

void loop() {  
}
