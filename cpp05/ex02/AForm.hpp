#pragma once
#include <string>
#include "Color.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _gradesigned;
        const int _gradeexec;
	protected:
		virtual void executeAction() const = 0;
    public:
        class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        AForm(const std::string &name, const int gradesign, const int gradeexec);
        AForm(AForm const &src);
        AForm &operator=(AForm const &AForm);
        virtual ~AForm();
        const std::string getName()const;
        bool getSigned()const;
        int getGradeSigned()const;
        int getGradeExec()const;
		void beSigned(Bureaucrat& bureaucrat)const;
		void execute(Bureaucrat const & executor)const;
};
std::ostream &operator<<(std::ostream &os,AForm &e);
std::ostream &operator<<(std::ostream &os,AForm::GradeTooHighException &e);
std::ostream &operator<<(std::ostream &os,AForm::GradeTooLowException &e);

