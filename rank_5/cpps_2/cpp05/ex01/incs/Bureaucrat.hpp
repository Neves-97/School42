#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {

    public:

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        void incrementGrade();
        void decrementGrade();

        const std::string &getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception {
            
            public:

                virtual const char* what() const throw(); // Override what() method
        };
        class GradeTooLowException : public std::exception {
            
            public:
                
                virtual const char* what() const throw(); // Override what() method
        };
        void signForm(Form &form);

    private:

        std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj);

#endif