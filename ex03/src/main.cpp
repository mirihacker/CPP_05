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

#include "../inc/Intern.hpp"
#include <iostream>

int main()
{
  Intern randomIntern;

  std::cout << "\n--*--*-- INTERN FORM CREATION TEST --*--*--\n" << std::endl;

  // Valid inputs with different cases
  AForm* form1 = randomIntern.makeForm("Shrubbery creation", "Home");
  AForm* form2 = randomIntern.makeForm("shrubbery Creation", "Garden");
  AForm* form3 = randomIntern.makeForm("ROBOTOMY REQUEST", "Bender");
  AForm* form4 = randomIntern.makeForm("Presidential PArdon ", "Licha");

  // Invalid input
  AForm* form5 = randomIntern.makeForm("non existent form", "nowhere");

  if (form1) std::cout << *form1 << std::endl;
  if (form2) std::cout << *form2 << std::endl;
  if (form3) std::cout << *form3 << std::endl;
  if (form4) std::cout << *form4 << std::endl;
  if (!form5) std::cout << "Form5 is NULL" << std::endl;

  delete form1;
  delete form2;
  delete form3;
  delete form4;
  delete form5;

  return (0);
}