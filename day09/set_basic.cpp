#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>

int main() {
    // ---- 基本 ----
    std::set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);   // 重複は、無視される
    s.insert(5);

    std::cout << "size = " << s.size() << "\n";
    for (const auto& e : s) {
        std::cout << e << " ";    // 小さい順に並ぶ
    }
    std::cout << "\n";

    // ---- あるか調べる ----
    std::cout << "count(20) = " << s.count(20) << "\n";
    std::cout << "count(99) = " << s.count(99) << "\n";
    if (s.find(10) != s.end()) {
        std::cout << "10 はある\n";
    }

    // ---- 消す ----
    s.erase(10);
    std::cout << "erase後 size = " << s.size() << "\n";

    // ---- マスの座標を入れる(pair) ----
    std::set<std::pair<int, int>> closed;
    closed.insert({2, 3});
    closed.insert({0, 0});
    closed.insert({2, 3});   // 重複

    std::cout << "closed.size = " << closed.size() << "\n";

    std::pair<int, int> cell = {2, 3};
    if (closed.count(cell) > 0) {
        std::cout << "(2, 3) は調べ済み\n";
    }
    if (closed.count({5, 5}) == 0) {
        std::cout << "(5, 5) はまだ\n";
    }

    // ---- unordered_set:使い方は同じ(順序は不定) ----
    std::unordered_set<int> us = {3, 1, 2};
    std::cout << "us.count(2) = " << us.count(2) << "\n";

    return 0;
}