#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	_dataBtc.clear();
	this->_amount = 0;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	if(this!=&src){
		_dataBtc = src._dataBtc;
		_amount = src._amount;
	}
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &cpy){
	if(this!=&cpy){
		_dataBtc = cpy._dataBtc;
		_amount = cpy._amount;
	}
	return *this;
	}

BitcoinExchange::~BitcoinExchange(){}
 bool BitcoinExchange::checkDate(std::string const & date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dayMax = dayInMonth[month - 1];
	if (month < 1 || month > 12)
		return (false);
	if (dayMax < day || day < 0)
		return (false);
	if (year < 0 || year > 2024)
		return (false);
	return (true);    
} 

template<typename T>
bool checkValue(T value, T maxValue){
	if(value > 1000 && maxValue){
		std::cerr<< "Error: too large a number.\n";
		return false;
	}
	if(value > INT_MAX || value < INT_MIN){
		std::cerr<< "Error: overflow int.\n";
		return false;
	}
	if(value < 0){
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	return true;
}

void BitcoinExchange::stockMap(std::string const &filename){
	std::ifstream file(filename.c_str());
	if(!file.is_open()){
		std::cerr <<"Error: could not open file.\n";
		return ;}
	std::string line;
	while(std::getline(file, line))
	{
		size_t pos = line.find(",");
		if(pos!=std::string::npos)
		{
			std::string date = line.substr(0,pos);
			
		if(checkDate(date) == false){
			std::cerr << "Error : Invalide date : " << date<< std::endl;
			continue; ;
		}
			float value = std::atof(line.substr(pos+1).c_str());
			if(checkValue<float>((value), 0) == false)
				continue ;
			_dataBtc[date] = value;
		}
	}
	file.close();
}

void BitcoinExchange::findValue(std::string const &date, float const &value){
	if(checkValue<float>((value), 1) == false)
		return ;
	if(checkDate(date) == false){
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	std::map<std::string, float>::iterator it2 = _dataBtc.begin();
	std::map<std::string, float>::iterator it;
	for(it = _dataBtc.begin();it != _dataBtc.end(); ++it){				
		if(it->first == date){
			_amount = it->second * value;
			std::cout << it->first << " => " << value << " = " << _amount<< std::endl;
			break ;
		}
		if(it->first > date){
			_amount = it2->second * value;
			std::cout << it2->first << " => " << value << " = " << _amount << std::endl;
			break ;
		}
		it2 = it;
	}
		if(it2->first < date && it == _dataBtc.end()){
			_amount = it2->second * value;
			std::cout << it2->first << " => " << value << " = " << _amount<< std::endl;
		}
}