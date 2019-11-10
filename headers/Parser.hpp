/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:25:57 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/10 19:04:01 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "Exept.hpp"
# include <iostream> 
# include <stack>
# include <fstream>

class Parser
{

private:

    std::stack<std::string> _strStack;
    bool    _is_ValidLine;
    bool    _is_exit;

public:
    
    Parser();
    Parser(Parser const &);
    ~Parser();

    Parser& operator=(Parser const &);

    void    read_terminal();
    void    read_file(char *file);
};

#endif