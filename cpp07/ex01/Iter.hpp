#pragma once

#include <iostream>
#include <string>
#include <cstring>

template<typename T>
void print(T& a) {
	std::cout << a << " ";
}

template<typename T>
void increment(T& a) {
	++a;
}

template<typename T>
void changeChar(T& a) {
	for(int i =0; a[i]; i++)
	{
		if(a[i] == 'o')
			a[i] = 'O';
	}
}
template<typename T>
void	iter(T *array, int len,void((*function)(T&))){
	if(!array || !function){
		std::cout << "Error" << std::endl;
		return;
	}
	for(int i = 0; i < len;i++){
		function(array[i]);
	}
}