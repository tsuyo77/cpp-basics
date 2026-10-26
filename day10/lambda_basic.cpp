#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    int x;
    int y;
    double cost;
};

void print(const std::vector<Node>& nodes) {
    for (const auto& n : nodes) {
        std::cout << "(" << n.x << "," << n.y << ") cost=" << n.cost << "\n";
    }
}

int main() {
    // ---- ラムダ式を変数に入れて呼ぶ ----
    auto add = [](int a, int b) { return a + b; };
    std::cout << "add(2, 3) = " << add(2, 3) << "\n";

    // ---- sortの比べ方をラムダで書く ----
    std::vector<int> v = {5, 3, 8, 1, 9, 2};
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (const auto& e : v) std::cout << e << " ";
    std::cout << "\n";

    // ---- 構造体のメンバで比べる ----
    std::vector<Node> nodes = {
        {0, 0, 5.0},
        {1, 0, 2.5},
        {1, 1, 7.1},
        {2, 1, 1.0},
    };

    std::sort(nodes.begin(), nodes.end(),
              [](const Node& a, const Node& b) { return a.cost < b.cost; });

    std::cout << "--- コストの小さい順 ---\n";
    print(nodes);

    // ---- 文字列を長さ順に ----
    std::vector<std::string> words = {"robot", "a", "navigation", "map"};
    std::sort(words.begin(), words.end(),
         
    [](const std::string& a, const std::string& b) {
                  return a.size() < b.size();
              });
    for (const auto& w : words) std::cout << w << " ";
    std::cout << "\n";

    // ---- キャプチャ:外の変数を使う ----
    double limit = 3.0;
    auto it = std::find_if(nodes.begin(), nodes.end(),
                           [limit](const Node& n) { return n.cost > limit; });
    if (it != nodes.end()) {
        std::cout << "cost > " << limit << " の最初: ("
                  << it->x << "," << it->y << ") cost=" << it->cost << "\n";
    }

    return 0;
}