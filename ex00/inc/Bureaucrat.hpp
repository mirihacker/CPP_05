/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:07:48 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/11 14:40:52 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT.HPP
#define BUREAUCRAT.HPP

#include <iostream>
#include <string>
#include <stdexcept>

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