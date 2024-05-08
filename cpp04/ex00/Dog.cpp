#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog desctructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wouf wouf" << std::endl;
}