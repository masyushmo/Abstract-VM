/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:51 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/02 18:59:35 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <regex>
# include <iostream>
# include <string>
# include "Exept.hpp"

# define EXIT "(?:[\\s]*(exit)([\\s]+(;.*))?)"
# define COMMENT "(?:[\\s]*(;.*))"
# define COMMAND "(?:[\\s]*(pop|dump|add|sub|mul|div|mod|print)([\\s]+(;.*))?)"
# define COMMAND_NUN "(?:[\\s]*(push|assert)[\\s]+(int8|int16|int32|float|double)([(]([-]?([\\d]+|[\\d]+.[\\d]+))[)])([\\s]+(;.*))?))"
# define GOOD_COM "(?:(.*)?(pop|dump|add|sub|mul|div|mod|print|push|assert|exit|;;)(.*)?)"

class Lexer
{

private:
    std::regex const    _exit;
    std::regex const    _comment;
    std::regex const    _command;
    std::regex const    _command_num;
    std::regex const    _allow_com;

public:

    Lexer();
    Lexer(Lexer const &);
    ~Lexer();

    Lexer&   operator=(Lexer const &);
    std::regex const getCommand() const;
    std::regex const getCommandNum() const;
    bool     check_skip(std::string line);
    bool     check_exit(std::string line);
    bool     check_reg(std::string line);
};

#endif