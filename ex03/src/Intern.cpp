#include "../inc/Intern.hpp"
#include <cctype>

// OCF
Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other; // No private var, ergo empty
}
Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

// Utility

static std::string normalize(const std::string &str)
{
    std::string result;

    // Skip leading spaces
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start]))
        start++;
    
    // Skip trailing spaces
    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1]))
        end--;
    
    // Convert to lowercase
    for (size_t i = 0; i < str.size(); i++)
    {
        result += static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
    }
    return (result);
}

// MakeForm

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm* returnForm = 0;
    std::string formTypes[3] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    std::string normInput = normalize(formName);

    int formIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        if (normInput == formTypes[i])
        {
            formIndex = i;
            break;
        }
    }

    switch (formIndex)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            returnForm = new ShrubberyCreationForm(target);
            break;
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            returnForm = new RobotomyRequestForm(target);
            break;
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            returnForm = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Intern could not create form: " << formName << std::endl;
            break;
    }
    return (returnForm);
}