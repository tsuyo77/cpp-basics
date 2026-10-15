#include <cmath>
#include <iostream>

class Vec2 {
public:
    // TODO: コンストラクタ2つ、ゲッタ、dot、length、normalized、operator+ - *
    Vec2() : x_(0.0), y_(0.0) {}
    Vec2(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    Vec2 operator+(const Vec2& other) const{
        return Vec2(x_ + other.x_, y_ + other.y_);
    }
    
    Vec2 operator-(const Vec2& other) const{
        return Vec2(x_ - other.x_, y_ - other.y_);
    }

    Vec2 operator*(double k) const{
        return Vec2(x_ * k, y_ * k);
    }

    double dot(const Vec2& other) const{
        return x_ * other.x_ + y_ * other.y_;
    }

    double length() const{
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    Vec2 normalized() const{
        double len = length();
        if (len == 0.0) {
            return Vec2(0.0, 0.0);
        } else {
            return Vec2(x_ / len, y_ / len);
        }
    }

private:
    double x_;
    double y_;
};

// TODO: operator*(double, const Vec2&)
// TODO: operator<<
   Vec2 operator*(double k, const Vec2& v){
    return v * k;
   }

   std::ostream& operator<<(std::ostream& os, const Vec2& v){
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
   }

// ---------- ここから下はテスト(変更しない) ----------

bool near(double a, double b) { return std::abs(a - b) < 1e-9; }
bool near(const Vec2& a, const Vec2& b) {
    return near(a.x(), b.x()) && near(a.y(), b.y());
}

void check(const char* name, bool ok) {
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

int main() {
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);
    Vec2 zero;

    check("default ctor",   near(zero, Vec2(0.0, 0.0)));
    check("a + b",          near(a + b, Vec2(4.0, 6.0)));
    check("a - b",          near(a - b, Vec2(2.0, 2.0)));
    check("a * 2",          near(a * 2.0, Vec2(6.0, 8.0)));
    check("2 * a",          near(2.0 * a, Vec2(6.0, 8.0)));
    check("2(int) * a",     near(2 * a, Vec2(6.0, 8.0)));
    check("a.dot(b)",       near(a.dot(b), 11.0));
    check("a.length()",     near(a.length(), 5.0));
    check("normalized",     near(a.normalized(), Vec2(0.6, 0.8)));
    check("zero normalized", near(zero.normalized(), Vec2(0.0, 0.0)));
    check("a unchanged",    near(a, Vec2(3.0, 4.0)));

    std::cout << "a = " << a << ", b = " << b << "\n";
    return 0;
}