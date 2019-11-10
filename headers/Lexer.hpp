/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:26:51 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/10 14:51:04 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

class Lexer
{

private:

public:
    Lexer();
    Lexer(Lexer const &);
    ~Lexer();

    Lexer& operator=(Lexer const &);
};

#endif