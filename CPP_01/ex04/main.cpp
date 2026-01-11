#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    std::ifstream file;
    std::ofstream outFile;
    std::string contents;
    std::string line;
    std::string s1 = std::string(av[2]);
    std::string s2 = std::string(av[3]);
    size_t pos = 0;

    if (ac != 4 || s1.empty())
    {
        std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    file.open(av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << av[1] << std::endl;
        return 1;
    }
    while (std::getline(file, line))
    {
        contents += line;
        if(!file.eof())
            contents += "\n";
    }
    file.close();
    while ((pos = contents.find(s1, pos)) != std::string::npos)
    {
        contents.erase(pos, s1.length());
        contents.insert(pos, s2);
        pos += s2.length();
    }
    std::string outputFileName = std::string(av[1]) + ".replace";
    outFile.open(outputFileName.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error creating output file: " << outputFileName << std::endl;
        return 1;
    }
    outFile << contents;
    outFile.close();
}
