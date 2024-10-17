/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:20:10 by ymostows          #+#    #+#             */
/*   Updated: 2024/10/17 15:39:55 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
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
    {
        int intValue = static_cast<int>(value);
        std::cout << "int: " << intValue << std::endl;
    }
}
void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else 
    {
        float floatValue = static_cast<float>(value);
        std::cout << "float: " << floatValue << "f" <<std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else 
    {
        double doubleValue = static_cast<double>(value);
        std::cout << "double: " << doubleValue << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
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