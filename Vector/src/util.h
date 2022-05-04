#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "shape.h"
#include "triangle.h"
#include "math_vector.h"

std::vector<Shape *> shapesFromFile(std::string fileName) {
    std::ifstream ifs(fileName);
    std::string name;
    std::vector<Shape *> shapes;
    ifs >> name;
    
    MathVector _v[3];
    for (int i = 0 ; i < 3; i ++) {
        ifs >> _v[i];
    }
    // way1. 
    shapes.push_back(new Triangle(_v[0], _v[1], _v[2], "triangle"));

    //way2.
    Triangle *triangle = new Triangle();
    ifs >> *triangle;
    shapes.push_back(triangle);

    // following is wrong because triangle disapears after line 33. (透過 default constructor 構建的 triangle 隨著 return 消失，然而透過 new 構建的 triangle pointer 則不會.)
    /* Triangle triangle;
    ifs >> triangle;
    shapes.push_back(&tri); */
    return shapes;
}