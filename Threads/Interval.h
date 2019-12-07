#pragma once
#include <Arduino.h>

class Interval {
    private:
        uint32_t time;
        uint16_t timeOut;                                                                                                                                    
    public:
        Interval(uint16_t timeOut) {
            this->timeOut = timeOut;
            this->time = millis();
        }
        bool isIter() {
            if (millis() - this->time > this->timeOut) {
                return true;
            }
            return false;
        }
}