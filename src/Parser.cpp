/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 19:29:41 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"

Parser::Parser() {}

Parser::Parser(Parser const &cpy)
{
    *this = cpy;
}

Parser& Parser::operator=(Parser const & src)
{
    return *this;
}

Parser::~Parser() {}

void    Parser::set_exit(bool i)
{
    this->_is_exit = i;
}

// void    Parser::chose_op()
// {
    
// }

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
        else if (lex.check_exit(line))
            _is_exit = true;
        else if (lex.check_reg(line))
            std::cout << "goood" << std::endl;
    }
    ifs.close();
    try
    {
        if (_is_exit == false)
            throw Ex_NoExit();
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    Parser::read_instruct()
{
    std::string line;
    Lexer lex;
    
    while (std::getline(std::cin, line) && line != ";;")
    {
        if (lex.check_skip(line))
            continue;
        else if (lex.check_exit(line))
            _is_exit = true;
        else if (lex.check_reg(line))
            std::cout << "goood" << std::endl;
    }
    try
    {
        if (_is_exit == false)
            throw Ex_NoExit();
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
