/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/11 18:12:35 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

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
}