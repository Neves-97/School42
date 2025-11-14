#include "../incs/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}
Intern &Intern::operator=(const Intern &src) {
    (void) src;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makePresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);   
}

AForm *Intern::makeRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}


AForm *Intern::makeForm(std::string form_type, std::string target) {
	std::string forms[3] = { 
		"presidential pardon",
		"robotomy request",
		"shrubbery creation" };

	AForm *(Intern::*functions[3])(std::string target) = { 
		&Intern::makePresidentialForm,
		&Intern::makeRobotomyForm,
		&Intern::makeShrubberyForm };

	for (int i = 0; i < 3; i++) {
		if (form_type == forms[i]) {
			std::cout << "    ✅ " << "Intern creates " << form_type;
			return (this->*functions[i])(target);
		}
	}

	std::cout << "    ❌ \"" << form_type << "\" is not a valid form type";
	return NULL;
}

