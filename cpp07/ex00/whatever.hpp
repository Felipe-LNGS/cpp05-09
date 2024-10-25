#pragma once

#include <string>
#include <iostream>

template<typename T>
T const &max(T const &a, T const &b){
		if (a == b) { 
		return (b);
	} else {
		return (a > b ? a : b);
	}
}

template<typename T>
T const &min(T const &a, T const &b){
	if (a == b) { 
		return (b);
	} else {
		return (a < b ? a : b);
	}
}

template<typename T>
void  swap(T  &x, T  &y){
	T swap;
	swap = x;
	x = y;
	y = swap;
}
