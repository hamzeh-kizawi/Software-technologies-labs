#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0)
        data = std::make_unique<int[]>(rows * cols);
}
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (other.data) {
        data = std::make_unique<int[]>(rows * cols);
        for (int i = 0; i < rows * cols; ++i)
            data[i] = other.data[i];
    }
}
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        if (other.data) {
            data = std::make_unique<int[]>(rows * cols);
            for (int i = 0; i < rows * cols; ++i)
                data[i] = other.data[i];
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        result.data[i] = this->data[i] + other.data[i];
    }
    return result;
}
void Matrix::fill(int value) {
    for (int i = 0; i < rows * cols; ++i)
        data[i] = value;
}
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << data[i * cols + j] << " ";
        std::cout << "\n";
    }
}
