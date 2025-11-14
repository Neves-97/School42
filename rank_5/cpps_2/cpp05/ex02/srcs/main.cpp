#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"


int main()
{
    // Create a bureaucrat
    Bureaucrat bureaucrat("John Doe", 5);

    // Create a ShrubberyCreationForm
    ShrubberyCreationForm shrubberyForm("home");


    // Test executing ShrubberyCreationForm
    try
    {
        shrubberyForm.beSigned(bureaucrat);
        shrubberyForm.execute(bureaucrat);
        std::cout << "ShrubberyCreationForm executed successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error executing ShrubberyCreationForm: " << e.what() << std::endl;
    }

    // Create a RobotomyRequestForm
    RobotomyRequestForm robotomyForm("target");

    // Test executing RobotomyRequestForm
    try
    {
        robotomyForm.beSigned(bureaucrat);
        robotomyForm.execute(bureaucrat);
        std::cout << "RobotomyRequestForm executed successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error executing RobotomyRequestForm: " << e.what() << std::endl;
    }

    // Create a PresidentialPardonForm
    PresidentialPardonForm pardonForm("target");

    // Test executing PresidentialPardonForm
    try
    {
        pardonForm.beSigned(bureaucrat);
        pardonForm.execute(bureaucrat);
        std::cout << "PresidentialPardonForm executed successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error executing PresidentialPardonForm: " << e.what() << std::endl;
    }

    bureaucrat.decrementGrade();
//now it should not execute!!
    try
    {
        pardonForm.beSigned(bureaucrat);
        pardonForm.execute(bureaucrat);
        std::cout << "PresidentialPardonForm executed successfully" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error executing PresidentialPardonForm: " << e.what() << std::endl;
    }

    return 0;
}