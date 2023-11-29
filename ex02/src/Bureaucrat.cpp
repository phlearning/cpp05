/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:12:52 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 14:58:44 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                                MY EXCEPTIONS                               */
/* -------------------------------------------------------------------------- */

const char *Bureaucrat::GradeTooHigh::what() const throw() {
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLow::what() const throw() {
    return ("Grade is too low!");
}

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

// In private because no grade set;
Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(0) {
    if (SHOWMSG) {
        std::cout << COLOR("Bureaucrat: Default constructor called.", GREEN) << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    if (SHOWMSG) {
        std::cout << COLOR("Bureaucrat copy constructor called: ", GREEN) << this->_name << ", " << this->_grade << std::endl;
    }
}

// in private because of the const _name that cannot be assigned only initialized.
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Bureaucrat copy assignment operator called: ", GREEN) << other._name << ", " << other._grade << std::endl;
    }
    this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Bureaucrat destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

    whichException(grade);
    this->_grade = grade;
    if (SHOWMSG) {
        std::cout << COLOR("Bureaucrat constructor with name and grade called: ", GREEN) << name << ", " << grade << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

// Might need to add try and catch here
void Bureaucrat::incrementGrade(void) {
    whichException(this->_grade - 1);
    this->_grade--;
}
    // void decrementGrade(void);
void Bureaucrat::decrementGrade(void) {
    whichException(this->_grade + 1);
    this->_grade++;
}

void Bureaucrat::whichException(int grade) {
    if (grade < 1) {
        throw GradeTooHigh();
    } else if (grade > 150) {
        throw GradeTooLow();
    }
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        std::cout << COLOR(this->getName(), CYAN) << " signed " << COLOR(f.getName(), CYAN) << std::endl;
    } catch (std::exception &e) {
        std::cout << COLOR(this->getName(), CYAN) << " couldn't sign " << COLOR(f.getName(), CYAN) << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {

    if (form.getSigned() && getGrade() <= form.getGradeRequiredToExecute()) {
        std::cout << COLOR(getName(), CYAN) << " executed " << COLOR(form.getName(), CYAN) << std::endl;
    }
    form.execute(*this);
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat) {
    output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (output);
}