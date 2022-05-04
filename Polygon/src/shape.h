#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <cmath>
#include <string>

class Shape {
protected:
    std::string _name;
    double _radius;

public:
    Shape() {
        _name = "nothing";
        _radius = 1;
    }

    Shape(double radius, std::string name) {
        _name = name;
        _radius = radius;
    }

    virtual ~Shape() {}
    
    virtual double perimeter() const {
        return _radius * 2 * M_PI;
    }

    virtual double area() const {
        return _radius * _radius * M_PI;
    }

    virtual std::string getName() const {
        return _name;
    }
};

#endif