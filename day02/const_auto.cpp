#include <iostream>
#include <vector>

// コピーを避け、変更もしない:const参照
double sum(const std::vector<double>& v) {
    double s = 0.0;
    for (const auto& x : v) {
        s += x;
    }
    return s;
}

// 値を書き換える:非const参照
void scale(std::vector<double>& v, double k) {
    for (auto& x : v) {
        x *= k;
    }
}

int main() {
    const int N = 3;            // 変更不可
    // N = 5;                   // コメントを外すとコンパイルエラーになる

    std::vector<double> data = {1.0, 2.0, 3.0};

    std::cout << "sum = " << sum(data) << "\n";

    scale(data, 2.0);
    std::cout << "sum after scale = " << sum(data) << "\n";

    auto a = 10;        // int
    auto b = 3.14;      // double
    auto c = data[0];   // double
    std::cout << a << " " << b << " " << c << "\n";

    std::cout << "N = " << N << "\n";
    return 0;
}