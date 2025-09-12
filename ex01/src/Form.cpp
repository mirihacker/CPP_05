/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:47:24 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/12 14:33:58 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Form.hpp"

// OCF
Form::Form(void) : name("Buro"), isSigned(0), signedGrade(100), execGrade(100) {}

Form::Form(const std::string &name, int signedGrade, int execGrade) : name(name), isSigned(0), signedGrade(signedGrade), execGrade(execGrade)
{
    if (signedGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signedGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), execGrade(other.execGrade) {}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form(void) {}

//Getters
const std::string &Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getSignedGrade() const
{
    return (this->signedGrade);
}

int Form::getExecGrade() const
{
    return (this->execGrade);
}

// Other member functions
void Form::beSigned(const Bureaucrat& buro)
{
    if (buro.getGrade() > this->signedGrade)
        throw GradeTooLowException();    
    this->isSigned = 1;
}

// Exception classes
const char* Form::GradeTooHighException::what() const throw()
{
    return("Grade is too high!\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Grade is too low!\n");
}

// Operator Overload
std::ostream& operator<<(std::ostream& out, const Form& buro)
{
    out << buro.getName() << ", Form grade " << buro.getGrade() << std::endl;
    return (out);
}