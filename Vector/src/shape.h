#ifndef SHAPE_H
#define SHAPE_H

// Base class to triangle and polygon.
class Shape {
protected:
    std::string _name;

public:
    static std::string log;
    static void resetLog() {
        log = "";
    }
    Shape() {
        _name = "nothing";
        log += "=>Shape ";
    }
    Shape(std::string name) : _name(name) {
        //_name = name;
        log += "=>Shape ";
    }
    virtual ~Shape() {
        log += "=>~Shape ";
        //std::cout << "~Shape, " << std::endl;
    }
    virtual double perimeter() const = 0; // pure virtual = no definition.
    virtual double area() const = 0; // duo to pure virtual, base class cannot be initialized.
    // Hard to know what to return.
    /* double perimeter() const {}
    double area() const {} */
    virtual std::string toString() const = 0;
    virtual std::string getName() const {
        return _name;
    }

};
std::string Shape::log = "";
#endif