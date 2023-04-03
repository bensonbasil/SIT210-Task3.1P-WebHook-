#include "HC-SR04.h"

HC_SR04::HC_SR04(int trig, int echo) {
    trigPin = trig;
    echoPin = echo;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float HC_SR04::getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    signed duration = pulseIn(echoPin, HIGH);

    if (duration == 0) {
        return NO_SIGNAL;
    }

    float distance = duration * 0.034 / 2;
    return distance;
}
