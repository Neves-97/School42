#include "../incs/AForm.hpp"


// Default constructor
AForm::AForm() : _name("DefaultForm"), _signed(false), _grade_sign(150), _grade_exec(150) {}

// Parameterized constructor
AForm::AForm(const std::string &name, int gradeSign, int gradeExec) 
    : _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1) {
        throw GradeTooHighException();
    } else if (gradeSign > 150 || gradeExec > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm &src) 
    : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec) {}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        // _name, _grade_sign, and _grade_exec are constants and can't be assigned.
        // Only _signed can be assigned.
        this->_signed = src._signed;
    }
    return *this;
}
// Destructor
AForm::~AForm() {}

// Assignment operator overload

// Getters
const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getSign() const {
    return _signed;
}

int AForm::getGradeSign() const {
    return _grade_sign;
}

int AForm::getGradeExec() const {
    return _grade_exec;
}

// beSigned function
void AForm::beSigned(Bureaucrat &obj) {
    if (this->_signed)
        throw AForm::SignedException();
    if (obj.getGrade() <= this->_grade_sign) {
        this->_signed = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->_grade_exec)
        throw AForm::GradeTooLowException();
    else if (!this->getSign())
        throw AForm::NotSignedException();
    this->executor();
}


// Exception what() methods
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low!";
}

const char *AForm::SignedException::what() const throw() {
    return "Form: already signed!";
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form: not signed!";
}

// Overload of << operator
std::ostream &operator<<(std::ostream &stream, const AForm &src) {
    stream << "Form " << src.getName() 
           << " [Sign grade: " << src.getGradeSign() 
           << ", Exec grade: " << src.getGradeExec()
           << ", Signed: " << (src.getSign() ? "Yes" : "No") << "]";
    return stream;
}