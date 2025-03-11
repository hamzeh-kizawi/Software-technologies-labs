#include <iostream>
#include <vector>
#include <algorithm> // for remove_if

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    cout << "original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 != 0; }), numbers.end());

    cout << "removed odd numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    if (!numbers.empty()) {
        numbers.front() = 500;
        numbers.back() = 400;
    }

    cout << "replaced first and last element: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    if (numbers.size() > 4) {
        numbers.erase(numbers.begin() + 4);
    }

    cout << "removed the 5th element: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
