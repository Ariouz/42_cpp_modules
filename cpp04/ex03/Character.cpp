#include "Character.hpp"

Character::Character(std::string const& name) : name(name)
{
    this->dropIdx = 0;
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = 0;
    }
    for (int i = 0; i < 1000; i++)
    {
        this->dropped[i] = 0;
    }
}

Character::Character(const Character& from)
{
    this->name = from.name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = from.inventory[i]->clone();
}

Character& Character::operator=(const Character& from)
{
    this->name = from.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != 0)
            delete this->inventory[i];
        this->inventory[i] = from.inventory[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != 0)
            delete this->inventory[i];
    }
    while (dropIdx >= 0)
    {
        delete this->dropped[dropIdx];
        dropIdx--;
    }
}

std::string const& Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == 0)
        {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (inventory[idx] == 0) return;
    this->dropped[dropIdx++] = this->inventory[idx];
    this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (inventory[idx] == 0) return;
    inventory[idx]->use(target);
}