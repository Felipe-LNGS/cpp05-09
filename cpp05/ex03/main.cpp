#include "Bureaucrat.hpp"
#include "Form.hpp"
#include"ShrubberyCreationForm.hpp" 
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    Form* a;
	Form* b;
	Form* c;
	Form* d;

    a = someRandomIntern.makeForm("shrubbery creation", "HOME");
    b = someRandomIntern.makeForm("presidential pardon", "Ben");
    c = someRandomIntern.makeForm("robotomy request", "alibaba");
    d = someRandomIntern.makeForm("creation random", "Bender");

	if(a)
		delete a;
	if(b)
		delete b;
	if(c)
		delete c;
	if(d)
		delete d;
    return 0;
}
