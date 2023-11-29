/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:38:04 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 15:43:08 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PresidentialPardonForm.hpp"


/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("None") {
    if (SHOWMSG) {
        std::cout << COLOR("PresidentialPardonForm: Default constructor called.", GREEN) << std::endl;
    }
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {
    if (SHOWMSG) {
        std::cout << COLOR("PresidentialPardonForm copy constructor called: ", GREEN) << std::endl;
    }
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (SHOWMSG) {
        std::cout << COLOR("PresidentialPardonForm copy assignment operator called: ", GREEN) << std::endl;
    }
    this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    if (SHOWMSG) {
        std::cout << COLOR("PresidentialPardonForm destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {

    if (SHOWMSG) {
        std::cout << COLOR("PresidentialPardonForm constructor with target called: ", GREEN) << target << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void PresidentialPardonForm::executeForm(void) const {
    std::cout << COLOR(this->_target, CYAN) << " has been pardoned by " << COLOR("Zaphod Beeblebrox", BOLDWHITE) << std::endl;
}