#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if ( grade > 150)
        throw(Bureaucrat::GradeTooLowException()); 
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {

    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {

    if (this != &src)
        _grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);  // Attempt to sign the form
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->_name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->_name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Exeptions

const char *Bureaucrat::GradeTooHighException::what() const throw() {

    return "\033[31mBureaucrat GradeTooHighException\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

    return "\033[34mBureaucrat GradeTooLowException\033[0m";
}

// Increment && Decrement

void Bureaucrat::incrementGrade() {

    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {

    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}

// Getter

const std::string &Bureaucrat::getName() const {

    return _name;
}

int Bureaucrat::getGrade() const {

    return _grade;
}

// overload

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj) {

    stream << obj.getName() << ", Bureaucrat grade is --> " << obj.getGrade();
    return stream;
}