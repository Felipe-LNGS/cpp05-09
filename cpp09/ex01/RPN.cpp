// push_back() : Ajouter un élément à la fin du vector, comme lorsqu'on empile un élément dans une pile.
// pop_back() : Supprimer le dernier élément du vector, qui correspond à dépiler le sommet de la pile.
// back() : Accéder au dernier élément du vector sans le retirer, ce qui permet de consulter la valeur au sommet de la pile.
// empty() : Vérifier si le vector est vide. Utile pour s'assurer qu'il y a assez d'éléments pour une opération ou pour confirmer qu'il reste bien un élément à la fin (le résultat final).

#include "RPN.hpp"

		std::stack<int> _array;
		std::stack<int> _arrayTmp;
		
		ReversePolish::ReversePolish(): _array(), _arrayTmp(), _index(0){}
		
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

		bool ReversePolish::storeNumber(char *av){
			
    	std::string input = static_cast<std::string>(av);
		for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/') {
            _array.push(std::string(1, c));
        } else {
            std::cerr << "Invalid character found: " << c << std::endl;
        }
    }

		}

		std::stack<std::string> ReversePolish::splitRes(){
			
			std::stack
			while(_array.size() > 3){
				_arra
			}

		}

		std::stack<std::string> ReversePolish::solveCalcul(){
			
	
		}
