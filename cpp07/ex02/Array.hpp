#pragma once

#include <string>
#include <cstddef> 

template<typename T>
class Array{
	private :
		T *_array;
		std::size_t _size;
	public :
		Array() : _array(new T[0]), _size(0){}
		Array(unsigned int const n): _array(new T[n]), _size(n){}
		Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
			for (std::size_t i = 0; i < _size; i++) {
				_array[i] = src._array[i];
			}
		}
		Array & operator=(Array const &cpy){
			if(this!=&cpy)
			{
				delete[]_array;
				this->_size = cpy._size;
				_array = new T[_size];
				for(std::size_t i =0; i < _size; i++)
				{
					_array[i] = cpy._array[i];
				}
			}
			return *this;
		}

		T & operator[](std::size_t idx){
			if(idx >= _size)
				throw(IndexOutOfBounds());
			return(_array[idx]);
		}
		~Array(){
			delete[] this->_array;
		}
		
		std::size_t size()const{
			return this->_size;
		}

		class IndexOutOfBounds : public std::exception{
			public :
				virtual const char *what() const throw(){
					return ("Error : Index is out of bounds\n");
				}
		};
		
};
