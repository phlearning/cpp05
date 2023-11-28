/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:02:25 by pvong             #+#    #+#             */
/*   Updated: 2023/11/28 16:14:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialRequestForm : public AForm {

public: 
    PresidentialRequestForm(void);
    virtual ~PresidentialRequestForm(void);
    PresidentialRequestForm(const PresidentialRequestForm &src);
    PresidentialRequestForm &operator=(const PresidentialRequestForm &other);

    PresidentialRequestForm(const std::string target);
    
    virtual void execute(Bureaucrat const &executor);

private:
    std::string _target;
}

#endif