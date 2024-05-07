#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy(10), attack_damage(0)
{
    std::cout << "ClapTrap "<< this->name << " constructor called" << std::endl;   
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap "<< this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy == 0)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy to attack" << std::endl;
        return ;
    }
    this->energy--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy == 0)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy to be repaired" << std::endl;
        return ;
    }
    this->hit_points += amount;
    this->energy--;
    std::cout << "ClapTrap " << this->name << " has been repaired and got " << amount << " hit points back!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " took " << amount << " damages, it has " << this->hit_points << " hit points left!" << std::endl;
    if (this->hit_points <= 0)
    {
        this->hit_points = 0;
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
    }
}