#include <iostream>

int main()
{
    char *p = new char;
    p = 0; // the leak is here
    std::cout << "Hello, leak!\n" << std::endl;
    return 0;
}