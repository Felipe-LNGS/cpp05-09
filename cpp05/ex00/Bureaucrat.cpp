#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade to high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade to low");
}

void Bureaucrat::incrementGrade(){
  
    if (this->_grade <= 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade(){  
    if (this->_grade >= 150)
        throw GradeTooLowException();
    else 
        this->_grade++;
}

const std::string Bureaucrat::getName()const{
    return this->_name;
}

int Bureaucrat::getGrade()const{
    return this->_grade;
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat& e){
    return os << CORL + ITAL + e.getName() + RESET << CORL+ ", bureaucrat grade " << ITAL << e.getGrade()<< RESET;
}
std::ostream & operator<<(std::ostream &os, const Bureaucrat::GradeTooHighException& e){
    return os << e.what() ;
}
std::ostream & operator<<(std::ostream &os, const Bureaucrat::GradeTooLowException& e){
    return os << e.what();
}