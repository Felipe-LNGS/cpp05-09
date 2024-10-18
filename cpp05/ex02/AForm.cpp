#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm(const std::string &name, const int gradesigned, const int gradeexec): _name(name),_signed(false), _gradesigned(gradesigned), _gradeexec(gradeexec){
    if(gradeexec < 1 ||gradesigned < 1)
        throw GradeTooHighException();
    if(gradeexec > 150 ||gradesigned > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &src): _name(src._name), _signed(src._signed), _gradesigned(src._gradesigned), _gradeexec(src._gradeexec){}

AForm &AForm::operator=(AForm const &AForm){
    if (this != &AForm)
        this->_signed = AForm._signed;
    return *this;
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low");
}

const std::string AForm::getName()const{
    return this->_name;
}

bool AForm::getSigned()const{
    return this->_signed;
}

int AForm::getGradeSigned()const{
    return this->_gradesigned;
}
int AForm::getGradeExec()const{
    return this->_gradeexec;
}
void AForm::beSigned(Bureaucrat& bureaucrat)const{
    if (bureaucrat.getGrade() > getGradeSigned())
        throw GradeTooLowException();
}
void AForm::execute(Bureaucrat const& bureaucrat)const {
        if ((bureaucrat.getGrade() > getGradeExec()) )
       		throw GradeTooLowException();
		else
			this->executeAction();
}

std::ostream &operator<<(std::ostream &os,AForm &e){
    return os << NAVY + "AForm " << e.getName() << " created, grade required for sign " << e.getGradeSigned() << " and grade required for exec " << e.getGradeExec() << RESET;
}
std::ostream &operator<<(std::ostream &os,const AForm::GradeTooHighException &e){
    return os << e.what();
}
std::ostream &operator<<(std::ostream &os,const AForm::GradeTooLowException &e){
    return os << e.what();
}
