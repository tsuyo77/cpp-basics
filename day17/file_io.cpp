#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// カンマなどで区切って、vector<string> にする
std::vector<std::string> split(const std::string& line, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

int main() {
    // ---- 1. 書き出し ----
    {
        std::ofstream out("map.csv");
        if (!out) {
            std::cerr << "map.csv を書き込み用に開けません\n";
            return 1;
        }
        out << "0,0,0,1\n";
        out << "0,1,0,0\n";
        out << "0,0,0,0\n";
    }   // ここで out が破棄され、ファイルが閉じられる

    // ---- 2. 読み込み ----
    std::ifstream in("map.csv");
    if (!in) {
        std::cerr << "map.csv を開けません\n";
        return 1;
    }

    std::vector<std::vector<int>> grid;
    std::string line;
    while (std::getline(in, line)) {
        std::vector<int> row;
        for (const auto& cell : split(line, ',')) {
            row.push_back(std::stoi(cell));
        }
        grid.push_back(row);
    }

    // ---- 3. 確認 ----
    std::cout << "rows = " << grid.size()
              << ", cols = " << grid[0].size() << "\n";
    for (const auto& row : grid) {
        for (int c : row) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }

    // ---- split 単体の確認 ----
    for (const auto& s : split("a,b,c", ',')) {
        std::cout << "[" << s << "]";
    }
    std::cout << "\n";

    return 0;
}