// #ifndef FORM_HPP
// #define FORM_HPP

// #include "Bureaucrat.hpp"

// class Bureaucrat;


// class Form {

//     public:
        
//         Form();
//         Form(std::string name, int grade_sign, int grade_exec);
//         Form(const Form &src);
//         Form &operator=(const Form &src);
//         ~Form();

//         class GradeTooHighException : public std::exception {
            
//             public:

//                 virtual const char* what() const throw(); // Override what() method
//         };
//         class GradeTooLowException : public std::exception {
            
//             public:
                
//                 virtual const char* what() const throw(); // Override what() method
//         };

//         const std::string &getName() const;
//         bool                getSign() const;
//         int                 getGradeSign() const;
//         int                 getGradeExec() const;

//         void beSigned(Bureaucrat &obj);


    

//     private:

//         const std::string _name;
//         bool              _signed;
//         const int         _grade_sign;
//         const int         _grade_exec;

// };

// std::ostream &operator<<(std::ostream &stream, const Form &src);

// #endif

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExec); // Updated
        Form(const Form &src);
        Form &operator=(const Form &src);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw(); // Override what() method
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw(); // Override what() method
        };

        const std::string &getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(Bureaucrat &obj);

    private:
        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;
};

std::ostream &operator<<(std::ostream &stream, const Form &src);

#endif
