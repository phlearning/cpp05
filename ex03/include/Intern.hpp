/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:22:52 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 16:31:53 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <string>

class Intern {

public:
    Intern(void);
    ~Intern(void);
    
    AForm *makeForm(const std::string nameOfForm, const std::string target);

private:
    AForm *_makeShrubbery(const std::string target);
    AForm *_makeRobotomy(const std::string target);
    AForm *_makePresidential(const std::string target);

    Intern(const Intern &src);
    Intern &operator=(const Intern &other);
};

#endif