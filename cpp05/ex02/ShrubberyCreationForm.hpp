#pragma once 
#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm & operator =(const ShrubberyCreationForm &crea);
		~ShrubberyCreationForm();
		std::string getTarget()const;
		void executeAction()const;
};