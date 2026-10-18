#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

void print(const std::vector<int>& v) {
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    // ---- 作り方 ----
    std::vector<int> a;                 // 空
    std::vector<int> b(5);              // 要素5個、すべて0
    std::vector<int> c(5, 7);           // 要素5個、すべて7
    std::vector<int> d = {1, 2, 3};     // 値を並べて初期化

    std::cout << "a.size = " << a.size() << "\n";
    std::cout << "b: "; print(b);
    std::cout << "c: "; print(c);
    std::cout << "d: "; print(d);

    // ---- アクセス ----
    std::cout << "d[0] = " << d[0] << "\n";
    std::cout << "d.front() = " << d.front() << ", d.back() = " << d.back() << "\n";
    std::cout << "d.at(1) = " << d.at(1) << "\n";

    // ---- 追加 ----
    d.push_back(4);
    d.push_back(5);
    std::cout << "push_back後: "; print(d);

    d.insert(d.begin() + 1, 99);        // 1番目の位置に99を挿入
    std::cout << "insert後:    "; print(d);

    // ---- 削除 ----
    d.pop_back();                       // 末尾を削除
    std::cout << "pop_back後:  "; print(d);

    d.erase(d.begin() + 1);             // 1番目の要素を削除
    std::cout << "erase後:     "; print(d);

    d.clear();                          // 全削除
    std::cout << "clear後 size = " << d.size()
              << ", empty = " << d.empty() << "\n";

    // ---- 構造体も入れられる ----
    std::vector<Point> path;
    path.push_back({0, 0});
    path.push_back({1, 0});
    path.push_back({1, 1});
    for (const auto& p : path) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\n";

    return 0;
}