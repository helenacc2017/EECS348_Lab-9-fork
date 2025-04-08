#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"

template <typename T>
void process_matrix(std::ifstream& inFile) {
    std::size_t N;
    inFile >> N;

    // create the matrix to hold the input
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

    // Create the matrix to use
    Matrix<T> m1(mat1);
    Matrix<T> m2(mat2);

    // (1) Print the original matrix
    std::cout << "\n(1/7) Printing Matrix info from file:";
    std::cout << "Matrix 1:\n";
    m1.print_matrix();
    std::cout << "Matrix 2:\n";
    m2.print_matrix();

    // (2) Addition operation
    Matrix<T> sum = m1 + m2;
    std::cout << "\n(2/7) Sum of Matrices:\n";
    sum.print_matrix();

    // (3) Multiplication operation
    Matrix<T> product = m1 * m2;
    std::cout << "\n(3/7) Product of Matrices:\n";
    product.print_matrix();

    // (4) Diagonal sums operation
    std::cout << "\n(4/7) Sum of Major Diagonal (Matrix 1): " << m1.sum_diagonal_major() << std::endl;
    std::cout << "(4/7) Sum of Minor Diagonal (Matrix 1): " << m1.sum_diagonal_minor() << std::endl;
    std::cout << "\n(4/7) Sum of Major Diagonal (Matrix 2): " << m2.sum_diagonal_major() << std::endl;
    std::cout << "(4/7) Sum of Minor Diagonal (Matrix 2): " << m2.sum_diagonal_minor() << std::endl;

    // (5) Swapping Rows (mat 1)
    std::size_t r1, r2;
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> r1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> r2;
    if ( (r1 >= m1.get_size()) || (r2 >= m1.get_size()) ) {
        std::cout << "\ninvalid row index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m1.swap_rows(r1, r2);
        std::cout << "(5/7) Matrix 1 after swapping rows:\n";
        m1.print_matrix();
    }
    // Swapping Rows (mat 2)
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> r1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> r2;
    if ( (r1 >= m2.get_size()) || (r2 >= m2.get_size()) ) {
        std::cout << "\ninvalid row index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m2.swap_rows(r1, r2);
        std::cout << "(5/7) Matrix 2 after swapping rows:\n";
        m2.print_matrix();
    }

    // (6) Swapping Columns (mat 1)
    std::size_t c1, c2;
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c2;
    if ( (c1 >= m1.get_size()) || (c2 >= m1.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m1.swap_cols(c1, c2);
        std::cout << "(6/7) Matrix 1 after swapping cols:\n";
        m1.print_matrix();
    }
    // Swapping Columns (mat 2)
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c2;
    if ( (c1 >= m2.get_size()) || (c2 >= m2.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m2.swap_cols(c1, c2);
        std::cout << "(6/7) Matrix 2 after swapping cols:\n";
        m2.print_matrix();
    }

    // (7) Updating a Single Value (mat 1)
    std::size_t row, col;
    int newVal;
    std::cout << "\nEnter row index for new value update for (Matrix 1): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 1): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 1): ";
    std::cin >> newVal;
    if ( (row >= m1.get_size()) || (col >= m1.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m1.set_value(row, col, newVal);
        std::cout << "(7/7) Matrix 1 after updating value:\n";
        m1.print_matrix();
    }
    // Updating a Single Value (mat 2)
    std::cout << "\nEnter row index for new value update for (Matrix 2): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 2): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 2): ";
    std::cin >> newVal;
    if ( (row >= m2.get_size()) || (col >= m2.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        m2.set_value(row, col, newVal);
        std::cout << "(7/7) Matrix 2 after updating value:\n";
        m2.print_matrix();
    }
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
