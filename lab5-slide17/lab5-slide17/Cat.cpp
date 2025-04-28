#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string& name) : Animal(name) {}

void Cat::speak() const {
    std::cout << name << " say: meow meow !" << std::endl;
}
