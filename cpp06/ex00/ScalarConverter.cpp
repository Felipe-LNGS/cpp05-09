#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter(){}


static bool isSpecialValue(const std::string &inputValue){
    return (inputValue == "+inf" || inputValue == "-inf" || inputValue == "nan" ||
            inputValue == "+inff" || inputValue == "-inff" || inputValue == "nanf");
}

bool ScalarConverter::isChar(const std::string &inputValue){
    return (inputValue.length() == 1 && std::isprint(inputValue[0]) && !std::isdigit(inputValue[0]));
}

bool ScalarConverter::isInt(const std::string &inputValue){
    char *endPointer;
    for (size_t index = 0; index < inputValue.length(); ++index) {
        if (!std::isdigit(inputValue[index]) && (inputValue[index] != '-' && index == 0) && (inputValue[index] != '+' && index == 0)) {
            return false; 
        }
    }
    long numberValue = std::strtol(inputValue.c_str(), &endPointer, 10);
    return (*endPointer == '\0' && numberValue >= std::numeric_limits<int>::min() && numberValue <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &inputValue){
    if (inputValue.length() < 2 || inputValue[inputValue.length() - 1] != 'f')
        return false; 
    char *endPointer;
    for (size_t index = 0; index < inputValue.length() - 1; ++index) {
        if (!std::isdigit(inputValue[index]) && inputValue[index] != '.' && inputValue[index] != '-' && inputValue[index] != '+') {
            return false; 
        }
    }
    std::strtof(inputValue.c_str(), &endPointer);

    return (*endPointer == '\0' || *endPointer == 'f');
}

bool ScalarConverter::isDouble(const std::string &inputValue){
    if (inputValue.length() < 2 || inputValue.find('.') == std::string::npos) 
        return false;
    char *endPointer;
    for (size_t index = 0; index < inputValue.length(); ++index) {
        if (!std::isdigit(inputValue[index]) && inputValue[index] != '.' && inputValue[index] != '-' && inputValue[index] != '+') {
            return false; 
        }
    }
    std::strtod(inputValue.c_str(), &endPointer);
    return (*endPointer == '\0');
}

void ScalarConverter::displayChar(double convertedValue){
    if (std::isnan(convertedValue) || std::isinf(convertedValue) || convertedValue < 0 || convertedValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(convertedValue)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(convertedValue) << "'" << std::endl;
}

void ScalarConverter::displayInt(double convertedValue){
    if (std::isnan(convertedValue) || std::isinf(convertedValue) || convertedValue < std::numeric_limits<int>::min() || convertedValue > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(convertedValue) << std::endl;
}

void ScalarConverter::displayFloat(double convertedValue){
    std::cout << "float: " << static_cast<float>(convertedValue);
    if (std::isnan(convertedValue) || std::isinf(convertedValue))
        std::cout << "f" << std::endl;
    else
        std::cout << "f" << std::endl;
}

void ScalarConverter::displayDouble(double convertedValue){
    std::cout << "double: " << convertedValue << std::endl;
}

void ScalarConverter::convert(const std::string &inputValue)
{
    double convertedValue = 0.0;

    if (isSpecialValue(inputValue))
    {
        if (inputValue == "+inf" || inputValue == "+inff")
            convertedValue = std::numeric_limits<double>::infinity();
        else if (inputValue == "-inf" || inputValue == "-inff")
            convertedValue = -std::numeric_limits<double>::infinity();
        else
            convertedValue = std::numeric_limits<double>::quiet_NaN();

        displayChar(convertedValue);
        displayInt(convertedValue);
        displayFloat(convertedValue);
        displayDouble(convertedValue);
        return;
    }

    if (isChar(inputValue))
        convertedValue = static_cast<double>(inputValue[0]);
    else if (isInt(inputValue))
        convertedValue = static_cast<double>(std::atoi(inputValue.c_str()));
    else if (isFloat(inputValue))
        convertedValue = std::strtof(inputValue.c_str(), NULL);
    else if (isDouble(inputValue))
        convertedValue = std::strtod(inputValue.c_str(), NULL);
    else
    {
        std::cout << "Invalid literal" << std::endl;
        return;
    }
    displayChar(convertedValue);
    displayInt(convertedValue);
    displayFloat(convertedValue);
    displayDouble(convertedValue);
}
