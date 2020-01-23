/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:59 by mmasyush          #+#    #+#             */
/*   Updated: 2020/01/23 13:19:26 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <stack>
# include "IOperand.hpp"
# include "FactoryMethod.hpp"
# include "Exept.hpp"

class Brain
{

private:

    std::stack<const IOperand *> _stacki;
	const IOperand * _first;
	const IOperand * _second;

public:

    Brain();
    Brain(Brain const &);
    ~Brain();

    Brain & operator=(Brain const &);
	void	pop();
	void	push(const IOperand * op);
    void	assert(const IOperand * op);
	void	dump();
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print() const;
	void	help() const;
};


#endif