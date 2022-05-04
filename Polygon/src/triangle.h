#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <cmath>
#include <string>
#include "circle.h"
#include "shape.h"

class Triangle : public Shape{
private:
    std::vector <Circle *> _circles;
    std::string _name;
    double _radius;
public:
    Triangle() {
        _name = "nothing";
        _radius = 1;
    }

    Triangle(std::string name, double radius) {
        _name = name;
        _radius = radius;
    }

    ~Triangle() override {}

    void addCircle(Circle* circle) {
        _circles.push_back(circle);
    }
    
    double perimeter() const override {
        return _radius * 2 * M_PI; 
    }

    double area() const override {
        return _radius * _radius * M_PI; 
    }

    std::string getName() const override {
        return _name;
    }

    Circle* getCircle(int index) const {
        return _circles[index];
    }
};

#endif