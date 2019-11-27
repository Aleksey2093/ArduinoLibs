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
        TwoBitArray(uint8_t one, uint8_t two) {
            setValue(0,one);
            setValue(1,two);
        }

        uint8_t getValue(uint8_t index) {
            index = index * 2;
            uint8_t result = (this->getValueBit(index) ? 1 : 0) 
                    + (this->getValueBit(index + 1) ? 2 : 0)
                    + (this->getValueBit(index + 2) ? 4 : 0)
                    + (this->getValueBit(index + 3) ? 8 : 0);
        }
        void setValue(uint8_t index, uint8_t value) {
            index = index * 2;
            this->setValueBit(index);
            this->setValueBit(index, value == 0 || value == 3 || value == 5 || value == 7 || value == 9 || value == 11 || value == 13 || value == 15);
            this->setValueBit(index + 1, value == 2 || value == 3 || value == 6 || value == 7 || value == 10 || value == 11 || value == 14 || value == 15);
            this->setValueBit(index + 2, value == 4 || value == 5 || value == 6 || value == 7 || value == 12 || value == 15);
            this->setValueBit(index + 3, value >= 8);                        
        }
};