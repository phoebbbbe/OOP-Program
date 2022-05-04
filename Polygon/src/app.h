#ifndef APP_H
#define APP_H
#include <vector>
#include "shape.h"

class App {
private:
    std::vector <Shape *> _shapes;
public:
    App() {

    }
    void addShape(Shape* s) {
        _shapes.push_back(s);
    }

    Shape* at(int index) const {
        return _shapes[index];
    }
};

#endif