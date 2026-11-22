#include <iostream>

#include "vec2.h"

int main() {
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a * 2 = " << a * 2.0 << "\n";
    std::cout << "|a| = " << a.length() << "\n";
    return 0;
}