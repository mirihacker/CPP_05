/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/09/11 15:32:37 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    std::cout << "\n--*--*-- BUREAUCRAT CREATION TEST --*--*--" << std::endl;

    try
    {
        std::cout << "Creating Bureaucrat Juan grade 5..." << std::endl;
        Bureaucrat Juan("Juan", 5);
        std::cout << Juan
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}