    #include "../incs/Bureaucrat.hpp"
    #include "../incs/AForm.hpp"
    #include "../incs/PresidentialPardonForm.hpp"
    #include "../incs/RobotomyRequestForm.hpp"
    #include "../incs/ShrubberyCreationForm.hpp"
    #include "../incs/Intern.hpp"

int main(void)
{
	{
		std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
		Intern  someRandomIntern;
		AForm* rrf;
		Bureaucrat tio("ze", 10);
		std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf;
		rrf->beSigned(tio);
		//tio.execute(*rrf);
		std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		delete rrf;
	}

}