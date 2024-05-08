#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal desctructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}

Brain* AAnimal::getBrain() const
{
    return this->brain;
}