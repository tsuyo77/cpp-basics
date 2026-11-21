#include <iostream>
#include <memory>
#include <string>
#include <utility>

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

// 使うだけ(所有しない):参照で受け取る
void use(const Tracker& t) { t.hello(); }

// 所有権を受け取る:unique_ptr を値で受け取る
void take(std::unique_ptr<Tracker> t) {
    std::cout << "take の中\n";
    t->hello();
}   // ここで t が破棄され、Tracker も破棄される

// 所有権を返す
std::unique_ptr<Tracker> make(const std::string& name) {
    return std::make_unique<Tracker>(name);
}

int main() {
    {
        std::unique_ptr<Tracker> a = std::make_unique<Tracker>("A");
        a->hello();
        use(*a);
        std::cout << "ブロックの終わり\n";
    }   // delete を書いていないのに、破棄される

    std::cout << "--- 所有権の移動 ---\n";
    auto b = std::make_unique<Tracker>("B");
    // auto c = b;            // コピーは禁止(コメントを外すとエラー)
    auto c = std::move(b);
    std::cout << "b は空? " << (b == nullptr)
              << ", c は空? " << (c == nullptr) << "\n";

    std::cout << "--- 関数に渡す ---\n";
    take(std::move(c));
    std::cout << "take の後、c は空? " << (c == nullptr) << "\n";

    std::cout << "--- 関数から受け取る ---\n";
    auto d = make("D");
    d->hello();

    std::cout << "--- reset ---\n";
    d.reset();
    std::cout << "reset の後\n";

    std::cout << "main 終了\n";
    return 0;
}