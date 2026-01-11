#include "BitcoinExchange.hpp"

static bool isInt(const std::string &literal) {
    if (literal.empty()) return false;

    char *end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}


static bool isFloat(const std::string &literal) {
    if (literal.empty()) return false;

    char *end;
    std::strtof(literal.c_str(), &end);
    return *end == '\0' && literal.find('.') != std::string::npos;
}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
        return false;
    if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) ||
        date[4] != '-' ||
        !isdigit(date[5]) || !isdigit(date[6]) ||
        date[7] != '-' ||
        !isdigit(date[8]) || !isdigit(date[9]))
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    static const int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int maxDay = (month == 2 && isLeap) ? 29 : daysInMonth[month - 1];

    if (day < 1 || day > maxDay)
        return false;
    return true;
}

bool BitcoinExchange::hasValidExtension(const std::string &filename)
{
    size_t dotPos = filename.rfind('.');
    if (dotPos == std::string::npos)
        return false;

    std::string ext = filename.substr(dotPos);
    return  ext == ".txt";
}

bool BitcoinExchange::parsePipeLine(const std::string &line, std::string &key, std::string &value) {
    size_t pipe_pos = line.find('|');
    if (pipe_pos == std::string::npos || pipe_pos == 0 || pipe_pos == line.size() - 1) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (line[pipe_pos - 1] != ' ' || line[pipe_pos + 1] != ' ') {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    key = line.substr(0, pipe_pos - 1);     
    value = line.substr(pipe_pos + 2);

    key.erase(0, key.find_first_not_of(" \t"));
    key.erase(key.find_last_not_of(" \t") + 1);

    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    return true;
}


void BitcoinExchange::SetData(std::string line)
{
    this->line++;
    if(this->line == 1){
        if (line != "date,exchange_rate")
        {
            std::cerr << "Error: bad header format." << std::endl;
            throw 4;
        }
        return;
    }
    std::string key;
    std::string value;

    size_t pos = line.find(',');
    if (pos == std::string::npos){
        std::cerr << "Error: bad input csv" << std::endl;
        throw 8;
    }

    key = line.substr(0, pos);
    value = line.substr(pos + 1);

    if (!isValidDate(key))
    {
        std::cerr << "Error: bad Data" << std::endl;
        throw 7;
    }
    if(!isFloat(value) && !isInt(value))
    {
        std::cerr << "Error: bad Data" << std::endl;
        throw 7;
    }
    data[key] = value;
}

void BitcoinExchange::GetResults(std::string line) {
    this->line++;
    if (this->line == 1) {
        if (line != "date | value") {
            std::cerr << "Error: bad header format." << std::endl;
            throw 4;
        }
        return;
    }
    std::string key, value;

    if(!parsePipeLine(line, key, value))
        return;

    if (!isValidDate(key)) {
        std::cerr << "Error: bad input => " << key << std::endl;
        return;
    }

    float amount;
    if (isInt(value)) {
        long val = std::strtol(value.c_str(), NULL, 10);
        if(val > std::numeric_limits<int>::max()){
            std::cerr << "Error: too large a number." << std::endl;
            return;
        }
        amount = static_cast<float>(std::atoi(value.c_str()));
    } else if (isFloat(value)) {
        amount = std::strtof(value.c_str(), NULL);
    } else {
        std::cerr << "Error: bad input => " << value << std::endl;
        return;
    }

    if (amount < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (amount > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    std::map<std::string, std::string>::iterator it = data.find(key);
    if (it == data.end()) {
        it = data.lower_bound(key);
        if (it == data.begin() && it->first > key) {
            std::cerr << "Error: no earlier exchange rate available." << std::endl;
            return;
        }
        if (it == data.end() || it->first != key) {
            if (it != data.begin())
                --it;
        }
    }

    float rate = std::strtof(it->second.c_str(), NULL);;
    float result = rate * amount;

    std::cout << key << " => " << amount << " = " << result << std::endl;
}

BitcoinExchange::BitcoinExchange(): line(0)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): data(copy.data), line(copy.line){

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
    if(this != &copy){
        data = copy.data;
        line = copy.line;
    }
    return *this;
}