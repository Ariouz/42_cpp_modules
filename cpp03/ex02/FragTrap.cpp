#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap "<< this->name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap "<< this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "High Fives!" <<std::endl;
}