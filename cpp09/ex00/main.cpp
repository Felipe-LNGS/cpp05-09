#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	
	(void) ac;
	BitcoinExchange btc;
/**************MANDATORY*****************/
	btc.stockMap(av[1]);
	btc.findValue("2011-01-03", 3);
	btc.findValue("2011-01-03", 2);
	btc.findValue("2011-01-03", 1);
	btc.findValue("2011-01-03", 1.2);
	btc.findValue("2011-01-09", 1);
	btc.findValue("2012-01-11", -1);
	btc.findValue("2001-42-42", 0);
	btc.findValue("2012-01-11", 1);
	btc.findValue("2012-01-11", 2147483648);
/**************TEST****************/
	// btc.findValue("2012-01-11", 999);
	// btc.findValue("2025-01-11", 2);
	// btc.findValue("2023-01-11", 0);
	// btc.findValue("2013-01-11", 1000);
	// btc.findValue("2024-01-11", 2);
}