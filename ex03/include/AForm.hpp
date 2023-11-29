/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:18 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 16:31:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {

public:
    virtual ~AForm(void);
    AForm(const AForm &src);

    AForm(std::string name, int gradeToSign, int gradeToExecute);

    void beSigned(Bureaucrat &b);

    bool getSigned(void) const;
    std::string getName(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;

    virtual void execute(Bureaucrat const &executor) const;

    class GradeTooHigh : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLow : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSigned : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    bool _signed;
    const std::string _name;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;
    virtual void executeForm(void) const = 0;

    AForm(void);
    AForm &operator=(const AForm &other);

    void whichException(int grade, std::string whichGrade);
};

std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif