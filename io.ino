int readButtonDebounce(int pin) {
  const int DEBOUNCE_DELAY = 50;
  static int buttonState, lastButtonState;
  static long lastDebounceTime; 
  int out = 0;

  int reading = digitalRead(pin);
  if(reading != lastButtonState) lastDebounceTime = millis();

  if((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      // CHANGE TO !buttonState if active low
      if(!buttonState) {
        out = 1;
      }
    }
  }
  lastButtonState = reading;
  return out;
}
