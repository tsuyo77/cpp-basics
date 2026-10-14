#include <iostream>

struct Vec2 {
    double x;
    double y;

    // コンストラクタ:引数なし(原点)
    Vec2() : x(0.0), y(0.0) {}

    // コンストラクタ:x, yを指定
    Vec2(double x_, double y_) : x(x_), y(y_) {}

    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Vec2 a;              // 引数なし → (0, 0)
    Vec2 b(3.0, 4.0);    // 引数2つ → (3, 4)

    a.print();
    b.print();

    return 0;
}