#pragma once

#include <algorithm>
#include<iostream>
#include<vector>
#include <limits.h>
#include <iterator> 
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& src) : std::stack<T>(src) {}
		MutantStack& operator=(const MutantStack& cpy) {
			if (this != &cpy) {
				std::stack<T>::operator=(cpy);
			}
			return *this;
		}
		~MutantStack() {}

		// Typedefs pour les iterateurs
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Methodes pour les itérateurs
		iterator begin() { return std::stack<T>::c.begin();}
		iterator end() { return std::stack<T>::c.end();}
		const_iterator cbegin() const { return std::stack<T>::c.cbegin();}
		const_iterator cend() const { return std::stack<T>::c.cend();}
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin();}
		reverse_iterator rend() { return std::stack<T>::c.rend();}
		const_reverse_iterator crbegin() const { return std::stack<T>::c.rbegin();}
		const_reverse_iterator crend() const { return std::stack<T>::c.rend();}
};

//  Dans std::stack, c est le nom du conteneur sous-jacent qui stocke les élément
// Par défaut, c’est un std::deque, mais il peut être remplacé par un autre type de conteneur compatible, comme un std::vector ou une std::list
// std::deque (double-ended queue) est un conteneur de la STL en C++ qui permet d’ajouter ou de supprimer des éléments efficacement à ses deux extrémités (avant et arrière)

// begin et end : Renvoient des itérateurs pour parcourir le conteneur de l'avant à l'arrière.
// cbegin et cend : Renvoient des itérateurs constants pour un parcours en lecture seule.
// rbegin et rend : Renvoient des itérateurs pour un parcours à l’envers.
// crbegin et crend : Renvoient des itérateurs constants pour un parcours en lecture seule à l'envers.
// push(const T& value) : Pour ajouter un élément à la stack.
// pop() : Pour retirer l'élément du haut de la stack.
// top() : Pour accéder à l'élément au sommet de la stack.
// empty() : Vérifie si la stack est vide.
// size() : Retourne le nombre d'éléments dans la stack.

