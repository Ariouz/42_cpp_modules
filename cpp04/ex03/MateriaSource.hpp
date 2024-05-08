#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const& type);

    private:
        int idx;
        AMateria *materias[4];
};

#endif