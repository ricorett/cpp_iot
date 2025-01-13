#include "SwitchLed.h"

SwitchLed::SwitchLed(int redPin, int greenPin, int bluePin, int redIncreaseButton, int redDecreaseButton,
                     int greenIncreaseButton, int greenDecreaseButton, int blueIncreaseButton, int blueDecreaseButton) {
  _pins[0] = redPin;
  _pins[1] = greenPin;
  _pins[2] = bluePin;

  _buttons[0] = redIncreaseButton;
  _buttons[1] = redDecreaseButton;
  _buttons[2] = greenIncreaseButton;
  _buttons[3] = greenDecreaseButton;
  _buttons[4] = blueIncreaseButton;
  _buttons[5] = blueDecreaseButton;

  _debounceDelay = 50;
  _activeColor = -1;

  for (int i = 0; i < 3; i++) {
    _colorBrightness[i] = 0;
    pinMode(_pins[i], OUTPUT);
  }

  for (int i = 0; i < 6; i++) {
    pinMode(_buttons[i], INPUT);
    _lastButtonState[i] = HIGH;
    _lastDebounceTime[i] = 0;
  }
}

void SwitchLed::update() {
  for (int i = 0; i < 6; i += 2) {
    int colorIndex = i / 2;
    checkButton(_buttons[i], colorIndex, true);
    checkButton(_buttons[i + 1], colorIndex, false);
  }

  for (int i = 0; i < 3; i++) {
    analogWrite(_pins[i], _colorBrightness[i]);
  }
}

void SwitchLed::checkButton(int buttonPin, int colorIndex, bool increase) {
  int reading = digitalRead(buttonPin);
  int buttonIndex = colorIndex * 2 + (increase ? 0 : 1);

  if (reading != _lastButtonState[buttonIndex]) {
    _lastDebounceTime[buttonIndex] = millis();
  }

  if ((millis() - _lastDebounceTime[buttonIndex]) > _debounceDelay) {
    if (reading != _lastButtonState[buttonIndex]) {
      _lastButtonState[buttonIndex] = reading;

      if (reading == LOW) { 
        int step = 25;

        if (_activeColor != colorIndex) {
          _activeColor = colorIndex;
        }

        if (increase) {
          _colorBrightness[colorIndex] = min(255, _colorBrightness[colorIndex] + step);
        } else {
          _colorBrightness[colorIndex] = max(0, _colorBrightness[colorIndex] - step);
        }
      }
    }
  }
}
