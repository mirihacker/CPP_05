#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
    public:
        // OCF
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        //Make Form
        AForm* makeForm(const std::string &formName, const std::string &target);
};

#endif