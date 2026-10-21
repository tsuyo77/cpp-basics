#include <array>
#include <iostream>
#include <string>

    std::string make_name(const std::string& base, int id)
    {
        return base + "_" + std::to_string(id);
    }

int main() {

    
    std::string line = "speed=1.5";
    std::size_t pos = line.find("=");
    if(line.find("=") == std::string::npos) {
       std::cout << "Error: '=' not found in the line.\n";
       return 1;
    }

    std::string key = line.substr(0, pos);
    double value = std::stod(line.substr(pos + 1));
    std::cout << "key = " << key << ", value * 2 = " << value * 2.0 << "\n";

    for( int i = 1; i <= 3; i++) {
        std::string name = make_name("robot", i);
        std::cout << name << "\n";
    }

    const std::array<int, 4> dx = {1, -1, 0, 0};
    const std::array<int, 4> dy = {0, 0, 1, -1};
    int x = 2;
    int y = 2;
    for (std::size_t i = 0; i < dx.size(); i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            std::cout << "(" << nx << ", " << ny << ") ";
        }
    }
    std::cout << "\n";
    return 0; 
}
// std::array<int, 4> と std::array<int, 5> は要素数も型の一部で、別の型。
// print は array<int, 4> 専用なので、array<int, 5> は渡せず、必ずコンパイルエラーになる。