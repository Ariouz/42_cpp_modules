#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        ~WrongAnimal();
    
        std::string getType() const;
        void makeSound() const;
    protected:
        std::string type;
};

#endif