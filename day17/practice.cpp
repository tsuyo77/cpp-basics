#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// exceptions.cpp から split / parse_cell / load_grid / load_file をコピー
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

// 問1:save_grid
void save_grid(const std::string& path,
               const std::vector<std::vector<int>>& grid) {
    std::ofstream out(path);
    if (!out) {
        throw std::runtime_error("ファイルを書き込み用に開けません: " + path);
    }
    for (const auto& row : grid) {
        for (std::size_t i = 0; i < row.size(); i++) {
            if (i > 0) out << ',';
            out << row[i];
        }
        out << "\n";
    }
}

// 問2:load_ascii_map
std::vector<std::vector<int>> load_ascii_map(std::istream& in) {
    std::vector<std::vector<int>> grid;
    std::string line;
    int row = 0;
    while (std::getline(in, line)) {
        std::vector<int> r;
        for (std::size_t col = 0; col < line.size(); col++) {
            char c = line[col];
            if (c == '.') {
                r.push_back(0);
            } else if (c == '#') {
                r.push_back(1);
            } else {
                throw std::runtime_error(
                    "行" + std::to_string(row) + " 列" + std::to_string(col) +
                    " に不正な文字があります: '" + std::string(1, c) + "'");
            }
        }
        grid.push_back(r);
        row++;
    }
    return grid;
}


// 問3:parse_int_or
int parse_int_or(const std::string& s, int fallback)
{
    try {
        std::size_t pos = 0;
        int v = std::stoi(s, &pos);
        if (pos != s.size()) {
            throw std::invalid_argument("余計な文字がある");
        }
        return v;
    } catch (const std::exception&) {
        return fallback;
    }
}

int main() {
    // 問1
    save_grid("out.csv", {{0, 1, 0}, {0, 0, 1}});
    for (const auto& row : load_file("out.csv")) {
        for (int c : row) std::cout << c << " ";
        std::cout << "\n";
    }
    try {
        save_grid("no_such_dir/out.csv", {{0, 1}});
    } catch (const std::exception& e) {
        std::cout << "失敗: " << e.what() << "\n";
    }

    // 問2
    for (const char* text : {"..#\n.#.\n", "..x\n"}) {
        std::istringstream ss(text);
        try {
            for (const auto& row : load_ascii_map(ss)) {
                for (int c : row) std::cout << c << " ";
                std::cout << "\n";
            }
        } catch (const std::exception& e) {
            std::cout << "失敗: " << e.what() << "\n";
        }
    }

    // 問3
    for (const char* s : {"42", "abc", "", "12abc", "-5", "99999999999"}) {
        std::cout << parse_int_or(s, -1) << "\n";
    }
    return 0;
}

// 問4のコメント:
//void process() {
//    std::vector<int> buf(100);
//    risky();
//}をしようする。newの場合メモリリークが起きる可能性があるため。