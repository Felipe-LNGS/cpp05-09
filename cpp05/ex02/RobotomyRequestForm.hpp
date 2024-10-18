#pragma once 
#include <string>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm & operator =(const RobotomyRequestForm &crea);
		~RobotomyRequestForm();
		std::string getTarget()const;
		void executeAction()const;
};