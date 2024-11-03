int ledR = 13;
int ledG = 12;
int ledB = 11;
void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
}

void loop() {
    digitalWrite(ledR, HIGH);
    delay(1000);
    digitalWrite(ledR, LOW);
    delay(1000);

    digitalWrite(ledG, HIGH);
    delay(1000);
    digitalWrite(ledG, LOW);
    delay(1000);

    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledB, LOW);
    delay(1000);

    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, HIGH);
    delay(1000);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    delay(1000);

    digitalWrite(ledR, HIGH);
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledR, LOW);
    digitalWrite(ledB, LOW);
    delay(1000);

    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    delay(1000);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    delay(1000);

    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
    delay(1000);
}
