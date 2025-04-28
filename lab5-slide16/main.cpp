#include "Matrix.h"
#include <iostream>

int main() {
    Matrix a(2, 2);
    Matrix b(2, 2);
    a.fill(1);
    b.fill(2);
    Matrix c(b);
    Matrix d = a;
    Matrix e = a + b;
    std::cout << "matrix a:\n";
    a.print();
    std::cout << "\nMatrix b:\n";
    b.print();
    std::cout << "\nMatrix c (copyof b):\n";
    c.print();
    std::cout << "\nMatrix d (assigned from a):\n";
    d.print();
    std::cout << "\nMatrix e (a + b):\n";
    e.print();
    return 0;
}
