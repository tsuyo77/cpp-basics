#include <iostream>

#include "grid2d.h"
#include "mathutil.h"
#include "vec2.h"

int main() {
    // 問1
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);
    std::cout << a - b << "\n";
    std::cout << a.dot(b) << "\n";

    // 問2
    std::cout << clamp_range(15.0, 0.0, 10.0) << "\n";
    std::cout << lerp_value(0.0, 10.0, 0.25) << "\n";

    // 問3
    Grid2D<int> g(3, 2, 0);
    g.at(1, 1) = 7;
    g.print();

    return 0;
}

// 問4のコメント: