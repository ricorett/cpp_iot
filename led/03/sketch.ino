int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int delayTimes[] = {1000, 500, 250, 100};
int delayIndex = 0;

void setup() {

    for (int i = 0; i < 8; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], HIGH);
    }
}

void loop() {

    for (int i = 0; i < 8; i++) {

        digitalWrite(ledPins[i], LOW);
        delay(delayTimes[delayIndex]);
        digitalWrite(ledPins[i], HIGH);
    }

    delayIndex = (delayIndex + 1) % 4;
}