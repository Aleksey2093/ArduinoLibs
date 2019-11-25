#include "Button.h"

ButtonByAlex::ButtonByAlex(uint8_t pin, uint8_t mode) {
    this->pin = pin;
    this->mode = mode;
    pinMode(pin, INPUT_PULLUP);
    for (uint8_t i=0;i<8;i++) {
        this->state &= ~(1<<i); 
    }
}

uint8_t ButtonByAlex::getClickCount() {
    return this->click_count;
}

uint32_t ButtonByAlex::getTimeOfDown() {
    return this->timerUp;
}

boolean ButtonByAlex::isEnabled() {
    return (bool((1 << 0)  &  state));
}

void ButtonByAlex::setEnabled(bool value) {
    if (value) {
        this->state |= (1 << 0);
    } else {
        this->state &= ~(1 << 0);
    }
}

bool ButtonByAlex::isFlag() {
    return (bool((1 << 1)  &  state));
}

void ButtonByAlex::setFlag(bool value) {
    if (value) {
        this->state |= (1 << 1);
    } else {
        this->state &= ~(1 << 1);
    }
} 

boolean ButtonByAlex::wasClick() {
    return (bool((1 << 2)  &  state));
}

void ButtonByAlex::setWasClick(bool value) {
    if (value) {
        this->state |= (1 << 2);
    } else {
        this->state &= ~(1 << 2);
    }
}

boolean ButtonByAlex::isDown() {
    return (bool((1 << 3)  &  state));
}

void ButtonByAlex::setDown(bool value) {
    if (value) {
        this->state |= (1 << 3);
    } else {
        this->state &= ~(1 << 3);
    }
}


boolean ButtonByAlex::isUp() {
    return (bool((1 << 4)  &  state));
}

void ButtonByAlex::setUp(bool value) {
    if (value) {
        this->state |= (1 << 4);
    } else {
        this->state &= ~(1 << 4);
    }
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