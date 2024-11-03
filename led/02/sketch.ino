int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {

    for (int i = 0; i < 8; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

void loop() {

    for (int i = 7; i >= 0; i--) {
        digitalWrite(ledPins[i], HIGH);
        delay(1000);
    }

    for (int i = 0; i < 8; i++) {
        digitalWrite(ledPins[i], LOW);
        delay(500);
    }

}