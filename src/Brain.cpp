/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:43 by mmasyush          #+#    #+#             */
/*   Updated: 2019/11/23 16:34:13 by mmasyush         ###   ########.fr       */
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

Brain & Brain::operator=(Brain const &)
{
    return *this;
}

void	Brain::push(const IOperand* value)
{

}

void	Brain::assert(const IOperand* value)
{

}

void	Brain::pop()
{
	
}

void	Brain::dump()
{

}

void	Brain::add()
{
	try
	{
		if (_stacki.size() < 2)
		throw Ex_NotEnough();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	const IOperand * result;

	_first = _stacki.top();
	_stacki.pop();
	_second = _stacki.top();
	_stacki.pop();
	result = *_first + *_second;
	_stacki.push(result);
	delete _first;
	delete _second;
}

void	Brain::sub()
{
	try
	{
		if (_stacki.size() < 2)
		throw Ex_NotEnough();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	const IOperand * result;

	_first = _stacki.top();
	_stacki.pop();
	_second = _stacki.top();
	_stacki.pop();
	result = *_first - *_second;
	_stacki.push(result);
	delete _first;
	delete _second;
}

void	Brain::mul()
{
	try
	{
		if (_stacki.size() < 2)
		throw Ex_NotEnough();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	const IOperand * result;

	_first = _stacki.top();
	_stacki.pop();
	_second = _stacki.top();
	_stacki.pop();
	result = *_first * *_second;
	_stacki.push(result);
	delete _first;
	delete _second;
}

void	Brain::div()
{
	try
	{
		if (_stacki.size() < 2)
		throw Ex_NotEnough();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	const IOperand * result;

	_first = _stacki.top();
	_stacki.pop();
	_second = _stacki.top();
	_stacki.pop();
	result = *_first / *_second;
	_stacki.push(result);
	delete _first;
	delete _second;
}

void	Brain::mod()
{
	try
	{
		if (_stacki.size() < 2)
		throw Ex_NotEnough();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	const IOperand * result;

	_first = _stacki.top();
	_stacki.pop();
	_second = _stacki.top();
	_stacki.pop();
	result = *_first % *_second;
	_stacki.push(result);
	delete _first;
	delete _second;
}

void	Brain::print() const
{
    
}
