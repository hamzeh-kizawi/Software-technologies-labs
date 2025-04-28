#include "Animal.h"

Animal::Animal(const std::string& name) : name(name) {}

Animal::~Animal() {}
std::string Animal::getName() const {
    return name;
}
std::ostream& operator<<(std::ostream& os, const Animal& animal) {
    os << animal.name;
    return os;
}
