#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// 型の穴が1つ:座標
template <typename T>
struct Point {
    T x;
    T y;
};

// 型の穴が1つ:どんな型でも持てるグリッド
template <typename T>
class Grid2D {
public:
    Grid2D(int width, int height, const T& init)
        : width_(width), height_(height),
          cells_(height, std::vector<T>(width, init)) {}

    int width() const { return width_; }
    int height() const { return height_; }

    T& at(int x, int y) { return cells_[y][x]; }
    const T& at(int x, int y) const { return cells_[y][x]; }

    void print() const {
        for (const auto& row : cells_) {
            for (const auto& c : row) {
                std::cout << c << " ";
            }
            std::cout << "\n";
        }
    }

private:
    int width_;
    int height_;
    std::vector<std::vector<T>> cells_;
};

// 型の穴と、数値の穴:固定長の配列(std::array の簡易版)
template <typename T, std::size_t N>
class FixedArray {
public:
    FixedArray() : data_{} {}

    T& operator[](std::size_t i) { return data_[i]; }
    const T& operator[](std::size_t i) const { return data_[i]; }
    std::size_t size() const { return N; }

private:
    T data_[N];
};

int main() {
    // ---- Point<T> ----
    Point<int> pi{3, 4};
    Point<double> pd{1.5, 2.5};
    Point<std::string> ps{"a", "b"};
    std::cout << pi.x << "," << pi.y << "\n";
    std::cout << pd.x << "," << pd.y << "\n";
    std::cout << ps.x << "," << ps.y << "\n";

    // ---- Grid2D<T>:同じクラスで、コスト用と地図用 ----
    Grid2D<int> cost(4, 3, 0);
    cost.at(1, 2) = 5;
    cost.print();

    Grid2D<char> map(4, 3, '.');
    map.at(2, 1) = '#';
    map.print();

    // ---- FixedArray<T, N> ----
    FixedArray<int, 4> fa;
    fa[0] = 10;
    fa[3] = 40;
    for (std::size_t i = 0; i < fa.size(); i++) {
        std::cout << fa[i] << " ";
    }
    std::cout << "\nsize = " << fa.size() << "\n";

    return 0;
}