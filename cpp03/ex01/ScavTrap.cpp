#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap "<< this->name << " constructor called" << std::endl; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap "<< this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy == 0)
    {
        std::cout << "ScavTrap " << this->name << " has not enough energy to attack" << std::endl;
        return ;
    }
    this->energy--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->name <<" is now in Gate keeper mode" << std::endl;
}