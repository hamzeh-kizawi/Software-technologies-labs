#include <iostream>
#include <vector>
#include <functional>

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
    bool valueCmp(int a, int b, bool asc) {
        return asc ? (a < b) : (a > b);
    }

    bool lastDigitCmp(int a, int b, bool asc) {
        return asc ? ((a % 10) < (b % 10)) : ((a % 10) > (b % 10));
    }

private:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    bool sumCmp(int a, int b, bool asc) {
        int sa = digitSum(a);
        int sb = digitSum(b);
        return asc ? (sa < sb) : (sa > sb);
    }
};

class MyData {
private:
    std::vector<int> data;
    MySort sorter;

public:
    MyData(const std::vector<int>& vec) : data(vec) {}

    void sortNormal(bool asc) {
        auto cmp = std::bind(&MySort::valueCmp, &sorter, std::placeholders::_1, std::placeholders::_2, asc);
        sorter.bubble(data, cmp);
        print("sort by value");
    }
    void sortByLastDigit(bool asc) {
        auto cmp = std::bind(&MySort::lastDigitCmp, &sorter, std::placeholders::_1, std::placeholders::_2, asc);
        sorter.bubble(data, cmp);
        print("sort by last digit");
    }

    void sortBySum(bool asc) {
        auto cmp = std::bind(&MySort::sumCmp, &sorter, std::placeholders::_1, std::placeholders::_2, asc);
        sorter.bubble(data, cmp);
        print("sot by digit sum");
    }

    void print(const std::string& title) {
        std::cout << title << ": ";
        for (int x : data) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> table{244, 57, 78, 331, 9, 212, 6};
    MyData data(table);

    data.sortNormal(true);
    data.sortNormal(false);

    data.sortByLastDigit(true);
    data.sortByLastDigit(false);

    data.sortBySum(true);
    data.sortBySum(false);
    return 0;
}
