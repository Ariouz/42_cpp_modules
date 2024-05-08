#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap trap = ClapTrap("Trap01");
    trap.attack("Bob");
    trap.takeDamage(2);
    trap.beRepaired(1);
    trap.takeDamage(9);
    
    std::cout << "-------------- ScavTrap --------------" << std::endl;

    ScavTrap scav = ScavTrap("Scav01");
    scav.attack("Harry");
    scav.guardGate();

    std::cout << "-------------- FragTrap --------------" << std::endl;

    FragTrap frag = FragTrap("Frag01");
    frag.attack("Harry");
    frag.highFivesGuys();

    std::cout << "-------------- END --------------" << std::endl;
    return (0);
}