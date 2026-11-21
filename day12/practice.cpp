#include <iostream>
#include <vector>
#include <queue>

class Grid {
private:
    std::vector<std::vector<int>> cells;

public:
    Grid(int width, int height)
        : cells(height, std::vector<int>(width, 0)) {
        }

    bool isInside(int x, int y) const {
        return y >= 0 &&
               y < static_cast<int>(cells.size()) &&
               x >= 0 &&
               x < static_cast<int>(cells[y].size());
    }

    bool isWalkable(int x, int y) const {
        if(!isInside(x, y)) {
            return false;
        }
        return cells[y][x] == 0;
    }

    void setObstacle(int x, int y) {
        if(isInside(x,y)) {
            cells[y][x] = 1;
        }
    }
};

struct Node {
        int x;
        int y;
        int cost;
};

struct CompareCost {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost;
    }   
};

int main() {

    std::priority_queue<
    Node, 
    std::vector<Node>, 
    CompareCost> pq;
    pq.push({0, 0, 7});
    pq.push({1, 0, 3});
    pq.push({2, 1, 6});
    pq.push({3, 2, 1});

    while(!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        std::cout << "Node at (" << node.x << ", " << node.y << ") with cost: " << node.cost << std::endl;
    }

    Grid grid(5, 4);
    grid.setObstacle(2, 1);
    grid.setObstacle(2, 2);
    grid.setObstacle(4, 0);

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



    

