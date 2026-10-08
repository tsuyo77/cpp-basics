#include <iostream>
#include <vector>

void swap_int(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int max_value(const std::vector<int>& v) {
    int m = v[0];
    for (const auto& x : v) {
        if (x > m) {
            m = x;
        }
    }
    return m;
}

void add_all(std::vector<double>& v, double n) {
    for (auto& x : v) {
        x += n;
    }
}

int main() {
    std::cout << "practice\n";

    int x = 1;
    int y = 2;
    std::vector<int> v_int = {1, 2, 3, 4, 5};

    std::vector<double> v = {1.0, 2.0 , 3.0};

    std::cout << "x = " << x << ", y = " << y << "\n";
    swap_int(x, y);
    std::cout << "x = " << x << ", y = " << y << "\n";

    int max = max_value(v_int);
    std::cout << "max = " << max << "\n";

    add_all(v, 0.5);
    std::cout << "v = ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

//危険な理由：Localのリターンが参照で返されると、Localの変数は関数終了時に破棄されるため、参照が無効になる。S
