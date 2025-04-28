#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

int main() {

    std::vector<std::shared_ptr<Animal>> animals;

    animals.push_back(std::make_shared<Dog>("buddy"));
    animals.push_back(std::make_shared<Cat>("whiskers"));
    animals.push_back(std::make_shared<Dog>("max"));
    animals.push_back(std::make_shared<Cat>("luna"));
    std::cout << "available Animals:\n";
    for (const auto& animal : animals) {
        std::cout << *animal << std::endl;
    }
    std::string kidChoice;
    std::cout << "\nWhich pet does the kid wants? ";
    std::cin >> kidChoice;

    auto it = std::find_if(animals.begin(), animals.end(),
                           [&kidChoice](const std::shared_ptr<Animal>& animal) {
                               return animal->getName() == kidChoice;
                           });

    if (it != animals.end()) {
        std::cout << "kid adopted: " << **it << "\n";
        animals.erase(it);
    } else {
        std::cout << "sorry, pet not found.\n";
    }
    std::cout << "\nRemaining Animals:\n";
    for (const auto& animal : animals) {
        std::cout << *animal << std::endl;
    }

    return 0;
}
