#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Tracker {
public:
    explicit Tracker(const std::string& name) : name_(name) {
        std::cout << "[生成] " << name_ << "\n";
    }
    ~Tracker() {
        std::cout << "[破棄] " << name_ << "\n";
    }
    void hello() const { std::cout << "hello from " << name_ << "\n"; }

private:
    std::string name_;
};

int main() {
    std::shared_ptr<Tracker> a = std::make_shared<Tracker>("S");
    std::cout << "use_count = " << a.use_count() << "\n";

    {
        std::shared_ptr<Tracker> b = a;   // コピーできる
        std::cout << "use_count = " << a.use_count() << "\n";
        b->hello();
    }
    std::cout << "ブロックの後 use_count = " << a.use_count() << "\n";

    std::vector<std::shared_ptr<Tracker>> list;
    list.push_back(a);
    list.push_back(a);
    std::cout << "vectorに2つ入れた use_count = " << a.use_count() << "\n";

    list.clear();
    std::cout << "clear後 use_count = " << a.use_count() << "\n";

    a.reset();   // 最後の持ち主が手放す
    std::cout << "reset後\n";

    return 0;
}