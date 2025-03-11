#include <iostream>
#include <vector>

class Human {
public:
    Human(std::string n, int a) : name(n), age(a) {}
    
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
private:
    std::string name;
    int age;
};

int main() {
    std::vector<Human> humans = {
            Human("Hamza", 21),
            Human("Mark", 32),
            Human("Noah", 42)
    };
    std::cout << "Human data:\n";
    for (const auto& human : humans) {
        human.display();
    }
    return 0;
}
