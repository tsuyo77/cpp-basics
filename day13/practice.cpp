#include <iostream>
#include <memory>
#include <string>
#include <vector>
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

 std::unique_ptr<Tracker> make_tracker(const std::string& name)
 {
    return std::make_unique<Tracker>(name);
 }

 void consume(std::unique_ptr<Tracker> t)
 {
    std::cout << "consume の中\n";
    t->hello();
 }


int main() 
{ 

    std::vector<std::unique_ptr<Tracker>> v ;
    v.push_back(std::make_unique<Tracker>("A"));
    v.push_back(std::make_unique<Tracker>("B"));
    v.push_back(std::make_unique<Tracker>("C"));

    for (const auto& p : v ){
        p->hello();
    }

    v.clear();

    std::cout << "clear後 \n";


    auto p = std::make_shared<Tracker>("P");
    auto q = p;
    std::cout << "use_count = " << p.use_count() << "\n";
    q.reset();
    std::cout << "use_count = " << p.use_count() << "\n";
    p.reset();
    std::cout << "use_count = " << p.use_count() << "\n";

    std::unique_ptr<Tracker> t = make_tracker("X");   // 作って返す
    consume(std::move(t));   // "consume の中" と表示し、t->hello() を呼ぶ
    std::cout << "t は空? " << (t == nullptr) << "\n";
    return 0; 
}

// fail が true のとき、return で関数を抜けるので delete p; を通らず、
// Tracker が破棄されない(メモリリーク。デストラクタも呼ばれず、[破棄] X が出ない)。
//
// unique_ptr で書き直した版:
// void f(bool fail) {
//     auto p = std::make_unique<Tracker>("X");
//     if (fail) return;   // return でスコープを出るとき、p が自動で破棄される
// }