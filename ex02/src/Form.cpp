/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:29:50 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 13:43:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                MY EXCEPTIONS                               */
/* -------------------------------------------------------------------------- */

const char *AForm::GradeTooHigh::what() const throw() {
    return ("Grade is too high!");
}

const char *AForm::GradeTooLow::what() const throw() {
    return ("Grade is too low!");
}

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

// Private
AForm::AForm(void) : _signed(false), _name("Unnamed form"), _gradeRequiredToSign(0), _gradeRequiredToExecute(0) {
    if (SHOWMSG) {
        std::cout << COLOR("AForm: Default constructor called.", GREEN) << std::endl;
    }
}

AForm::AForm(const AForm &src) : _signed(src._signed), _name(src._name), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute) {
    if (SHOWMSG) {
        std::cout << COLOR("AForm copy constructor called: ", GREEN) << this->_name << std::endl;
    }
}

// Private
AForm &AForm::operator=(const AForm &other) {
    if (SHOWMSG) {
        std::cout << COLOR("AForm copy assignment operator called: ", GREEN) << std::endl;
    }
    this->_signed = other._signed;
    return (*this);
}

AForm::~AForm(void) {
    if (SHOWMSG) {
        std::cout << COLOR("AForm destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _signed(false), _name(name), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute) {
    whichException(gradeToSign, "Grade required to sign");
    whichException(gradeToExecute, "Grade required to execute");
    if (SHOWMSG) {
        std::cout << COLOR("AForm constructor called: ", GREEN) << name << ", " << gradeToSign << ", " << gradeToExecute << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_gradeRequiredToSign) {
        this->_signed = true;
    } else {
        throw GradeTooLow();
    }
}

bool AForm::getSigned(void) const {
    return (this->_signed);
}

std::string AForm::getName(void) const {
    return (this->_name);
}

int AForm::getGradeRequiredToSign(void) const {
    return (this->_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute(void) const {
    return (this->_gradeRequiredToExecute);
}

void AForm::whichException(int grade, std::string whichGrade) {
    if (grade < 1) {
        std::cout << "AForm: " << whichGrade << ": ";
        throw GradeTooHigh();
    } else if (grade > 150) {
        std::cout << "AForm: " << whichGrade << ": ";
        throw GradeTooLow();
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &output, const AForm &form) {
    output << "AForm " << form.getName() << ": signed(" << (form.getSigned() ? "Yes" : "No") << "), gradeToSign(" << form.getGradeRequiredToSign() 
    << "), gradeToExecute("
    << form.getGradeRequiredToExecute() << ").";
    return output;
}