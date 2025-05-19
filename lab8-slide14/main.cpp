#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class MySort {
public:
    void bubble(std::vector<int>& vec, std::function<bool(int, int)> cmp) {
        for (size_t i = 0; i < vec.size(); ++i) {
            for (size_t j = 0; j < vec.size() - 1 - i; ++j) {
                if (!cmp(vec[j], vec[j + 1])) {
                    std::swap(vec[j], vec[j + 1]);
                }
            }
        }
    }

    bool byValue(int a, int b) { return a < b; }
    bool byLastDigit(int a, int b) { return (a % 10) < (b % 10); }

    bool bySum(int a, int b) {
        return digitSum(a) < digitSum(b);
    }

private:
    int digitSum(int n) {
        int sum =0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

class MyData {
private:
    std::vector<int> data;
    MySort sorter;
public:
    MyData(const std::vector<int>& vec) : data(vec) {}

    void sortNormal() {
        sorter.bubble(data, std::bind(&MySort::byValue, &sorter, std::placeholders::_1, std::placeholders::_2));
        print("sorted by value");
    }
    void sortByLastDigit() {
        sorter.bubble(data, std::bind(&MySort::byLastDigit, &sorter, std::placeholders::_1, std::placeholders::_2));
        print("sorted by last digit");
    }

    void sortBySum() {
        sorter.bubble(data, std::bind(&MySort::bySum, &sorter, std::placeholders::_1, std::placeholders::_2));
        print("sorted by digit sum");
    }
    void print(const std::string& title) {
        std::cout << title << ": ";
        for (int x : data) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> table{244, 57, 78, 331, 9, 212,6};
    MyData data(table);
    data.sortNormal();
    data.sortByLastDigit();
    data.sortBySum();
    return 0;
}