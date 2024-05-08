#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal desctructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal class doesn't make sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}