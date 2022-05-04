#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double _radius;
public:
    Circle() {

    }

    Circle(double radius) {
        _radius = radius;
    }
    // override : 表這function是繼承來的，且在這裡重新定義了他的內容
    double perimeter() const override {
        return _radius * 2 * M_PI;
    }
    double area() const override{
        return _radius * _radius * M_PI;
    }

    std::string toString() const override {
        return "";
    }
};

#endif