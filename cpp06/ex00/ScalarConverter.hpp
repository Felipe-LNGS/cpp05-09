
#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include "Color.hpp"
class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &src);

    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static void displayChar(double value);
    static void displayInt(double value);
    static void displayFloat(double value);
    static void displayDouble(double value);
};