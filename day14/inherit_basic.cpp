#include <iostream>
#include <string>

class Robot {
public:
    explicit Robot(const std::string& name) : name_(name) {
        std::cout << "[Robot 生成] " << name_ << "\n";
    }
    virtual ~Robot() {
        std::cout << "[Robot 破棄] " << name_ << "\n";
    }

    void hello() const { std::cout << "I am " << name_ << "\n"; }
    virtual void describe() const { std::cout << "Robot: " << name_ << "\n"; }

protected:
    std::string name_;   // 派生クラスから使える
};

class Drone : public Robot {
public:
    Drone(const std::string& name, double max_alt)
        : Robot(name), max_alt_(max_alt) {
        std::cout << "[Drone 生成] " << name_ << "\n";
    }
    ~Drone() {
        std::cout << "[Drone 破棄] " << name_ << "\n";
    }

    void fly() const {
        std::cout << name_ << " flies up to " << max_alt_ << " m\n";
    }
    void describe() const override{   // 基底と同じ名前の関数
        std::cout << "Drone: " << name_ << " (max " << max_alt_ << " m)\n";
    }

private:
    double max_alt_;
};

// Robot の参照で受け取る関数
void show(const Robot& r) {
    r.describe();
}

int main() {
    {
        Drone d("D1", 120.0);
        d.hello();      // 基底クラスから引き継いだ関数
        d.fly();
        d.describe();

        std::cout << "--- Robot の参照で呼ぶ ---\n";
        show(d);

        std::cout << "ブロックの終わり\n";
    }
    return 0;
}