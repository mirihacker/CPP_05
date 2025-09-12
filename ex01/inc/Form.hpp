/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:01:57 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/12 14:34:18 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signedGrade;
        const int execGrade;
    
    public:
        // OCF
        Form();
        Form(const std::string &name, int signedGrade, int execGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignedGrade() const;
        int getExecGrade() const;

        // Other member functions
        void beSigned(const Bureaucrat& buro);
        
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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif