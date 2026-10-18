#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    for (const auto& e : v) {
    if (e % 2 == 0) {
        std::cout << e << " ";
        }
    }
    std::cout << "\n";

    std::vector<int> v1 = {5, 3, 8, 1, 9};
    v1.insert(v1.begin(), 0);
    print(v1);
    v1.pop_back();
    print(v1);
    v1.erase(v1.begin() + 2);
    print(v1);

    const int H = 3;   // 行数
    const int W = 5;   // 列数

    std::vector<std::vector<int>> grid(H, std::vector<int>(W, 0));

        for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (r == 0 || r == H - 1 || c == 0 || c == W - 1) {
                grid[r][c] = 1;
            }
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            std::cout << grid[r][c] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
// reserveは場所(capacity)を確保するだけで、要素は作らない。sizeは0のまま。
// v[0]は存在しない要素への書き込みになり、未定義動作になる。