/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exept.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:19:03 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/18 19:20:41 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Exept.hpp"

const char * Ex_BadParams::what() const throw()
{
    return "Given bad parameters";
}

const char * Ex_BadFile::what() const throw()
{
    return "Bad file given";
}

const char * Ex_BadLex::what() const throw()
{
    return "Lexical error";
}

const char * Ex_BadComand::what() const throw()
{
    return "No such commund";
}

const char * Ex_Overflow::what() const throw()
{
    return "Overerflow exception";
}

const char * Ex_Underflow::what() const throw()
{
    return "Underflow exception";
}

const char * Ex_PopEmpty::what() const throw()
{
    return "Bad pop command, stack is empty";
}

const char * Ex_DivByZero::what() const throw()
{
    return "Division by zero error";
}

const char * Ex_NoExit::what() const throw()
{
    return "Neded exit command";
}

const char * Ex_BadAssert::what() const throw()
{
    return "Bad assert command";
}

const char * Ex_NotEnough::what() const throw()
{
    return "Not enought parameters for operation";
}