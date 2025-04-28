#pragma once
#include <memory>

class Matrix {
private:
    int rows, cols;
    std::unique_ptr<int[]> data;
public:
    Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    void fill(int value);
    void print() const;
};
