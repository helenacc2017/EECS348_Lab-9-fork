// matrix.tpp
#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
Matrix<T>::Matrix(std::size_t N) : data(N, std::vector<T>(N)) {}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums) : data(std::move(nums)) {}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
    std::size_t N = get_size();
    Matrix<T> result(N);
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const {
    std::size_t N = get_size();
    Matrix<T> result(N);
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            for (std::size_t k = 0; k < N; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n) {
    data.at(i).at(j) = n;
}

template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    return data.at(i).at(j);
}

template <typename T>
std::size_t Matrix<T>::get_size() const {
    return data.size();
}

template <typename T>
T Matrix<T>::sum_diagonal_major() const {
    T sum = 0;
    for (std::size_t i = 0; i < get_size(); ++i)
        sum += data[i][i];
    return sum;
}

template <typename T>
T Matrix<T>::sum_diagonal_minor() const {
    T sum = 0;
    for (std::size_t i = 0; i < get_size(); ++i)
        sum += data[i][get_size() - 1 - i];
    return sum;
}

template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < get_size() && r2 < get_size())
        std::swap(data[r1], data[r2]);
}

template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < get_size() && c2 < get_size()) {
        for (auto& row : data)
            std::swap(row[c1], row[c2]);
    }
}

template <typename T>
void Matrix<T>::print_matrix() const {
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << std::setw(10) << static_cast<double>(val);
        std::cout << '\n';
    }
    std::cout << std::endl;
}
