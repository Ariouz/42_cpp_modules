
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

        private:
            std::string name;
    };

    Zombie *newZombie(std::string name);
    void randomChump(std::string name);

#endif