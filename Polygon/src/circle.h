#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include <string>
#include "shape.h"


class Circle : public Shape {
private:
    std::string _name;
    double _radius;
public:
    Circle() {
        _name = "nothing";
        _radius = 1;
    }

    Circle(std::string name, double radius) {
        _name = name;
        _radius = radius;
    }
    
    ~Circle() override {}

    double perimeter() const override {
        return _radius * 2 * M_PI;
    }

    double area() const override {
        return _radius * _radius * M_PI;
    }

    std::string getName() const override {
        return _name;
    }


};

#endif