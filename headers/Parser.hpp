/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:25:57 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/18 17:01:48 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "Exept.hpp"
# include "Lexer.hpp"
# include <stack>
# include <fstream>

class Parser
{

private:

    std::stack<std::string> _strStack;

public:
    
    Parser();
    Parser(Parser const &);
    ~Parser();

    Parser& operator=(Parser const &);

    void    read_instruct();
    void    read_instruct(char *file);
    
};

#endif