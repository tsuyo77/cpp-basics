#include <iostream>
#include <memory>
#include <string>
#include <vector>

// 問1:Shape、Circle、Rect
class Shape {
public:
    virtual double area() const = 0;
    virtual std::string name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    explicit Circle(double r) : radius_(r) {}
    ~Circle() override = default;
    double area() const override { return 3.14159 * radius_ * radius_; }
    std::string name() const override { return "Circle"; }
private:
    double radius_;
};

class Rect : public Shape {
    public:
    Rect(double w, double h) : width_(w), height_(h) {}
    ~Rect() override = default;
    double area() const override { return width_ * height_; }
    std::string name() const override { return "Rect"; }
private:
    double width_;
    double height_;
};

// 問2:Controller、PController、PDController、run
class Controller {
public:
    virtual ~Controller() = default;
    virtual double update(double error) = 0;   // constを付けない(状態を持つため)
};

class PController : public Controller{
    public:
    ~PController() override = default;
    explicit PController(double kp) : kp_(kp){}
    
    double update(double error) override {
        return kp_ * error;
    }
private:
    double kp_;
};

class PDController : public Controller{
    public:
    ~PDController() override = default;
    PDController (double kp , double kd, double dt) : kp_(kp),kd_(kd),dt_(dt){}
    double update(double error) override {
        double derivative = (error - prev_error_) / dt_;
        prev_error_ = error;
        return kp_ * error + kd_ * derivative;
    }
    private:
    double prev_error_ = 0.0;
    double kp_;
    double kd_;
    double dt_;
};

void run(Controller& c, const std::vector<double>& errors)
{
    for (double e : errors) {
        double u = c.update(e);
        std::cout << "error: " << e << ", control output: " << u << std::endl;
    }
}

// 問3・問4で使うクラスは、main の外に書く
class A {
public:
    virtual ~A() = default;
    void f() const { std::cout << "A::f\n"; }
    virtual void g() const { std::cout << "A::g\n"; }
};
class B : public A {
public:
    void f() const { std::cout << "B::f\n"; }
    void g() const override { std::cout << "B::g\n"; }
};

class Base {
public:
    virtual ~Base() { std::cout << "[Base 破棄]\n"; }   // virtual を足す
};
class Derived : public Base {
public:
    ~Derived() { std::cout << "[Derived 破棄]\n"; }
};

int main() {
    // 問1
    std::vector<std::unique_ptr<Shape>> p;
    p.push_back(std::make_unique<Circle>(1.0));
    p.push_back(std::make_unique<Rect>(2.0, 3.0));
    p.push_back(std::make_unique<Rect>(1.5, 2.0));
    
    // 問2
    std::vector<double> errors = {1.0, 0.5, 0.2};
    PController p1(2.0);
    std::cout << "P: ";
    run(p1, errors);
    PDController pd(2.0, 1.0, 1.0);
    std::cout << "PD: ";
    run(pd, errors);

    // 問3
    std::unique_ptr<A> p2 = std::make_unique<B>();
    p2->f();
    p2->g();
    B b;
    b.f();
    b.g();
  // 問3の予想: A::f, B::g, B::f, B::g
// 理由:
// f は virtual ではないので、呼ぶ関数は「ポインタの型」(A*)で決まり、A::f が呼ばれる。
// g は virtual なので、呼ぶ関数は「実体の型」(B)で決まり、B::g が呼ばれる。
// b.f() は変数 b の型が B だと分かっているので、どちらも B 版が呼ばれる。
    // 問4
    {
    std::unique_ptr<Base> q = std::make_unique<Derived>();
    }


    return 0;
}


// 問4の問題と直し方:
//デストラクタにvirtual関数がないのでDeriveが破棄されない。