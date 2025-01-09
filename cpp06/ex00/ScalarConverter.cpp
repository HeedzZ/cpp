#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        double value = static_cast<double>(c);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    char* end;
    double value = std::strtod(literal.c_str(), &end);

    if (*end != '\0' && *end != 'f') {
        std::cout << "Conversion error: invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << ((value < 0) ? "-inff" : "+inff") << std::endl;
    else
    {
        float floatValue = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << ((value < 0) ? "-inf" : "+inf") << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << value << std::endl;
    }
}

