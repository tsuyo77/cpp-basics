#include <iostream>
#include <string>

// 引数の型が違う
void print(int x) {
    std::cout << "int: " << x << "\n";
}

void print(double x) {
    std::cout << "double: " << x << "\n";
}

void print(const std::string& s) {
    std::cout << "string: " << s << "\n";
}

// 引数の個数が違う
double area(double r) {
    return 3.14159 * r * r;          // 円
}

double area(double w, double h) {
    return w * h;                    // 長方形
}

int main() {
    print(42);                       // int版
    print(3.14);                     // double版
    print(std::string("hello"));     // string版

    std::cout << "circle: " << area(2.0) << "\n";
    std::cout << "rect:   " << area(2.0, 3.0) << "\n";
    return 0;
}