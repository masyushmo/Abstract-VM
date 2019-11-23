/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:25:57 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/23 16:14:18 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "Exept.hpp"
# include "Lexer.hpp"
# include "Brain.hpp"
# include <stack>
# include <fstream>

class Parser
{

private:

    bool _is_exit;

public:
    
    Parser();
    Parser(Parser const &);
    ~Parser();

    Parser& operator=(Parser const &);

    void    set_exit(bool);
    void    read_terminal();
    void    read_file(char *file);
    void    chose_op(std::string line);
    
};

#endif