/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:54:49 by pvong             #+#    #+#             */
/*   Updated: 2023/11/29 14:02:03 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm {

public:
    ShrubberyCreationForm(void);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    ShrubberyCreationForm(const std::string target);


private:
    std::string _target;
    void executeForm(void) const;
};


#endif