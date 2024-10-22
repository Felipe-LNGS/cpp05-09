#include "RobotomyRequestForm.hpp"

	RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45), _target(target){}
		
	RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src._target){}
		
	RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &crea){
		if (this != &crea)
			this->_target = crea._target;
		return *this;
	}
	
	RobotomyRequestForm::~RobotomyRequestForm(){}
	
	std::string RobotomyRequestForm::getTarget()const{
		return this->_target;
	}
	
	void RobotomyRequestForm::executeAction()const{
		std::cout << GRNN +getTarget() <<  " has been robotomized successfully.\n" + RESET;
	}