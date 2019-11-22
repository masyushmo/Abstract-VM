/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:51 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 14:18:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <regex>
# include <iostream>
# include <string>
# include "Exept.hpp"
# include "Parser.hpp"

# define EXIT "([\\s]*(exit)([\\s]*(;.*))?)"
# define COMMENT "([\\s]*(;.*))"
# define COMMAND "([\\s]*(pop|dump|add|sub|mul|div|mod|print)([\\s]*(;.*))?)"
# define COMMAND_NUN "([\\s]*(push|assert)[\\s]+(int8|int16|int32|float|double))([(](([-]?|[+]?)([\\d]+|[\\d]+.[\\d]+))[)])"  

class Lexer
{

private:

    bool                _is_ValidLine;
    std::regex const    _exit;
    std::regex const    _stop;
    std::regex const    _comment;
    std::regex const    _command;
    std::regex const    _command_num;

public:

    Lexer();
    Lexer(Lexer const &);
    ~Lexer();

    Lexer&   operator=(Lexer const &);
    bool     check_skip(std::string line);
    bool     check_exit(std::string line);
    bool     check_reg(std::string line);
};

#endif