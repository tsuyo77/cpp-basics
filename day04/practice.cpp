#include <iostream>

struct Vec2 {
    double x;
    double y;

    Vec2() : x(0), y(0) {}  // デフォルトコンストラクタ
    Vec2( double x_, double y_ ) : x(x_), y(y_) {}  // 引数ありコンストラクタ

    double dot(const Vec2& other) const {
    return x * other.x + y * other.y;
    }

    Vec2 add(const Vec2& other) const{
        return Vec2(x + other.x, y + other.y);
    }

    void print() const {
    std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Vec2 a(1.0, 2.0);
    Vec2 b(3.0, 4.0);

    std::cout << "dot = " << a.dot(b) << "\n";   // 11

    Vec2 c = a.add(b);
    c.print();                                    // (4, 6)
    a.print();                                    // (1, 2) ← 変わっていない
    return 0;
}
//constがついていないと呼び出しが拒否される可能性がある。