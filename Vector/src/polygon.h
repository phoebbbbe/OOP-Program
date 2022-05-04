#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "math_vector.h"
#include "shape.h"
#include "triangle.h"

// 將 centroid() 變成獨立的 function 為了因應在createPolygon時會需要呼叫到 centroid
MathVector centroid(int numberOfVertex, MathVector* vertex) { // 找多邊形的中心點
    MathVector centroid;
    for(int i = 0; i < numberOfVertex; i++) {
        centroid = centroid + vertex[i]; // 需要overload＋、＝運算符
    }
    // std::cout << centroid.at(0) << " " << centroid.at(1) << std::endl;
    return centroid / (double)(numberOfVertex);
}
class Factory; // forward declaration (預先宣告) 
// Derived class of shape.
class Polygon : public Shape {
// 一個 class 允許其 friend class 存取其 private 內的 variable
friend class Factory;
friend Polygon createPolygonSA(int numberOfVertex, MathVector* vertex);
public:
    static Polygon createPolygon(int numberOfVertex, MathVector* vertex) { // 聰明版的constructor : factory 給定參數回傳物件
        // 設定其功能為"排序"
        MathVector c = centroid(numberOfVertex, vertex);
        CCWBefore ccwb(c);
        std::sort(vertex, vertex + numberOfVertex, ccwb); // 放地址的起始與結尾
        //std::sort(_vertex.begin(), _vertex.end(), ccwb); // 能夠放入任何object，並且告訴他比較的方法，這個方法是一個物件，如果放的是func會很麻煩
        return Polygon(numberOfVertex, vertex); // factory 會回傳一個被初始化的物件
    }
    
    Polygon() {}
    
    double perimeter() const override {
        double sum = 0;
        for (int i = 0; i < _vertex.size(); i++) {
            // std::cout << _vertex.at(i).at(0) << "," << _vertex.at(i).at(1) << std::endl;
            sum += (_vertex.at((i+1)%(_vertex.size())) - _vertex.at(i)).length();
        }
        //sum += (_vertex[0] - _vertex[_vertex.size() - 1]).length();
        return sum;
    }
    
    double area() const override {
        //切成多個三角形算面積
        double area = 0;
        int n = (int)_vertex.size(); //.size()回傳vertex中有幾個物件
        for(int i = 0; i < n - 2; i++) {
            Triangle T(_vertex[0], _vertex[i + 1], _vertex[(i + 2)]);
            area += T.area();
            // 固定一個點與其他點連成三角形再相加
            // 0->1,2/ 0->2,3/ ...
        }
        return area;
    }
    bool operator< (const Polygon &rhs) const {
        return (this->perimeter() < rhs.perimeter());
    }

    bool operator> (const Polygon &rhs) const {
        return (this->perimeter() > rhs.perimeter());
    }

    /* MathVector getCentroid() const {
        return centroid();
    } */

    std::string toString() const override {
        return "";
    }

private:
    std::vector<MathVector> _vertex;
    //MathVector* _vertex;
    /* 將此
        MathVector centroid() const {
        MathVector centroid;
        for (int i = 0; i < (double)_vertex.size(); i++) {
            centroid = centroid + _vertex[i];
        }
        // std::cout << centroid.at(0) << " " << centroid.at(1) << std::endl;
        return centroid / (double)_vertex.size(); 
    } */
    Polygon(int numberOfVertex, MathVector* vertex) { // 用途就是初始化物件 
        /* for (int i = 0; i < numberOfVertex; i++) {
            _vertex.push_back(vertex[i]);
        } */
        /* _vertex = new MathVector[numberOfVertex];
        for (int i = 0; i < numberOfVertex; i++) {
            _vertex[i] = vertex[i];
        } */
        _vertex = std::vector<MathVector>(vertex, vertex + numberOfVertex);
        /* 這些動作已經超出constructur的範圍了
        MathVector c = centroid();
        CCWBefore ccwb(c);
        std::sort(_vertex.begin(), _vertex.end(), ccwb); */
    }
};

Polygon createPolygonSA(int numberOfVertex, MathVector* vertex) { // 聰明版的constructor : factory 給定參數回傳物件
    // 設定其功能為"排序"
    MathVector c = centroid(numberOfVertex, vertex);
    CCWBefore ccwb(c);
    std::sort(vertex, vertex + numberOfVertex, ccwb); // 放地址的起始與結尾
    //std::sort(_vertex.begin(), _vertex.end(), ccwb); // 能夠放入任何object，並且告訴他比較的方法，這個方法是一個物件，如果放的是func會很麻煩
    return Polygon(numberOfVertex, vertex); // factory 會回傳一個被初始化的物件
}

class Factory {
public:
    static Polygon createPolygon(int numberOfVertex, MathVector* vertex) {
        MathVector c = centroid(numberOfVertex, vertex);
        CCWBefore ccwb(c);
        std::sort(vertex, vertex + numberOfVertex, ccwb);
        return Polygon(numberOfVertex, vertex);
    }
};

#endif