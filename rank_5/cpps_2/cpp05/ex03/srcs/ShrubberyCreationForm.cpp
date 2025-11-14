#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137) {
    *this = src;
} 

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {

    if (this->_target != src._target) 
        this->_target = src._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget(void)const {
	return (this->_target);
}

void ShrubberyCreationForm::executor() const {
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}
