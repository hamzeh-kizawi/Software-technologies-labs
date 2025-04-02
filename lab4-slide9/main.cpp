#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70};

    std::vector<int> full_copy(numbers.size());
    std::copy(numbers.begin(), numbers.end(), full_copy.begin());
    std::cout << "full copy: ";
    for (int n : full_copy) std::cout << n << " ";
    std::cout << "\n";

    std::vector<int> first_four(4);
    std::copy(numbers.begin(), numbers.begin() + 4, first_four.begin());
    std::cout << "first 4 entries from a vector: ";
    for (int n : first_four) std::cout << n << " ";
    std::cout << "\n";

    // Copy the last 4 entries
    std::vector<int> last_four(4);
    std::copy(numbers.end() - 4, numbers.end(), last_four.begin());
    std::cout << "last 4 entries from a vector: ";
    for (int n : last_four) std::cout << n << " ";
    std::cout << "\n";

    std::vector<int> middle_elements(numbers.size() - 2);
    std::copy(numbers.begin() + 1, numbers.end() - 1, middle_elements.begin());
    std::cout << "all the elements but the first and last element from a vector of integers;: ";
    for (int n : middle_elements) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
