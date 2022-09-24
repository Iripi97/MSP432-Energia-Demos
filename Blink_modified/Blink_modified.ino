/*
  Blink
  The basic Energia example.
  Turns on two LED on for one second, then off for one second, consecutively and repeatedly.
*/

#define LED RED_LED
#define LED2 GREEN_LED

void setup() {                
  // initialize the LEDs as outputs
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);     
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on
  delay(500);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off
  delay(500);               // wait for a second
  digitalWrite(LED2, HIGH);   // turn the LED2 on
  delay(500);               // wait for a second
  digitalWrite(LED2, LOW);   // turn the LED2 off
  delay(500);               // wait for a second
}
