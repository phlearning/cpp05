/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:13:20 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 16:42:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <time.h>
#include <cstdlib>

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("None") {
    if (SHOWMSG) {
        std::cout << COLOR("RobotomyRequestForm: Default constructor called.", GREEN) << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {
    if (SHOWMSG) {
        std::cout << COLOR("RobotomyRequestForm copy constructor called: ", GREEN) << std::endl;
    }
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (SHOWMSG) {
        std::cout << COLOR("RobotomyRequestForm copy assignment operator called: ", GREEN) << std::endl;
    }
    this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    if (SHOWMSG) {
        std::cout << COLOR("RobotomyRequestForm destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {

    if (SHOWMSG) {
        std::cout << COLOR("RobotomyRequestForm constructor with target called: ", GREEN) << target << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void RobotomyRequestForm::executeForm(void) const {
    std::cout << "Drilling noises: bzzzzzzzz... ";
    srand(time(NULL)); // to initialize a random seed for rand based on each execution time;

    if (rand() % 2 == 0) {
        std::cout << COLOR(this->_target, CYAN) << " has been robotimized successfully." << std::endl;
    } else {
        std::cout << COLOR(this->_target, CYAN) << " has failed the robotomy." << std::endl;
    }
}