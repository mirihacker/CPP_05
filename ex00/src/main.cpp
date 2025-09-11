/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/11 17:46:25 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    std::cout << "\n--*--*-- BUREAUCRAT CREATION TEST --*--*--\n" << std::endl;

    try
    {
        std::cout << "Creating Bureaucrat Juan grade 5..." << std::endl;
        Bureaucrat Juan("Juan", 5);
        std::cout << Juan;
        while (Juan.getGrade() > 1)
        {
            Juan.incrementGrade();
            std::cout << Juan;
        }
        std::cout << "\nIncrementing over the limit!!!...\n" << std::endl;
        Juan.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cerr << e.what();
    }

    std::cout << "\n--*--*-- INVALID BUREAUCRAT TEST --*--*--\n" << std::endl;

    try
    {
        std::cout << "Creating Bureaucrat Jose grade 151 (should throw exception)" << std::endl;
        Bureaucrat Jose("Jose", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << "\nException caught: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Creating Bureaucrat Juanjo grade 0 (should throw exception)" << std::endl;
        Bureaucrat Juanjo("Juanjo", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << "\nException caught: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }   
}