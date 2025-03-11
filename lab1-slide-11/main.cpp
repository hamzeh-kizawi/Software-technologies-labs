#include <iostream>
#include <vector>
#include <algorithm>

class Human {
public:
    std::string name;
    int age;
    Human() : name(""), age(0) {}
    Human(std::string n, int a) : name(n), age(a) {}
};

int main() {
    Human h1("Hamza", 21);
    Human h2("Elina", 23);
    Human h3("Mark", 32);
    Human h4("David", 23);

    std::vector<Human> humans = {h1, h2, h3, h4};

    std::cout << "All humans:" << std::endl;
    for (const auto &human : humans) {
        std::cout << "Name: " << human.name << ", Age: " << human.age << std::endl;
    }

    Human youngest = humans[0];
    for (const auto &human : humans) {
        if (human.age < youngest.age) {
            youngest = human;
        }
    }
    std::cout << "\nThe youngest human:" << std::endl;
    std::cout << "Name: " << youngest.name << ", Age: " << youngest.age << std::endl;

    // Sort humans by name in descending order
    for (size_t i = 0; i < humans.size(); ++i) {
        for (size_t j = i + 1; j < humans.size(); ++j) {
            if (humans[i].name < humans[j].name) {
                std::swap(humans[i], humans[j]);
            }
        }
    }

    std::cout << "\nHumans' all names in descending order:" << std::endl;
    for (const auto &human : humans) {
        std::cout << human.name << std::endl;
    }
    return 0;
}