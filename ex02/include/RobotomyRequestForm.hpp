/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:10:03 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 16:14:14 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {

public: 
    RobotomyRequestForm(void);
    virtual ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    RobotomyRequestForm(const std::string target);
    
    virtual void execute(Bureaucrat const &executor);

private:
    std::string _target;
}

#endif