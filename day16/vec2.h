#pragma once

#include <iostream>
#include <vector>

class Vec2 {
public:
    Vec2();
    Vec2(double x, double y);

    double x() const;
    double y() const;

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator*(double k) const;
    double length() const;

    Vec2 operator-(const Vec2& other) const;
    double dot(const Vec2& other) const;


private:
    double x_;
    double y_;
};

std::ostream& operator<<(std::ostream& os, const Vec2& v);