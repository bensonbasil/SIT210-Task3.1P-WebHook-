#ifndef HC_SR04_H
#define HC_SR04_H

#include "Particle.h"

class HC_SR04 {
    private:
        int trigPin;
        int echoPin;
    public:
        const float NO_SIGNAL = -1.0;
        HC_SR04(int trig, int echo);
        float getDistance();
};

#endif // HC_SR04_H
