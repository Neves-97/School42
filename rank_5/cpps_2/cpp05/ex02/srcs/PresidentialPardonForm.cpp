#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("Presidential Pardon Form", 25, 5) {
    *this = src;
} 

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {

    if (this->_target != src._target) 
        this->_target = src._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executor() const {
    std::cout << _target << " was pardoned by Zaphod Beeblebrox!" << std::endl;
}