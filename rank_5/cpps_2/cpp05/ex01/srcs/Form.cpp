#include "../incs/Form.hpp"


// Default constructor
Form::Form() : _name("DefaultForm"), _signed(false), _grade_sign(150), _grade_exec(150) {}

// Parameterized constructor
Form::Form(const std::string &name, int gradeSign, int gradeExec) 
    : _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1) {
        throw GradeTooHighException();
    } else if (gradeSign > 150 || gradeExec > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &src) 
    : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec) {}

// Destructor
Form::~Form() {}

// Assignment operator overload
Form &Form::operator=(const Form &src) {
    if (this != &src) {
        // _name, _grade_sign, and _grade_exec are constants and can't be assigned.
        // Only _signed can be assigned.
        this->_signed = src._signed;
    }
    return *this;
}

// Getters
const std::string &Form::getName() const {
    return _name;
}

bool Form::getSign() const {
    return _signed;
}

int Form::getGradeSign() const {
    return _grade_sign;
}

int Form::getGradeExec() const {
    return _grade_exec;
}

// beSigned function
void Form::beSigned(Bureaucrat &obj) {
    if (obj.getGrade() <= this->_grade_sign) {
        this->_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

// Exception what() methods
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low!";
}

// Overload of << operator
std::ostream &operator<<(std::ostream &stream, const Form &src) {
    stream << "Form " << src.getName() 
           << " [Sign grade: " << src.getGradeSign() 
           << ", Exec grade: " << src.getGradeExec()
           << ", Signed: " << (src.getSign() ? "Yes" : "No") << "]";
    return stream;
}