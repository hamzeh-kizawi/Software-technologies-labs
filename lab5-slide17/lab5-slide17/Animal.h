#pragma once
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
public:
    Animal(const std::string& name);
    virtual ~Animal();
    virtual void speak() const = 0;
    std::string getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};
