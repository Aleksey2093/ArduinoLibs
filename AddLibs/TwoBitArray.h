#pragma once

class TwoBitArray {
    private:
        uint8_t value;
    private:
        bool getValueBit(uint8_t index) {
            return (bool((1 << index) & value));
        }
        void setValueBit(uint8_t index, bool value) {
            if (value) {
                this->value |= (1 << index);
            } else {
                this->value &= ~(1 << index);
            }
        }

    public:
        TwoBitArray() {
            this->value = 0;
        }
        TwoBitArray(uint8_t one, uint8_t two, uint8_t three, uint8_t four) {
            setValue(0,one);
            setValue(1,two);
            setValue(2,three);
            setValue(3,four);
        }

        uint8_t getValue(uint8_t index) {
            index = index * 2;
            uint8_t result = (this->getValueBit(index) ? 1 : 0) + (this->getValueBit(index + 1) ? 2 : 0);
        }
        void setValue(uint8_t index, uint8_t value) {
            index = index * 2;
            this->setValueBit(index, value == 1 || value == 3);
            this->setValueBit(index + 1, value == 2 || value == 3);
        }
};