#pragma once

#include "Data.h"
#include "Color.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

class Serializer{
	public:
		static uintptr_t  serialize(Data* ptr);
		static Data* deserialize(uintptr_t  raw);
	private :
		Serializer();
		Serializer(Serializer const &src);
		Serializer & operator=(Serializer const &cpy);
		~Serializer();
};
