#include <iostream>

#include "vec2.h"

int main() {
    Vec2 p(1.0, 1.0);
    Vec2 q = p * 3.0 + Vec2(0.5, 0.5);
    std::cout << "q = " << q << ", |q| = " << q.length() << "\n";
    return 0;
}