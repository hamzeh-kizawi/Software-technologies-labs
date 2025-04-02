#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> oddNumbers(numbers.size());

        auto it = std::copy_if(numbers.begin(), numbers.end(), oddNumbers.begin(),
                               [](int num) { return num % 2 != 0; });
        oddNumbers.resize(std::distance(oddNumbers.begin(), it));
        std::cout << "only the odd elements: ";
        for (int num : oddNumbers) {
            std::cout << num << " ";
        }
        std::cout << "\n\n";
    }

    {
        std::vector<int> numbers = {2, 1, 2, 3, 4, 2, 5, 6, 2, 7};
        std::vector<int> result(4); // we need only  4 elements
        int count = 0;
        auto it = std::copy_if(numbers.begin(), numbers.end(), result.begin(),
                               [&count](int num) {
                                   if (num != 2 && count < 4) {
                                       count++;
                                       return true;
                                   }
                                   return false;
                               });
        std::cout << "first 4 entries different than 2: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << "\n\n";
    }

    {
        std::vector<int> numbers = {1, 3, 5, 6, 7, 9, 12, 15, 18, 21, 24, 2, 4};
        std::vector<int> multiplesOfThree;
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(multiplesOfThree),
                     [](int num) { return num % 3 == 0; });

        int startPos = multiplesOfThree.size() > 4 ? multiplesOfThree.size() - 4 : 0;
        std::vector<int> lastFour(multiplesOfThree.begin() + startPos, multiplesOfThree.end());

        std::cout << "last 4 entries which are multiple of 3: ";
        for (int num : lastFour) {
            std::cout << num << " ";
        }
        std::cout << "\n\n";
    }

    {
        std::vector<int> numbers = {5, 10, 15, 20, 25, 30};
        std::vector<int> result;
        if (numbers.size() >= 2) {
            std::copy_if(numbers.begin() + 1, numbers.end() - 1, std::back_inserter(result),
                         [](int num) { return num % 5 == 0; });
        }
        std::cout << "all the elements but the first and last element from a vector of integers if\n"
                     "they are divisible with 5: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}