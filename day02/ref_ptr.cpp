#include <iostream>

// C流:ポインタで渡す
void add_one_ptr(int* p) {
    *p += 1;
}

// C++流:参照で渡す
void add_one_ref(int& r) {
    r += 1;
}

int main() {
    int x = 10;

    add_one_ptr(&x);
    std::cout << "after ptr: " << x << "\n";

    add_one_ref(x);   // &を付けなくてよい
    std::cout << "after ref: " << x << "\n";

    // 参照は別名
    int& alias = x;
    alias = 100;
    std::cout << "x = " << x << "\n";

    // 参照とポインタのアドレス比較
    std::cout << "&x     = " << &x << "\n";
    std::cout << "&alias = " << &alias << "\n";

    // nullptr(CのNULLの代わり)
    int* p = nullptr;
    if (p == nullptr) {
        std::cout << "p is null\n";
    }

    return 0;
}