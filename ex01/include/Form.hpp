/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:18 by pvong             #+#    #+#             */
/*   Updated: 2023/11/27 16:02:03 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form {
    
public:
    ~Form(void);
    Form(const Form &src);
    
    Form(std::string name, int gradeToSign, int gradeToExecute);
    
    void beSigned(Bureaucrat b);

    bool getSigned(void) const;
    std::string getName(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;

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

    Form(void);
    Form &operator=(const Form &other);

};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif