/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:29:50 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 11:41:20 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                MY EXCEPTIONS                               */
/* -------------------------------------------------------------------------- */

const char *Form::GradeTooHigh::what() const throw() {
    return ("Grade is too high!");
}

const char *Form::GradeTooLow::what() const throw() {
    return ("Grade is too low!");
}

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

// Private
Form::Form(void) : _signed(false), _name("Unnamed form"), _gradeRequiredToSign(0), _gradeRequiredToExecute(0) {
    if (SHOWMSG) {
        std::cout << COLOR("Form: Default constructor called.", GREEN) << std::endl;
    }
}

Form::Form(const Form &src) : _signed(src._signed), _name(src._name), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute) {
    if (SHOWMSG) {
        std::cout << COLOR("Form copy constructor called: ", GREEN) << this->_name << std::endl;
    }
}

// Private
Form &Form::operator=(const Form &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Form copy assignment operator called: ", GREEN) << std::endl;
    }
    this->_signed = other._signed;
    return (*this);
}

Form::~Form(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Form destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _signed(false), _name(name), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute) {
    whichException(gradeToSign, "Grade required to sign");
    whichException(gradeToExecute, "Grade required to execute");
    if (SHOWMSG) {
        std::cout << COLOR("Form constructor called: ", GREEN) << name << ", " << gradeToSign << ", " << gradeToExecute << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_gradeRequiredToSign) {
        this->_signed = true;
    } else {
        throw GradeTooLow();
    }
}

bool Form::getSigned(void) const {
    return (this->_signed);
}

std::string Form::getName(void) const {
    return (this->_name);
}

int Form::getGradeRequiredToSign(void) const {
    return (this->_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute(void) const {
    return (this->_gradeRequiredToExecute);
}

void Form::whichException(int grade, std::string whichGrade) {
    if (grade < 1) {
        std::cout << "Form: " << whichGrade << ": ";
        throw GradeTooHigh();
    } else if (grade > 150) {
        std::cout << "Form: " << whichGrade << ": ";
        throw GradeTooLow();
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &output, const Form &form) {
    output << "Form " << form.getName() << ": signed(" << (form.getSigned() ? "Yes" : "No") << "), gradeToSign(" << form.getGradeRequiredToSign() 
    << "), gradeToExecute("
    << form.getGradeRequiredToExecute() << ").";
    return output;
}