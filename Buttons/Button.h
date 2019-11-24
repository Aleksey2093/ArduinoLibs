#pragma once
#include <Arduino.h>

class ButtonByAlex
{
    private:
        uint8_t pin;
        uint8_t mode;
        uint32_t timer = 0;
        uint32_t timerUp = 0;

        uint8_t state = 0;

        uint8_t click_count = 0;
        uint16_t timeout = 500;
	    uint16_t click_timeout = 300;
	    uint16_t step_timeout = 400;
    private:
        void setEnabled(bool value);
        void setFlag(bool value);
        void setWasClick(bool value);
        void setDown(bool value);
        void setUp(bool value);
        bool isFlag();
    public:
        ButtonByAlex(uint8_t pin, uint8_t mode);
        bool wasClick();
        bool isDown();
        bool isUp();
        void tick();
        uint16_t getClickTimeout();
        void setClickTimeout(uint16_t value);
        uint16_t getStepTimeout();
        void setStepTimeout(uint16_t value);
        uint8_t getClickCount();
        bool isEnabled();
        uint32_t getTimeOfDown();
};