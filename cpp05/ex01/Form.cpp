#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int gradesigned, const int gradeexec): _name(name),_signed(false), _gradesigned(gradesigned), _gradeexec(gradeexec){
    if(gradeexec < 1 ||gradesigned < 1)
        throw GradeTooHighException();
    if(gradeexec > 150 ||gradesigned > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &src): _name(src._name), _signed(src._signed), _gradesigned(src._gradesigned), _gradeexec(src._gradeexec){}

Form &Form::operator=(Form const &form){
    if (this != &form)
        this->_signed = form._signed;
    return *this;
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade for exec or sign is too high for approuvate form");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade for exec or sign is too low for approuvate form");
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

void Form::beSigned(Bureaucrat& bureaucrat){
        if (bureaucrat.getGrade() <= getGradeSigned() && (bureaucrat.getGrade() <= getGradeExec()) ){
        this->_signed = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os,Form &e){
    return os << NAVY + "Form " << e.getName() << " created, grade required for sign " << e.getGradeSigned() << " and grade required for exec " << e.getGradeExec() << RESET;
}
std::ostream &operator<<(std::ostream &os,Form::GradeTooHighException &e){
    return os << e.what();
}
std::ostream &operator<<(std::ostream &os,Form::GradeTooLowException &e){
    return os << e.what();
}
