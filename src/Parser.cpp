/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/12 19:18:51 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"

Parser::Parser() : _is_ValidLine(false), _is_exit(false) {}

Parser::Parser(Parser const &cpy)
{
    *this = cpy;
}

Parser& Parser::operator=(Parser const &)
{
    return *this;
}

Parser::~Parser() {}

void    Parser::read_instruct(char *file)
{
    std::ifstream ifs(file);
    if(!ifs)
        throw Ex_BadFile();
    
    std::string line;
    while (std::getline(ifs, line))
        _strStack.push(line);
    ifs.close();
}

void    Parser::read_instruct()
{
    std::string line;
        
    while (std::getline(std::cin, line))
        _strStack.push(line);
}
