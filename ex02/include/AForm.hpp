/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:18 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 16:40:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class AForm {
    
public:
    ~AForm(void);
    AForm(const AForm &src);
    
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    
    void beSigned(Bureaucrat &b)    ;

    bool getSigned(void) const;
    std::string getName(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHigh : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLow : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    bool _signed;
    const std::string _name;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;

    AForm(void);
    AForm &operator=(const AForm &other);

    void whichException(int grade, std::string whichGrade);

};

std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif