#include <iostream>
#include <string>
#include <vector>

// 大きいほうを返す
template <typename T>
T max_of(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// vector の中身を表示する(3日目の重複が1つになる)
template <typename T>
void print_vec(const std::vector<T>& v) {
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

// 合計を返す
template <typename T>
T sum(const std::vector<T>& v) {
    T total{};   // int なら 0、double なら 0.0、string なら ""
    for (const auto& e : v) {
        total += e;
    }
    return total;
}

// 型を2つ使う
template <typename T, typename U>
auto add(const T& a, const U& b) {
    return a + b;
}

int main() {
    std::cout << max_of(3, 7) << "\n";
    std::cout << max_of(2.5, 1.5) << "\n";
    std::cout << max_of(std::string("apple"), std::string("banana")) << "\n";

    // 型を明示する書き方
    std::cout << max_of<double>(3, 2.5) << "\n";

    print_vec(std::vector<int>{1, 2, 3});
    print_vec(std::vector<double>{0.5, 1.5});
    print_vec(std::vector<std::string>{"a", "b"});

    std::cout << sum(std::vector<int>{1, 2, 3}) << "\n";
    std::cout << sum(std::vector<double>{0.5, 1.5}) << "\n";

    std::cout << add(1, 2.5) << "\n";

    return 0;
}