#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExec); // Updated
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw(); // Override what() method
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw(); // Override what() method
        };
        class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        class SignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        const std::string &getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(Bureaucrat &obj);
        virtual void execute(Bureaucrat const &executor) const;
        virtual void executor() const = 0;  

    private:
        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;
};

std::ostream &operator<<(std::ostream &stream, const AForm &src);

#endif
