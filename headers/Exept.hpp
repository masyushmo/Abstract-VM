/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exept.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:00:20 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/02 15:48:24 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEPT_HPP
# define EXEPT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Ex_BadParams : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_BadFile : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_LexError : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_BadComand : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_Overflow : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_Underflow : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_PopEmpty : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_Empty : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_DivByZero : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_ModByZero : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_NoExit : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_BadAssert : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_NotEnough : public std::exception
{
public:
    const char * what() const throw();
};

class Ex_Print : public std::exception
{
public:
    const char * what() const throw();
};

#endif