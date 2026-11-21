#include <iostream>
#include <vector>
#include <queue>

// マス目状の地図を管理するクラス
class Grid {
private:
    // 0 = 通行可能、1 = 障害物
    std::vector<std::vector<int>> cells;

public:
    // 幅と高さを指定して地図を作る
    Grid(int width, int height)
        : cells(height, std::vector<int>(width, 0)) {
    }

    // 座標が地図の範囲内か調べる
    bool isInside(int x, int y) const {
        return y >= 0 &&
               y < static_cast<int>(cells.size()) &&
               x >= 0 &&
               x < static_cast<int>(cells[y].size());
    }

    // そのマスを通行できるか調べる
    bool isWalkable(int x, int y) const {
        if (!isInside(x, y)) {
            return false;
        }

        return cells[y][x] == 0;
    }

    // 指定したマスを障害物にする
    void setObstacle(int x, int y) {
        if (isInside(x, y)) {
            cells[y][x] = 1;
        }
    }

    // 地図を表示する
    void print() const {
        for (const auto& row : cells) {
            for (int cell : row) {
                if (cell == 0) {
                    std::cout << ". ";
                } else {
                    std::cout << "# ";
                }
            }

            std::cout << '\n';
        }
    }
};

// 座標とコストをまとめる構造体
struct Node {
    int x;
    int y;
    int cost;
};

// コストが小さいNodeを優先する比較関数
struct CompareCost {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost;
    }
};

int main() {
    // 幅5、高さ4の地図を作る
    Grid grid(5, 4);

    // 障害物を設置する
    grid.setObstacle(2, 1);
    grid.setObstacle(2, 2);
    grid.setObstacle(4, 0);

    std::cout << "=== Grid ===\n";
    grid.print();

    // コストの小さいNodeを優先して取り出す
    std::priority_queue<
        Node,
        std::vector<Node>,
        CompareCost
    > pq;

    // 候補となるマスを登録する
    pq.push({0, 0, 5});
    pq.push({1, 0, 2});
    pq.push({3, 1, 8});
    pq.push({4, 3, 1});

    std::cout << "\n=== Priority Queue ===\n";

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        std::cout
            << "x=" << current.x
            << ", y=" << current.y
            << ", cost=" << current.cost
            << '\n';
    }

    // 通行可能かどうかを確認する
    std::cout << "\n=== Walkability ===\n";

    std::cout << "(1, 1): "
              << grid.isWalkable(1, 1) << '\n';

    std::cout << "(2, 1): "
              << grid.isWalkable(2, 1) << '\n';

    std::cout << "(5, 1): "
              << grid.isWalkable(5, 1) << '\n';

    return 0;
}