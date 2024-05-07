#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap = ClapTrap("Trap01");
    trap.attack("Bob");
    trap.takeDamage(2);
    trap.beRepaired(1);
    trap.takeDamage(15);

    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);
    trap.beRepaired(1);

    return (0);
}