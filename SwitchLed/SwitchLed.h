#ifndef SwitchLed_h
#define SwitchLed_h

#include "Arduino.h"

class SwitchLed {
  public:
    SwitchLed(int redPin, int greenPin, int bluePin, int redIncreaseButton, int redDecreaseButton,
              int greenIncreaseButton, int greenDecreaseButton, int blueIncreaseButton, int blueDecreaseButton);
    void update(); 
  private:
    void checkButton(int buttonPin, int colorIndex, bool increase);
    int _pins[3];         
    int _buttons[6];    
    unsigned long _debounceDelay;      
    unsigned long _lastDebounceTime[6]; 
    int _lastButtonState[6];         
    int _colorBrightness[3];   
    int _activeColor;     
};

#endif
