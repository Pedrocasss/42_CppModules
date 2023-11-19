/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:28 by psoares-          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:29 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
    int index;
    Contact contacts[8];
public:
    Phonebook();
    ~Phonebook();
    void    addAll();
    void    printInfo(int i);
    void    printTable();
    bool	Verify_contact(int num);
};


#endif