/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:43 by mmasyush          #+#    #+#             */
/*   Updated: 2019/12/02 15:33:31 by mmasyush         ###   ########.fr       */
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
			std::cout << copy.top()->toString() << std::endl;
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
	int8_t ch;
	
    try
	{
		if (_stacki.empty())
			throw Ex_Empty();
		if (_stacki.top()->getType() == Int8)
		{
			ch = static_cast<int8_t>(std::stoi(_stacki.top()->toString()));
			std::cout << ch << std::endl;
		}
		else
			throw Ex_Print();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
