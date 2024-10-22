#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Form::Form(const std::string &name, const int gradesigned, const int gradeexec): _name(name),_signed(false), _gradesigned(gradesigned), _gradeexec(gradeexec){
    if(gradeexec < 1 ||gradesigned < 1)
        throw GradeTooHighException();
    if(gradeexec > 150 ||gradesigned > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &src): _name(src._name), _signed(src._signed), _gradesigned(src._gradesigned), _gradeexec(src._gradeexec){}

Form &Form::operator=(Form const &Form){
    if (this != &Form)
        this->_signed = Form._signed;
    return *this;
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low");
}

const std::string Form::getName()const{
    return this->_name;
}

bool Form::getSigned()const{
    return this->_signed;
}

int Form::getGradeSigned()const{
    return this->_gradesigned;
}
int Form::getGradeExec()const{
    return this->_gradeexec;
}
void Form::beSigned(Bureaucrat& bureaucrat)const{
    if (bureaucrat.getGrade() > getGradeSigned())
        throw GradeTooLowException();
}
void Form::executeAction()const{
	std::cout << "Default Form" << std::endl;
}

void Form::execute(Bureaucrat const& bureaucrat)const {
        if ((bureaucrat.getGrade() > getGradeExec()) )
       		throw GradeTooLowException();
		else
			this->executeAction();
}

std::ostream &operator<<(std::ostream &os,Form &e){
    return os << NAVY + "Intern created form : " << e.getName() << " ,grade required for sign " << e.getGradeSigned() << " and grade required for exec " << e.getGradeExec() << RESET;
}
std::ostream &operator<<(std::ostream &os,const Form::GradeTooHighException &e){
    return os << e.what();
}
std::ostream &operator<<(std::ostream &os,const Form::GradeTooLowException &e){
    return os << e.what();
}
