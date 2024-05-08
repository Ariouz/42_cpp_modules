#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog desctructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wouf wouf" << std::endl;
}