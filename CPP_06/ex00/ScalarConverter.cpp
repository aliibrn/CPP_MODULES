#include "ScalarConverter.hpp"

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

static bool isInt(const std::string& literal) {
    char* end;
    long val = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& literal) {
    if (literal == "+inff" || literal == "-inff" || literal == "nanf") return true;
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f';
}

static bool isDouble(const std::string& literal) {
    if (literal == "+inf" || literal == "-inf" || literal == "nan") return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& literal) {
    float f;
    double d;
    int i;
    char c;

    std::cout << std::fixed << std::setprecision(1);

    if (isChar(literal)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isInt(literal)) {
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } else if (isFloat(literal)) {
        f = std::strtof(literal.c_str(), NULL);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } else if (isDouble(literal)) {
        d = std::strtod(literal.c_str(), NULL);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } else {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || i < 0 || i > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";

    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << i << "\n";

    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf\n";
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << "\n";
    else
        std::cout << f << "f\n";

    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << "\n";
    else
        std::cout << d << "\n";
}


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){
    (void)copy;
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){
    (void)copy;
}
