#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
    this->type = type;
}

AMateria::AMateria(){}

AMateria::~AMateria(){}

void AMateria::use(ICharacter&){}

std::string const& AMateria::getType() const
{
    return this->type;
}