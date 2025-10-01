/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/25 17:13:54 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n\033[33m--*--*-- BUREAUCRAT CREATION TEST --*--*--\n" << "\033[0m" << std::endl;

    try
    {
        std::cout << "Creating Bureaucrat Juan grade 5..." << std::endl;
        Bureaucrat Juan("Juan", 5);
        while (Juan.getGrade() >= 1)
        {
            std::cout << "\033[32m" << Juan << "\033[0m";
            Juan.incrementGrade();
        }
        std::cout << "\n\033[31mIncrementing over the limit!!!...\n" << "\033[0m" << std::endl;
        Juan.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cerr << e.what();
    }

    std::cout << "\n\033[33m--*--*-- INVALID BUREAUCRAT TEST --*--*--\n" << "\033[0m" << std::endl;

    try
    {
        std::cout << "\033[31mCreating Bureaucrat Jose grade 151 (should throw exception)" << "\033[0m" << std::endl;
        Bureaucrat Jose("Jose", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << "\nException caught: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "\033[31mCreating Bureaucrat Juanjo grade 0 (should throw exception)" << "\033[0m" << std::endl;
        Bureaucrat Juanjo("Juanjo", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << "\nException caught: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n\033[33m--*--*-- FORM CREATION TEST --*--*--\n" << "\033[0m" << std::endl;
   
    std::cout << "Creating Form 'ShrubberyCreationForm' ...\n" << std::endl;
    ShrubberyCreationForm Shru1;
    ShrubberyCreationForm Heilbronn("Heilbronn");
    std::cout << Shru1 << "\n" << Heilbronn << std::endl;

    std::cout << "\nCreating Form 'RobotomyRequestForm' ...\n" << std::endl;
    RobotomyRequestForm Tito;
    RobotomyRequestForm Toto("Toto");
    std::cout << Tito << "\n" << Toto << std::endl;

    std::cout << "\nCreating Form 'PresidentialPardonForm' ...\n" << std::endl;
    PresidentialPardonForm Def;
    PresidentialPardonForm Julion("Julion Alvarez");
    std::cout << Def << "\n" << Julion << std::endl;
  
    
    std::cout << "\n\033[33m--*--*-- SIGNING TEST --*--*--\n" << "\033[0m" << std::endl;

    std::cout << "Creating Bureaucrat Juan grade 26..." << std::endl;
    Bureaucrat Juan("Juan", 26);
    std::cout << "\033[32m\nBureaucrat Juan tries to sign all forms...\033[0m" << std::endl;
    std::cout << "\033[32m\nJuan tries to sign ShrubberyCreationForms ...\033[0m" << std::endl;
    Juan.signForm(Shru1);
    Juan.signForm(Heilbronn);
    std::cout << "\033[32m\n\nJuan tries to sign RobotomyRequestForms ...\033[0m" << std::endl;
    Juan.signForm(Tito);
    Juan.signForm(Toto);
    std::cout << "\033[32m\n\nJuan tries to sign PresidentialPardonForms ...\033[0m" << std::endl;
    Juan.signForm(Def);
    Juan.signForm(Julion);
    std::cout << "\033[31mIncrementing Juan's grade ...\n\033[0m" << std::endl;
    Juan.incrementGrade();
    std::cout << Juan;
    Juan.signForm(Def);
    Juan.signForm(Julion);
    
    std::cout << "\n\033[33m--*--*-- EXECUTION TEST --*--*--\n" << "\033[0m" << std::endl;

    std::cout << "Creating Bureaucrat Julio grade 30..." << std::endl;
    Bureaucrat Julio("Julio", 30);
    std::cout << "\033[32m\nBureaucrat Julio tries to execute all forms...\033[0m" << std::endl;
    std::cout << "\033[32m\nJulio tries to execute ShrubberyCreationForms ...\033[0m" << std::endl;
    Shru1.execute(Julio);
    Heilbronn.execute(Julio);
    std::cout << "\033[32m\n\nJulio tries to execute RobotomyRequestForms ...\033[0m" << std::endl;
    Tito.execute(Julio);
    Toto.execute(Julio);
    std::cout << "\033[31mCalling Julio's boss Sisi ...\n\033[0m" << std::endl;
    Bureaucrat Sisi("Sisi", 5);
    Def.execute(Sisi);
    Julion.execute(Sisi);
    std::cout << "\033[32m\n\nJulio tries to execute PresidentialPardonForms ...\033[0m" << std::endl;
    try 
    {
        Def.execute(Julio);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught while Julio tries to execute Def: " 
                  << e.what() << std::endl;
    }
}