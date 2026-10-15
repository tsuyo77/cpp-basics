#include <iostream>

class Vec2 {
public:
    Vec2() : x_(0.0), y_(0.0) {}
    Vec2(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    // a + b
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x_ + other.x_, y_ + other.y_);
    }

    // a * k (スカラー倍)
    Vec2 operator*(double k) const {
        return Vec2(x_ * k, y_ * k);
    }

private:
    double x_;
    double y_;
};

// std::cout << v を可能にする
std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

int main() {
    Vec2 a(1.0, 2.0);
    Vec2 b(3.0, 4.0);

    Vec2 c = a + b;
    std::cout << "a + b = " << c << "\n";

    Vec2 d = a * 2.0;
    std::cout << "a * 2 = " << d << "\n";

    std::cout << "a + b * 2 = " << a + b * 2.0 << "\n";
    std::cout << "a = " << a << "\n";   // aは変わっていない

    return 0;
}