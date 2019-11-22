/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:43 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/22 19:33:31 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Brain.hpp"

Brain::Brain()
{

}

Brain::Brain(Brain const & src)
{
    *this = src;
}

Brain::~Brain() {}

Brain & Brain::operator=(Brain const & src)
{
    return *this;
}

void	Brain::_push(const IOperand* value)
{

}

void	Brain::_assert(const IOperand* value)
{
    
}

void	Brain::_pop()
{

}

void	Brain::_dump()
{

}

void	Brain::_add()
{
    if (_stacki.size() < 2)
		throw Ex_NotEnough();
	right_ = bs.stack_.back();
	bs.stack_.pop_back();
	left_ = bs.stack_.back();
	bs.stack_.pop_back();
	const IOperand *res = *left_ + *right_;
	bs.stack_.push_back(res);
	ce_del_io(&left_);
	ce_del_io(&right_);
}

void	Brain::_sub()
{

}

void	Brain::_mul()
{

}

void	Brain::_div()
{

}

void	Brain::_mod()
{

}

void	Brain::_print() const
{
    
}
