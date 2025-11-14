#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    public:

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        std::string getTarget() const;

        void executor() const;

    private:

        std::string _target;
};
#endif