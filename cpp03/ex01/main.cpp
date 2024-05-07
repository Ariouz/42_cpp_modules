#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return (0);
}