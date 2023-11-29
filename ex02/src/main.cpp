/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 15:17:37 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

void attemptSignForm(void) {
    printMsg(__func__, '=', WIDTH, BOLDWHITE);
    try {
        Bureaucrat pTester1("Prisoner1", 26);
        Bureaucrat pTester2("Prisoner2", 25);
        PresidentialPardonForm p("target");
        std::cout << p << std::endl;
        pTester1.signForm(p);
        std::cout << p << std::endl;
        pTester2.signForm(p);
        std::cout << p << std::endl;
        std::cout << std::endl;

        Bureaucrat rTester1("Tester1", 73);
        Bureaucrat rTester2("Tester2", 72);
        RobotomyRequestForm r("target");
        std::cout << r << std::endl;
        rTester1.signForm(r);
        std::cout << r << std::endl;
        rTester2.signForm(r);
        std::cout << r << std::endl;
        std::cout << std::endl;

        Bureaucrat sTester1("Tester1", 146);
        Bureaucrat sTester2("Tester2", 145);
        ShrubberyCreationForm s("target");
        std::cout << s << std::endl;
        sTester1.signForm(s);
        std::cout << s << std::endl;
        sTester2.signForm(s);
        std::cout << s << std::endl;

        std::cout << std::endl;


    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", YELLOW) << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void attemptExecuteForm() {
    printMsg(__func__, '=', WIDTH, BOLDWHITE);
    try {
        Bureaucrat pTester1("Tester1", 25);
        Bureaucrat pTester2("Tester2", 5);
        PresidentialPardonForm p("target");
        pTester2.signForm(p);
        pTester1.executeForm(p);
        pTester2.executeForm(p);
        std::cout << std::endl;

        Bureaucrat sTester1("Tester1", 145);
        Bureaucrat sTester2("Tester2", 137);
        ShrubberyCreationForm s("target");
        sTester2.signForm(s);
        sTester1.executeForm(s);
        pTester2.executeForm(s);
        std::cout << std::endl;

        Bureaucrat rTester1("Tester1", 72);
        Bureaucrat rTester2("Tester2", 45);
        RobotomyRequestForm r("target");
        rTester2.signForm(r);
        rTester1.executeForm(r);
        rTester2.executeForm(r);
        std::cout << std::endl;


    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", YELLOW) << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    // attemptSignForm();
    // attemptExecuteForm();

    printMsg("Main", '=', WIDTH, BOLDWHITE);
    try {
        PresidentialPardonForm test("target");
        std::cout << test << std::endl;
        Bureaucrat bureaucrat("test", 25);
        bureaucrat.signForm(test);
        test.execute(bureaucrat);
        bureaucrat.executeForm(test);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", YELLOW) << e.what() << std::endl;
    }
    
    return (0);
}
