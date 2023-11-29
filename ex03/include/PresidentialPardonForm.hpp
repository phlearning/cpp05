/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:02:25 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 15:41:21 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {

public: 
    PresidentialPardonForm(void);
    virtual ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    PresidentialPardonForm(const std::string target);

private:
    std::string _target;
    void executeForm(void) const;
};

#endif