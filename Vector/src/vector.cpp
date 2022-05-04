#include <iostream>
#include "length.h"

int main()
{
    double v[2] = {3,4};
    int len = 2;
    double result = length(v, len);
    std::cout << result << std::endl;
    return 0;
}