#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "matrix.hpp"

template<typename T>
void update_matrix_element(std::vector<std::vector<T>>& matrix, size_t row, size_t col, T new_value) {
    if (row < matrix.size() && col < matrix.size())
        matrix[row][col] = new_value;
}

template<typename T>
void swap_vector_rows(std::vector<std::vector<T>>& matrix, size_t r1, size_t r2) {
    if (r1 < matrix.size() && r2 < matrix.size())
        std::swap(matrix[r1], matrix[r2]);
}

template<typename T>
void swap_vector_cols(std::vector<std::vector<T>>& matrix, size_t c1, size_t c2) {
    if (c1 < matrix.size() && c2 < matrix.size()) {
        for (auto& row : matrix)
            std::swap(row[c1], row[c2]);
    }
}

int main(int argc, char* argv[]) {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::size_t N;
    int type_flag;
    inFile >> N >> type_flag;

    std::vector<std::vector<int>> mat1(N, std::vector<int>(N));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N));

    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            inFile >> mat1[i][j];

    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            inFile >> mat2[i][j];

    Matrix m1(mat1);
    Matrix m2(mat2);

    std::cout << "Matrix 1:\n";
    m1.print_matrix();
    std::cout << "\nMatrix 2:\n";
    m2.print_matrix();

    Matrix sum = m1 + m2;
    std::cout << "\nMatrix Addition:\n";
    sum.print_matrix();

    Matrix product = m1 * m2;
    std::cout << "\nMatrix Multiplication:\n";
    product.print_matrix();

    std::cout << "\nMain Diagonal Sum of Matrix 1: " << m1.sum_diagonal_major() << "\n";
    std::cout << "Secondary Diagonal Sum of Matrix 1: " << m1.sum_diagonal_minor() << "\n";

    m1.swap_rows(0, 1);
    std::cout << "\nMatrix 1 After Swapping Row 0 and Row 1:\n";
    m1.print_matrix();

    m1.swap_cols(0, 1);
    std::cout << "\nMatrix 1 After Swapping Column 0 and Column 1:\n";
    m1.print_matrix();

    update_matrix_element(mat1, 2, 2, 99);
    std::cout << "\nMatrix 1 Vector After Updating Element (2,2) to 99:\n";
    for (const auto& row : mat1) {
        for (auto val : row)
            std::cout << std::setw(5) << static_cast<double>(val);
        std::cout << "\n";
    }

    return 0;
}


