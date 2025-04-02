#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


template <typename T>
class MyContainer {
private:
    T data;
    std::string tag;

public:
    MyContainer(T val, std::string t) : data(val), tag(t) {}

    T getData() const { return data; }
    std::string getTag() const { return tag; }


    void display() const {
        std::cout << "data:" << data << ", Tag: " << tag;
    }
};

int main() {
    std::vector<MyContainer<int>> containerVec;

    containerVec.emplace_back(10, "important");
    containerVec.emplace_back(25, "normal");
    containerVec.emplace_back(8, "low");
    containerVec.emplace_back(42, "important");
    containerVec.emplace_back(15, "normal");
    containerVec.emplace_back(3, "low");
    containerVec.emplace_back(99, "critical");

    std::cout << " display all elements:\n";
    for (const auto& item : containerVec) {
        item.display();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    auto found = std::find_if(containerVec.begin(), containerVec.end(),
                              [](const MyContainer<int>& item) {
                                  return item.getData() > 30;
                              });

    if (found != containerVec.end()) {
        std::cout << "first element > 30: ";
        found->display();
        std::cout << std::endl << std::endl;
    }

    containerVec.erase(
            std::remove_if(containerVec.begin(), containerVec.end(),
                           [](const MyContainer<int>& item) {
                               return item.getTag() == "low";
                           }),
            containerVec.end());

    std::cout << "after removing 'low' items:\n";
    for (const auto& item : containerVec) {
        item.display();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    containerVec.erase(
            std::remove_if(containerVec.begin(), containerVec.end(),
                           [](const MyContainer<int>& item) {
                               return item.getData() % 2 == 0;
                           }),
            containerVec.end());

    std::cout << "after removing even values:\n";
    for (const auto& item : containerVec) {
        item.display();
        std::cout << std::endl;
    }

    return 0;
}