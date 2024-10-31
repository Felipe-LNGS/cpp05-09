#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	
	(void) ac;
	BitcoinExchange btc;

	btc.stockMap(av[1]);
	btc.findValue("2009-04-32", 5);
}