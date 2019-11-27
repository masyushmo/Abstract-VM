/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/27 19:28:11 by mmasyush         ###   ########.fr       */
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

eOperandType    Parser::getType(std::string mtch) const
{
    if (mtch == "double")
        return (Double);
    else if (mtch == "float")
        return (Float);
    else if (mtch == "int8")
        return (Int8);
    else if (mtch == "int16")
        return (Int16);
    else
        return (Int32);
}

void    Parser::chose_op(std::string line)
{
    std::smatch match;
    eOperandType eOT;
    Lexer _lex;
    
    if (regex_match(line, match, _lex.getCommand()))
    {
        if (match[1] == "pop")
            _br.pop();
        else if (match[1] == "dump")
            _br.dump();
        else if (match[1] == "add")
            _br.add();
        else if (match[1] == "sub")
            _br.sub();
        else if (match[1] == "mul")
            _br.mul();
        else if (match[1] == "div")
            _br.div();
        else if (match[1] == "mod")
            _br.mod();
        else if (match[1] == "print")
            _br.print();    
    }
    else if (regex_match(line, match, _lex.getCommandNum()))
    {
        eOT = getType(match[2]);
        if (match[1] == "push")
            _br.push(_fac.createOperand(eOT, match[4]));
        else if (match[1] == "assert")
            _br.assert(_fac.createOperand(eOT, match[4]));
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
