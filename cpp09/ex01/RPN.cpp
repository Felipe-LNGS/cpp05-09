// push_back() : Ajouter un élément à la fin du vector, comme lorsqu'on empile un élément dans une pile.
// pop_back() : Supprimer le dernier élément du vector, qui correspond à dépiler le sommet de la pile.
// back() : Accéder au dernier élément du vector sans le retirer, ce qui permet de consulter la valeur au sommet de la pile.
// empty() : Vérifier si le vector est vide. Utile pour s'assurer qu'il y a assez d'éléments pour une opération ou pour confirmer qu'il reste bien un élément à la fin (le résultat final).

#include "RPN.hpp"

ReversePolish::ReversePolish(): _array(), _countNumber(0), _countSign(0){}

ReversePolish::ReversePolish(const ReversePolish &src){
	if(this != &src){
		_array = src._array;
		_countNumber = src._countNumber;
		_countSign = src._countSign;
	}
}

ReversePolish &ReversePolish::operator =(const ReversePolish &cpy){
	if(this != &cpy){
		_array = cpy._array;
		_countNumber = cpy._countNumber;
		_countSign = cpy._countSign;
	}
	return *this;
}

ReversePolish::~ReversePolish(){}

int ReversePolish::makeCalcul(int nb1, int nb2, char who){
	
	int result = 0;
	switch(who){
		case '+':
			result = nb2 + nb1;
			if ((nb2 > 0 && nb1 > 0 && result < 0) || (nb2 < 0 && nb1 < 0 && result > 0))
				throw std::overflow_error("Overflow: result too large in addition");
		break;
		case  '-':
			result = nb2 - nb1;
			if ((nb2 < 0 && nb1 > 0 && result > 0) || (nb2 > 0 && nb1 < 0 && result < 0))
				throw std::overflow_error("Overflow: result too large in subtraction");
		break;
		case '*' :
			result = nb2 * nb1;
			if (nb2 != 0 && result / nb2 != nb1)
				throw std::overflow_error("Overflow: result too large in multiplication");
		break;
		case '/' :
			if (nb1 == 0)
				throw std::runtime_error("Error : Division by zero");
			else
				result = nb2 / nb1;
		break;
		default :
			throw std::runtime_error("Error : Invalid operator");
	}
	if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Overflow: result exceeds integer limits");
	return result;
}

bool ReversePolish::checkInput(std::string str, int who){
	int nb = -42;
	if(who == 1){
		for(int i = 0; str[i]; ++i){
			if(!isdigit(str[i]))
				return false ;
			}
		nb = atoi(str.c_str());
		if(nb >= 0 && nb <= 9 ){
			_array.push(nb);
			return true ;
		}
	}
	if (who == 0){
		if(strchr("/*-+", str[0]) && str.size() == 1)
			return true;
	}
return false;
}

char ReversePolish::parseStack(std::string str){
	
	char sign = 0;			
		if(checkInput(str,1)){
			_countNumber++;
			return sign;
		}
		if(checkInput(str, 0)){
			_countSign++;
			return sign = str[0];
		}
		else
			throw std::runtime_error("Error: wrong input");
return sign;
}

int ReversePolish::calculator(char *av){

	std::stringstream ss(av);
	std::string input ;
	int result = 0;

	while (ss >> input){
	char sign = parseStack(input);
	if( _array.size() >= 2 && sign){
		int nb1 = _array.top();
		_array.pop();
		int nb2 = _array.top();
		_array.pop();
		result = makeCalcul(nb1,nb2,sign);
		_array.push(result); 
		// std::cout  << nb2 << " " << sign << " " << nb1 << std::endl;
		// std::cout <<"result : "<<  result << std::endl <<std::endl;
		sign = 0;
		}
	}
	if ((_countSign == 1 && _countNumber == 1 ) )
		throw std::runtime_error("Error: wrong usage");
	if(_countSign != _countNumber -1 || _array.size() != 1)
		throw std::runtime_error("Error: wrong number of operators and operands");
return result;
}