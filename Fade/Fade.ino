/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int blueLed = 9;
int redLed = 10;
int greenLed = 11;
int yellowLed = 12;
int whiteLed = 13;
int brightness = 0;
int fadeAmount = 3;

void setup() {
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // blue LED fades in
  analogWrite(blueLed, brightness);

  // red LED fades out (inversely)
  analogWrite(redLed, 255 - brightness);

  // green LED fades out (inversely)
  analogWrite(greenLed, brightness);

  // yellow LED fades out (inversely)
  analogWrite(yellowLed, 255 - brightness);

  // red LED fades out (inversely)
  analogWrite(whiteLed, brightness);

  // update brightness
  brightness = brightness + fadeAmount;

  // reverse direction at limits
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
