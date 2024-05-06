#include "HumanA.hpp"

HumanA::HumanA(){}

HumanA::HumanA(const HumanA& human)
{
    this->name = human.name;
    this->weapon = human.weapon;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA(){}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}