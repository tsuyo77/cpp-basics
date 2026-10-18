#include <iostream>
#include <vector>

int main() {
    // ---- サイズと容量 ----
    std::vector<int> v;
    std::cout << "size = " << v.size() << ", capacity = " << v.capacity() << "\n";

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
        std::cout << "size = " << v.size()
                  << ", capacity = " << v.capacity() << "\n";
    }

    std::vector<int> w;
    w.reserve(10);   // 先に10個分の場所を確保
    std::cout << "reserve後 size = " << w.size()
              << ", capacity = " << w.capacity() << "\n";

    // ---- 2次元vector(グリッド) ----
    const int H = 3;   // 行数
    const int W = 4;   // 列数
    std::vector<std::vector<int>> grid(H, std::vector<int>(W, 0));

    grid[1][2] = 1;    // 障害物を置く(行1、列2)
    grid[0][3] = 1;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            std::cout << grid[r][c] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}