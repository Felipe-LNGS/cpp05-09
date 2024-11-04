#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>

class ReversePolish{
	private :
		std::stack<std::string> _array;
		std::stack<std::string> _arrayTmp;
		int _index;
	public :
		ReversePolish();
		ReversePolish(const ReversePolish & src);
		ReversePolish & operator=(const ReversePolish &cpy);
		~ReversePolish();
		bool storeNumber(char *input);
		std::stack<std::string> splitRes();
		std::stack<std::string> solveCalcul();
};