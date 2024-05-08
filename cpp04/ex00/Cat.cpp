#include "Cat.hpp"

Cat::Cat()
{
     this->type = "Cat";
     std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat desctructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Mew mew" << std::endl;
}