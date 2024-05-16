#include "HumanB.hpp"

HumanB::HumanB()
{
    this->weapon = new Weapon();
}

HumanB::HumanB(const HumanB& human)
{
    this->name = human.name;
    this->weapon = human.weapon;
}

HumanB::HumanB(std::string name){
    this->name = name;
    this->weapon = 0;
}

HumanB::~HumanB(){}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}
