#pragma once 
#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm & operator =(const PresidentialPardonForm &crea);
		~PresidentialPardonForm();
		std::string getTarget()const;
		void executeAction()const;
};