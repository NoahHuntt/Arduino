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

int leds[] = {9, 10, 11, 12, 13};  // LED pins
int numLeds = 5;

int brightness = 0;
int fadeAmount = 3;

int currentLed = 0;
bool fadingIn = true;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
    analogWrite(leds[i], 0);  // make sure all LEDs start off
  }
}

void loop() {
  // Set brightness to current LED
  analogWrite(leds[currentLed], brightness);

  // Update brightness
  if (fadingIn) {
    brightness += fadeAmount;
    if (brightness >= 255) {
      brightness = 255;
      fadingIn = false;
    }
  } else {
    brightness -= fadeAmount;
    if (brightness <= 0) {
      brightness = 0;
      fadingIn = true;

      // Move to next LED
      analogWrite(leds[currentLed], 0);  // make sure it's fully off
      currentLed = (currentLed + 1) % numLeds;
    }
  }

  delay(30);
}
