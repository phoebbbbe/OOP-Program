#ifndef DOG_H
#define DOG_H
#include "pet.h"

class Dog : public Pet {
public:
    Dog() {
        _name = "nothing";
        _weight = 0;
    }
    Dog(std::string name, double weight) {
        if ((weight < 10) or (weight > 50)) {
            throw std::range_error("Range error.");
        } 
        _name = name;
        _weight = weight;
    }

    std::string name() const override {
        return _name;
    }

    double weight() const override {
        return _weight;
    }
    void feed() override {
        if (_weight + 0.8 > 50) {
            throw std::out_of_range("Out of range.");
        } 
        _weight = _weight + 0.8;
    }

private:
    std::string _name;
    double _weight;
};

#endif