#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    Cat(const std::string& name);
    void speak() const override;
};
