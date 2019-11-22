/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exept.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:19:03 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 13:55:41 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Exept.hpp"

const char * Ex_BadParams::what() const throw()
{
    return "\033[0;31mGiven bad parameters\033[0;37m";
}

const char * Ex_BadFile::what() const throw()
{
    return "\033[0;31mBad file given\033[0;37m";
}

const char * Ex_BadComand::what() const throw()
{
    return "\033[0;31mAn instruction is unknown\033[0;37m";
}

const char * Ex_Overflow::what() const throw()
{
    return "\033[0;31mOvererflow exception\033[0;37m";
}

const char * Ex_Underflow::what() const throw()
{
    return "\033[0;31mUnderflow exception\033[0;37m";
}

const char * Ex_PopEmpty::what() const throw()
{
    return "\033[0;31mBad pop command, stack is empty\033[0;37m";
}

const char * Ex_DivByZero::what() const throw()
{
    return "\033[0;31mDivision/modulo by 0 error\033[0;37m";
}

const char * Ex_NoExit::what() const throw()
{
    return "\033[0;31mThe program doesn’t have an exit instruction!!\033[0;37m";
}

const char * Ex_BadAssert::what() const throw()
{
    return "\033[0;31mBad assert command\033[0;37m";
}

const char * Ex_NotEnough::what() const throw()
{
    return "\033[0;31mNot enought parameters for operation\033[0;37m";
}