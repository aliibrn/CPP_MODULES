#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        BitcoinExchange btc;
        if (ac != 2 || !btc.hasValidExtension(av[1]))
        {
            std::cerr << "Error: could not open file." << std::endl;
            throw 1;
        }
        std::fstream file_txt(av[1]);
        if (!file_txt.is_open())
        {
            std::cerr << "Error: could not open file." << std::endl;
            throw 1;
        }
        std::fstream file_csv("data.csv");
        if (!file_csv.is_open())
        {
            std::cerr << "Error: could not open csv file." << std::endl;
            throw 1;
        }
        std::string buffer;
        if (file_csv.peek() == std::ifstream::traits_type::eof())
        {
            std::cerr << "Error: csv File is empty." << std::endl;
            throw 4;
        }
        while (std::getline(file_csv, buffer))
        {
            btc.SetData(buffer);
        }
        buffer.clear();
        if (file_txt.peek() == std::ifstream::traits_type::eof() || btc.line < 2)
        {
            std::cerr << "Error: txt File is empty or no data in csv file." << std::endl;
            throw 4;
        }
        btc.line = 0;
        while (std::getline(file_txt, buffer))
        {
            btc.GetResults(buffer);
        }
    }
    catch (int error)
    {
        return 1;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}