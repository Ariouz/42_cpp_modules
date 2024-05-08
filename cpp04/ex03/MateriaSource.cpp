#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] != 0)
        {
            delete this->materias[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
       if (idx == 3) return ;
       this->materias[idx] = m->clone();
}

AMateria *MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] != 0)
        {
            if (this->materias[i]->getType().compare(type) == 0)
                return this->materias[i]->clone();
        }
    }
    return 0;
}