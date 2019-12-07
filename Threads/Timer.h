#pragma once
#include <Arduino.h>

class Timer {
    private:
        uint32_t time;
        uint16_t timeOut;
        void (*foo)();
        bool done;
    public:
        void func() {

        };
        Timer(uint16_t timeOut,void (*foo)()) {
            this->timeOut = timeOut;
            this->foo = foo;
            this->done = false;
        };
        Timer() {
            this->done = false;
        }
        void iter() {
            if (this->time == -1) {
                this->time = millis();
            }
            if (millis() - this->time > timeOut) {
                this->foo();
                this->done;
            }
        }
        uint32_t getTime() {
            return this->time;
        }
        void setTime(uint32_t value) {
            this->time = value;
        }
        bool isDone() {
            return this->done;
        }
};