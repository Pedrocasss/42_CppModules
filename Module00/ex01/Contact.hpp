/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:34 by psoares-          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:35 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

class Contact{
    private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

    public:
    void    setFirst(std::string _firstname);
    void    setLast(std::string _lastname);
    void    setNickname(std::string _nickname);
    void    setPhonenumber(std::string _phonenumber);
    void    setDarkestsecret(std::string _darkestsecret);
    std::string    returnFirst();
    std::string    returnLast();
    std::string    returnNickname();
    std::string    returnPhonenumber();
    std::string    returnDarkestsecret();
};
#endif