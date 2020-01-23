/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:43 by mmasyush          #+#    #+#             */
/*   Updated: 2020/01/23 13:54:02 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Brain.hpp"

Brain::Brain() {}

Brain::Brain(Brain const & src)
{
    *this = src;
}

Brain::~Brain() {}

Brain & Brain::operator=(Brain const &)
{
    return *this;
}

void	Brain::push(const IOperand * op)
{
	_stacki.push(op);
}

void	Brain::assert(const IOperand * op)
{
	try
	{
		if (_stacki.empty())
			throw Ex_Empty();
		if (op->toString() != _stacki.top()->toString())
			throw Ex_BadAssert();
	}
	catch(const std::exception& e)
	{
		std::cout<< e.what() << '\n';
	}
	
}

void	Brain::pop()
{
	try
	{
		if (_stacki.empty())
			throw Ex_PopEmpty();
		_stacki.pop();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::dump()
{
	try
	{
		if (_stacki.empty())
			throw Ex_Empty();
		std::stack<const IOperand *> copy = _stacki;
		while (!copy.empty())
		{
			std::cout << copy.top()->toString() <<  std::endl;
			copy.pop();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::add()
{
	try
	{
		if (_stacki.size() < 2)
			throw Ex_NotEnough();
		
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
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::sub()
{
	try
	{
		if (_stacki.size() < 2)
			throw Ex_NotEnough();
		
		const IOperand * result;

		_first = _stacki.top();
		_stacki.pop();
		_second = _stacki.top();
		_stacki.pop();
		result = *_second - *_first;
		_stacki.push(result);
		delete _first;
		delete _second;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::mul()
{
	try
	{
		if (_stacki.size() < 2)
			throw Ex_NotEnough();
		
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
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::div()
{
	const IOperand * result;
	
	try
	{
		if (_stacki.size() < 2)
			throw Ex_NotEnough();

		_first = _stacki.top();
		if (std::stold(_first->toString()) == 0)
			throw Ex_DivByZero();
		_stacki.pop();
		_second = _stacki.top();
		_stacki.pop();
		result = *_second / *_first;
		_stacki.push(result);
		delete _first;
		delete _second;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::mod()
{
	const IOperand * result;

	try
	{
		if (_stacki.size() < 2)
			throw Ex_NotEnough();
		_first = _stacki.top();
		if (std::stold(_first->toString()) == 0)
			throw Ex_ModByZero();
		_stacki.pop();
		_second = _stacki.top();
		_stacki.pop();
		result = *_second % *_first;
		_stacki.push(result);
		delete _first;
		delete _second;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Brain::print() const
{	
    try
	{
		if (_stacki.empty())
			throw Ex_Empty();
		if (_stacki.top()->getType() != Int8)
			throw Ex_Print();
		else
			std::cout << "\033[0;36m" << static_cast<int8_t>(std::stoi(_stacki.top()->toString())) << "\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

void	Brain::help() const
{	
	std::cout << "\033[1;34mHi! Here list of all alowed commands for this program:\033[0;32m\n" <<
		"1) push \033[4;31mVALUE\033[0;32m\n2) pop\n3) dump\n4) assert \033[4;31mVALUE\033[0;32m\n5) add\n6) sub\n7) mul\n8) div\n9) mod\n10) print\n11) exit\n"
		<< "\n\033[4;31mVALUE: \033[0;32m\n1) int8(N)\n2) int16(N)\n3) int32(N)\n4) float(Z)\n5) double(Z)\033[0m" << std::endl;
}
