/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:08:01 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/11 17:42:05 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// OCF
Bureaucrat::Bureaucrat(void) : name("Buro"), grade(100) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

//Getters
const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

// Methodsto +/- grade
void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

// Exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high!\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low!\n");
}

// Operator Overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& buro)
{
    out << buro.getName() << ", bureaucrat grade " << buro.getGrade() << std::endl;
    return (out);
}