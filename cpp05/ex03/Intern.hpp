#pragma once

#include "Form.hpp"

class Intern {

	public:
		Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &cpy);
		~Intern();
		Form* makeForm(const char *form, const char *name);
};