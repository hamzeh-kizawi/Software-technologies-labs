#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name) : Animal(name) {}

void Dog::speak() const {
    std::cout << name << " says: wooooof" << std::endl;
}
