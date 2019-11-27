#pragma once

class BitsValue {
    private: 
        uint8_t value;    
    public:
        BitsValue() {
            this->value = 0;
        }
        BitsValue(uint8_t value) {
            this->value = value;
        }
        BitsValue(bool v1, bool v2, bool v3, bool v4, bool v5, bool v6, bool v7, bool v8) {
            this->value = 0;
            this->setValue(0,v1);
            this->setValue(1,v2);
            this->setValue(2,v3);
            this->setValue(3,v4);
            this->setValue(4,v5);
            this->setValue(5,v6);
            this->setValue(6,v7);
            this->setValue(7,v8);
        }
        BitsValue(bool arr[]) {
            this->value = 0;
            this->setValue(0,arr[0]);
            this->setValue(1,arr[1]);
            this->setValue(2,arr[2]);
            this->setValue(3,arr[3]);
            this->setValue(4,arr[4]);
            this->setValue(5,arr[5]);
            this->setValue(6,arr[6]);
            this->setValue(7,arr[7]);
        }
        bool getValue(uint8_t index) {
            return (bool((1 << index) & value));
        }
        void setValue(uint8_t index, bool value) {
            if (value) {
                this->value |= (1 << index);
            } else {
                this->value &= ~(1 << index);
            }
        }
};