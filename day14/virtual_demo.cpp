#include <iostream>
#include <memory>
#include <string>

// インターフェース:実装を持たない約束だけの基底クラス
class Planner {
public:
    virtual ~Planner() { std::cout << "[Planner 破棄]\n"; }

    virtual std::string name() const = 0;             // 純粋仮想関数
    virtual double plan(double distance) const = 0;   // 所要時間を返す

    // 共通の処理:派生クラスの name() と plan() を呼ぶ
    void report(double distance) const {
        std::cout << name() << ": " << plan(distance) << " s\n";
    }
};

class FastPlanner : public Planner {
public:
    ~FastPlanner() override { std::cout << "[Fast 破棄]\n"; }

    std::string name() const override { return "Fast"; }
    double plan(double distance) const override { return distance / 2.0; }
};

class SafePlanner : public Planner {
public:
    ~SafePlanner() override { std::cout << "[Safe 破棄]\n"; }

    std::string name() const override { return "Safe"; }
    double plan(double distance) const override { return distance / 0.5 + 1.0; }
};

// 種類を知らずに、基底クラスの参照だけで使う
void show(const Planner& p) {
    p.report(20.0);
}

int main() {
    std::cout << "--- 1. 派生クラスのまま呼ぶ ---\n";
    FastPlanner f;
    SafePlanner s;
    f.report(10.0);
    s.report(10.0);

    std::cout << "--- 2. 基底クラスの参照で呼ぶ ---\n";
    show(f);
    show(s);

    std::cout << "--- 3. 基底クラスのポインタで持つ ---\n";
    {
        std::unique_ptr<Planner> p = std::make_unique<SafePlanner>();
        p->report(5.0);
    }

    std::cout << "--- 終了 ---\n";
    return 0;
}