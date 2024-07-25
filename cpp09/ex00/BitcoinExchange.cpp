# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& infilename)
{
    this->_data_file.open("data.csv");
    this->_infile.open(infilename.c_str());
    this->_infilename = infilename;

    if (parseValues("data.csv", this->_data_file, this->_values, ",") == 1)
        return ;
    if (parseValues(infilename, this->_infile, this->_infile_values, "|") == 1)
        return ;
    if (checkInFile() == 1)
        return ;
    std::cout << "Date | Value" << std::endl;
    printValues();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;
    this->_values = other.getValues();
    this->_infilename = other.getInfileName();
    return *this;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _values(other.getValues()), _infilename(other.getInfileName()) {}

BitcoinExchange::~BitcoinExchange() 
{
    if (this->_data_file.is_open())
        this->_data_file.close();
}

std::multimap<std::time_t, float> BitcoinExchange::getValues() const
{
    return this->_values;
}

std::string BitcoinExchange::getInfileName() const
{
    return this->_infilename;
}

static std::time_t convertToUnixTimestamp(const std::string& date_str, const std::string& filename) {
    std::tm tm = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::istringstream ss(date_str);
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        std::cout << "Error: "<< filename << " => " << date_str <<": Invalid date" << std::endl;
        return -1;
    }

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    std::time_t timestamp = std::mktime(&tm);
    if (timestamp == -1) {
        std::cout << "Error: mktime failed" << std::endl;
        return -1;
    }
    return timestamp;
}

static std::string convertTimeToStr(time_t time)
{
    struct tm* timeInfo;
    timeInfo = localtime(&time);
    std::ostringstream oss;

    oss << (1900 + timeInfo->tm_year) << '-'
        << std::setw(2) << std::setfill('0') << (1 + timeInfo->tm_mon) << '-'
        << std::setw(2) << std::setfill('0') << timeInfo->tm_mday;
    return oss.str();
}

int BitcoinExchange::parseValues(const std::string& filename, std::ifstream& file, std::multimap<std::time_t, float>& container, const std::string& delimiter)
{
    if (!file)
    {
        std::cout << "Error: "<< filename <<" file not found" << std::endl;
        return 1;
    }

    std::string line;
    (void) std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, line.find(delimiter));
        std::string value = line.substr(line.find(delimiter) + delimiter.size());
        std::time_t time = convertToUnixTimestamp(date, filename);
        if (time == -1)
            return 1;
        float val = 0;
        std::istringstream ss(value);
        ss >> val;
        if (ss.fail())
        {
            std::cout << "Error: " << value << ": invalid value" << std::endl;
            return 1;
        }
        std::pair<std::time_t, float> pair = std::make_pair(time, val);
        container.insert(pair);
    }
    file.close();
    return 0;
}

int BitcoinExchange::checkInFile() const
{
    std::multimap<std::time_t, float> values = this->_infile_values;
    for (std::multimap<std::time_t, float>::iterator it = values.begin(); it != values.end(); it++)
    {
        float value = it->second;

        if (value < 0 || value > 1000)
        {
            std::cout << "Invalid data value: " << value << std::endl;
            return 1;
        }
    }
    return 0;
}

static std::time_t getClosest(std::multimap<std::time_t, float> values, std::time_t value)
{
    std::time_t closest = 0;
    for (std::multimap<std::time_t, float>::iterator it = values.begin(); it != values.end(); it++)
    {
        if (it->first < value)
            closest = it->first;
    }
    return closest;
}

void BitcoinExchange::printValues() const
{
    std::multimap<std::time_t, float> invalues = this->_infile_values;
    std::multimap<std::time_t, float> values = this->_values;

    for (std::multimap<std::time_t, float>::iterator it = invalues.begin(); it != invalues.end(); it++)
    {
        std::time_t key = it->first;
        float       value = it->second;
        std::string date = convertTimeToStr(key);

        typedef std::multimap<std::time_t, float>::iterator iter;
        std::pair<iter, iter> range = values.equal_range(key);

        if (values.find(key) != values.end())
            std::cout << date << " => " << value << " => " << (((range.first)->second) * value) << std::endl;
        else
        {
            key = getClosest(values, key);
            if (key == 0)
            {
                std::cout << "Not found for " << date << std::endl;
                continue ;
            }
            std::cout << date << " => " << convertTimeToStr(key) << " ";
            std::cout << " => " << value << " => " << (((range.first)->second) * value) << std::endl;
        }
    }
}
