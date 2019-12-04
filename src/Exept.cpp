/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exept.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:19:03 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/04 18:42:50 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Exept.hpp"

const char * Ex_BadParams::what() const throw()
{
    return "\033[0;31mGiven bad parameters\033[0m";
}

const char * Ex_BadFile::what() const throw()
{
    return "\033[0;31mBad file given\033[0m";
}

const char * Ex_LexError::what() const throw()
{
    return "\033[0;31mLexical error\033[0m";
}

const char * Ex_BadComand::what() const throw()
{
    return "\033[0;31mAn instruction is unknown\033[0m";
}

const char * Ex_Overflow::what() const throw()
{
    return "\033[0;31mOvererflow exception\033[0m";
}

const char * Ex_Underflow::what() const throw()
{
    return "\033[0;31mUnderflow exception\033[0m";
}

const char * Ex_PopEmpty::what() const throw()
{
    return "\033[0;31mCan't pop command, stack is empty\033[0m";
}

const char * Ex_Empty::what() const throw()
{
    return "\033[0;31mStack is empty\033[0m";
}

const char * Ex_DivByZero::what() const throw()
{
    return "\033[0;31mDivision by 0 error\033[0m";
}

const char * Ex_ModByZero::what() const throw()
{
    return "\033[0;31mModul by 0 error\033[0m";
}

const char * Ex_NoExit::what() const throw()
{
    return "\033[0;31mThe program doesn’t have an exit instruction!!\033[0m";
}

const char * Ex_BadAssert::what() const throw()
{
    return "\033[0;31mAn assert instruction is not true\033[0m";
}

const char * Ex_NotEnough::what() const throw()
{
    return "\033[0;31mNot enought parameters for operation\033[0m";
}

const char * Ex_Print::what() const throw()
{
    return "\033[0;31mCan't print symbol\033[0m";
}