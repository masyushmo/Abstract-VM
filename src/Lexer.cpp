/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:54 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/02 16:35:50 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Lexer.hpp"

Lexer::Lexer() : _exit(EXIT), _comment(COMMENT), _command(COMMAND), _command_num(COMMAND_NUN), _allow_com(GOOD_COM)
{ }

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

bool Lexer::check_exit(std::string line)
{
    if (std::regex_match(line, _exit))
        return true;
    return false;
}

bool Lexer::check_reg(std::string line)
{
    try
    {
        if (!(std::regex_match(line, _allow_com)))
            throw Ex_BadComand();
        if (std::regex_match(line, _command) || std::regex_match(line, _command_num))
            return true;
        throw Ex_LexError();
    }
    catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    return false;
}

std::regex const Lexer::getCommand() const { return _command; }

std::regex const Lexer::getCommandNum() const { return _command_num; }


