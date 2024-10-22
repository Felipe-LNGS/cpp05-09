#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

		PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, 25, 5), _target(target){}
		
		PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src), _target(src._target){}
		
		PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &crea){
			if (this != &crea)
				this->_target = crea._target;
			return *this;
		}
	
		PresidentialPardonForm::~PresidentialPardonForm(){}

		
		std::string PresidentialPardonForm::getTarget()const{
			return this->_target;
		}
		
		void PresidentialPardonForm::executeAction()const{
			std::cout << GRNN +getTarget() <<  " has been pardoned by Zaphod Beeblebrox\n" + RESET;
		}