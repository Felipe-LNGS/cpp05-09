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
	public :
		ReversePolish();
		ReversePolish(const ReversePolish & src);
		ReversePolish & operator=(const ReversePolish &cpy);
		~ReversePolish();
		int makeCalcul(int nb1, int nb2, char who);
		bool checkInput(char c, int who);
		void calculator(char *input);
};