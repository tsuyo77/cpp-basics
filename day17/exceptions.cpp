#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// ---------- 1. スタックの巻き戻し ----------
struct Guard {
    std::string name;
    explicit Guard(std::string n) : name(std::move(n)) {
        std::cout << "[生成] " << name << "\n";
    }
    ~Guard() { std::cout << "[破棄] " << name << "\n"; }
};

void inner() {
    Guard g("inner");
    throw std::runtime_error("inner で失敗");
}

void outer() {
    Guard g("outer");
    inner();
    std::cout << "ここは実行されない\n";
}

// ---------- 2. CSV の読み込み ----------
std::vector<std::string> split(const std::string& line, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

// 変換に失敗したら、行・列つきの例外に包み直す
int parse_cell(const std::string& s, int row, int col) {
    try {
        std::size_t pos = 0;
        int v = std::stoi(s, &pos);
        if (pos != s.size()) {
            throw std::invalid_argument("余計な文字がある");
        }
        return v;
    } catch (const std::exception&) {
        throw std::runtime_error("行" + std::to_string(row) + " 列" +
                                 std::to_string(col) +
                                 " の値が数字ではありません: '" + s + "'");
    }
}

std::vector<std::vector<int>> load_grid(std::istream& in) {
    std::vector<std::vector<int>> grid;
    std::string line;
    int row = 0;
    while (std::getline(in, line)) {
        std::vector<int> r;
        int col = 0;
        for (const auto& cell : split(line, ',')) {
            r.push_back(parse_cell(cell, row, col));
            col++;
        }
        if (!grid.empty() && r.size() != grid[0].size()) {
            throw std::runtime_error(
                "行" + std::to_string(row) + " の列数が違います(期待 " +
                std::to_string(grid[0].size()) + "、実際 " +
                std::to_string(r.size()) + ")");
        }
        grid.push_back(r);
        row++;
    }
    if (grid.empty()) {
        throw std::runtime_error("データがありません");
    }
    return grid;
}

std::vector<std::vector<int>> load_file(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("ファイルを開けません: " + path);
    }
    return load_grid(in);
}

void try_load(const std::string& label, std::istream& in) {
    std::cout << "--- " << label << " ---\n";
    try {
        auto g = load_grid(in);
        std::cout << "読めた: " << g.size() << "行 x " << g[0].size() << "列\n";
    } catch (const std::exception& e) {
        std::cout << "失敗: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "--- スタックの巻き戻し ---\n";
    try {
        outer();
    } catch (const std::exception& e) {
        std::cout << "捕まえた: " << e.what() << "\n";
    }

    std::istringstream good("0,0,1\n0,0,0\n");
    try_load("正常なデータ", good);

    std::istringstream bad_cell("0,0,1\n0,x,0\n");
    try_load("数字でないセル", bad_cell);

    std::istringstream empty_cell("0,,1\n");
    try_load("空のセル", empty_cell);

    std::istringstream uneven("0,0,1\n0,0\n");
    try_load("列数が違う行", uneven);

    std::istringstream none("");
    try_load("空データ", none);

    std::cout << "--- 存在しないファイル ---\n";
    try {
        load_file("nothing.csv");
    } catch (const std::exception& e) {
        std::cout << "失敗: " << e.what() << "\n";
    }

    return 0;
}