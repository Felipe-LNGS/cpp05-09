#pragma once 
#include <string>
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form{
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