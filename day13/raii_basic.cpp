#include <iostream>
#include <string>

class Tracker {
public:
    explicit Tracker(const std::string& name) : name_(name) {
        std::cout << "[生成] " << name_ << "\n";
    }
    ~Tracker() {
        std::cout << "[破棄] " << name_ << "\n";
    }

private:
    std::string name_;
};

void scope_demo() {
    std::cout << "scope_demo 開始\n";
    Tracker a("A");
    {
        Tracker b("B");
        std::cout << "内側のブロックの終わり\n";
    }
    Tracker c("C");
    std::cout << "scope_demo 終了\n";
}

int main() {
    scope_demo();

    std::cout << "--- new/delete(手動) ---\n";
    Tracker* p = new Tracker("D");
    std::cout << "Dを使っている\n";
    delete p;   // これを忘れると、デストラクタが呼ばれない

    std::cout << "main 終了\n";
    return 0;
}