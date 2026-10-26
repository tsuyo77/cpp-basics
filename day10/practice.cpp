#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Point { int x; int y; };

int main() {
    // 問1
    std::vector<int> v = {-5, 3, -1, 4, -2};
    std::sort(v.begin(),v.end(),[](int a,int b){ return std::abs(a) < std::abs(b); });

    for(int n : v)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 問2
    std::vector<Point> pts = {{3, 4}, {1, 1}, {0, 5}, {2, 0}};
    std::sort(pts.begin(),pts.end(),
              [](const Point& a,const Point& b){return (a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y); });

    for (const auto& p : pts) {
        std::cout << "(" << p.x << "," << p.y << ") ";
    }
    std::cout << "\n";

    // 問3
    std::vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8};
    int count = std::count_if(v3.begin(), v3.end(), [](int x) {
        return x % 3 == 0;
    });

    std::cout << "問3: 3の倍数: " << count << "個\n";

    return 0;
}

// 問4のコメント:
// 値キャプチャ [threshold]:ラムダを作った時点の値をコピーして持つ。
//   あとで threshold を変えても、ラムダの中の値は変わらない。
//   int threshold = 3; auto f = [threshold](int x){ return x > threshold; };
//   threshold = 10; f(5) → true (5 > 3 のまま)
// 参照キャプチャ [&threshold]:元の変数そのものを参照する。
//   あとで threshold を変えると、ラムダの挙動も変わる。
//   int threshold = 3; auto g = [&threshold](int x){ return x > threshold; };
//   threshold = 10; g(5) → false (5 > 10 になる)
// キャプチャし忘れると、ラムダの中で threshold が使えず、コンパイルエラーになる。