/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:03:37 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 16:45:05 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

// In private because no grade set;
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("None") {
    if (SHOWMSG) {
        std::cout << COLOR("ShrubberyCreationForm: Default constructor called.", GREEN) << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {
    if (SHOWMSG) {
        std::cout << COLOR("ShrubberyCreationForm copy constructor called: ", GREEN) << std::endl;
    }
}

// in private because of the const _name that cannot be assigned only initialized.
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (SHOWMSG) {
        std::cout << COLOR("ShrubberyCreationForm copy assignment operator called: ", GREEN) << std::endl;
    }
    this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    if (SHOWMSG) {
        std::cout << COLOR("ShrubberyCreationForm destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {

    if (SHOWMSG) {
        std::cout << COLOR("ShrubberyCreationForm constructor with target called: ", GREEN) << target << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getSigned()) {
        throw AForm::GradeTooLow();
    }
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw AForm::GradeTooLow();
    }
    
    std::ofstream outFile(this->_target + "_shrubbery");
    if (outFile.is_open()) {
        outFile << "ASCII trees for " << this->_target << " have been created";

        outFile.close();
    } else {
        throw (std::runtime_error("Error: Unable to create ASCII trees"));
    }
}