/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:25:57 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/02 16:14:25 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "Exept.hpp"
# include "Lexer.hpp"
# include "Brain.hpp"
# include "Lexer.hpp"
# include "IOperand.hpp"
# include <stack>
# include <fstream>
# include <map>

class Parser
{

private:

    bool _is_exit;
    Factory _fac;
    Brain _br;
    Lexer _lex;

public:
    
    Parser();
    Parser(Parser const &);
    ~Parser();

    Parser& operator=(Parser const &);

    void    read_terminal();
    void    read_file(char *file);
    void    chose_op(std::string line);
    eOperandType    getType(std::string mtch) const;
    
};

#endif