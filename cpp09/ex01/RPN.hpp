#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <climits>
class ReversePolish{
	private :
		std::stack<int> _array;
		int _countNumber;
		int _countSign;
	public :
		ReversePolish();
		ReversePolish(const ReversePolish & src);
		ReversePolish & operator=(const ReversePolish &cpy);
		~ReversePolish();
		
		char parseStack(std::string str);
		int makeCalcul(int nb1, int nb2, char who);
		bool checkInput(std::string str, int who);
		int calculator(char *input);
};