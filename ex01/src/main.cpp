/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/27 15:58:39 by pvong            ###   ########.fr       */
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

void attemptInvalidGrade0(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Bureaucrat bureaucrat("John", 0);
        std::cout << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", RED) << e.what() << std::endl;
    }
}

void attemptInvalidGrade151(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Bureaucrat bureaucrat("John", 151);
        std::cout << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", RED) << e.what() << std::endl;
    }
}

void attemptInvalidDecrement(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Bureaucrat bureaucrat("John", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", RED) << e.what() << std::endl;
    }
}

void attemptInvalidIncrement(void) {
    printMsg(__func__, '=', WIDTH, BOLDBLACK);
    try {
        Bureaucrat bureaucrat("John", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    } catch (std::exception &e) {
        std::cout << COLOR("Exception: ", RED) << e.what() << std::endl;
    }
}

int main() {
    // attemptInvalidGrade0();
    // attemptInvalidGrade151();
    // attemptInvalidDecrement();
    // attemptInvalidIncrement();
    Form("hello", 1, 2);

    return (0);
}
