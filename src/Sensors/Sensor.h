#ifndef SENSOR_H
#define SENSOR_H

#include <arduino.h>


class Sensor {
    public: 
        Sensor(uint8_t id, uint8_t pin);
        uint16_t getValue();
        uint8_t getId();
        uint8_t getPin();
        bool hasChanged();
        void execute();   
    private:
        uint8_t pin;
        uint16_t raw_value;
        uint16_t value;
        uint8_t id;
        uint16_t read();
        bool changed;
        uint8_t precision = 50;
};

Sensor::Sensor(uint8_t id, uint8_t pin){
    this->id = id;
    this->pin = pin;
}

uint16_t Sensor::getValue(){
    this->changed = false;
    return this->value = value;
}

uint8_t Sensor::getId(){
    return this->id = id;
}

bool Sensor::hasChanged(){
    return this->changed = changed;
}

uint8_t Sensor::getPin(){
    return this->pin = pin;
}

uint16_t Sensor::read(){
    return uint16_t(analogRead(this->pin)); 
}

void Sensor::execute(){
    uint16_t new_value = this->read();
    if (abs((new_value - this->raw_value)) >= precision){
        this->raw_value = new_value;
        this->value = new_value;
        this->changed = true;
    }
}

#endif