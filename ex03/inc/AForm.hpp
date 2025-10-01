/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:01:57 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/25 16:35:10 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signedGrade;
        const int execGrade;
    
    public:
        // OCF
        AForm();
        AForm(const std::string &name, int signedGrade, int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignedGrade() const;
        int getExecGrade() const;

        // Other member functions
        void beSigned(const Bureaucrat& buro);

        // Pure virtual function (ensures True Abstract Class)
        virtual void execute(const Bureaucrat& executor) const = 0;
        
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
        
        class UnsignedFormException: public std::exception
        {
            public:
            const char* what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif