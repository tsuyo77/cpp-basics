#include <iostream>
#include <string>

int main() {
    // ---- 作り方 ----
    std::string a = "robot";
    std::string b("nav");
    std::string c(3, '*');          // '*' が3個
    std::cout << a << " " << b << " " << c << "\n";

    // ---- 連結 ----
    std::string topic = "/" + a + "/" + b;
    topic += "/cmd_vel";
    std::cout << topic << "\n";

    // ---- サイズと文字アクセス ----
    std::cout << "size = " << topic.size() << "\n";
    std::cout << "topic[0] = " << topic[0] << "\n";
    std::cout << "front = " << topic.front() << ", back = " << topic.back() << "\n";

    // ---- 比較 ----
    std::string x = "abc";
    std::string y = "abc";
    std::cout << "x == y : " << (x == y) << "\n";

    // ---- 検索と切り出し ----
    std::string path = "map/floor1/room_A.csv";

    std::size_t pos = path.find("floor1");
    std::cout << "find floor1 = " << pos << "\n";

    if (path.find("xyz") == std::string::npos) {
        std::cout << "xyz は見つからない\n";
    }

    std::size_t dot = path.rfind('.');           // 最後の'.'の位置
    std::string ext  = path.substr(dot);         // ".csv"
    std::string stem = path.substr(0, dot);      // "map/floor1/room_A"
    std::cout << "ext = " << ext << ", stem = " << stem << "\n";

    // ---- 数値との変換 ----
    int n = 42;
    std::string s = "ID_" + std::to_string(n);
    std::cout << "s = " << s << "\n";

    int m = std::stoi("123");
    double d = std::stod("3.14");
    std::cout << "stoi = " << m << ", stod = " << d << "\n";

    return 0;
}