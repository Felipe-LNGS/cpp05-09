#pragma once 

#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Color.hpp"
#include <exception>
#include <typeinfo>

class Base{
	public:
		Base();
		virtual ~Base();
		static Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};