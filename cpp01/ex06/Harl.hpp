#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>
#include <string>

class Harl
{

    public:
        Harl();
        ~Harl();

        void complain(std::string level);
        int isValidLevel(std::string level);

    private:
        std::map<std::string, void (Harl::*)()> functions;

        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

};

#endif