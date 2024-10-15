#pragma once

#include <string>
#include <iostream>
#include "Color.hpp"

class Bureaucrat{
	private :
		const std::string  _name;
		int _grade;

	public :
		class GradeTooHighException : public std::exception{
			public :
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				const char* what() const throw();
		};

		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();
		void incrementGrade();
		void decrementGrade();
		int getGrade() const;
		const std::string getName()const;
};
		std::ostream& operator<<(std::ostream& os, const Bureaucrat& e);
		std::ostream& operator<<(std::ostream& os, const Bureaucrat::GradeTooHighException& e);
		std::ostream& operator<<(std::ostream& os, const Bureaucrat::GradeTooLowException& e);
