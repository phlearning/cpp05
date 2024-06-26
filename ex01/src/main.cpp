/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 13:12:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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

void attemptInvalidForm1(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Form form("hello", 0, 50);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void attemptInvalidForm2(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Form form("hello", 50, 0);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void attemptInvalidGradeRequired(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Form form("hello", 50, 50);
        std::cout << form << std::endl;
        Bureaucrat bureaucrat("test", 51);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    attemptInvalidForm1();
    attemptInvalidForm2();
    attemptInvalidGradeRequired();
    printMsg("Main", '=', WIDTH, BOLDWHITE);
    try {
        Form form("hello", 50, 50);
        std::cout << form << std::endl;
        Bureaucrat bureaucrat("test", 49);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
}
