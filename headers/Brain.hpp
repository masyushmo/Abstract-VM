/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:59 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 19:34:15 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <stack>
# include "IOperand.hpp"
# include "Exept.hpp"

class Brain
{

private:

    std::stack<const IOperand *> _stacki;
	IOperand * _first;
	IOperand * _second;

public:

    Brain();
    Brain(Brain const &);
    ~Brain();

    Brain & operator=(Brain const &);
    void	_push(const IOperand* value);
    void	_assert(const IOperand* value);
	void	_pop();
	void	_dump();
	void	_add();
	void	_sub();
	void	_mul();
	void	_div();
	void	_mod();
	void	_print() const;
};


#endif