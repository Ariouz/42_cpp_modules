
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

    class Zombie 
    {
        public:
            Zombie();
            Zombie(std::string name);
            Zombie(Zombie& zombie);
            ~Zombie();

            void announce(void);
            void setName(std::string name);

        private:
            std::string name;
    };

    Zombie* zombieHorde(int N, std::string name);

#endif