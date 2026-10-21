#include <array>
#include <iostream>

// サイズも型の一部:array<int, 4> 専用の関数
void print(const std::array<int, 4>& a) {
    for (const auto& e : a) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    std::array<int, 4> a = {1, 2, 3, 4};
    std::array<int, 4> z{};             // すべて0
    std::array<int, 4> b;
    b.fill(7);                          // すべて7

    print(a);
    print(z);
    print(b);

    std::cout << "size = " << a.size() << "\n";
    std::cout << "a[2] = " << a[2] << ", a.at(2) = " << a.at(2) << "\n";
    // a.push_back(5);                  // エラー:arrayは要素を増やせない

    // ---- 4方向の隣接マスの差分(A*で使う) ----
    const std::array<int, 4> dx = {1, -1, 0, 0};
    const std::array<int, 4> dy = {0, 0, 1, -1};

    int x = 2;
    int y = 2;
    for (std::size_t i = 0; i < dx.size(); i++) {
        std::cout << "(" << x + dx[i] << ", " << y + dy[i] << ") ";
    }
    std::cout << "\n";

    // ---- 代入はコピーになる ----
    std::array<int, 4> c = a;
    c[0] = 100;
    std::cout << a[0] << " " << c[0] << "\n";

    return 0;
}