const int led = 9;    // LED on port 9
const int button = 2; // button on port 2
int lastButton = LOW; // last state of button
int curButton = LOW;  // current state of button
int ledOn = LOW;      // current state of LED

// Функция подавления дребезга last — предыдущее состояние кнопки
int debounce (int last){
	int current = digitalRead(button);
	if (last != current) { // если состояние изменилось
		delay(5); // задержка для подавления дребезга
		current = digitalRead(button);
	} 
	return current;
}

void setup() {
	pinMode(led, OUTPUT);           // порт светодиода как выход
	digitalWrite(led, LOW);          // выключить светодиод

	pinMode(button, INPUT_PULLUP);   // порт кнопки как вход с подтягивающим резистором
}

void loop() {
	curButton = debounce(lastButton);
	if (lastButton == HIGH && curButton == LOW) { // если кнопка нажата
		ledOn = !ledOn;            // переключаем состояние светодиода
		digitalWrite(led, ledOn);
	}
	lastButton = curButton;
}
