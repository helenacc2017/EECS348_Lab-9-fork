#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip> // for std::setw

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    Matrix<T> operator+(const Matrix<T>& rhs) const;
    Matrix<T> operator*(const Matrix<T>& rhs) const;

    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    std::size_t get_size() const;

    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;

    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);

    void print_matrix() const;
};

#include "matrix.tpp" // Include implementation file

#endif
