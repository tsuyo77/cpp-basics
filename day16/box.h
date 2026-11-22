#pragma once

template <typename T>
class Box {
public:
    explicit Box(const T& v) : value_(v) {}
    T get() const { return value_; }

private:
    T value_;
};