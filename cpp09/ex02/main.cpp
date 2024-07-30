# include <iostream>
# include <string>
# include <sstream>
# include <sys/time.h>
# include "PmergeMe.hpp"


std::vector<std::string> splitArgs(const std::string& arg)
{
    std::vector<std::string> args;
    std::istringstream iss (arg);

    std::string word;
    while (iss >> word)
    {
        args.push_back(word);
    }
    return args;
}

long getCurrentTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Argument are expected. => ./PmergeMe 1 2 3 4 5 6" << std::endl;
        return 1;
    }

    std::deque<int> valuesQ;
    std::vector<int> valuesV;
    for (int index = 1; index < argc; index++)
    {
        int val = std::atoi(argv[index]);
        if (val < 1)
        {
            std::cout << "Invalid value: '" << argv[index] << "'; must be a positive integer" << std::endl;
            return 1;
        }

        if (std::find(valuesQ.begin(), valuesQ.end(), val) != valuesQ.end())
        {
            std::cout << "Invalid value: '" << val << "'; cannot contains duplicates" << std::endl;
            return 1;
        }

        valuesQ.push_back(val);
        valuesV.push_back(val);
    }

    PmergeMe p;

    long vStart, qStart, vEnd, qEnd;

    std::cout << "Vector:" << std::endl;
    vStart = getCurrentTimeInMicroseconds();
    p.mergeInsertionSortVector(valuesV);
    vEnd = getCurrentTimeInMicroseconds();
    
    std::cout << std::endl;

    std::cout << "Deque:" << std::endl;
    qStart = getCurrentTimeInMicroseconds();
    p.mergeInsertionSortDeque(valuesQ);
    qEnd = getCurrentTimeInMicroseconds();

    std::cout << std::endl;
    std::cout << "Execution time with std::vector: " << std::fixed << (vEnd-vStart) << " us" << std::endl;
    std::cout << "Execution time with std::deque: " << std::fixed << (qEnd-qStart) << " us" << std::endl;

    return (0);
}