#pragma once 

#include <string>
class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _gradesigned;
        const int _gradeexec;
    public:
        class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        Form(const std::string &name, const int gradesign, const int gradeexec);
        Form(Form const &src);
        Form &operator=(Form const &form);
        ~Form();
        void beSigned(Bureaucrat& bureaucrat);
        const std::string getName()const;
        bool getSigned()const;
        int getGradeSigned()const;
        int getGradeExec()const;
};
std::ostream &operator<<(std::ostream &os,Form &e);
std::ostream &operator<<(std::ostream &os,Form::GradeTooHighException &e);
std::ostream &operator<<(std::ostream &os,Form::GradeTooLowException &e);

