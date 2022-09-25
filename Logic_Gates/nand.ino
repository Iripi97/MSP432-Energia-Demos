/* "NAND" TI LaunchPad Energia Program
 *  Created by: Justin Russo
 *  
 *               SN74LS00N
 *              ___________
 *        1A  -| 1  |_|  14|- Vcc = 5V
 *        1B  -| 2       13|- 4A
 *        1Y  -| 3       12|- 4B
 *        2A  -| 4       11|- 4Y
 *        2B  -| 5       10|- 3A
 *        2Y  -| 6        9|- 3B
 *        GND -| 7        8|- 3Y   
 */

int buttonPin = PUSH2;                              // Using switch 2
int buttonState;
int lastButtonState = LOW;  
long lastDebounceTime = 0;
long timer = 500;                                  // Setting up the delay for the switch
int A = 19;                                        // Using P2_5
int B = 18;                                        // Using P3_0
int a = 0, b = 0;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);                // Initialize the button pin as an input
  pinMode(A, OUTPUT);                              // The inputs to the NAND gate
  pinMode(B, OUTPUT); 
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  attachInterrupt(buttonPin, switchdelay, FALLING);
}

void switchdelay() {
  if ((millis() - lastDebounceTime) > timer){
    if (!a && !b){                                // case A = 0, B = 0
       digitalWrite(B, HIGH); b += 1;
    }
    else if (!a && b){                            // case A = 0, B = 1
      digitalWrite(A, HIGH); digitalWrite(B, LOW);
      a += 1; b -= 1;
    }
    else if (a && !b){                            // case A = 1, B = 0
      digitalWrite(B, HIGH); b += 1;   
    }
    else {                                        // case A = 1, B = 1
      digitalWrite(A, LOW); digitalWrite(B, LOW); 
      a -= 1; b -= 1;
    }
  }
    lastDebounceTime = millis();
}

void loop() {
}
