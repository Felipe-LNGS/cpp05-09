		#include "Intern.hpp"
		#include"ShrubberyCreationForm.hpp" 
		#include"RobotomyRequestForm.hpp"
		#include"PresidentialPardonForm.hpp"
		#include "Bureaucrat.hpp"

		#include <cstdio>
		Intern::Intern(){}

		Intern::Intern(Intern const &src){
			(void)src;
		}

		Intern & Intern::operator=(Intern const &cpy){
		(void)cpy;
		return *this;
		}

		Intern::~Intern(){}

		Form *Intern:: makeForm(const char *formName, const char *name){
			Form *form = NULL;
			int whichForm = 42;
			std::string nameString = name;
			std::string formNameString = formName;

			std::string tab[]={"robotomy request", "presidential pardon", "shrubbery creation"};
			
			for(int i =0; i < 3; i++)
			{				
				if(formName == tab[i])
					{whichForm = i;
					break;}
			}
			switch(whichForm){
				case 0 :
					form = new RobotomyRequestForm(nameString);
				break;
				case 1 :
					form = new PresidentialPardonForm(nameString);
				break;
				case 2 :
					form = new ShrubberyCreationForm(nameString);
				break;
				default :
					std::cout << REDD +"Wrong type form : " + RESET << formName << std::endl;
				return form;
			}
			try{
				Bureaucrat random("Eugene", 1);
				std::cout << *form << std::endl;
				std::cout<<random<<std::endl;
				random.executeForm(*form);
			}
			catch (std::exception & e){
      	  		std::cout <<REDD+ e.what() +RESET<< std::endl << std::endl;
    		}
			return form;
		}

