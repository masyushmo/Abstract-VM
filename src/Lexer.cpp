/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:54 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/18 17:17:33 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Lexer.hpp"

Lexer::Lexer() : _exit(EXIT), _comment(COMMENT), _command(COMMAND), _command_num(COMMAND_NUN)
{
    _is_ValidLine = false;
    _is_exit = false;
}

Lexer::Lexer(Lexer const &cpy)
{
    *this = cpy;
}

Lexer& Lexer::operator=(Lexer const &)
{
    return *this;
}

Lexer::~Lexer() {}

bool Lexer::check_skip(std::string line)
{
    if ((std::all_of(line.begin(), line.end(), isspace)) || line.empty() || \
        (std::regex_match(line, _comment)))
        return true;
    return false;
}

bool Lexer::check_reg(std::string line)
{
    if (std::regex_match(line, _exit))
    {
        _is_exit = true;
        return true;
    }
    else if (std::regex_match(line, _command) || std::regex_match(line, _command_num))
        return true;
    else if (_is_exit == false)
        throw Ex_NoExit();
    else
        throw Ex_BadLex();
    return false;
}


