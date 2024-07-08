# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void) other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void) other; return *this;}
ScalarConverter::~ScalarConverter() {}

static int getDecimalCount(double n)
{
    std::ostringstream ss;
    ss << std::fixed << n;
    std::string str = ss.str();
    if (str.find(".") == std::string::npos) return 1;
    int pos = str.find_last_of(".");
    str.erase(0, pos+1);
    str.erase(str.find_last_not_of("0") + 1, std::string::npos);
    int dcount = str.length();
    return (dcount == 0 ? 1 : dcount);
}

static void convertInt(int n)
{
    if (isascii(n))
    {
        if (isprint(n))
            std::cout << "char: '" << static_cast<char> (n) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (n >= INT_MIN && n <= INT_MAX)
        std::cout << "int: " << static_cast<int> (n) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout.precision(getDecimalCount(n));
    std::cout << "float: " << std::fixed << static_cast<float> (n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double> (n) << std::endl;
}

static void convertFloat(double n)
{
    if (isascii(n))
    {
        if (isprint(n))
            std::cout << "char: '" << static_cast<char> (n) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (n >= INT_MIN && n <= INT_MAX)
        std::cout << "int: " << static_cast<int> (n) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    
    std::cout.precision(getDecimalCount(n));
    std::cout << "float: " << std::fixed << static_cast<float> (n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double> (n) << std::endl;
}

static void convertDouble(double n)
{
    if (isascii(n))
    {
        if (isprint(n))
            std::cout << "char: '" << static_cast<char> (n) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (n >= INT_MIN && n <= INT_MAX)
        std::cout << "int: " << static_cast<int> (n) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout.precision(getDecimalCount(n));
    std::cout << "float: " << std::fixed << static_cast<float> (n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double> (n) << std::endl;
}

static void convertChar(char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int> (c) << std::endl;
    std::cout.precision(1);
    std::cout << "float: " << std::fixed << static_cast<float> (c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << static_cast<double> (c) << std::endl;
}

static void convertInvalid(std::string s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << s << "f" << std::endl;
    std::cout << "double: " << s << std::endl;
}

static bool isInteger(const std::string& value)
{
    long n = 0;
    int sign = 1;
    for (std::size_t index = 0; index < value.size(); index++)
    {
        if (value[index] == '-')
            sign = -sign;
        if (!isdigit(value[index]) && value[index] != '-') return false;
        if (isdigit(value[index]))
            n = n * 10 + (value[index] - '0');
        if (n*sign < INT_MIN || n*sign > INT_MAX)
            return false;
    }
    return true;
}

static bool isDouble(const std::string& value)
{
    long double  n = 0;
    int     sign = 1;
    int     dotCount = 0;
    if (value.find('f') != std::string::npos)
        return false;
    for (std::size_t index = 0; index < value.size(); index++)
    {
        if (value[index] == '-')
            sign = - sign;
        if (!isdigit(value[index]) && value[index] != '-')
        {
            if (value[index] == '.' && dotCount == 0)
                dotCount++;
            else
                return false;
        }
        if (isdigit(value[index]))
            n = n * 10 + (value[index] - '0');
    }
    return true;
}

static bool isFloat(const std::string& value)
{
    double  n = 0;
    int     sign = 1;
    int     dotCount = 0;
    if (value.find('f') == std::string::npos)
        return false;
    for (std::size_t index = 0; index < value.size(); index++)
    {
        if (value[index] == '-')
            sign = - sign;
        if (!isdigit(value[index]) && value[index] != '-' && value[index] != 'f')
        {
            if (value[index] == '.' && dotCount == 0)
                dotCount++;
            else
                return false;
        }
        if (isdigit(value[index]))
            n = n * 10 + (value[index] - '0');
    }
    return true;
}

static double atod(const std::string& str)
{
    std::stringstream ss (str);
    long double n = 0;
    ss >> n;
    return n;
}

void ScalarConverter::convert(const std::string& value)
{
    if (value.size() == 3 && isprint(value[1]) && value[0] == '\'' && value[2] == '\'')
        convertChar(value[1]);
    else if (isInteger(value))
        convertInt(atoi(value.c_str()));
    else if (isDouble(value))
        convertDouble(atod(value.c_str()));
    else if (isFloat(value))
        convertFloat(atof(value.c_str()));
    else if (value.compare("nan") == 0 || value.compare("nanf") == 0)
        convertInvalid("nan");
    else if (value.compare("inf") == 0 || value.compare("inff") == 0)
        convertInvalid("inf");
    else if (value.compare("-inf") == 0 || value.compare("-inff") == 0)
        convertInvalid("-inf");
    else
        std::cout << "Invalid input" << std::endl;
}