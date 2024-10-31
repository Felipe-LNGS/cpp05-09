#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <limits.h>

class BitcoinExchange{

	private :
		std::map<std::string , float> _dataBtc;
		unsigned long _amount;
	public :
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &cpy);
		~BitcoinExchange();
		void stockMap(std::string const &filename);
		void findValue(std::string const &date, int const &value);
};