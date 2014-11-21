#include <Servo.h>

/* Initialize the Servo objects */
Servo leftLeg;
Servo rightLeg;

/* Moves the pet forwards */
void forward() {
    leftLeg.write(80);
    delay(250);
    rightLeg.write(40);
    delay(250);
    leftLeg.write(110);
    delay(250);
    rightLeg.write(60);
    delay(250);
}

/* Moves the pet backwards */
void backward() {
    leftLeg.write(140);
    delay(250);
    rightLeg.write(90);
    delay(250);
    leftLeg.write(110);
    delay(250);
    rightLeg.write(60);
    delay(250);
}

/* Makes the pet's eye red */
void red() {
    analogWrite(9, 0);
    analogWrite(10, 255);
    analogWrite(11, 255);
}

/* Makes the pet's eye green */
void green() {
    analogWrite(9, 255);
    analogWrite(10, 0);
    analogWrite(11, 255);
}

/* Makes the pet's eye blue */
void blue() {
    analogWrite(9, 255);
    analogWrite(10, 255);
    analogWrite(11, 0);
}

void setup () {
    /* Initialize Servomotors */
    leftLeg.attach(5);
    rightLeg.attach(6);
    /* Initial position for the legs */
    leftLeg.write(110);
    rightLeg.write(40);
    /* Initialize serial communication */
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        switch (c) {
            case 'w':
                forward();
                break;
            case 's':
                backward();
                break;
            case 'r':
                red();
                break;
            case 'g':
                green();
                break;
            case 'b':
                blue();
                break;
        }
    }
}
