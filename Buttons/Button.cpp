#include "Button.h"

#define ENABLE_POSITION 0
#define FLAG_POSITION 1
#define WAS_CLICK_POSITION 2
#define DOWN_POSITION 3
#define UP_POSITION 4

ButtonByAlex::ButtonByAlex(uint8_t pin, uint8_t mode) {
    this->pin = pin;
    this->mode = mode;
    pinMode(pin, INPUT_PULLUP);
}

uint8_t ButtonByAlex::getClickCount() {
    return this->click_count;
}

uint32_t ButtonByAlex::getTimeOfDown() {
    return this->timerUp;
}

boolean ButtonByAlex::isEnabled() {
    return this->state.getValue(ENABLE_POSITION);
}

void ButtonByAlex::setEnabled(bool value) {
    this->state.setValue(ENABLE_POSITION,value);
}

bool ButtonByAlex::isFlag() {
    return this->state.getValue(FLAG_POSITION);
}

void ButtonByAlex::setFlag(bool value) {
    this->state.setValue(FLAG_POSITION,value);
} 

boolean ButtonByAlex::wasClick() {
    return this->state.getValue(WAS_CLICK_POSITION);
}

void ButtonByAlex::setWasClick(bool value) {
    this->state.setValue(WAS_CLICK_POSITION,value);
}

boolean ButtonByAlex::isDown() {
    return this->state.getValue(DOWN_POSITION);
}

void ButtonByAlex::setDown(bool value) {
    this->state.setValue(DOWN_POSITION,value);
}


boolean ButtonByAlex::isUp() {
    return this->state.getValue(UP_POSITION);
}

void ButtonByAlex::setUp(bool value) {
return this->state.setValue(UP_POSITION,value);
}

void ButtonByAlex::tick() {
    bool down = !digitalRead(this->pin);

    if (!down && this->isDown()) {
        this->setUp(true);
    }

    if (down) {
        this->setUp(false);
    }

    if (down && !this->isFlag() && millis() - this->timer > this->click_timeout) {
        this->setFlag(true);
        this->setWasClick(true);
        this->click_count = this->click_count + 1;
        this->timer = millis();
    } else if (!down && this->isFlag()) {
        if (this->isDown() == false) {
            this->setEnabled(!this->isEnabled());
        }
        this->setFlag(false);
        this->setDown(false);
        this->setWasClick(false);
    }
    if (down && this->isFlag() && millis() - this->timer > this->step_timeout) {
        this->setDown(true);
        this->timerUp = millis() - this->timer;
    }
    if (!down && !this->isFlag() && millis() - this->timer > this->step_timeout) {
        this->click_count = 0;
    }
}

uint16_t  ButtonByAlex::getClickTimeout() {
    return this->click_timeout;
}
void  ButtonByAlex::setClickTimeout(uint16_t value) {
    this->click_timeout = value;
}
uint16_t  ButtonByAlex::getStepTimeout() {
    return this->step_timeout;
}
void  ButtonByAlex::setStepTimeout(uint16_t value) {
    this->step_timeout = value;
}