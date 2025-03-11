#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    cout << "Original list: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    numbers.remove_if([](int n) { return n % 2 != 0; });

    cout << "Removed odd numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    if (!numbers.empty()) {
        numbers.front() = 500;
        numbers.back() = 400;
    }

    cout << "Replaced first and last element: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    if (numbers.size() > 4) {
        auto it = numbers.begin();
        advance(it, 4);
        numbers.erase(it);
    }

    cout << "Removed the 5th element: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
