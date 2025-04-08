#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"

template <typename T>
void process_matrix(std::ifstream& inFile) {
    std::size_t N;
    inFile >> N;

    std::vector<std::vector<T>> mat1(N, std::vector<T>(N));
    std::vector<std::vector<T>> mat2(N, std::vector<T>(N));

    // Read first matrix
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            inFile >> mat1[i][j];

    // Read second matrix
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            inFile >> mat2[i][j];

    Matrix<T> m1(mat1);
    Matrix<T> m2(mat2);

    std::cout << "Matrix 1:\n";
    m1.print_matrix();
    std::cout << "Matrix 2:\n";
    m2.print_matrix();

    // Addition
    Matrix<T> sum = m1 + m2;
    std::cout << "Sum:\n";
    sum.print_matrix();

    // Multiplication
    Matrix<T> product = m1 * m2;
    std::cout << "Product:\n";
    product.print_matrix();

    // Diagonal sums
    std::cout << "Main diagonal sum of Matrix 1: " << m1.sum_diagonal_major() << "\n";
    std::cout << "Minor diagonal sum of Matrix 1: " << m1.sum_diagonal_minor() << "\n\n";

    // Swap rows (0 and 1)
    std::cout << "Matrix 1 after swapping rows 0 and 1:\n";
    m1.swap_rows(0, 1);
    m1.print_matrix();

    // Swap columns (0 and 1)
    std::cout << "Matrix 1 after swapping cols 0 and 1:\n";
    m1.swap_cols(0, 1);
    m1.print_matrix();

    // Update element (0,0) to a new value
    T new_value;
    std::cout << "Enter a new value to update position (0,0): ";
    std::cin >> new_value;
    m1.set_value(0, 0, new_value);
    std::cout << "Matrix 1 after updating (0,0):\n";
    m1.print_matrix();
}

int main() {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Could not open input.txt\n";
        return 1;
    }

    std::size_t N;
    int type_flag;
    inFile >> N >> type_flag;

    inFile.seekg(0); // rewind to re-read from start

    if (type_flag == 0) {
        process_matrix<int>(inFile);
    } else if (type_flag == 1) {
        process_matrix<double>(inFile);
    } else {
        std::cerr << "Invalid matrix type flag in file. Expected 0 (int) or 1 (double).\n";
        return 1;
    }

    return 0;
}
