/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:08:01 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/10 12:22:37 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Buro"), grade(100) {}

Bureaucrat::Bureaucrat(const std::string&name, int grade)
{
    if (grade > 150)
        throw GradeTooLowException;
    else if (grade < 1)
        throw GradeTooHighException;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    
}
