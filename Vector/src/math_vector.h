#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>
#include <sstream>
#include <iostream>

class MathVector {
private:
    int _dim;
    double *_vec;
    void init(int dim, double *v) {
        //std::cout << "Copy is called" << std::endl;
        this->_dim = dim;
        this->_vec = new double [this->_dim];
        for(int i = 0; i < this->_dim; i++) {
            this->_vec[i] = v[i];
        }
    }
public:
    // Default constructor
    MathVector() {
        _dim = 0;
        _vec = nullptr;
    }
    // Constructor
    MathVector(int dim, double * v) {
        if(dim < 0) {
            throw std::string("undefined.");
        }
        init(dim, v);
    }
    // Copy Constructor
    MathVector(const MathVector &v) {
        init(v._dim, v._vec);
    }
    // Copy Assignment (注意：此非constructor 所以有回傳東西)
    MathVector& operator=(const MathVector &v) {
        if (this != &v)
        {
            if(this->_vec != nullptr){
                delete [] _vec;
            }
            init(v._dim, v._vec);
        }
        return *this;

    }
    // Deconstructor
    ~MathVector() {
        if (this->_vec != nullptr){
            delete[] this->_vec;
        }
    }

    // Member function
    double length() {
        double result = 0;
        for(int i = 0; i < _dim; i++) {
            result += _vec[i] * _vec[i];
        }
        result = sqrt(result);
        return result;
    }
    // Getter
    double at(int index) const {
        return _vec[index];
    }
    // Get dimention
    int dimension() const {
        return _dim;
    }
    // Setter
    void setIndex(int index, double input) {
        if (index >= _dim) {
            throw std::string("undefined.");
        }
        _vec[index] = input;
    }

    MathVector operator+ (const MathVector &v) const {
        if (this->dimension() == 0) { // 檢查是否為空的 Vector
            return MathVector(v._dim, v._vec); // 新的 MathVector 由 v 來創造
        }
        if(v.dimension() == 0) {
            // return *this; // 為什麼不能return *this: 不能更動自己（不能直接回傳自己）！！！！！
            return MathVector(this->_dim, this->_vec);
        }
        double w[this->dimension()];
        for(int i = 0; i < this->dimension(); i++) {
            w[i] = this->at(i) + v.at(i);
        }
        return MathVector(this->dimension(), w);
    }

    MathVector operator- (const MathVector &v) const {
        double w[this->dimension()];
        for(int i = 0; i < this->dimension(); i++) {
            w[i] = this->at(i) - v.at(i);
        }
        return MathVector(this->dimension(), w);
    }

    MathVector operator/(const double a) const { // v 是要去除以一個 int, 在這裏使用 double
        double w[this->dimension()];
        for (int i = 0; i < this->dimension(); i++) {
            w[i] = this->at(i) / a;
        }
        return MathVector(this->dimension(), w);
    }

    friend std::istream &operator>>(std::istream &input, MathVector &M);

    std::string toString() const {
        std::stringstream ss;
        for (int i = 0; i < _dim; i++) {
            ss << _vec[i];
            if (i != _dim - 1) {
                ss << " ";
            }
        }
        return ss.str();
    }
};

class CCWBefore {
private:
    MathVector centroid;
public:
    CCWBefore(const MathVector &v) {
        centroid = v;
    }
    bool operator()(const MathVector &a, const MathVector &b) {
        MathVector da = a - centroid;
        MathVector db = b - centroid;
        return (0.5 * (da.at(0) * db.at(1) - da.at(1) * db.at(0)) >= 0.000); // 二階行列式，透過結果的 >0 或 <0 做排序，所以 >0 回傳 True <0 回傳 False
    }
};

std::istream &operator>>(std::istream &input, MathVector &M) {
    input >> M._vec[0] >> M._vec[1];
    return input;
}

#endif