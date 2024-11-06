// push_back() : Ajouter un élément à la fin du vector, comme lorsqu'on empile un élément dans une pile.
// pop_back() : Supprimer le dernier élément du vector, qui correspond à dépiler le sommet de la pile.
// back() : Accéder au dernier élément du vector sans le retirer, ce qui permet de consulter la valeur au sommet de la pile.
// empty() : Vérifier si le vector est vide. Utile pour s'assurer qu'il y a assez d'éléments pour une opération ou pour confirmer qu'il reste bien un élément à la fin (le résultat final).

#include "RPN.hpp"

	std::stack<int> _array;
	std::stack<int> _arrayTmp;
	
	// ReversePolish::ReversePolish(): _array(), _arrayTmp(), _index(0){}
	
	// ReversePolish::ReversePolish(const ReversePolish &src){
	// 	if(this != &src){
	// 		for(int i = 0; src._array; ++i){
	// 			this->_array = src._array;
	// 		}
	// 		for(int i = 0; src._arrayTmp; ++i){
	// 			this->_array = src._arrayTmp;
	// 		}	
	// 	}
	// }
	// ReversePolish &ReversePolish::operator =(const ReversePolish &cpy){
	// 	if(this != &cpy){
	// 		for(int i = 0; cpy._array[i]; ++i){
	// 			this->_array[i] = cpy._array[i];
	// 		}
	// 		for(int i = 0; cpy._arrayTmp[i]; ++i){
	// 			this->_array[i] = cpy._arrayTmp[i];
	// 		}	
	// 	}
	// 	return *this;
	// }
	ReversePolish::~ReversePolish(){}
	int makeCalcul(int nb1, int nb2, char who){
		
		int result = 0;
		
		switch(who){
			case '+':
				result = nb2 + nb1; 
			case  '-':
				result = nb2 - nb1;
			case '*' :
				result = nb2 * nb1;
			case '/' :
				{if (nb1 == 0|| nb2 == 0){
					std::cerr << "Division par 0 impossible \n";
					throw();}
				else
					result = nb2 / nb1;
			}
			default :
				std::cerr << "Wrong type\n";
		}
		return result;
	}

	bool ReversePolish::checkInput(char c, int who){
		if(c >= '0' && c <= '9' && who == 1)
			return true ;
		if(strchr("+-*/", c) && who == 0)
			return true;
	return false;
	}

	void ReversePolish::calculator(char *av){
		std::stringstream ss(av);
		std::string input;
		int signNb = 0;
		int number = 0;
		char sign;

		while (ss >> input){
			int i = 0;
		while(ss >> input){
			if(checkInput(input[i], 1)){
				_array.push(input);
				number++;
				}
			if(checkInput(input[i], 0)){
				signNb++;
				sign = input[i];
				break ;}
			i++;
		}
		int nb1 = atoi(input.c_str());
		_array.pop();
		int nb2 = atoi(input.c_str());
		_array.pop();
		makeCalcul(nb1,nb2,sign);
	}
	}