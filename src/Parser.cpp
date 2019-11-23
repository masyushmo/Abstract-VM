/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/23 16:35:09 by mmasyush         ###   ########.fr       */
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

void    Parser::set_exit(bool i)
{
    this->_is_exit = i;
}

void    Parser::chose_op(std::string line)
{
    std::smatch match;
    Lexer lex;
    Brain br;
    
    if (regex_search(line, match, lex.getCommand()))
    {
        if (match[1] == "pop")
            br.pop();
        else if (match[1] == "dump")
            br.dump();
        else if (match[1] == "add")
            br.add();
        else if (match[1] == "sub")
            br.sub();
        else if (match[1] == "mul")
            br.mul();
        else if (match[1] == "div")
            br.div();
        else if (match[1] == "mod")
            br.mod();
        else if (match[1] == "print")
            br.print();    
    }
    else if (regex_search(line, match, lex.getCommandNum()))
    {
        if (match[1] == "push")
            br.push();
        else if (match[1] == "dump")
            br.dump();
    }
}

void    Parser::read_file(char *file)
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
            chose_op(line);
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

void    Parser::read_terminal()
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
            chose_op(line);
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
