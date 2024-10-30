#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

class NotFind : public std::exception{
    public:
        const char *what() const throw(){
            return("Error: No occurrences found");
        }
};

template<typename T>
void easyfind(T& container, int toFind){
    
    typename T::iterator it = std::find(container.begin(),container.end(), toFind);
    if(it != container.end())
        std::cout << "Element found : " << *it << std::endl;
    else
        throw NotFind();
}