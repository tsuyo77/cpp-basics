#include <iostream>

#include "box.h"

int main() {
    Box<int> b(42);
    std::cout << b.get() << "\n";
    return 0;
}