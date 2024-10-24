#include "Serializer.hpp"

int main(){
	Data *originalPtr = new Data;
	originalPtr->id = 42;
	originalPtr->name = "Xavier";
	if(originalPtr)
		std::cout <<GRNN + "Original ptr : " << originalPtr << "\nSerialize id : " << originalPtr->id << "\nOriginal name : " << originalPtr->name +RESET<<std::endl;
	
	uintptr_t  serialized = Serializer::serialize(originalPtr);
	Data *deserialized = Serializer::deserialize(serialized);
	if(deserialized == originalPtr)
	{
		std::cout << CYAN +"Serialize ptr : " << deserialized << "\nSerialize id : " << deserialized->id << "\nSerialized name : " << deserialized->name + RESET<<std::endl;
	}
	else
		std::cout << "Conversion failed" << std::endl;
	delete originalPtr;
}
