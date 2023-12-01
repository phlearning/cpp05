/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:09 by pvong             #+#    #+#             */
/*   Updated: 2023/12/01 11:43:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

Intern::Intern(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Intern: Default constructor called.", GREEN) << std::endl;
    }
}

Intern::Intern(const Intern &src) {
    (void) src;
    if (SHOWMSG) {
        std::cout << COLOR("Intern copy constructor called: ", GREEN) << std::endl;
    }
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    if (SHOWMSG) {
        std::cout << COLOR("Intern copy assignment operator called: ", GREEN) << std::endl;
    }
    return (*this);
}

Intern::~Intern(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Intern destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

AForm *Intern::makeForm(const std::string name, std::string target) {
    
    std::string myForms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    /* With typedef */
    // typedef AForm* (Intern::*FunctionPointers)(const std::string);

    // FunctionPointers makeDifferentForms[] = {
    //     &Intern::_makeShrubbery,
    //     &Intern::_makeRobotomy,
    //     &Intern::_makePresidential
    // };

    /* Without typedef */
    AForm* (Intern::*makeDifferentForms[])(const std::string) = {
        &Intern::_makeShrubbery,
        &Intern::_makeRobotomy,
        &Intern::_makePresidential
    };
    
    for (int i = 0; i < 3; i++) {
        if (myForms[i] == name) {
            std::cout << COLOR("Intern", CYAN) << " creates " << COLOR(name, CYAN) << std::endl;
            return (this->*makeDifferentForms[i])(target);
        }
    }
    std::cout << COLOR("Error:", RED) << " Unknown form. Possible choice: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm." << std::endl;
    exit(0);
    // return (NULL);
}

AForm *Intern::_makeShrubbery(const std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::_makeRobotomy(const std::string target) {
    return (new RobotomyRequestForm(target));
}
AForm *Intern::_makePresidential(const std::string target) {
    return (new PresidentialPardonForm(target));
}