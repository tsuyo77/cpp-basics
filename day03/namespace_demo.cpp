#include <cmath>
#include <iostream>

namespace geometry {

struct Point {
    double x;
    double y;
};

// ユークリッド距離
double dist(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

}  // namespace geometry

namespace grid {

struct Cell {
    int x;
    int y;
};

// マンハッタン距離(グリッド上の移動距離)
int dist(const Cell& a, const Cell& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

}  // namespace grid

int main() {
    geometry::Point p1{0.0, 0.0};
    geometry::Point p2{3.0, 4.0};
    std::cout << "euclid:    " << geometry::dist(p1, p2) << "\n";

    grid::Cell c1{0, 0};
    grid::Cell c2{3, 4};
    std::cout << "manhattan: " << grid::dist(c1, c2) << "\n";

    return 0;
}