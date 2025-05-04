#include <iostream>
using namespace std;

template<typename T>
T multiply(T value) {
    return value;
}
template<typename T, typename... Args>
T multiply(T first, Args... rest) {
    return first * multiply(rest...);
}

int main() {
    cout << "product 1: "<< multiply(2, 3) << endl;
    cout << "product 2: "<< multiply(1.5, 4, 2) << endl;
    cout << "product 3: "<< multiply(1, 2, 3, 4, 5) << endl;
    cout << "product 4: "<< multiply(2.0f, 3.5f) << endl;
    return 0;
}
