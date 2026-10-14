#include <cmath>
#include <iostream>

struct Vec2 {
    double x;
    double y;

    // メンバ関数:原点からの長さ
    double length() const {
        return std::sqrt(x * x + y * y);
    }

    // メンバ関数:全体をk倍する(自分自身を変更)
    void scale(double k) {
        x *= k;
        y *= k;
    }
};

int main() {
    Vec2 v{3.0, 4.0};

    std::cout << "length = " << v.length() << "\n";

    v.scale(2.0);
    std::cout << "x = " << v.x << ", y = " << v.y << "\n";
    std::cout << "length = " << v.length() << "\n";

    return 0;
}