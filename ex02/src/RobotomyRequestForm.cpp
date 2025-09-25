/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:17:35 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/25 16:40:59 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default RobotomyRequestForm", 72, 45), target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other); //Call parent class copy assignment
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::UnsignedFormException();
    if (executor.getGrade() > getExecGrade())
    {
        std::cerr << "Error: Unable to execute!!!\n" << std::endl;
        throw AForm::GradeTooLowException();
    }
    
    std::cout << "\n ----------- ZZZZZZ DRILLING NOISESSS ----------- " << std::endl;
    std::cout << "\n ----------- ZZZZZZ DRILLING NOISESSS ----------- " << std::endl;
    std::cout << "\n ----------- ZZZZZZ DRILLING NOISESSS ----------- \n" << std::endl;
    
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has succesfully been robotomized!\n" << std::endl;
    else
        std::cout << this->target << " has failed the robotomy!\n" << std::endl;

}

