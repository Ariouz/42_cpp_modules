#include <iostream>
#include <fstream>
#include <string>

void    processLine(std::string line, std::ofstream& out, std::string s1, std::string s2)
{
    int i = 0;
    std::string sub;

    while (line[i])
    {
        sub = line.substr(i, s1.length());
        if (sub.compare(s1) == 0)
        {
            out << s2;
            i += (int) s1.length() - 1;
        }
        else
            out << line[i];
        i++;
    }
    out << std::endl;
}

void    replaceAll(std::ifstream& in, std::ofstream& out, std::string s1, std::string s2)
{
    (void) s2;
    std::string line;
    while (getline(in, line))
    {
        processLine(line, out, s1, s2);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Syntax: filename s1 s2" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::ifstream file (filename.c_str());

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (file.is_open())
    {
        std::ofstream replace ((filename + ".replace").c_str());

        replaceAll(file, replace, s1, s2);

        file.close();
        replace.close();
        std::cout << "Content replaced in " + filename + ".replace" << std::endl;
    }
    else
        std::cout << "File cannot be open (not found or no permission)" << std::endl;
    return (0);
}