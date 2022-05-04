#include <cmath>
#include "math_vector.h"

double length(double v[], int dim) // trans an array v, and know the end of v
{
    double result = 0;
    for(int i = 0; i < dim; i++)
    {
        result += v[i] * v[i]; // 做畢氏定理
    }
    result = sqrt(result);
    return result;
}


//overload 重載
double length(MathVector v)
{
    double result = 0;
    for(int i = 0; i < v.dimension(); i++)
    {
        result += v.at(i) * v.at(i);
    }
    result = sqrt(result);
    return result;
}