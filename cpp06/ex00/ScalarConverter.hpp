#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

# include <iostream>
# include <string>
# include <stdlib.h>
# include <limits.h>
# include <limits>
# include <sstream>
# include "float.h"
# include <iomanip>

class ScalarConverter
{
    public:
        ~ScalarConverter();

        static void    convert(const std::string& value);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
};

#endif