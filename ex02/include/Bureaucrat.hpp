/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:01:05 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 13:43:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

#ifndef SHOWMSG
#define SHOWMSG 1
#endif

#ifndef MYCOLORS
#define MYCOLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */


#define MSG_SEP "============================"
#define MSG_SEP2 "============="
#define COLOR(text, color) color << text << RESET
#define MY_SEP() std::cout << COLOR(MSG_SEP, BOLDBLACK) << std::endl
#define MY_SEP2(msg) std::cout << COLOR(MSG_SEP2, BOLDWHITE) << " " << msg << " " << COLOR(MSG_SEP2, BOLDWHITE) << std::endl


#endif

class AForm;

class Bureaucrat {
    
public:
    // Orthodox canonical class form
    ~Bureaucrat(void);
    Bureaucrat(const Bureaucrat &src);

    // My constructors
    Bureaucrat(std::string name, int grade);

    // Member functions
    std::string getName(void) const; // Getters
    int getGrade(void) const; // Getters
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm &f);

    // My exceptions
    class GradeTooHigh : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLow : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    const std::string _name;
    int _grade;
    
    Bureaucrat(void);
    Bureaucrat &operator=(const Bureaucrat &other);// to put into private scope

    void whichException(int grade);
};

    // Operator overload
std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif