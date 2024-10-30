#include "Span.hpp"

		unsigned int _nbMax;
		std::vector<int> vec;
		Span::Span( unsigned int const &n):_nbMax(n){}
		
		Span::Span(Span const &src){
			if(this!=&src)
			{
				_nbMax = src._nbMax;
				_vec.resize(src._vec.size());
				for(unsigned int i = 0; i < _nbMax; i++)
					_vec[i] = src._vec[i];
			}
		}

		Span &Span::operator=(Span const &cpy){
			if(this!=&cpy)
			{
				_nbMax = cpy._nbMax;
				_vec.resize(cpy._vec.size());
				for(unsigned int i = 0; i < _nbMax; i++)
					_vec[i] = cpy._vec[i];
			}
			return *this;
		}

	   Span::~Span(){}

		int Span::shortestSpan(){
			int shortest = INT_MAX;
			int distance = 0;

			if( _vec.size() < 2)
				throw VecEmpty();
			std::sort(_vec.begin(), _vec.end());
			
			for(unsigned int i = 0; i < _vec.size() -1; i++){
				distance = _vec[i+1] - _vec[i];
				if(distance < shortest)
					shortest = distance;

				
			}
		return shortest;

		}

		 int Span::longestSpan(){
			if( _vec.size() < 2)
				throw VecEmpty();
			std::sort(_vec.begin(), _vec.end());
			int lower = _vec[0];
			int bigger = _vec[_vec.size()-1];
			return bigger - lower;
		} 

		void Span::addNumber(int &nb){
				if(_vec.size() == _nbMax)
					throw VecFull();
				else
					_vec.push_back(nb);
		}

        void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
			int dist = end - begin;

			if (dist + _vec.size() > _nbMax) {
				throw VecFull(); 
			}
			for (std::vector<int>::iterator it = begin; it != end; ++it) {
				addNumber(*it);
			}
		}

        std::vector<int> randomNumber(int size){
		
		std::vector<int> numbers;
		for (int i = 0; i < size; i++) {
			int random = rand() % 30000;
			numbers.push_back(random);
			std::cout << random << " ";
   			 }
		return numbers;
		}
