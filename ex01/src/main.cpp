/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/12 16:35:36 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

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
    try
    {
        std::cout << "Creating Form 'Residence permit' with signed grade 3 ..." << std::endl;
        Form Residence("Residence permit", 3, 1);
        std::cout << Residence;
        std::cout << "\nCreating Form 'Working permit' with signed grade 0 ..." << std::endl;
        Form Working("Working permit", 0, 1);
        std::cout << Working;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n\033[33m--*--*-- SIGNING TEST --*--*--\n" << "\033[0m" << std::endl;

    std::cout << "\033[32mCreating Bureaucrat Julio grade 3 and Residence permit Form...\033[0m" << std::endl;
    Bureaucrat Julio("Julio", 3);
    Form Residence("Residence permit", 3, 1);
    Form Residence2 = Residence;
    std::cout << Residence << "\n" << std::endl;
    std::cout << "\033[32mJulio tries to sign Residence Permit ...\n\033[0m" << std::endl;
    Julio.signForm(Residence);
    std::cout << "\n" << Residence << "\n" << std::endl;
    std::cout << "\033[32mCreating New Residence permit Form...\033[0m" << std::endl;
    std::cout << Residence2 << "\n" << std::endl;
    std::cout << "\033[31mDecrementing Julio's grade ...\n\033[0m" << std::endl;
    Julio.decrementGrade();
    std::cout << Julio;
    Julio.signForm(Residence2);
    
}