#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

void print(const char* label, const std::vector<int>& v) {
    std::cout << label;
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {5, 3, 8, 1, 9, 2};
    print("元: ", v);

    // ---- 並べ替え ----
    std::sort(v.begin(), v.end());                          // 昇順
    print("昇順: ", v);

    std::sort(v.begin(), v.end(), std::greater<int>());     // 降順
    print("降順: ", v);

    std::reverse(v.begin(), v.end());                       // 逆順
    print("reverse後: ", v);

    // ---- 探す ----
    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) {
        std::cout << "8 は添字 " << (it - v.begin()) << " にある\n";
    }

    auto it2 = std::find(v.begin(), v.end(), 7);
    if (it2 == v.end()) {
        std::cout << "7 は見つからない\n";
    }

    // ---- 最大・最小 ----
    std::cout << "max = " << *std::max_element(v.begin(), v.end())
              << ", min = " << *std::min_element(v.begin(), v.end()) << "\n";

    // ---- 数える ----
    std::vector<int> w = {1, 2, 2, 3, 2};
    std::cout << "count(2) = " << std::count(w.begin(), w.end(), 2) << "\n";

    
    std::vector<std::string> s = {"dog", "cat", "bird"};
    std::sort(s.begin(), s.end());
    for (const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    std::vector<int> t = {9, 5, 3, 8, 1};
    std::sort(t.begin() + 1, t.end());
    print("先頭を除いて昇順:: ", t);

    std::vector<int> e;
    std::cout << (std::find(e.begin(), e.end(), 1) == e.end()) << "\n";

    return 0;
}