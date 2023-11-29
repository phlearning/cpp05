/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 16:54:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iomanip>

#define WIDTH 40

void printMsg(const std::string &message, char separatorChar, int totalWidth, std::string color) {
    int messageWidth = message.length();
    int separatorWidth = (totalWidth - messageWidth) / 2;
    int leftSeparatorWidth = separatorWidth;
    int rightSeparatorWidth = separatorWidth + (totalWidth - messageWidth) % 2;

    std::cout << color << std::setw(leftSeparatorWidth) << std::setfill(separatorChar) << " "
              << message << " "
              << std::setw(rightSeparatorWidth) << std::setfill(separatorChar) << "" << RESET << std::endl;
}


int main() {
    AForm *ptr;
    AForm *ptr2;

    printMsg("Main", '=', WIDTH, BOLDWHITE);
    try {
        Intern myIntern;
        MY_SEP();
        ptr = myIntern.makeForm("RobotomyRequestForm", "target");
        Bureaucrat tester("tester", 1);
        ptr2 = myIntern.makeForm("PresidentialPardonForm", "target");
        MY_SEP();
        tester.signForm(*ptr2);
        tester.signForm(*ptr);
        tester.executeForm(*ptr);
        tester.executeForm(*ptr2);
        MY_SEP();
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", YELLOW) << e.what() << std::endl;
    }
    delete ptr;
    delete ptr2;    
    return (0);
}
