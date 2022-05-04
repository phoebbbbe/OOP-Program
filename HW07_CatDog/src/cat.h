#ifndef CAT_H
#define CAT_H
#include "pet.h"

class Cat : public Pet {
public:
    Cat() {
        _name = "nothing";
        _weight = 0;
    }
    Cat(std::string name, double weight) {
        if ((weight < 2) or (weight > 6)) {
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
        if (_weight + 0.2 > 6) {
            throw std::out_of_range("Out of range.");
        } 
        _weight = _weight + 0.2;
    }
private:
    std::string _name;
    double _weight;
};

#endif