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
					// std::cout << date << std::endl;

					float value = std::atof(line.substr(pos+1).c_str());
					if(value < 0){
						std::cerr << "Error : invalid value.\n";
						return;
					}
					_dataBtc[date] = value;
				}
			}
		}
	
		void BitcoinExchange::findValue(std::string const &date, int const &value){
			if(value < 0){
				std::cerr << "Error: not a positive number.\n";
				return ;
			}
			if(value > INT_MAX){
				std::cerr<< "Error: too large a number.\n";
				return;
			}
				int year = std::atoi(date.substr(0, 4).c_str());
				int month = std::atoi(date.substr(5, 2).c_str());
				int day = std::atoi(date.substr(8, 2).c_str());
				if(!year || !month || !day)
				{
					std::cerr << "Error : Invalide date.\n";
					return ;
				}
			std::map<std::string, float>::iterator it2 = _dataBtc.begin();
			std::map<std::string, float>::iterator it;
			for(it = _dataBtc.begin();it != _dataBtc.end(); ++it){
				if(it->first == date){
					_amount = it->second * value;
					break ;
				}
				else if(it->first > date){
					_amount = it2->second * value;
					break ;
				}
				it2 = it;
			}
			if(_amount ){
				std::cerr << "Error: bad input => " << date << std::endl;
				return;
			}
			std::cout << it->first << "=>" << value << "=" << _amount; 
		}