/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:07:48 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/12 15:33:23 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "../inc/Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Methods to +/- grade
    void incrementGrade();
    void decrementGrade();

    // Other member Functions
    void signForm(Form &form);

    // Exception classes
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

// Operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& buro);

#endif