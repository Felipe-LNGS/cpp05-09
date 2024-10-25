#include "Iter.hpp"

int main() {
	std::cout << "************INT ARRAY**********\n";
	int intArray[5] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(intArray, 5, &print<int>);

	std::cout << "\nModifier int array: ";
	iter(intArray, 5, &increment<int>);
	iter(intArray, 5, &print<int>);
	std::cout << "\n\n************STR ARRAY**********\n";

	std::string strArray[3] = {"Bonjour", "le", "correcteur"};
	std::cout << "Original str array: ";
	iter(strArray, 3, &print<std::string>);
	std::cout << "\nmodified str array: ";
	iter(strArray, 3, &changeChar<std::string>);
	iter(strArray, 3, &print<std::string>);

	std::cout << std::endl;
	return (0);
}