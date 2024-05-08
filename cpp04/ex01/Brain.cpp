#include "Brain.hpp"

Brain::Brain()
{
    this->ideas = new std::string[100];
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
    delete[] this->ideas;
}

std::string* Brain::getIdeas() const
{
    return this->ideas;
}