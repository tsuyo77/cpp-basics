#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Grid2D {
public:
    Grid2D(int width, int height, const T& init)
        : width_(width), height_(height),
          cells_(height, std::vector<T>(width, init)) {}

    int width() const { return width_; }
    int height() const { return height_; }

    T& at(int x, int y) { return cells_[y][x]; }
    const T& at(int x, int y) const { return cells_[y][x]; }

    void print() const {
        for (const auto& row : cells_) {
            for (const auto& c : row) {
                std::cout << c << " ";
            }
            std::cout << "\n";
        }
    }

private:
    int width_;
    int height_;
    std::vector<std::vector<T>> cells_;
};