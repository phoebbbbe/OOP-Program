#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "util.h"


int main(int argc, char** argv) { // argc：傳進參數的數表，argv：真正傳進來的東西
    if (argc != 2) { // argc 自己本身默認為1
        std::cout << "Too few arguments.\n";
        return EXIT_FAILURE;
    }
    std::vector <Shape *> s = shapesFromFile(argv[1]); // 從[1]開始拿東西
    std::cout << s[0]->getName() << std::endl;
    return EXIT_SUCCESS;
}