#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    public:
        Character(std::string const& name);
        Character(const Character& from);
        Character& operator=(const Character& from);
        ~Character();

        std::string const& getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string name;
        int dropIdx;
        AMateria *inventory[4];
        AMateria *dropped[1000];

};

#endif