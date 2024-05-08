#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        ~Brain();
    
        std::string *getIdeas() const;

    protected:
        std::string *ideas;
};

#endif