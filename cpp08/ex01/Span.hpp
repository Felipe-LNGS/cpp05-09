
#include <algorithm>
#include<iostream>
#include<vector>
#include <limits.h>
#include <iterator> 

#define n10K 11111

class Span{
    private :
        unsigned int _nbMax;
        std::vector<int> _vec;
    public :
        Span(const unsigned int &n);
        Span(Span const &src);
        Span & operator=(Span const &cpy);
        ~Span();
        void addNumber(int  &nb);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        class VecFull : public std::exception{
            public :
                const char *what() const throw(){
                    return ("ERROR : Try to add number but your container is full.");
                }
        };     
        class VecEmpty : public std::exception{
             public :
                const char *what() const throw(){
                    return ("ERROR : You need minimum 2 number in your container.");
                }
        };     
};

    std::vector<int> randomNumber(int size);
