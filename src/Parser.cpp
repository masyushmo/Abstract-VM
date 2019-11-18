/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/18 17:38:37 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"

Parser::Parser() {}

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
    Lexer lex;
    if(!ifs)
        throw Ex_BadFile();
    
    std::string line;
    while (std::getline(ifs, line))
    {
        if (lex.check_skip(line))
            continue;
        else if (lex.check_reg(line))
            std::cout << "goood" << std::endl;
    }
    ifs.close();
}

void    Parser::read_instruct()
{
    std::string line;
    Lexer lex;
        
    while (std::getline(std::cin, line))
    {
        if (lex.check_skip(line))
            continue;
        else if (lex.check_reg(line))
            std::cout << "goood" << std::endl;
    }
}
