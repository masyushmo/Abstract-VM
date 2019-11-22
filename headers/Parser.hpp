/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:25:57 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 13:47:42 by mmasyush         ###   ########.fr       */
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
    bool _is_exit;

public:
    
    Parser();
    Parser(Parser const &);
    ~Parser();

    Parser& operator=(Parser const &);

    void    set_exit(bool);
    void    read_instruct();
    void    read_instruct(char *file);
    
};

#endif