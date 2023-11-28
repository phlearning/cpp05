/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 16:41:49 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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

    printMsg("Main", '=', WIDTH, BOLDWHITE);
    try {
        ShrubberyCreationForm test("target");
        std::cout << test << std::endl;
        Bureaucrat bureaucrat("test", 49);
        bureaucrat.signForm(test);
        test.execute(bureaucrat);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
}
