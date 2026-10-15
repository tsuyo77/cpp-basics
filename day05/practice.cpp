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

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x_ - other.x_, y_ - other.y_);
    }

private:
    double x_;
    double y_;
};

   Vec2 operator*(double k, const Vec2& v){
    return v * k;
   }
   //わからない

// std::cout << v を可能にする
std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

int main() {
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);

    Vec2 c = a - b;
    std::cout << "a - b = " << c << "\n";

    Vec2 d = 2.0 * a;
    std::cout << "2 * a = " << d << "\n";
    return 0;
}
//違うclassから変更されるの防ぐため。
//メンバの誤った更新を防ぐ。
//上限を超える回転数や負の値を、set_rpmの1か所で止められる
//内部の持ち方(単位や変数名)を変えても、使う側のコードが壊れない
//値を変える場所がset_rpmだけなので、不具合の調査範囲が狭くなる