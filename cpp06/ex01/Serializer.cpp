
#include "Serializer.hpp"

		uintptr_t  Serializer::serialize(Data* ptr){
		uintptr_t  convert = reinterpret_cast<uintptr_t >(ptr);
			return convert;
		}

		Data* Serializer::deserialize(uintptr_t  raw){
			Data *convert = reinterpret_cast<Data*>(raw);
			return convert;
		}

		Serializer::Serializer(){}
		Serializer::Serializer(Serializer const &src){
			(void)src;
		}
		Serializer & Serializer::operator=(Serializer const &cpy){
			(void)cpy;
			return *this;
		}
		Serializer::~Serializer(){}