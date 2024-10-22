#include "ShrubberyCreationForm.hpp"
#include <fstream>

		ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, 145, 137 ), _target(target){}
		
		ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src),_target(src._target){}
		
		ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &crea){
			if (this != &crea)
				this->_target = crea._target;
			return *this;
		}
	
		ShrubberyCreationForm::~ShrubberyCreationForm(){}

		std::string ShrubberyCreationForm::getTarget()const{
			return this->_target;
		}
		
		void ShrubberyCreationForm::executeAction()const{
		std::ofstream outfile(std::string(this->_target + "_shrubbery").c_str());

		if (!outfile.is_open()) {
			std::cerr << "Error: Could not open the file!" << std::endl;
			return;
			}
		outfile  << "       ###\n"
				<< "      #o###\n"
				<< "    #####o###\n"
				<< "   #o#\\#|#/###\n"
				<< "    ###\\|/#o#\n"
				<< "     # }|{  #\n"
				<< "       }|{\n";
   		 outfile.close();
		std::cout << GRNN +"File " << getTarget() << "_shruberry created.\n" + RESET;
		}