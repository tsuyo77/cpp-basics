#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T clamp_value(const T& v, const T& lo, const T& hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

template <typename T>
bool contains(const std::vector<T>& v, const T& x) {
    for (const auto& e : v) {
        if (e == x) {
            return true;
        }
    }
    return false;
}

template <typename T>
class Stack {
    public:
    void push(const T& x) {
        data_.push_back(x);
    }
    void pop(){
        data_.pop_back();
    }
    const T& top() const {
        return data_.back();
    }
    bool empty() const {
        return data_.empty();
    }

    std::size_t size() const{
        return data_.size();
    }
    private:
    std::vector<T> data_;
};

template <typename T>
T sum(const std::vector<T>& v) {
    T total{};
    for (const auto& e : v) {
        total += e;
    }
    return total;
}

struct V { int x; int y; };

V& operator+=(V& a, const V& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

int main() {
    // 問1
    std::cout << clamp_value(15, 0, 10) << "\n";
    std::cout << clamp_value(-0.5, 0.0, 1.0) << "\n";
    std::cout << clamp_value(5, 0, 10) << "\n";

    // 問2
    std::cout << contains(std::vector<int>{1, 2, 3}, 2) << "\n";
    std::cout << contains(std::vector<std::string>{"a", "b"}, std::string("z")) << "\n";

    // 問3
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << "\n";
    s.pop();
    std::cout << s.top() << "\n";
    std::cout << s.size() << "\n";

    Stack<std::string> t;
    t.push("a");
    t.push("b");
    std::cout << t.top() << "\n";

    // 問4
    V r = sum(std::vector<V>{{1, 2}, {3, 4}});
    std::cout << "(" << r.x << ", " << r.y << ")\n";

    return 0;
}
