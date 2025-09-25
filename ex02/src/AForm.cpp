/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:47:24 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/25 12:39:45 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

// OCF
AForm::AForm(void) : name("Buro"), isSigned(0), signedGrade(1), execGrade(1) {}

AForm::AForm(const std::string &name, int signedGrade, int execGrade) : name(name), isSigned(0), signedGrade(signedGrade), execGrade(execGrade)
{
    if (signedGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signedGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), execGrade(other.execGrade) {}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm(void) {}

//Getters
const std::string &AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getSignedGrade() const
{
    return (this->signedGrade);
}

int AForm::getExecGrade() const
{
    return (this->execGrade);
}

// Other member functions
void AForm::beSigned(const Bureaucrat& buro)
{
    if (buro.getGrade() > this->signedGrade)
        throw GradeTooLowException();    
    this->isSigned = 1;
}

// Exception classes
const char* AForm::GradeTooHighException::what() const throw()
{
    return("Grade is too high!\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Grade is too low!\n");
}

const char* AForm::UnsignedFormException::what() const throw()
{
    return("Form not yet signed!\n");
}

// Operator Overload
std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << form.getName() << ":\n" << "Is form signed? " \
    << form.getIsSigned() << "\n" << "Form has signed grade of: " \
    << form.getSignedGrade() << "\n" << "Form has execution grade of: " \
    << form.getExecGrade() << std::endl;
    return (out);
}