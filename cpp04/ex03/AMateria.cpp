#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
    this->type = type;
}

AMateria::AMateria(){}

std::string const& AMateria::getType() const
{
    return this->type;
}