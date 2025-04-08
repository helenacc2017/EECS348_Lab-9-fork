#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) : data(std::move(nums)) {}

Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = get_size();
    Matrix result(N);
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = get_size();
    Matrix result(N);
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            for (std::size_t k = 0; k < N; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    data.at(i).at(j) = n;
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
  if (i >= data.size() || j >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data.at(i).at(j);
}


int Matrix::get_size() const {
    return data.size();
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < get_size(); ++i)
        sum += data[i][i];
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < get_size(); ++i)
        sum += data[i][get_size() - 1 - i];
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < get_size() && r2 < get_size())
        std::swap(data[r1], data[r2]);
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < get_size() && c2 < get_size())
        for (auto& row : data)
            std::swap(row[c1], row[c2]);
}

void Matrix::print_matrix() const {
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << std::setw(5) << static_cast<double>(val);
        std::cout << "\n";
    }
}


