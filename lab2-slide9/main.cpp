#include <iostream>

class MyClass {
private:
    int value;
public:
    constexpr MyClass(int v) : value(v) {}
    constexpr int multiplyByTwo() const {
        return value * 2;
    }
};

int main() {
    constexpr MyClass obj(3);
    constexpr int result = obj.multiplyByTwo();

    std::cout << "result: " << result << std::endl;

    return 0;
}
