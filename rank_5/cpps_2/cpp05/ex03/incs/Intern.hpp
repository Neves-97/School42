#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

    public: 

        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
    private:
        
        AForm *makePresidentialForm(std::string target);
        AForm *makeRobotomyForm(std::string target);
        AForm *makeShrubberyForm(std::string target);
};

std::ostream &operator<<(std::ostream &stream, const Intern &obj);

#endif