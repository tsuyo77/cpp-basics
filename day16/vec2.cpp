#include "vec2.h"

#include <cmath>

Vec2::Vec2() : x_(0.0), y_(0.0) {}
Vec2::Vec2(double x, double y) : x_(x), y_(y) {}

double Vec2::x() const { return x_; }
double Vec2::y() const { return y_; }

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x_ + other.x_, y_ + other.y_);
}

Vec2 Vec2::operator*(double k) const {
    return Vec2(x_ * k, y_ * k);
}

double Vec2::length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

Vec2 Vec2::operator-(const Vec2& other) const{
    return Vec2(x_ - other.x_, y_ - other.y_);
}
double Vec2::dot(const Vec2& other) const {
    return x_ * other.x_ + y_ * other.y_;
}
