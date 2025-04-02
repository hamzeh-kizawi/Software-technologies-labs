#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::cout << "original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (numbers.size() >= 5) {
        numbers.erase(numbers.begin(), numbers.begin() + 5);
    }

    std::cout << "after removing the  first 5 elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    std::vector<int> moreNumbers = {15, 23, 34, 42, 55, 61, 73, 84, 97, 100};

    std::cout << "original vector: ";
    for (int num : moreNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    moreNumbers.erase(
            std::remove_if(moreNumbers.begin(), moreNumbers.end(),
                           [](int x) { return x % 2 == 0; }),
            moreNumbers.end()
    );

    std::cout << "after removing  the even numbers: ";
    for (int num : moreNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}