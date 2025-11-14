#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
    public:

        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();

        void executor() const;

    private:

        std::string _target;
};

#endif