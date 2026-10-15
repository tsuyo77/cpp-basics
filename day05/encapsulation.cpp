#include <iostream>

class Motor {
public:
    explicit Motor(double max_rpm) : rpm_(0.0), max_rpm_(max_rpm) {}

    // 指令値を設定(範囲外は丸める)
    void set_rpm(double rpm) {
        if (rpm > max_rpm_) rpm = max_rpm_;
        if (rpm < 0.0) rpm = 0.0;
        rpm_ = rpm;
    }

    // 現在値を読む(変更しないのでconst)
    double rpm() const { return rpm_; }

private:
    double rpm_;
    double max_rpm_;
};

int main() {
    Motor m(3000.0);

    m.set_rpm(1500.0);
    std::cout << "rpm = " << m.rpm() << "\n";

    m.set_rpm(9999.0);   // 上限を超える
    std::cout << "rpm = " << m.rpm() << "\n";

    m.set_rpm(-100.0);   // 負の値
    std::cout << "rpm = " << m.rpm() << "\n";

    // m.rpm_ = 99999.0; // コメントを外すとコンパイルエラー

    return 0;
}