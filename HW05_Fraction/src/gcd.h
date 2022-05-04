// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative

#ifndef GCD_H
#define GCD_H
#include <string>
#include <cmath>

int gcd(int a, int b) 
{
    a = abs(a);
    b = abs(b);
    if (b == 0) 
    {
        return a;
    }
    else 
    {
        return gcd(b, a % b);
    }    
}

#endif