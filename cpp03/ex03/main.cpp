#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "-------------- DiamondTrap --------------" << std::endl;

    DiamondTrap diamond = DiamondTrap("Diamond01");
    diamond.attack("Alex");
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
    

    std::cout << "-------------- END --------------" << std::endl;
    return (0);
}