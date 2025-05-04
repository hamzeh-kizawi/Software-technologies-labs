#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printValue(T value) {
    cout << value << endl;
}

template <typename T1, typename T2>
void printValue(T1 a, T2 b) {
    if constexpr (is_same<T1, int>::value && is_same<T2, int>::value) {
        if (a % 2 != 0) cout << a << endl;

        else if (b % 2 != 0) cout << b << endl;

        else cout << "both are even" << endl;

    } else {
        cout << a << " " << b << endl;
    }
}

int main() {
    printValue("Hello");
    printValue("Hello,", "world");
    printValue(3, 4);
    printValue(2, 6);
    printValue(5.6, 9);
    return 0;
}
