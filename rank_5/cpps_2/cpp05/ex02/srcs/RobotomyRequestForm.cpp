#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("default target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Presidential Pardon Form", 72, 45) {
    *this = src;
} 

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {

    if (this->_target != src._target) 
        this->_target = src._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executor() const {
	std::cout << " SOME DRILLING NOISES " << std::endl << _target;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << " has been successfully Roooobotimized!" << std::endl;
	else
		std::cout << " did not work, womp womp!" << std::endl;
}