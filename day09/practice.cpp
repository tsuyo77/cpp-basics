#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    
    
    std::vector<std::string> words = {"cat", "dog", "cat", "bird", "dog", "cat"};
    
    std::map<std::string, int> counts;
    for (const auto& w : words) {
        counts[w]++;
    }
    for (const auto& kv : counts) {
        std::cout << kv.first << ": " << kv.second << "\n";
    }

    std::map<std::pair<int, int>, int> cost;
    cost[{1, 1}] = 5;
    cost[{2, 3}] = 8;

    if( cost.find({1, 1}) != cost.end() ) {
        std::cout << "cost(1, 1) = " << cost[{1, 1}] << "\n";
    }
    if( cost.find({9, 9}) == cost.end() ) {
        std::cout << "(9, 9) not found\n";
    }

    std::set<std::pair<int, int>> closed;
    closed.insert({0, 0});
    closed.insert({1, 0});
    closed.insert({1, 1});
    closed.insert({0, 0});
    closed.insert({2, 1});

    std::cout << "closed.size = " << closed.size() << "\n";

    for (const auto& cell : closed) {
        std::cout << "(" << cell.first << ", " << cell.second << ") ";
    }
    std::cout << "\n";

    return 0; }
//stock["banana"]が[]により、stock内に作成され、sizeは2になる。