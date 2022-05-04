#ifndef APP_H
#define APP_H
#include <vector>
#include "shape.h"
#include <algorithm>

// 功能：用 shape class 代表三種不同的形狀 circle\polygon\triangle 裝進同一個 vector 去比較他們
class App {
private:
    std::vector<Shape *> _shapes; //必須以 pointer 的型態存儲，因為 shape class 有 pure virtual function 所以不能實體化

public:
    App() {
        
    }
    void add(Shape* s) {
        _shapes.push_back(s);
    }

    void sort() {
        std::sort(_shapes.begin(), _shapes.end(),
        [](Shape* a, Shape* b){ //anonymous function, a.k.a lambda function
            return a->area() < b->area();
        });
    }
    Shape * at(int index) const {
        return _shapes[index];
    }

};
#endif