#include "Cat.hpp"

Cat::Cat()
{
     this->type = "Cat";
     this->brain = new Brain();
     std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat desctructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Mew mew" << std::endl;
}