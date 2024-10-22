#pragma once 
#include <string>
#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form{
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