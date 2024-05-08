#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::~Ice(){}

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}